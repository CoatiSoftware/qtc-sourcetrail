#include "sourcetrailpluginsettingspage.h"
#include "ui_sourcetrailpluginsettingspage.h"

#include <QSettings>
#include <coreplugin/icore.h>

using namespace SourceTrailPlugin;

SourceTrailPluginSettingsPage::SourceTrailPluginSettingsPage(QObject *parent) :
	Core::IOptionsPage(parent),
	m_page(0)
{
	setId("P.SourceTrail");
	setDisplayName(tr("SourceTrail"));

	QSettings* s = Core::ICore::settings();
	m_sourceTrailPluginSettings.fromSettings(s);
}

SourceTrailPluginSettingsPage::~SourceTrailPluginSettingsPage()
{
	delete m_page;
}

QWidget *SourceTrailPluginSettingsPage::widget()
{
	if (!m_widget) {
		m_widget = new QWidget;
//		m_page = new Ui::SourceTrailPluginSettingsPage;
//		m_page->setupUi(m_widget);

//		connect(m_page->completionTrigger,
//				static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
//				this, &CompletionSettingsPage::onCompletionTriggerChanged);

//		int caseSensitivityIndex = 0;
//		switch (m_completionSettings.m_caseSensitivity) {
//		case TextEditor::CaseSensitive:
//			caseSensitivityIndex = 0;
//			break;
//		case TextEditor::CaseInsensitive:
//			caseSensitivityIndex = 1;
//			break;
//		case TextEditor::FirstLetterCaseSensitive:
//			caseSensitivityIndex = 2;
//			break;
//		}

//		int completionTriggerIndex = 0;
//		switch (m_completionSettings.m_completionTrigger) {
//		case TextEditor::ManualCompletion:
//			completionTriggerIndex = 0;
//			break;
//		case TextEditor::TriggeredCompletion:
//			completionTriggerIndex = 1;
//			break;
//		case TextEditor::AutomaticCompletion:
//			completionTriggerIndex = 2;
//			break;
//		}

//		m_page->caseSensitivity->setCurrentIndex(caseSensitivityIndex);
//		m_page->completionTrigger->setCurrentIndex(completionTriggerIndex);
//		m_page->automaticProposalTimeoutSpinBox
//					->setValue(m_completionSettings.m_automaticProposalTimeoutInMs);
//		m_page->insertBrackets->setChecked(m_completionSettings.m_autoInsertBrackets);
//		m_page->surroundBrackets->setChecked(m_completionSettings.m_surroundingAutoBrackets);
//		m_page->insertQuotes->setChecked(m_completionSettings.m_autoInsertQuotes);
//		m_page->surroundQuotes->setChecked(m_completionSettings.m_surroundingAutoQuotes);
//		m_page->partiallyComplete->setChecked(m_completionSettings.m_partiallyComplete);
//		m_page->spaceAfterFunctionName->setChecked(m_completionSettings.m_spaceAfterFunctionName);
//		m_page->autoSplitStrings->setChecked(m_completionSettings.m_autoSplitStrings);
//		m_page->animateAutoComplete->setChecked(m_completionSettings.m_animateAutoComplete);
//		m_page->highlightAutoComplete->setChecked(m_completionSettings.m_highlightAutoComplete);
//		m_page->skipAutoComplete->setChecked(m_completionSettings.m_skipAutoCompletedText);
//		m_page->removeAutoComplete->setChecked(m_completionSettings.m_autoRemove);

//		m_page->enableDoxygenCheckBox->setChecked(m_commentsSettings.m_enableDoxygen);
//		m_page->generateBriefCheckBox->setChecked(m_commentsSettings.m_generateBrief);
//		m_page->leadingAsterisksCheckBox->setChecked(m_commentsSettings.m_leadingAsterisks);

//		m_page->generateBriefCheckBox->setEnabled(m_page->enableDoxygenCheckBox->isChecked());
//		m_page->skipAutoComplete->setEnabled(m_page->highlightAutoComplete->isChecked());
//		m_page->removeAutoComplete->setEnabled(m_page->highlightAutoComplete->isChecked());
	}
	return m_widget;
}

void SourceTrailPluginSettingsPage::apply()
{
	if (!m_page) // page was never shown
		return;

//	CompletionSettings completionSettings;
//	CommentsSettings commentsSettings;

//	settingsFromUi(completionSettings, commentsSettings);

//	if (m_completionSettings != completionSettings) {
//		m_completionSettings = completionSettings;
//		m_completionSettings.toSettings(Core::ICore::settings());
//		emit completionSettingsChanged(completionSettings);
//	}

//	if (m_commentsSettings != commentsSettings) {
//		m_commentsSettings = commentsSettings;
//		m_commentsSettings.toSettings(Core::ICore::settings());
//		emit commentsSettingsChanged(commentsSettings);
//	}
}

void SourceTrailPluginSettingsPage::finish()
{
	delete m_widget;
	if (!m_page) // page was never shown
		return;
	delete m_page;
	m_page = 0;
}
