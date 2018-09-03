#pragma once

#include <QObject>
#include <QString>

class QSettings;

namespace Sourcetrail {

class SourcetrailPluginSettings
{
public:
    void toSettings(QSettings *s) const;
    void fromSettings(QSettings *s);

    bool equals(const SourcetrailPluginSettings &bs) const;

    QString m_hostAddress = "localhost";
    int m_sourcetrailPort = 6666;
    int m_pluginPort = 6667;
};

inline bool operator==(const SourcetrailPluginSettings &t1, const SourcetrailPluginSettings &t2) { return t1.equals(t2); }
inline bool operator!=(const SourcetrailPluginSettings &t1, const SourcetrailPluginSettings &t2) { return !t1.equals(t2); }


} // namespace Sourcetrail
