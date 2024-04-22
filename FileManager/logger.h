#ifndef LOGGER_H
#define LOGGER_H
#include <QObject>

class Logger : public QObject
{
    Q_OBJECT
public:
    Logger(){}
    ~Logger(){}
    void PrintInfo(QString fileName , qint64 size , bool fileExists);
public slots:
    void PrintFileExistChanged(QString fileName , qint64 size , bool fileExists);
    void PrintFileChanged(QString fileName , qint64 size);
};

#endif // LOGGER_H
