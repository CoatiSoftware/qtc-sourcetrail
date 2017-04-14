#include "sourcetrailpluginsettingspage.h"
#include "ui_sourcetrailpluginsettingspage.h"

#include <QSettings>
#include <coreplugin/icore.h>
#include <QLineEdit>
#include "sourcetrailpluginsettings.h"
#include "sourcetrailconstants.h"
#include <projectexplorer/projectexplorerconstants.h>

using namespace Sourcetrail;


SourceTrailPluginSettingsPage::SourceTrailPluginSettingsPage(QObject *parent) :
	Core::IOptionsPage(parent),
	m_page(0)
{
	setId(Constants::CATEGORY_ID);
	setDisplayName(tr(Constants::CATEGORY));

	setCategory(Core::Id(Constants::CATEGORY_ID));
	setDisplayCategory(QLatin1String(Constants::CATEGORY));
	setCategoryIcon(Utils::Icon(Constants::CATEGORY_ICON));

	QSettings* s = Core::ICore::settings();
	m_settings.fromSettings(s);
}

SourceTrailPluginSettingsPage::~SourceTrailPluginSettingsPage()
{
	delete m_page;
}

QWidget *SourceTrailPluginSettingsPage::widget()
{
	if (!m_widget) {
		m_widget = new QWidget;
		m_page = new Ui::SourceTrailPluginSettingsPage;
		m_page->setupUi(m_widget);

		m_page->hostaddress->setText(m_settings.m_hostAddress);
		m_page->pluginport->setText(QString::number(m_settings.m_pluginPort));
		m_page->sourcetrailport->setText(QString::number(m_settings.m_sourceTrailPort));
	}
	return m_widget;
}

void SourceTrailPluginSettingsPage::apply()
{
	if (!m_page) // page was never shown
		return;

	SourceTrailPluginSettings setting;
	settingsFromUi(setting);

	if (m_settings != setting)
	{
		m_settings = setting;
		emit SourceTrailPluginSettingsChanged(setting);
	}

	m_settings.debugOutput();
}

void SourceTrailPluginSettingsPage::settingsFromUi(SourceTrailPluginSettings &settings) const
{
	if (!m_page)
		return;

	settings.m_hostAddress = m_page->hostaddress->text();
	settings.m_pluginPort = m_page->pluginport->text().toInt();
	settings.m_sourceTrailPort = m_page->sourcetrailport->text().toInt();
}

void SourceTrailPluginSettingsPage::finish()
{
	delete m_widget;
	if (!m_page) // page was never shown
		return;
	delete m_page;
	m_page = 0;
}
