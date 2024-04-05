#include <QCoreApplication>
#include "filemanager.h"
#include <typeinfo>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager& fileManager = FileManager::Instance();
    QString path1 = "C:/Projects/TRPO/FilesForManager/file1.txt";
    QString path2 = "C:/Projects/TRPO/FilesForManager/file2.txt";
    QString path3 = "C:/Projects/TRPO/FilesForManager/file3.txt";

    fileManager.addTracker(path1);
    fileManager.addTracker(path2);
    fileManager.addTracker(path3);

    fileManager.startTracking();
    return a.exec();
}
