#include "filemanager.h"

FileManager::FileManager()
{
    this->trackers = std::vector<Tracker*>();
    connect(this,&FileManager::fileExistChanged,this,&FileManager::rePrint);
}

FileManager::~FileManager()
{
    for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
        delete *it;
    trackers.clear();
}

void FileManager::addTracker(QString path)
{
    bool alreadyExist = false;
    for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
    {
        if((*it)->getPath() == path)
            alreadyExist = true;
    }
    if(!alreadyExist)
    {
        Tracker *tracker = new Tracker(path);
        trackers.push_back(tracker);
        logger->PrintFirstInfo(tracker);
    }
}




void FileManager::startTracking()
{
    while(true)
    {
        for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
        {
            if( !(*it)->isFileExist && (*it)->CheckFileExists() )
            {
                (*it)->setIsFileExist(true);
                emit fileExistChanged();
            }
            else if ((*it)->isFileExist && !(*it)->CheckFileExists())
            {
                (*it)->setIsFileExist(false);
                emit fileExistChanged();
            }
        }

        std::this_thread::sleep_for( std::chrono::milliseconds(1000));
    }
}

void FileManager::rePrint()
{
    system("cls");
    for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
    {
        logger->PrintFirstInfo(*it);
    }
}
