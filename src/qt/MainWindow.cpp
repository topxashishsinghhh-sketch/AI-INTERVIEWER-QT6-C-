#include "MainWindow.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

namespace qt {

MainWindow::MainWindow(gui::SessionContext &sessionContext, QWidget *parent)
    : QMainWindow(parent), m_context(sessionContext) {
    // Simple UI setup
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    m_questionLabel = new QLabel(tr("Question: [Placeholder]"), central);
    m_questionLabel->setWordWrap(true);
    layout->addWidget(m_questionLabel);

    m_hintButton = new QPushButton(tr("Show Hint"), central);
    layout->addWidget(m_hintButton);

    setCentralWidget(central);

    // Connect button
    connect(m_hintButton, &QPushButton::clicked, this, &MainWindow::onShowHintClicked);
}

void MainWindow::onShowHintClicked() {
    // Placeholder hint – in a full implementation this would query the interview service.
    QMessageBox::information(this, tr("Hint"), tr("Hint not available in minimal UI."));
}

} // namespace qt
