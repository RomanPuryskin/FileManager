#include "tracker.h"
Tracker::Tracker(QString path)
{
    this->path = path;
    fileInfo = QFileInfo(path);
    isFileExist = fileInfo.exists();
    if (isFileExist)
        lastChange = fileInfo.lastModified();
}

bool Tracker::CheckFileExists()
{
    fileInfo.refresh();
    return fileInfo.exists();
}

QDateTime Tracker::CheckFileChanges()
{
    fileInfo.refresh();
    if (fileInfo.exists())
        return fileInfo.lastModified();
    return lastChange;
}
