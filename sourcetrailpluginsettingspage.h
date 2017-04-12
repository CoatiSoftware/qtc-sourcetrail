#ifndef SOURCETRAILPLUGINSETTINGSPAGE_H
#define SOURCETRAILPLUGINSETTINGSPAGE_H

#include "qtcreatorsourcetrail_global.h"

#include "sourcetrailpluginsettings.h"
#include <coreplugin/dialogs/ioptionspage.h>

#include <QPointer>

namespace SourceTrailPlugin {


namespace Ui {
class SourceTrailPluginSettingsPage;
}

class SourceTrailPluginSettingsPage : public Core::IOptionsPage
{
	Q_OBJECT

public:
	SourceTrailPluginSettingsPage(QObject *parent);
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
	SourceTrailPluginSettings m_sourceTrailPluginSettings;

	void settingsFromUi(SourceTrailPluginSettings& sourcetrail) const;
};

} // namespace SourceTrailPlugin

#endif // SOURCETRAILPLUGINSETTINGSPAGE_H
