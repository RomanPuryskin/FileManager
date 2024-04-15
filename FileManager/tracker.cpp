#include "tracker.h"

Tracker::Tracker(QString path)
{
    this->path = path;
    fileInfo = QFileInfo(path);
    isFileExist = fileInfo.exists();
    if (fileInfo.exists())
    {
        lastChange = fileInfo.lastModified();
    }
    else
    {
        lastChange = QDateTime();
    }
}

bool Tracker::CheckFileExists()
{
    fileInfo.refresh();
    return fileInfo.exists();
}

QDateTime Tracker::CheckFileChanges()
{
    fileInfo.refresh();
    return fileInfo.lastModified();
}
