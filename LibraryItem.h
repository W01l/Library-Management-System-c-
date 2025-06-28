
#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <QString>
#include <QTextStream>
#include <iostream>
using namespace std;

class LibraryItem
{
protected:
    QString title;
    QString author;
    int id;
    bool isBorrowed;

public:
    // Constructors
    LibraryItem();
    LibraryItem(const LibraryItem &other);
    LibraryItem(QString t, QString a, int i, bool isB);

    // Setters
    void setTitle(QString t);
    void setAuthor(QString a);
    void setId(int i);
    void setIsBorrow(bool isB);

    // Getters
    QString getTitle() const;
    QString getAuthor() const;

    int getId() const;
    bool getIsBorrowed()const;

    virtual void displayInfo()
    {
        QTextStream out(stdout);
        out << "Title: " << getTitle()
            << ", Author ID: " << getAuthor()
            << ", Status: " << (getIsBorrowed() ? "Borrowed" : "Available")
            << endl;
    }

};

#endif // LIBRARYITEM_H
