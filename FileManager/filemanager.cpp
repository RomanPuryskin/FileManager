#include "filemanager.h"

FileManager::FileManager()
{
    trackers = std::vector<Tracker*>();
    logger = new Logger();
    connect(this,&FileManager::fileExistChanged,logger,&Logger::rePrint);
    connect(this,&FileManager::fileChanged,logger,&Logger::rePrint);
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
