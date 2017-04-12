#ifndef SOURCETRAILPLUGINSETTINGS_H
#define SOURCETRAILPLUGINSETTINGS_H

#include <QObject>
#include <QString>

class QSettings;

namespace SourceTrail {

class SourceTrailPluginSettings
{
public:
	void toSettings(QSettings* s) const;
	void fromSettings(QSettings* s);

	bool equals(const SourceTrailPluginSettings &bs) const;

	QString m_hostAddress = "localhost";
	int m_sourceTrailPort = 6666;
	int m_pluginPort = 6667;
};

inline bool operator==(const SourceTrailPluginSettings &t1, const SourceTrailPluginSettings &t2) { return t1.equals(t2); }
inline bool operator!=(const SourceTrailPluginSettings &t1, const SourceTrailPluginSettings &t2) { return !t1.equals(t2); }


} // namespace SoureTrailPlugin

#endif // SOURCETRAILPLUGINSETTINGS_H
