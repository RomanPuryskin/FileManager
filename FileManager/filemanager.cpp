#include "filemanager.h"

FileManager::FileManager()
{

}

void FileManager::checkFIle(QString path)
{
    fileInfo = QFileInfo(path);
    if(fileInfo.isFile())
    {
        std::cout<<"Yes file";
    }

    else
        std::cout<<"No file";
}
