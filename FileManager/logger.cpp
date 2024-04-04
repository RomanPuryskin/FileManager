#include "logger.h"

Logger::Logger()
{

}

void Logger::PrintInfo(Tracker *tracker)
{
    QString fileName = tracker->getFileInfo().fileName();
    if(tracker->getFileInfo().exists())
        std::cout<<fileName.toStdString()<<" "<<"Yes file"<<std::endl;

    else
        std::cout<<fileName.toStdString()<<" "<<"No file"<<std::endl;
}
