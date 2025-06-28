
#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Magazine.h"
#include "LibraryItem.h"
#include "Book.h"
#include "librarymanagment.h"

#include <QString>
#include <QFile>       // for file handling
#include <QTextStream> // for file text input/output
#include <QObject>
#include <iostream>
using namespace std;

class Magazine: public LibraryItem
{

public:
       Magazine();// default constructor
       Magazine(const Magazine &other);// Copy constructor
       Magazine(QString t, QString a, int i, bool isB, int num);//overload constructor

       //setter and getter methods
       void setIssueNo(int num);
       int getIssueNo()const;

       //Override the display function
       void displayInfo()override
       {

           QTextStream out(stdout);
           out << "Title: " << getTitle()
               << ", Author ID: " << getAuthor()
               << ", Status: " << (getIsBorrowed() ? "Borrowed" : "Available")
               << ", Issue Number: " << getIssueNo()
                  << endl;
       }

       void borrowMagazine()
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

       void returnMagazine()
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



   private:
       int issueNumber;
};

#endif // MAGAZINE_H
