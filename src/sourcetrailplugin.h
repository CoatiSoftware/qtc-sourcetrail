#pragma once

#include "sourcetrail_global.h"
#include "sourcetrailpluginsettingspage.h"

#include <extensionsystem/iplugin.h>

class QTcpServer;
class StatusBarWidget;
class QAction;
namespace Core {
	class Command;
}

namespace Sourcetrail {

class SourcetrailPlugin : public ExtensionSystem::IPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Sourcetrail.json")

public:
	SourcetrailPlugin();
	~SourcetrailPlugin();

    bool initialize(const QStringList &arguments, QString *errorString) override;
	void extensionsInitialized() override;
    bool delayedInitialize() override;
	ShutdownFlag aboutToShutdown() override;

public slots:
	void restartServer();
	void stopServer();

private:
	void handleMessage(QString message);
	void triggerAction();
	void sendPing();
	void sendLocation();
	void startListening();
	void stopListening();
	void sendMessage(QString message);
	void setCursor(QString file, int line, int column);
	QTcpServer* m_server;
	SourceTrailPluginSettingsPage* m_page;
	SourceTrailPluginSettings m_settings;
	StatusBarWidget* m_statusBar;
	Core::Command* m_statusCommand;

};

} // namespace SourceTrailPlugin
