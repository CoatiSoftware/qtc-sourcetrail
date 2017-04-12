#include "sourcetrailpluginsettings.h"

#include <QSettings>
#include <extensionsystem/pluginmanager.h>
#include <coreplugin/icore.h>

static const char settingsGroup[]      = "SourceTrail";
static const char addressKey[]         = "Address";
static const char pluginPortKey[]      = "PluginPort";
static const char sourceTrailPortKey[] = "SourceTrailPort";

using namespace SourceTrail;


void SourceTrailPluginSettings::fromSettings(QSettings *s)
{
	// assign defaults
	*this = SourceTrailPluginSettings();

	s->beginGroup(settingsGroup);
	m_hostAddress = s->value(addressKey, m_hostAddress).toString();
	m_pluginPort = s->value(pluginPortKey, m_pluginPort).toInt();
	m_sourceTrailPort = s->value(sourceTrailPortKey, m_sourceTrailPort).toInt();
	s->endGroup();
}

void SourceTrailPluginSettings::toSettings(QSettings *s) const
{
	s->beginGroup(QLatin1String(settingsGroup));
	s->setValue(QLatin1String(addressKey), m_hostAddress);
	s->setValue(QLatin1String(pluginPortKey), m_pluginPort);
	s->setValue(QLatin1String(sourceTrailPortKey), m_sourceTrailPort);
	s->endGroup();
}

bool SourceTrailPluginSettings::equals(const SourceTrailPluginSettings &stps) const
{
	return  m_hostAddress     == stps.m_hostAddress
		&& m_pluginPort       == stps.m_pluginPort
		&& m_sourceTrailPort  == stps.m_sourceTrailPort
		;
}

