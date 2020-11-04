#include <iostream>
#include <string>
using namespace std;

void chReverse(char * chRef)
{
    for (int i = 0; i < 6; i++) {
        char chTemp = *(chRef + 10 - i);
        cout << chTemp << endl;
        *(chRef + 10 - i) = *(chRef + i);
        *(chRef + i) = chTemp;
    }
}

int main()
{
    string str = "Hello World";
    cout << "pointer size: " << sizeof (char*) << endl;
    chReverse(&str[0]);
    cout << "&str " << &str << " " << *(&str) << endl;
    return 0;
}