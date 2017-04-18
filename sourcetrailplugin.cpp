#include "sourcetrailplugin.h"
#include "sourcetrailconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>
#include <coreplugin/textdocument.h>
#include <extensionsystem/pluginmanager.h>
#include <texteditor/texteditor.h>

#include <QtPlugin>
#include <QAction>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QMainWindow>
#include <QMenu>
#include <QTcpSocket>
#include <QStringList>
#include <QTcpServer>
#include <QTextEdit>
#include <QTextDocument>
#include <QTextCursor>
#include <QFile>
#include <utils/fileutils.h>
#include <texteditor/textdocument.h>
#include <texteditor/texteditor.h>
#include <coreplugin/editormanager/editormanager.h>
#include <memory>
#include <QTcpServer>
#include <cppeditor/cppeditorconstants.h>
#include <QStatusBar>
#include <QPushButton>
#include <coreplugin/infobar.h>
#include <coreplugin/statusbarwidget.h>

using namespace Core;

namespace Sourcetrail {

SourcetrailPlugin::SourcetrailPlugin()
{
	m_server = new QTcpServer(this);

	connect(m_server, &QTcpServer::newConnection, [=](){
		QTcpSocket* connection = m_server->nextPendingConnection();
		connect(connection, &QAbstractSocket::disconnected,
				connection, &QObject::deleteLater);

		connect(connection, &QAbstractSocket::readyRead, [this, connection](){
			this->handleMessage(QString::fromLatin1(connection->readAll()));
		});
	});

	m_statusBar = new StatusBarWidget();
	m_statusBar->setWidget(new QLabel("Test"));
	m_statusBar->setPosition(StatusBarWidget::LastLeftAligned);
	addAutoReleasedObject(m_statusBar);

}

void SourcetrailPlugin::handleMessage(QString message)
{
	message = message.remove(message.indexOf("<EOM>"),5);
	QStringList list = message.split(">>");

	if (list[0] == "ping")
	{
		sendPing();
	}
	if (list[0] == "moveCursor")
	{
		setCursor(list[1], list[2].toInt(), list[3].toInt());
	}
}

SourcetrailPlugin::~SourcetrailPlugin()
{
	// Unregister objects from the plugin manager's object pool
	// Delete members

	stopListening();
	delete m_server;
}

void SourcetrailPlugin::restartServer()
{
	QSettings* s = Core::ICore::settings();
	m_settings.fromSettings(s);
	stopListening();
	startListening();
}



bool SourcetrailPlugin::initialize(const QStringList &arguments, QString *errorString)
{
	// Register objects in the plugin manager's object pool
	// Load settings
	// Add actions to menus
	// Connect to other plugins' signals
	// In the initialize function, a plugin can be sure that the plugins it
	// depends on have initialized their members.

	Q_UNUSED(arguments)
	Q_UNUSED(errorString)

	m_page = new SourceTrailPluginSettingsPage(this);
	addAutoReleasedObject(m_page);
	connect(m_page, &SourceTrailPluginSettingsPage::SourceTrailPluginSettingsChanged,
			this, &SourcetrailPlugin::restartServer);

	// (re-)start server
	QAction* startAction = new QAction(tr("Start Sourcetrail Listener"), this);
	Core::Command* restartCommand = Core::ActionManager::registerAction(startAction, Constants::RESTART_ACTION_ID,
															 Core::Context(Core::Constants::C_GLOBAL));

	connect(startAction, &QAction::triggered, this, & SourcetrailPlugin::restartServer);

	// stop server
	QAction* stopAction = new QAction(tr("Stop Sourcetrail Listener"), this);
	Core::Command* stopCommand = Core::ActionManager::registerAction(stopAction, Constants::RESTART_ACTION_ID,
															 Core::Context(Core::Constants::C_GLOBAL));

	connect(stopAction, &QAction::triggered, this, & SourcetrailPlugin::stopServer);

	// send location
	QAction* action = new QAction(QIcon(Constants::CATEGORY_ICON),tr("Send Location to Sourctrail"), this);
	Core::Command* cmd = Core::ActionManager::registerAction(action, Constants::SEND_ACTION_ID,
															 Core::Context(Core::Constants::C_GLOBAL));
	cmd->setDefaultKeySequence(QKeySequence(tr("Alt+S,Alt+S")));
	connect(action, &QAction::triggered, this, &SourcetrailPlugin::triggerAction);


	// sourctrail menu
	Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
	menu->menu()->setTitle(tr("Sourcetrail"));
	menu->menu()->setIcon(QIcon(Constants::CATEGORY_ICON));
	menu->addAction(cmd);
	menu->addAction(restartCommand);
	menu->addAction(stopCommand);
	Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);


	// Editor Context Menu
	if (ActionContainer *editorContextMenu =
			ActionManager::actionContainer(CppEditor::Constants::M_CONTEXT))
	{
//		editorContextMenu->addMenu(menu);
		editorContextMenu->addAction(cmd);
	}

	return true;
}


void SourcetrailPlugin::extensionsInitialized()
{
	// Retrieve objects from the plugin manager's object pool
	// In the extensionsInitialized function, a plugin can be sure that all
	// plugins that depend on it are completely initialized.
}

//void SourcetrailPlugin::delayedInitialize()
//{
////	restartServer();
//}

void SourcetrailPlugin::stopServer()
{
	stopListening();
}

void SourcetrailPlugin::startListening()
{
	if (!m_server->listen(QHostAddress::LocalHost, m_settings.m_sourceTrailPort))
	{
		QMessageBox::warning(Core::ICore::mainWindow(),
								 tr("SourceTrailPlugin Tcp Server"),
								 tr("Could not listen to port"));
	}
}


void SourcetrailPlugin::stopListening()
{
	if (m_server->isListening())
	{
		m_server->close();
	}
}

ExtensionSystem::IPlugin::ShutdownFlag SourcetrailPlugin::aboutToShutdown()
{
	// Save settings
	// Disconnect from signals that are not needed during shutdown
	// Hide UI (if you add UI that is not in the main window directly)
	return SynchronousShutdown;
}

void SourcetrailPlugin::sendMessage(QString message)
{
	QTcpSocket* senderSocket = new QTcpSocket(this);
	senderSocket->connectToHost(m_settings.m_hostAddress, m_settings.m_pluginPort);

	if (senderSocket->waitForConnected())
	{
		senderSocket->write(message.toUtf8());
		senderSocket->flush();
		senderSocket->waitForBytesWritten();
		senderSocket->close();
	}
}

void SourcetrailPlugin::sendPing()
{
	sendMessage("ping>>Qt Creator<EOM>");
}

void SourcetrailPlugin::setCursor(QString file, int line, int column)
{
	IEditor* editor = Core::EditorManager::openEditorAt(file, line, column);
	if (editor)
	{

	}
}

void SourcetrailPlugin::sendLocation()
{
	IEditor* editor = Core::EditorManager::currentEditor();
	if (editor)
	{
		int line = Core::EditorManager::currentEditor()->currentLine();
		int column = Core::EditorManager::currentEditor()->currentColumn();
		QString file = Core::EditorManager::currentDocument()->filePath().toString();

		QString message = "setActiveToken>>" + file + ">>" + QString::number(line)
				+ ">>" + QString::number(column) + "<EOM>";

		sendMessage(message);
	}
	else
	{
		QMessageBox::information(Core::ICore::mainWindow(),
								 tr("Action Triggered"),
								 tr("No cursor position sent, no editor"));
	}
}

void SourcetrailPlugin::triggerAction()
{
	sendPing();
	sendLocation();

	QStringList list;
	Core::ICore::openFiles(list);
}

} // namespace QtCreatorSourceTrail
