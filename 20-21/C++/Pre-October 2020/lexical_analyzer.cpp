#include <iostream>
#include <string>
using namespace  std;

// returns count of non-overlapping occurrences of 'sub' in 'str'
int countSubstring(const string& str, const string& sub)
{
	if (sub.length() == 0) return 0;
	int count = 0;
	for (int offset = str.find(sub); offset != string::npos; 
		offset = str.find(sub, offset + sub.length()))
	{
		++count;
	}
	return count;
}

int countWord(const string& source) {
	int atEnd = 0;
	int inWord = 0;
	int count = 0;
	for (int x = 0; x < source.length(); x++) {
		if (source[x] == ' ' || source[x] == '1' || source[x] == '2' || source[x] == '3' || source[x] == '4' || source[x] == '5' || source[x] == '6' || source[x] == '7' || source[x] == '8' || source[x] == '9' || source[x] == '0' || source[x] == '.' || source[x] == '!' || source[x] == '?') {
			if (inWord == 1) {
				inWord = 0;
				count++;
			}
		}
		else {
			if (inWord == 0) {
				inWord = 1;
			}
		}
	}
	if (inWord == 1) {
		inWord = 0;
		count++;
	}
	return count;
}

int countWordU (const string& source) {
	string foundWords = " ";
	string thisWord = "";
	int atEnd = 0;
	int inWord = 0;
	int count = 0;
	for (int x = 0; x < source.length(); x++) {
		if (source[x] == ' ' || source[x] == '1' || source[x] == '2' || source[x] == '3' || source[x] == '4' || source[x] == '5' || source[x] == '6' || source[x] == '7' || source[x] == '8' || source[x] == '9' || source[x] == '0' || source[x] == '.' || source[x] == '!' || source[x] == '?') {
			if (inWord == 1) {
				inWord = 0;
				if (foundWords.find(thisWord,0) == string::npos) {
					count++;
					foundWords += thisWord+" ";
					//cout << thisWord;
				}
				//cout << " " + thisWord << endl;
				thisWord = "";
			}
		}
		else {
			if (inWord == 0) {
				inWord = 1;
			}
			thisWord += source[x];
		}
	}
	if (inWord == 1) {
		inWord = 0;
		count++;
		foundWords += " ";
	}
	return count;
}

int sentances (const string& source) {
	int count = 0;
	for (int x = 1; x < source.length(); x++) {
		if ((source[x] == '.' || source[x] == '?' || source[x] == '!') && (source[x-1] != '.' && source[x-1] != '?' && source[x-1] != '!')) {
			count++;
		}
	}
	return count;
}

int main()
{
  string source = ("I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo.  I got the ramblin fever.  Said goodbye to ma and pa.   Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky.  I saw miles and miles of Texas gonna live here till I die.");
	cout << "Occurrences of \"is\": " << countSubstring(source, "is") << endl;
	cout << "Word/Unique word count: " << countWord(source) << "/" << countWordU(source) << " words" << endl;
	cout << "Number of sentances: " << sentances(source) << " words" << endl;
	cout << "Average words per sentance: " << countWord(source) / sentances(source) << " words" << endl;
	cout << "Lexical density (40-50\% low, 60-70\% high): " << (countWordU(source)*100)/countWord(source) << "\%" << endl;
	
	return 0;
}