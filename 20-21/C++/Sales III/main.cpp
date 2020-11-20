#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

class SALESREC {
	public:
		char     date[11];
		char     region[11];
		char     rep[11];
		char     item[11];
		int      units;
		float    unitCost;
		float    Total;
		float GetTotal() {
			return units * unitCost;
		}
		SALESREC () {
			units = 0;
			unitCost = 0;
		}
		void copySR (SALESREC tocopy) {
			int len = sizeof(date);
			char_traits<char>::copy(date,tocopy.date,len);
			char_traits<char>::copy(region,tocopy.region,len);
			char_traits<char>::copy(rep,tocopy.rep,len);
			char_traits<char>::copy(item,tocopy.item,len);
			units = tocopy.units;
			unitCost = tocopy.unitCost;
		}
};

void simpleSortTotal( SALESREC arr[], int c);

int main()
{
	ifstream infile;
	char cNum[11] ;
	SALESREC* salesArr = new SALESREC [40];
	int   salesArrayCount = 0;

	infile.open ("SalesDataDyn.csv", ifstream::in);
	if (infile.is_open())
	{
		int   c=0;
		while (infile.good())
		{
			infile.getline(cNum, 256, ',');
			string test = cNum;
			char_traits<char>::copy(salesArr[c].date,cNum,sizeof(cNum));
			//infile.getline(salesArr[c].date, 256, ',');
			infile.getline(salesArr[c].region, 256, ',');
			infile.getline(salesArr[c].rep, 256, ',');
			infile.getline(salesArr[c].item, 256, ',');
			infile.getline(cNum, 256, ',');
			salesArr[c].units = atoi(cNum);
			infile.getline(cNum, 256, '\n');
			salesArr[c].unitCost = atof(cNum);

			c++;
		}
		salesArrayCount = c-1;
		infile.close();
	}
	else
	{
		cout << "Error opening file";
	}
	
	simpleSortTotal (salesArr, salesArrayCount);
	  
	for (int i=0; i < salesArrayCount; i++) {
		string test = salesArr[i].date;
		cout << "Record: " << test <<", " << salesArr[i].region << ", " << salesArr[i].rep << ", " << salesArr[i].item << ", " << salesArr[i].units << ", " << salesArr[i].unitCost << ", " << salesArr[i].GetTotal() << endl;
	}
  free(salesArr);
}

void simpleSortTotal( SALESREC arr[], int c)
{
	SALESREC * x = new SALESREC;
	for (int i=0; i < c; i++) {
		for (int j=i; j < c; j++) {
			//cout << "\nI" << i << " " << &arr[i] << "\nJ"<< j << " " << &arr[j] << "\n";
			if (arr[i].GetTotal() > arr[j].GetTotal())
			{
				x->copySR(arr[i]);
				arr[i].copySR(arr[j]);
				arr[j].copySR(*x);
			}
		}
	}
}
