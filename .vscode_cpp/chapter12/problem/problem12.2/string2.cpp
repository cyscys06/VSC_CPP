#include <cstring>
#include "string2.h"
using namespace std;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char * s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

char & String::operator[](int i) // const 아닌 String 개별문자 접근
{
    return str[i]; 
}

const char & String::operator[](int i) const // const인 String 개별문자 접근
{
    return str[i];
}

bool operator<(const String & st1, const String & st2)
{
    return (strcmp(st1.str, st2.str) < 0); // st1이 st2보다 작으면 음수 반환, 0보다 작으면 true반환
}

bool operator>(const String & st1, const String & st2)
{
    return st2 < st1; 
}

bool operator==(const String & st1, const String & st2)
{
    return (strcmp(st1.str, st2.str) == 0); 
}

ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;  
    while (is && is.get() != '\n')  
        continue;
    return is;
}

String String::operator+(const String & st) const 
{
    char * temp = new char[len + st.len + 1]; 
    strcpy(temp, str);        
    strcat(temp, st.str);
    String result(temp);
    delete [] temp;
    return result;
}

String operator+(const char * s1, const String & s2) 
{
    String temp(s1);
    return temp + s2;
}
    
void String::stringlow() 
{
    for (int i = 0; i < len; i++) 
    {
        str[i] = tolower(str[i]);
    }
}

void String::stringup() 
{
    for (int i = 0; i < len; i++) 
    {
        str[i] = toupper(str[i]);
    }
}

    
int String::has(char s)
{
    int num_char = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == s)
            ++num_char;
    }    
    return num_char;
}