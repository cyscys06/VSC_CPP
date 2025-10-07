#include <iostream>
#include <cctype>
#include "stack1.h"
using namespace std;

int main()
{
    Stack st1;
    char ch;
    Item po;

    cout << "주문서를 추가하려면 A, 주문서를 처리하려면 B,\n" << 
            "주문서를 복사하려면 C, 주문서를 복사하려면 D\n," <<
            "종료하려면 Q를 입력하십시오.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch (ch)
        {
            case 'A':
            case 'a': 
            {
                cout << "추가할 주문서의 번호를 입력하십시오: ";
                cin >> po;
                if (st1.isfull())
                {
                    cout << "스택이 가득 차 있습니다.\n";
                }    
                else  
                {
                    st1.push(po);
                    cout << "주문서를 추가했습니다.\n";
                }    
                break;
            }
            case 'B':
            case 'b': 
            {   
                if (st1.isempty())
                {
                    cout << "스택이 비어 있습니다.\n";
                }
                else
                {
                    st1.pop(po);
                    cout << "#" << po << " 주문서를 처리하였습니다.\n";
                }
                break;
            }
            case 'C':
            case 'c': 
            {
                if (st1.isempty())
                {
                    cout << "주문서가 비어 있습니다.\n";
                }
                else
                {      
                    Stack st2 = st1;
                    st2.pop(po);
                    cout << "#" << po << " 주문서를 복사하였습니다.\n";
                }
                break;
            }
            case 'D':
            case 'd':
            {
                Stack st3;
                st3 = st1;
                cout << "주문서를 대입하였습니다. 대입된 주문서를 추가합니다.\n";
                if (st3.isempty())
                {
                    cout << "주문서가 비어 있습니다\n";
                }
                else
                {
                    st3.pop(po);
                    cout << "대입된 주문서를 추가하였습니다.\n";
                }
            }   
        }        
        cout << "주문서를 추가하려면 A, 주문서를 처리하려면 B,\n" << 
                "주문서를 복사하려면 C, 주문서를 복사하려면 D\n," <<
                "종료하려면 Q를 입력하십시오.\n";
    }
    cout << "프로그램을 종료합니다.\n";
    return 0;
}