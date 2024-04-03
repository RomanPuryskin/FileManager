#include "tracker.h"

Tracker::Tracker(QString path)
{
    this->path = path;
    this->fileInfo = QFileInfo(path);
}
