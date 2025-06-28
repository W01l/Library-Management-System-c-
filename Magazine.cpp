
#include "Magazine.h"
#include "LibraryItem.h"


#include <QString>
#include <iostream>
#include <QTextStream> // for file text input/output
#include <QDebug>
using namespace std;

Magazine::Magazine(): LibraryItem()
{
    issueNumber = 0;
}

Magazine::Magazine(const Magazine &other) : LibraryItem(other)
{
   issueNumber = other.issueNumber;
}

Magazine::Magazine(QString t, QString a, int i, bool isB, int num)
        :LibraryItem(t, a, i, isB)
{
        issueNumber = num;}

void Magazine::setIssueNo(int num)
 {
       issueNumber = num;
}
int Magazine::getIssueNo()const
{
   return issueNumber;
}

