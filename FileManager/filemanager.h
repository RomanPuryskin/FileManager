#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <vector>
#include "logger.h"
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
    std::vector<Tracker*> getTrackers()
    {
        return trackers;
    }
    Logger* getLogger()
    {
        return logger;
    }
protected:
    FileManager();
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator= (FileManager const&);
    std::vector<Tracker*> trackers;
    Logger *logger;
signals:
    void fileExistChanged();
    void fileChanged();
};

#endif // FILEMANAGER_H
