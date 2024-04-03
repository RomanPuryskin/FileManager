#include <QCoreApplication>
#include "filemanager.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager& fileManager = FileManager::Instance();
    QString path = "C:/Projects/TRPO/FilesForManager/file1.txt";
    fileManager.checkFIle(path);
    return a.exec();
}
