#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SalesRep
{
    public:
        char rep[10];
        char region[10];
};

class ItemCatalog
{
    friend class SALESREC;
    public:
        char item[10];
    private:
        float unitCost;
};

class SALESREC: public SalesRep, public ItemCatalog
{
    friend ostream& operator<<(ostream& stream, SALESREC record) {
        stream << record.formatStream();
        return stream;
    }
    public:
        char date[10];
        int units;
        
        void setUnitCost(float newCost)
        {
        unitCost = newCost;
        }
        
        float getUnitCost()
        {
        return unitCost;
        }

        float Total()
        {
            return   units * unitCost;
        }
        
        void displayRec()
        {
        cout << "Record: " << date <<", " << region << ", " << rep << ", " << item << ", " << units << ", " << unitCost << ", " << Total() << endl;
        }

        string formatStream () {
            string a = date;
            string b = rep;
            string c = item;
            return a + b + c;
        }

        bool operator == (SALESREC compareto) {
            string sdate = date;
            string sdate2 = compareto.date;
            string srep = rep;
            string srep2 = compareto.rep;
            string sitem = item;
            string sitem2 = compareto.item;
            if (sdate == sdate2 && srep == srep2 && sitem == sitem2)
                return true;
            else
                return false;
        }

        int operator + (SALESREC addto) {
            return units + addto.units;
        }
        
        /*SALESREC (char newdate, char newregion, char newrep, char newitem, int newunits, float newunitcost) {
            int len = sizeof(new char[10]);
            char_traits<char>::copy(date, &newdate, len);
            char_traits<char>::copy(region, &newregion, len);
            char_traits<char>::copy(rep, &newrep, len);
            char_traits<char>::copy(item, &newitem, len);
            units = newunits;
            unitCost = newunitcost;
        };*/
};

int consolidateRecords(SALESREC* s[], int c);

void simpleSortTotal(SALESREC* s[], int c);

int main()
{
    ifstream infile;
    int array[20];
    char cNum[10] ;
    SALESREC* salesArr[40];
    int   salesArrayCount;
    SALESREC* s[40];

    infile.open ("SalesDataP5.csv");
    if (infile.is_open())
    {
        int   c=0;
        float inputUnitCost;
        while (infile.good())
        {
            salesArr[c] = new SALESREC();
            infile.getline(salesArr[c]->date, 256, ',');
            infile.getline(salesArr[c]->region, 256, ',');
            infile.getline(salesArr[c]->rep, 256, ',');
            infile.getline(salesArr[c]->item, 256, ',');
            infile.getline(cNum, 256, ',');
            salesArr[c]->units = atoi(cNum);
            infile.getline(cNum, 256, '\n');
            inputUnitCost = atof(cNum);
            salesArr[c]->setUnitCost(inputUnitCost);
            
            c++;
        }
        salesArrayCount = c-1;
        infile.close();
    }
    else
    {
        cout << "Error opening file";
    }

    for (int i=0; i < salesArrayCount; i++)
        s[i] = salesArr[i];

    cout << " Unsorted Sales Record Array\n" ;
    for (int i=0; i < salesArrayCount; i++)
        salesArr[i]->displayRec();

    salesArrayCount = consolidateRecords (s, salesArrayCount);
    simpleSortTotal (s, salesArrayCount);

    cout << " - - - - - - - - - - - -\n" ;
    cout << " Sorted Sales Record Array\n" ;

    for (int i=0; i < salesArrayCount; i++)
        s[i]->displayRec();

    for (int i=0; i < salesArrayCount; i++)
    free(salesArr[i]);

}


void simpleSortTotal(SALESREC* s[], int c)
{
    SALESREC * temp;
    for (int i=0; i < c; i++)
        for (int j=i; j < c; j++)
            if (s[i]->Total() > s[j]->Total())
            {
            temp = s[j];
            s[j] = s[i];
            s[i] = temp;
            }
}

int consolidateRecords (SALESREC* s[], int c) {
    for (int i=0; i < c-1; i++) {
        for (int j=i+1; j < c; j++) {
            if (*s[i] == *s[j])
            {
                //cout << endl << s[i]->date << "|" << s[i]->rep << "|" << s[i]->item << " = " << s[j]->date << "|" << s[j]->rep << "|" << s[j]->item << endl << endl;
                s[i]->units = *s[i]+*s[j];
                SALESREC* temp[40];
                for (int x=0; x < c; x++) {
                    if (x > j) {
                        temp[x-1] = s[x];
                        //cout << "   " << s[x]->date << "|" << s[x]->rep << "|" << s[x]->item  << " | " << s[x]->units << endl;
                    }
                    else if (x < j) {
                        temp[x] = s[x];
                        //cout << "   " << s[x]->date << "|" << s[x]->rep << "|" << s[x]->item  << " | " << s[x]->units << endl;
                    }
                    else {
                        //cout << "X  " << s[x]->date << "|" << s[x]->rep << "|" << s[x]->item  << " | " << s[x]->units << endl;
                    }
                }
                for (int x=0; x < c; x++) {
                    s[x] = temp[x];
                }
                c--;
            }
        }
    }
    return c;
}