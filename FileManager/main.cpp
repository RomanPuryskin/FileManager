#include <QCoreApplication>
#include "filemanager.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager& fileManager = FileManager::Instance();

    //----------------Test------------//
    QString path1 = "C:/Projects/TRPO/FilesForManager/file1.txt";
    fileManager.addTracker(path1);

    QString path2 = "C:/Projects/TRPO/FilesForManager/file2.txt";
    fileManager.addTracker(path2);

    QString path3 = "C:/Projects/TRPO/FilesForManager/file3.txt";
    fileManager.addTracker(path3);

    // добавим путь как случайную строку
    QString path4 = "tyrt";
    fileManager.addTracker(path4);

    // добавим уже существующий трекер
    fileManager.addTracker(path3);


    fileManager.startTracking();
    return a.exec();
}
