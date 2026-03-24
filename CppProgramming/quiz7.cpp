#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {
    char str1[20];
    string str2, str3;
    bool flag = true;
    int length;

    cin >> str2 >> str3;
    
    if (str2.compare(str3) != 0) {
        strcpy(str1, str2);
    }
}