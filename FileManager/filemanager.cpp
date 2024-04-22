#include "filemanager.h"
FileManager::FileManager()
{
    trackers = std::vector<Tracker*>();
    logger = new Logger();
    connect(this,&FileManager::fileExistChanged,logger,&Logger::PrintFileExistChanged);
    connect(this,&FileManager::fileChanged,logger,&Logger::PrintFileChanged);
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
    }
}

void FileManager::update()
{
    for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
    {
        if( !(*it)->getIsFileExist() && (*it)->CheckFileExists() )
        {
            (*it)->setIsFileExist(true);
            (*it)->setLastChange((*it)->CheckFileChanges());
            emit fileExistChanged((*it)->getFileInfo().fileName(),(*it)->getFileInfo().size(),
                (*it)->getIsFileExist());
        }
        if ((*it)->getIsFileExist() && !(*it)->CheckFileExists())
        {
            (*it)->setIsFileExist(false);
            emit fileExistChanged((*it)->getFileInfo().fileName(),(*it)->getFileInfo().size(),
                                  (*it)->getIsFileExist());
        }

        if( (*it)->CheckFileChanges() > (*it)->getLastChange())
        {
            (*it)->setLastChange((*it)->CheckFileChanges());
            emit fileChanged((*it)->getFileInfo().fileName(),(*it)->getFileInfo().size());
        }
    }
}

bool FileManager::removeTracker(QString path)
{
    for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
    {
        if((*it)->getPath() == path)
        {
            trackers.erase(it);
            delete *it;
            return true;
        }
    }
    return false;
}


