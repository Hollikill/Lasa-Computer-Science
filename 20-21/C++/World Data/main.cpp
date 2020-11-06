 #include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

int * GetLinesLength(string file);
string * GetData(string file, int r, int c);
int ArrPos(int size, int r, int c);
void simpleSort(string &arrRef, int start, int end);
string * GetDataW(string file, int r, int c);

int main () {
	string file = "WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv";
	int * lenLines = GetLinesLength(file);
	string * data;
	data = GetData(file, lenLines[0], lenLines[1]);
	/* debug whole for (int i = 0; i < lenLines[1]; i++) {
		for (int x = 0; x < lenLines[0]; x++) {
			if (x < lenLines[0]-1) {
				cout << data[ArrPos(512,i,x)] << ",";
			}
			else {
				cout << data[ArrPos(512,i,x)] << "\n";
			}
		}
	}*/
	
	
	//world data part- the rest is csv reader United States of America
	int usOverall = 0;
	int tNum = 0;
	simpleSort(data[0], 17, lenLines[1]);
	for (int i = 18; i < lenLines[1]; i++) {
		//cout << data[ArrPos(512,i,16)] << "\n";
		tNum++;
		for (int x = 0; x < lenLines[0]; x++) {
			if (data[ArrPos(512,i,x)] == "\"United States of America\"") {
				usOverall = tNum;
			}
			if (x < lenLines[0]-1) {
				cout << data[ArrPos(512,i,x)] << ",";
			}
			else {
				cout << data[ArrPos(512,i,x)] << "\n";
			}
		}
	}
	usOverall = tNum - usOverall;
	cout << "\nUS overall rank: " << usOverall;
	data = GetDataW(file, lenLines[0], lenLines[1]);
	usOverall = 0;
	tNum = 0;
	simpleSort(data[0], 17, lenLines[1]);
	for (int i = 18; i < lenLines[1]; i++) {
		//cout << data[ArrPos(512,i,16)] << "\n";
		tNum++;
		for (int x = 0; x < lenLines[0]; x++) {
			if (data[ArrPos(512,i,x)] == "\"United States of America\"") {
				usOverall = tNum;
			}
		}
	}
	usOverall = tNum - usOverall;
	cout << "\nUS more developed regions rank: " << usOverall;
	return 0;
}

int * GetLinesLength(string file) {
	int r = 0;
	int c = 0;
	ifstream fileStream;
	fileStream.open (file, ifstream::in);
	if (fileStream.is_open()) {
		while (fileStream.good()) {
			if (c == 0) {
				char cArr[16*16];
				fileStream.getline(cArr, 4*16*16*16);
				string s;
				s = cArr;
				bool inS = false;
				for (int i = 0; i < s.length(); i++) {
					char loc = s[i];
					if (loc == '"') {
						inS = !inS;
					}
					else if (loc == ',' && !inS) {
						r++;
					}
				}
				c++;
			}
			else {
				char cArr[16*16];
				fileStream.getline(cArr, 4*16*16*16);
				c++;
			}
		}
	}
	fileStream.close();
	int * lenLines = new int[2];
	*lenLines = r;
	*(lenLines+1) = c;
	return lenLines;
}

string * GetData(string file, int r, int c) {
	ifstream fileStream;
	fileStream.open (file, ifstream::in);
	int tR = 0;
	int tC = 0;
	string * data = new string[(512*512)];
	while (fileStream.good()) {
		//cout << "\nrows:" << c << " cols:" << r << "\n";
		while (tC < c) {
			//cout << "\nrow " << tC-1 << " -> " << tC << "\n\n";
			char cArr[16*16];
			fileStream.getline(cArr, 4*16*16*16);
			string s = "";
			s = cArr;
			bool inS = false;
			string savedS = "";
			for (int i = 0; i < s.length(); i++) {
				char loc = s[i];
				if (loc == '"') {
					savedS += loc;
					inS = !inS;
				}
				else if (loc == ',' && !inS) {
					data[ArrPos(512,tC,tR)] = savedS;
					//cout << tR << " saved \"" << savedS << "\"" << "\n";
					tR++;
					savedS = "";
				}
				else {
					savedS += loc;
				}
			}
			tR = 0;
			tC++;
		}
	}
	fileStream.close();
	return data;
}

int ArrPos(int size, int r, int c) {
	return (c*size)+r;
}

//world data lab sort functions
void simpleSort(string &arrRef, int start, int end){
	string * arr = &arrRef;
	for (int i=start; i < end; i++) {
		//cout << "sorting " << i << "\n";
		for (int j=i; j < end; j++) {
			if (arr[ArrPos(512,i,16)] > arr[ArrPos(512,j,16)])
			{
				for (int r = 0; r < 18; r++) {
					string s = arr[ArrPos(512,i,r)];
					arr[ArrPos(512,i,r)] = arr[ArrPos(512,j,r)];
					arr[ArrPos(512,j,r)] = s;
				}
			}
		}
	}
}
string * GetDataW(string file, int r, int c) {
	ifstream fileStream;
	fileStream.open (file, ifstream::in);
	int tR = 0;
	int tC = 0;
	int tTC = 0;
	string * data = new string[(512*512)];
	while (fileStream.good()) {
		//cout << "\nrows:" << c << " cols:" << r << "\n";
		while (tC < c) {
			//cout << "\nrow " << tC-1 << " -> " << tC << "\n\n";
			char cArr[16*16];
			fileStream.getline(cArr, 4*16*16*16);
			string s = "";
			s = cArr;
			bool inS = false;
			string savedS = "";
			for (int i = 0; i < s.length(); i++) {
				char loc = s[i];
				if (loc == '"') {
					savedS += loc;
					inS = !inS;
				}
				else if (loc == ',' && !inS) {
					if ((tC < 18) || (tC>=150 && tC<=194) || tC == 241 || (tC>=237 && tC<=239) || tC == 98) {
						data[ArrPos(512,tTC,tR)] = savedS;	
					}
					//cout << tR << " saved \"" << savedS << "\"" << "\n";
					tR++;
					savedS = "";
				}
				else {
					savedS += loc;
				}
			}
			tR = 0;
			if ((tC < 18) || (tC>=150 && tC<=194) || tC == 241 || (tC>=237 && tC<=239) || tC == 98) {
				tTC++;
			}
			tC++;
		}
	}
	fileStream.close();
	return data;
}