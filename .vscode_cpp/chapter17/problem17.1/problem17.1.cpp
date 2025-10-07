#include <iostream>
using namespace std;

int main()
{
    char ch;
    int count = 0;

    cout << "문자를 입력하시오($입력시 종료): ";
    while (cin.peek() != '$') // 입력받은값 미리 보기(입력스트림 안에 있는걸 보는게 아님)
    {
        cin.get(ch); // '$' 전까지만 입력스트림으로
        ++count;
    }
    cout << "입력받은 문자 총 개수: " << count << endl;
    cin.get(ch); // 입력받은 값 입력스트림에 넣기
    cout << "입력스트림에 남아있는 문자 : " << ch << endl;
    
    return 0;
}