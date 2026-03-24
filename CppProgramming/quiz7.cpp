#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {
    char str1[20];
    string str2, str3;

    cin >> str2 >> str3;
    
    if (str2 != str3) {
        strcpy(str1, str2.c_str()); // c_str(): c++의 string 객체를 c 스타일의 char* 형으로 변환
        cout << str1;
        return 0;
    } else {
        cout << str2 + str3;
        return 0;
    }
}