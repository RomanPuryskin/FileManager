#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <vector>
#include "logger.h"
#include <thread>
 #include <future>
#include <typeinfo>
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
    void startTracking();

private:
    FileManager();
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator= (FileManager const&);
    std::vector<Tracker*> trackers;
    Logger *logger;

public slots:
    void rePrint();
signals:
    fileExistChanged();
};

#endif // FILEMANAGER_H
