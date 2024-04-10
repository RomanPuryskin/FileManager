#include "logger.h"

Logger::Logger()
{

}

// информация о файлах которая выводится изначально
void Logger::PrintFirstInfo(Tracker *tracker)
{
    QString fileName = tracker->getFileInfo().fileName();
        if(tracker->getIsFileExist())
        {
            qint64 size = tracker->getFileInfo().size();
            std::cout<<fileName.toStdString()<<" Exists "<<size<<"b"<<std::endl;
        }

        if(!tracker->getIsFileExist())
        {
            std::cout<<fileName.toStdString()<<" Doesn't exist"<<std::endl;
        }
}

void Logger::rePrint()
{
        system("cls");
        for(std::vector<Tracker*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
        {
            PrintFirstInfo((*it));
        }
}
