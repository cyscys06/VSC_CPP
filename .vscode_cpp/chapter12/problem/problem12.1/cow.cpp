#include <iostream>
#include <cstring>
#include "cow.h"
using std::cout;

Cow::Cow()
{
    name[0] = '\0';
    hobby = NULL;
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    strncpy(name, nm, 19); // 19글자까지만 받겠다는뜻(20번째는 널문자)
    name[19] = '\0';
    hobby = new char [strlen(ho) + 1]; // 동적메모리 할당(크기는 매개변수 크기 + 1(널문자 포함)만큼 할당)
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c) // 객체를 매개변수로 받음
{
    strncpy(name, c.name, 19); // 매개변수로 받은 객체의 name멤버를 복사
    name[19] = '\0';
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    cout << "객체 파괴\n";
    delete[] hobby;
}

Cow & Cow::operator=(const Cow & c) 
{
    if (this == &c)
        return *this;

    strncpy(name, c.name, 19);
    name[19] = '\0';

    delete[] hobby;
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);

    weight = c.weight;
    return * this;
}

void Cow::ShowCow() const 
{
    cout << "이름: " << name << "\n";
    cout << "취미: " << hobby << "\n";
    cout << "몸무게: " << weight << "kg\n";
}