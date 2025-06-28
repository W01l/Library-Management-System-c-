
#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"


#include <QString>
#include <iostream>
#include <QFile>       // for file handling
#include <QTextStream> // for file text input/output
using namespace std;

class Book: public LibraryItem
{
public:


    Book();// default constructor
    Book(const Book &other);
    Book(QString t , QString a , int i , bool isB, QString g,int nump);//overload constructor

    void setGenre(QString g);
    void setNumPages(int p);

    int getNumPages()const;
    QString getGenre()const;


    void displayInfo()
    {
        QTextStream out(stdout);
        out << "Title: " << getTitle()
            << ", Author ID: " << getAuthor()
            << ", Status: " << (getIsBorrowed() ? "Borrowed" : "Available")
            << ", Genre: " << getGenre()
             <<endl;
    }

    void borrowBook()
    {
            if(!isBorrowed)
            {
                isBorrowed = true;
                cout << "Book borrowed successfully." << endl;
            } else
            {
                cout << "This book is already borrowed." << endl;
            }
     }

    void returnBook()
    {
            if(isBorrowed)
            {
                isBorrowed = false;
                cout << "Book returned successfully." << endl;
            } else
            {
                cout << "This book was not borrowed." << endl;
            }
        }

    void searchBook()
    {
        QString query;

        //Simple search example
        cout << "==============Simple Search Example===============" << endl;
        cout << "Enter search term for books: ";

        QTextStream out(stdout);
        out << query;

    }

       private:
      QString genreBook;//Book
      int numPages;
};

#endif // BOOK_H
