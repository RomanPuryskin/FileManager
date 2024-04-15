#include <QCoreApplication>
#include "filemanager.h"
#include <thread>
void startTracking(FileManager& fileManager)
{
    std::vector<Tracker*> trackers = fileManager.getTrackers();
    (fileManager.getLogger())->setVector(trackers);

    while(true)
    {
        for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
        {
            if( !(*it)->getIsFileExist() && (*it)->CheckFileExists() )
            {
                (*it)->setIsFileExist(true);
                emit fileManager.fileExistChanged();
            }
            if ((*it)->getIsFileExist() && !(*it)->CheckFileExists())
            {
                (*it)->setIsFileExist(false);
                emit fileManager.fileExistChanged();
            }

            if( (*it)->CheckFileChanges() > (*it)->getLastChange())
            {
                (*it)->setLastChange((*it)->CheckFileChanges());
                emit fileManager.fileChanged();
            }
        }

        std::this_thread::sleep_for( std::chrono::milliseconds(1000));
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
    QString path4 = "tyrt";
    fileManager.addTracker(path4);

    // добавим уже существующий трекер
    fileManager.addTracker(path3);

    startTracking(fileManager);
    return a.exec();
}
