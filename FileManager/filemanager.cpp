#include "filemanager.h"

FileManager::FileManager()
{
    trackers = std::vector<Tracker*>();
    logger = new Logger();
    connect(this,&FileManager::fileExistChanged,this,&FileManager::rePrint);
    connect(this,&FileManager::fileChanged,this,&FileManager::rePrint);
}

FileManager::~FileManager()
{
    for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
        delete *it;
    trackers.clear();
     delete logger;
}


void FileManager::addTracker(QString path)
{
    bool alreadyExist = false;
    for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
    {
        if((*it)->getPath() == path)
        {
            alreadyExist = true;
            std::cerr<<"File already exists in manager"<<std::endl;
        }


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
            if( !(*it)->getIsFileExist() && (*it)->CheckFileExists() )
            {
                (*it)->setIsFileExist(true);
                emit fileExistChanged();
            }
            if ((*it)->getIsFileExist() && !(*it)->CheckFileExists())
            {
                (*it)->setIsFileExist(false);
                emit fileExistChanged();
            }

            if( (*it)->CheckFileChanges() > (*it)->getLastChange())
            {
                (*it)->setLastChange((*it)->CheckFileChanges());
                emit fileChanged();
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
