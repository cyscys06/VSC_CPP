#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
#include <cctype>
using namespace std;

class String
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String(const char * s);
    String();
    String(const String & st);
    ~String();
    int length() const { return len; }
    
    // 연산자 오버로딩
    String & operator=(const String & st);
    String & operator=(const char * s);
    char & operator[](int i);
    const char & operator[](int i) const;
    String operator+(const String & st) const; // a 
    void stringlow(); // b
    void stringup(); // c
    int has(char s); // d
    // 프렌드함수
    friend String operator+(const char * s1, const String & s2); // a
    friend bool operator<(const String & st1, const String & st2);
    friend bool operator>(const String & st1, const String & st2);
    friend bool operator==(const String & st1, const String & st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
    // static함수
    static int HowMany();
};
#endif