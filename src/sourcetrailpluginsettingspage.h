#ifndef SOURCETRAILPLUGINSETTINGSPAGE_H
#define SOURCETRAILPLUGINSETTINGSPAGE_H

#include "sourcetrail_global.h"

#include "sourcetrailpluginsettings.h"
#include <coreplugin/dialogs/ioptionspage.h>

#include <QPointer>

namespace Sourcetrail {

namespace Ui { class SourceTrailPluginSettingsPage; }

class SourceTrailPluginSettingsPage : public Core::IOptionsPage
{
	Q_OBJECT

public:
	SourceTrailPluginSettingsPage(QObject* parent);
	~SourceTrailPluginSettingsPage();

	// IOptionsPage
	QWidget* widget();
	void apply();
	void finish();

signals:
	void SourceTrailPluginSettingsChanged(const SourceTrailPluginSettings &);

private:
	Ui::SourceTrailPluginSettingsPage* m_page;
	QPointer<QWidget> m_widget;
	SourceTrailPluginSettings m_settings;

	void settingsFromUi(SourceTrailPluginSettings& sourcetrail) const;
};

} // namespace SourceTrail

#endif // SOURCETRAILPLUGINSETTINGSPAGE_H
