#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <vector>
#include <iostream>
#include "logger.h"
#include "tracker.h"
class FileManager : public QObject //нужен лишь один экземпеляр класса, используем паттерн одиночки
{
    Q_OBJECT
public:
    static FileManager& Instance()
    {
        static FileManager temp;
        return temp;
    }
    void addTracker(QString path);
    bool removeTracker(QString path);
    void update();

    Logger* getLogger()
    {
        return logger;

    }

    qint64 getAmountOfTrackers()
    {
        return trackers.size();
    }

    QFileInfo getFileInfoById(qint64 id)
    {
        return trackers[id]->getFileInfo();
    }

protected:
    FileManager();
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator= (FileManager const&);
    std::vector<Tracker*> trackers;
    Logger *logger;
signals:
    void fileExistChanged(QString fileName , qint64 size , bool fileExists);
    void fileChanged(QString fileName , qint64 size , bool fileExists);
};

#endif // FILEMANAGER_H
