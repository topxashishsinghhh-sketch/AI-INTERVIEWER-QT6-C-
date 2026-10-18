#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

// Forward declaration of the existing SessionContext class
namespace gui {
class SessionContext;
}

namespace qt {

/**
 * Minimal main window for the AI Interviewer Qt frontend.
 * Shows a placeholder question and a "Show Hint" button.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    /**
     * Construct the window with a shared SessionContext.
     */
    explicit MainWindow(gui::SessionContext &sessionContext, QWidget *parent = nullptr);

private slots:
    void onShowHintClicked();

private:
    gui::SessionContext &m_context;
    QLabel *m_questionLabel;
    QPushButton *m_hintButton;
};

} // namespace qt
