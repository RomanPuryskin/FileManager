#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <QObject>
#include "tracker.h"
class Logger
{
public:
    Logger();
    ~Logger(){}
    void PrintFirstInfo(Tracker* tracker);
};

#endif // LOGGER_H
