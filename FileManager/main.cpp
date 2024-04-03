#include <QCoreApplication>
#include "filemanager.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager& fileManager = FileManager::Instance();
    return a.exec();
}
