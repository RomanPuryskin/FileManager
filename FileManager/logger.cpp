#include "logger.h"
#include <QDebug>
void Logger::PrintInfo(QString fileName , qint64 size , bool fileExists)
{
    if(fileExists)
        qDebug() << "FileName: " << fileName << ", Exists ," <<" size: " << size << "bytes";
    else
        qDebug() << "FileName: " <<fileName << ", Doesn't exist";
}


void Logger::PrintFileExistChanged(QString fileName , qint64 size , bool fileExists)
{
    PrintInfo(fileName,size,fileExists);
}

void Logger::PrintFileChanged(QString fileName, qint64 size)
{
    qDebug() << "FileName: " << fileName << ", Exists (has changed)," <<" size: " << size << "bytes";
}
