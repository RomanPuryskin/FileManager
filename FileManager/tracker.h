#ifndef TRACKER_H
#define TRACKER_H
#include <QFileInfo>
#include <QObject>
class Tracker : public QObject
{
    Q_OBJECT
public:
    Tracker(QString path);
    ~Tracker(){}
    QFileInfo getFileInfo()
    {
        return fileInfo;
    }
    QString getPath()
    {
        return path;
    }

    bool getIsFileExist()
    {
        return isFileExist;
    }

    void setIsFileExist(bool exist)
    {
        this->isFileExist = exist;
    }
    bool CheckFileExists();
    bool isFileExist; // состояние файла(существует/не существует)
private:

    QFileInfo fileInfo;
    QString path;
};

#endif // TRACKER_H
