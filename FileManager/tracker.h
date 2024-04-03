#ifndef TRACKER_H
#define TRACKER_H
#include <QFileInfo>
#include <iostream>
class Tracker
{
public:
    Tracker(QString path);
    ~Tracker(){}
    QFileInfo getFileInfo()
    {
        return fileInfo;
    }
private:
    QFileInfo fileInfo;
    QString path;
};

#endif // TRACKER_H
