#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;
    
    ofstream fout("simulation1.txt"); // 객체와 파일 연결하기
    if (fout.fail())
    {
        cout << "파일 연결에 실패했습니다.";
        return 0;
    }

    cout << "파일에 복사할 내용 입력(q 입력시 종료): ";
    while (ch != 'q')
    {
        cin.get(ch);
        fout << ch;
        if (cin.eof())
        {
            cout << "파일의 끝에 도달했습니다.\n";
            break;
        }
    }
    fout.close();
    return 0;
}