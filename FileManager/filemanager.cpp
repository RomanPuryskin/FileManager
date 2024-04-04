#include "filemanager.h"

FileManager::FileManager()
{
    this->trackers = std::vector<Tracker*>();
    //Logger *logger = new Logger();
}

FileManager::~FileManager()
{
    for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
        delete *it;
    trackers.clear();
    //delete logger;
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
        logger->PrintInfo(tracker);
    }
}

