#pragma once

#include "qtcreatorsourcetrail_global.h"

#include <extensionsystem/iplugin.h>

class QTcpServer;

namespace QtCreatorSourceTrail {
namespace Internal {

class QtCreatorSourceTrailPlugin : public ExtensionSystem::IPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "QtCreatorSourceTrail.json")

public:
	QtCreatorSourceTrailPlugin();
	~QtCreatorSourceTrailPlugin();

	bool initialize(const QStringList &arguments, QString *errorString);
	void extensionsInitialized();
	ShutdownFlag aboutToShutdown();

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
};

} // namespace Internal
} // namespace QtCreatorSourceTrail
