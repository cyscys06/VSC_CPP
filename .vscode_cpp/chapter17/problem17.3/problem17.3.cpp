#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;
    
    ifstream fin("simulation2.txt");
    ofstream fout("simulation3.txt");
    if (fin.fail() || fout.fail())
    {
        cout << "파일 연결에 실패했습니다.";
        return 0;
    }

    while (fin.get(ch))
    {
        fout << ch;
        if (fin.eof())
        {
            cout << "파일의 끝에 도달했습니다.\n";
            break;
        }
    }
    fin.close();
    fout.close();
    return 0;
}