#include "librarymanagment.h"
#include "Magazine.h"
#include "LibraryItem.h"
#include "Book.h"

#include <QString>
#include <QFile>       // for file handling
#include <QTextStream> // for file text input/output
#include <QObject>
#include <QMessageBox>
#include <iostream>
using namespace std;

LibraryManagment::LibraryManagment()
{
    bookCount = 0;
    magCount = 0;
}

void LibraryManagment::addBook(QString t , QString a , int i , bool isB, QString g,int nump)
{
    if(bookCount < MAX)
    {
        bookTitle[bookCount] = t;
        bookAuthor[bookCount] = a;
        bookId[bookCount] = i;
        bookGenre[bookCount] = g;
        bookNum[bookCount] = nump;
        bookAvailable[bookCount] = isB;
        bookCount++;
    }
}

void LibraryManagment::addMagazine(QString t, QString a, int i, bool isB, int num)
{
    if(magCount < MAX)
    {
         magTitle[magCount] = t;
         magkAuthor[magCount] = a;
         magkId[magCount] = i;
         magAvailable[magCount] = isB;
         magIssue[magCount] = num;
         magCount++;
    }
}

void LibraryManagment::view_available_items()
{
     QTextStream qout(stdout);

       qout << "=== Available Books ===\n";
       bool any_books = false;
       for (int i = 0; i < bookCount; i++) {
           if (bookAvailable[i]) {
                 qout << "ISBN: " << bookId[i] << "\n\n";
                qout << "Title: " << bookTitle[i] << "\n";
                qout << "Author: " << bookAuthor[i] << "\n";
               any_books = true;
           }
       }
       if (!any_books) qout << "No available books.\n\n";

        qout << "=== Available Magazines ===\n";
       bool any_mags = false;
       for (int i = 0; i < magCount; i++) {
           if (magAvailable[i]) {
                 qout << "Issue: " <<QString::number(magIssue[i]) << "\n\n";
                qout << "Title: " << magTitle[i] << "\n\n";
               any_mags = true;
           }
       }
       if (!any_mags) qout << "No available magazines.\n";

        qout.flush();
}

