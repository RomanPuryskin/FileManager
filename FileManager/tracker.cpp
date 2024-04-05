#include "tracker.h"

Tracker::Tracker(QString path)
{
    this->path = path;
    fileInfo = QFileInfo(path);
    isFileExist = fileInfo.exists();
}

bool Tracker::CheckFileExists()
{
    fileInfo.refresh();
    return fileInfo.exists();
}
