#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QObject>

class FileManager : public QObject //нужен лишь один экземпеляр класса, используем паттерн одиночки
{
    Q_OBJECT
public:
    static FileManager& Instance()
    {
        static FileManager temp;
        return temp;
    }

private:
    FileManager();
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator= (FileManager const&);
};

#endif // FILEMANAGER_H
