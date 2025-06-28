//NAME: NIGELLA KOMA
//STUDENT NUMBER:24802123

#include "Book.h"
#include "LibraryItem.h"

#include <iostream>
#include <QString>
#include <QDebug>


Book::Book(): LibraryItem()
{
    genreBook = "";
    numPages = 0;
}

Book::Book(QString t , QString a , int i , bool isB, QString g,int nump)
{
    title = t;
    author = a;
    id = i;
    isBorrowed = isB;
    genreBook = g;
}
void Book::setGenre(QString g)
 {
        genreBook = g;
}
QString Book::getGenre()const
{
   return genreBook;
}

void Book::setNumPages(int p)
{
    numPages = p;
}
int Book::getNumPages()const
{
    return numPages;
}


