#include "sourcetrailpluginsettingspage.h"

#include "sourcetrailconstants.h"
#include "ui_sourcetrailpluginsettingspage.h"

#include <coreplugin/icore.h>

namespace Sourcetrail {

SourcetrailPluginSettingsPage::SourcetrailPluginSettingsPage(QObject *parent) :
    Core::IOptionsPage(parent),
    m_page(0)
{
    setId(Constants::CATEGORY_ID);
    setDisplayName(tr(Constants::CATEGORY));

    setCategory(Utils::Id(Constants::CATEGORY_ID));
    setDisplayCategory(QLatin1String(Constants::CATEGORY));
    setCategoryIcon(Utils::Icon(Constants::CATEGORY_ICON));

    QSettings *s = Core::ICore::settings();
    m_settings.fromSettings(s);
}

SourcetrailPluginSettingsPage::~SourcetrailPluginSettingsPage()
{
    delete m_page;
}

QWidget *SourcetrailPluginSettingsPage::widget()
{
    if (!m_widget) {
        m_widget = new QWidget;
        m_page = new Ui::SourcetrailPluginSettingsPage;
        m_page->setupUi(m_widget);

        m_page->hostaddress->setText(m_settings.m_hostAddress);
        m_page->pluginport->setText(QString::number(m_settings.m_pluginPort));
        m_page->sourcetrailport->setText(QString::number(m_settings.m_sourcetrailPort));
    }
    return m_widget;
}

void SourcetrailPluginSettingsPage::apply()
{
    if (!m_page) // page was never shown
        return;

    SourcetrailPluginSettings setting;
    settingsFromUi(setting);

    if (m_settings != setting)
    {
        m_settings = setting;
        QSettings *s = Core::ICore::settings();
        m_settings.toSettings(s);
        emit SourcetrailPluginSettingsChanged(setting);
    }
}

void SourcetrailPluginSettingsPage::finish()
{
    delete m_widget;
    if (!m_page) // page was never shown
        return;
    delete m_page;
    m_page = 0;
}

void SourcetrailPluginSettingsPage::settingsFromUi(SourcetrailPluginSettings &settings) const
{
    if (!m_page)
        return;

    settings.m_hostAddress = m_page->hostaddress->text();
    settings.m_pluginPort = m_page->pluginport->text().toInt();
    settings.m_sourcetrailPort = m_page->sourcetrailport->text().toInt();
}

} // namespace Sourcetrail
