#include "logger.h"

Logger::Logger()
{

}

// информация о файлах которая выводится изначально
void Logger::PrintFirstInfo(Tracker *tracker)
{
    QString fileName = tracker->getFileInfo().fileName();
    if(tracker->isFileExist)
    {
        qint64 size = tracker->getFileInfo().size();
        std::cout<<fileName.toStdString()<<" "<<"Exists"<<" "<<size<<"b"<<std::endl;
    }

    else
        std::cout<<fileName.toStdString()<<" "<<"Doesn't exist"<<std::endl;
}
