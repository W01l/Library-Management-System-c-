#define STUDENTADMIN "Student"
#define USERADMIN "user"

#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
#include "librarymanagment.h"

#include <QCoreApplication>
#include <QTextStream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <QString>
#include <QFile>
#include <fstream>
#include <QDebug>
#include <QVector>
#include <QMessageBox>

using namespace std;

int bookCount = 25;

bool writeFile(const QString &inFile)
{
    QString bookData;
     QString magazineData;

    //create a file
    QFile file(inFile);

    //open the file
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        if(bookData == "Book")
        {
            out << bookData;
            file.close();
            return true;
        }
        else
        {
            out << magazineData;
            file.close();
            return true;
        }

        qDebug() << "File written Successfully";
    }
    else
    {
        qDebug() << "Error: " << file.errorString();
        return false;
    }
}

void saveEntry(QString &type, QStringList &fields)
{
    QFile file("Library_Data.txt");

    if(file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << type;

        for(QString &field : fields)
            out << "|" << field;
        out << "\n\n\n";
        file.close();

        qDebug() << "Entry saved.";
    }
    else
    {
        qDebug() << "Entry unsaved.";
    }
}

//function that adds Books in the file
void  addBook()
{
    system("cls");

    QTextStream qin(stdin);
    QTextStream qout(stdout);

    QString titleId,author, genre;
    int bookId;

    cout << "Please enter book Id: ";
    qout.flush();
    cin >> bookId;

    cin.ignore();

    cout << "\nPlease enter the title of the book: ";
    qout.flush();
    titleId = qin.readLine();

    cout << "\nPlease enter the author of the book: ";
    qout.flush();
    author = qin.readLine();

    cout << "\nPlease enter the genre of the book: ";
    qout.flush();
    genre = qin.readLine();

    //write to file
    QFile fileName("Library_Data.txt");

    if(fileName.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&fileName);
        out << bookId << "," << titleId << "," << author << "," << genre << "\n";
        out.flush();
        fileName.close();
        qDebug() << "Book added successfully!";

    }
    else
    {
        QMessageBox::warning(nullptr, "Error", "Could not open the file!");
    }

    cout << "Book added to the library" << endl;
}




int main(int argc, char *argv[])
{
       QCoreApplication a(argc, argv);

       QTextStream in(stdin);
       QTextStream out(stdout);

       Book b;
       Magazine m;
       LibraryManagment l;

       int inOption = 0;

       while(inOption != 9)
       {
           system("cls");

           cout << " LIBRARY CONSOLE MANAGEMENT\n\n\n----------------------------------------------------------------------------";
           cout << endl << "1.Student:\n\n";
           cout << "\n2.User:\n\n";
           cout << "\n3.Exit: " << endl;
           cout << "---------------------------------------------------------------------" << endl;

            cout << "Enter the provided options: ";
            cin >> inOption;

            if(inOption == 1)
            {
                char studentUser[10];


                system("cls");

                cout << endl;
                cout << setw(20) << right << "\t\t--------->Student<----------";
                cout << "\n\nPlease enter your username(Password: Student):  "; //#define STUDENTADMIN "Student"
                cin >> studentUser;

                if(strcmp(studentUser, STUDENTADMIN) == 0)
                {

                    int inOptionStu = 0;

                    while(inOptionStu != 9)
                    {
                        system("cls");

                        cout << "\n0. Add a Book ";

                        cout << "\n1. Search a Book ";

                        cout << "\n2. View Available Book or Magazine ";

                        cout << "\n3. Borrow a Book";

                        cout << "\n4. Borrow a Magazine";

                        cout << "\n5. Return a Book";

                        cout << "\n6. Return a  Magazine";

                        cout << "\n7. Exit";

                        cout << "\n\n Enter your choice : ";

                        cin >> inOptionStu;


                        switch(inOptionStu)
                        {
                            case 0:
                                addBook();
                                break;

                            case 1:
                            break;

                            case 2:
                                b.displayInfo();
                                break;

                            case 3:
                             b.borrowBook();
                                break;

                            case 4:
                                m.borrowMagazine();
                                break;

                            case 5:
                                b.returnBook();
                                break;

                            case 6:
                                m.returnMagazine();
                                break;

                            case 7:
                                inOptionStu = 9;

                            default:
                                cout << "Try Again!" ;

                                    }
                     system ("cls");
                }
            }


           }
            else if(inOption == 2)
               {
                   char User[10];

                   system("cls");

                   cout << "\t\t--------->User<----------";
                   cout << "\n\nPlease enter your username(Password: user):  "; //#define STUDENTADMIN "Student"
                   cin >> User;

                   if(strcmp(User, USERADMIN) == 0)
                  {

                       int innerChoice = 0;

                       while(innerChoice != 9)
                       {
                           system("cls");

                           cout << "\n0. Add a Book ";

                           cout << "\n1. Search a Book ";

                           cout << "\n2.View Available Book or Magazine ";

                           cout << "\n3. Borrow a Book";

                           cout << "\n4. Borrow a Magazine";

                           cout << "\n5. Return a Book";

                           cout << "\n6. Return a  Magazine";

                           cout << "\n7. Exit";

                           cout << "\n\n Enter your choice : ";

                           cin >> innerChoice;


                           switch(innerChoice)
                           {
                           case 0:
                           addBook();
                           break;

                           case 1:
                           break;

                           case 2:
                           b.displayInfo();
                           break;

                           case 3:
                           b.borrowBook();
                           break;

                           case 4:
                           m.borrowMagazine();
                           break;

                           case 5:
                           b.returnBook();
                           break;

                           case 6:
                           m.returnMagazine();
                           break;

                           case 7:
                           innerChoice = 9;

                           default:
                           cout << "Try Again!" ;

                               getchar ();
                               getchar ();

                           }

                   }
               }
          }

           else if(inOption == 3)
            {
                terminate();
            }

            else
            {
                cout << "Thank you for using the Library! " << endl;

                getchar();
                getchar();
            }



    return a.exec();
       }
}


