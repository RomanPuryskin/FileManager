#include "logger.h"
#include <QDebug>
void Logger::PrintInfo(QString fileName , qint64 size , bool fileExists)
{
    if(fileExists)
        qDebug() << "FileName: " << fileName << ", Exists ," <<" size: " << size << "bytes";
    else
        qDebug() << "FileName: " <<fileName << ", Doesn't exist";
}


void Logger::rePrint(QString fileName , qint64 size , bool fileExists)
{
    PrintInfo(fileName,size,fileExists);
}
