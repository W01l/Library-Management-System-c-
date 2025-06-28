
#include "LibraryItem.h"
#include "Book.h"

#include <iostream>
#include <QString>
#include <QFile>       // for file handling
#include <QTextStream> // for file text input/output
#include <QDebug>
using namespace std;

LibraryItem::LibraryItem()
{
    title = "";
    author = "";
    id = 0;
    isBorrowed = false;
}

LibraryItem::LibraryItem(const LibraryItem &other)
{
    title = other.title;
    author = other.author;
    id = other.id;
    isBorrowed = other.isBorrowed;
}

LibraryItem::LibraryItem( QString t,  QString a, int i, bool isB)
//overloading constructor
    {
        title = t;
        author = a;
        id = i;
        isBorrowed = isB;
    }

void LibraryItem::setTitle(QString t) //initialise title for item
    {
        title = t;
    }
void LibraryItem::setAuthor(QString a) //initialise author for item
    {
        author = a;
    }
void LibraryItem::setId(int i) //initialise id for item
    {
        id = i;
    }
void LibraryItem::setIsBorrow(bool isB)
    {
        isBorrowed = isB;
    }

QString LibraryItem::getTitle()const //accessor
    {
        return title;
    }
QString LibraryItem::getAuthor()const //accessor
    {
        return author;
    }
int LibraryItem::getId()const //accessor
    {
        return id;
    }
bool LibraryItem::getIsBorrowed()const //Indicates whether the item is currently borrowed (True/False)
    {
        return isBorrowed;
    }


