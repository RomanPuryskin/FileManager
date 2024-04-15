#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <QObject>
#include "tracker.h"
class Logger : public QObject
{
    Q_OBJECT
public:
    Logger();
    ~Logger()
    {
        for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
            delete *it;
        trackers.clear();
    }
    void setVector(std::vector<Tracker*> trackers)
    {
        this->trackers = trackers;
    }
    void PrintFirstInfo(Tracker* tracker);
private:
    std::vector<Tracker*> trackers;
public slots:
    void rePrint();
};

#endif // LOGGER_H
