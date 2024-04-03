#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QObject>
#include <QFileInfo>
#include <iostream>

class FileManager : public QObject //нужен лишь один экземпеляр класса, используем паттерн одиночки
{
    Q_OBJECT
public:
    static FileManager& Instance()
    {
        static FileManager temp;
        return temp;
    }

    QFileInfo fileInfo;
    void checkFIle(QString path);

private:
    FileManager();
    ~FileManager(){}
    FileManager(FileManager const&);
    FileManager& operator= (FileManager const&);
};

#endif // FILEMANAGER_H
