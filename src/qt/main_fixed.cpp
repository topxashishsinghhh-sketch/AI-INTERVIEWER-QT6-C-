#include <QApplication>
#include "gui/SessionContext.h"
#include "db/RepositoryFactory.h"
#include <string>
#include "qt/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    const std::string dataDir = "./data";
    const bool useMongo = false; // using JSON storage for now
    const std::string mongoDb = "ai_interviewer";
    gui::SessionContext context(dataDir,
                               useMongo ? db::StorageBackend::Mongo : db::StorageBackend::Json,
                               mongoDb);
    qt::MainWindow window(context);
    window.show();
    return app.exec();
}
