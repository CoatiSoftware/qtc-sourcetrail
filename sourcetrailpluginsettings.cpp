#include "sourcetrailpluginsettings.h"

#include <QSettings>

static const char settingsGroup[]      = "SourceTrail";
static const char addressKey[]         = "Address";
static const char pluginPortKey[]      = "PluginPort";
static const char sourceTrailPortKey[] = "SourceTrailPort";

using namespace SourceTrailPlugin;


void SourceTrailPluginSettings::fromSettings(QSettings *s)
{

}

void SourceTrailPluginSettings::toSettings(QSettings *s) const
{

}

bool SourceTrailPluginSettings::equals(const SourceTrailPluginSettings &stps) const
{
	return  m_hostAddress     == stps.m_hostAddress
		&& m_pluginPort       == stps.m_pluginPort
		&& m_sourceTrailPort  == stps.m_sourceTrailPort
		;
}

