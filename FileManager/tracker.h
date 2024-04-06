#ifndef TRACKER_H
#define TRACKER_H
#include <QFileInfo>
#include <QObject>
#include <QDateTime>
#include <QFile>
class Tracker
{
public:
    Tracker(QString path);
    ~Tracker(){}
    QFileInfo getFileInfo()
    {
        return fileInfo;
    }
    QString getPath()
    {
        return path;
    }

    bool getIsFileExist()
    {
        return isFileExist;
    }

    void setIsFileExist(bool exist)
    {
        isFileExist = exist;
    }
    bool CheckFileExists();

    QDateTime getLastChange()
    {
        return lastChange;
    }
    void setLastChange(QDateTime temp)
    {
        lastChange = temp;
    }
    QDateTime CheckFileChanges();
private:
    QDateTime lastChange;
    QFileInfo fileInfo;
    QString path;
    bool isFileExist;
};

#endif // TRACKER_H
