#include <QCoreApplication>
#include "filemanager.h"
#include <thread>

void startTracking(FileManager& fileManager)
{
    while(true)
    {
        fileManager.update();
        std::this_thread::sleep_for( std::chrono::milliseconds(1000));
    }
}


void printFirstInfo(FileManager& fileManager)
{
    for(int i = 0 ; i<fileManager.getAmountOfTrackers(); i++)
    {
        fileManager.getLogger()->PrintInfo(fileManager.getFileInfoById(i).fileName(),
            fileManager.getFileInfoById(i).size(),fileManager.getFileInfoById(i).exists());
    }
}

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
 /* QString path4 = "tyrt";
    fileManager.addTracker(path4);*/

    // добавим уже существующий трекер
   // fileManager.addTracker(path3);

    printFirstInfo(fileManager);
    startTracking(fileManager);
    return a.exec();
}
