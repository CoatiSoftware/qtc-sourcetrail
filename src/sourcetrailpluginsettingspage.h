#pragma once

#include "sourcetrail_global.h"
#include "sourcetrailpluginsettings.h"

#include <coreplugin/dialogs/ioptionspage.h>

#include <QPointer>

namespace Sourcetrail {

namespace Ui { class SourcetrailPluginSettingsPage; }

class SourcetrailPluginSettingsPage : public Core::IOptionsPage
{
    Q_OBJECT

public:
    SourcetrailPluginSettingsPage(QObject *parent);
    ~SourcetrailPluginSettingsPage();

    // IOptionsPage
    QWidget *widget();
    void apply();
    void finish();

signals:
    void SourcetrailPluginSettingsChanged(const SourcetrailPluginSettings &);

private:
    void settingsFromUi(SourcetrailPluginSettings &sourcetrail) const;

    Ui::SourcetrailPluginSettingsPage *m_page;
    QPointer<QWidget> m_widget;
    SourcetrailPluginSettings m_settings;
};

} // namespace Sourcetrail
