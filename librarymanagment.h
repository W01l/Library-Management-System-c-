#ifndef LIBRARYMANAGMENT_H
#define LIBRARYMANAGMENT_H

#include <QString>
#include <QTextStream>
#include <iostream>

#include "Magazine.h"
#include "LibraryItem.h"
#include "Book.h"
#include "librarymanagment.h"

using namespace std;

class LibraryManagment : public LibraryItem
{
public:
    LibraryManagment();

    static const int MAX = 25;

    //data of book
    QString bookTitle[MAX];
    QString bookAuthor[MAX];
    QString bookId[MAX];
    QString bookGenre[MAX];
    int bookNum[MAX];
    bool bookAvailable[MAX];
    int bookCount;

    //data of magazine
    QString magTitle[MAX];
    QString magkAuthor[MAX];
    QString magkId[MAX];
    int magIssue[MAX];
    bool magAvailable[MAX];
    int magCount;

    void addBook(QString t , QString a , int i , bool isB, QString g,int nump);
    void addMagazine(QString t, QString a, int i, bool isB, int num);
    void view_available_items();
};

#endif // LIBRARYMANAGMENT_H
