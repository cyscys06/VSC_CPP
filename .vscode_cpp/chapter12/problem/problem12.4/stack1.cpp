#include "stack1.h"
#include <iostream>

Stack::Stack(int n) // 생성자
{
    size = n;
    pitems = new Item[size];
    top = 0;
}

Stack::Stack(const Stack & st) // 복사 생성자
{
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; ++i)
        pitems[i] = st.pitems[i];
}

Stack::~Stack()
{
    delete[] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)// 스택 항목 추가
{
    if (top < MAX)
    {
        pitems[top++] = item;
        return true;
    }
    else 
        return false;
}

bool Stack::pop(Item & item) // 스택 항목 제거
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false;
}

Stack & Stack::operator=(const Stack & st) // 대입 연산자 오버로딩
{
    if (this == &st)
        return *this;

    delete[] pitems; // 기존 메모리 해제

    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; ++i)
        pitems[i] = st.pitems[i];

    return *this;
}
