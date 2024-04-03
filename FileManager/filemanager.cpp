#include "filemanager.h"

FileManager::FileManager()
{
    this->trackers = std::vector<Tracker*>();
}

FileManager::~FileManager()
{
    for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
        delete *it;
    trackers.clear();
}

void FileManager::addTracker(QString path)
{
    trackers.push_back(new Tracker(path));
}

void FileManager::printInfo()
{
    for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
    {
        if((*it)->getFileInfo().exists())
            std::cout<<"Yes file"<<std::endl;
        else
            std::cout<<"No file"<<std::endl;
    }
}
