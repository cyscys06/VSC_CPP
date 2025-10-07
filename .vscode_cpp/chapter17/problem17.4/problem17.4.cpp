#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string str1, str2;
    ifstream fin1("input1.txt");
    ifstream fin2("input2.txt");
    ofstream fout("output.txt");

    if (fin1.fail() || fin2.fail() || fout.fail())
    {
        cout << "파일 연결에 실패했습니다.";
        return 0;
    }

    while (true)
    {
        bool f1 = static_cast<bool>(getline(fin1, str1)); // 표현식의 반환형을 bool형으로 변경한 bool형 변수. 이를 돕는 static_cast
        bool f2 = static_cast<bool>(getline(fin2, str2));

        if (!f1 && !f2)
        {
            break;
        }    
        if (f1)
        {
            fout << str1 << " ";
        }
        if (f2)
        {
            fout << str2 << endl;
        }
    }

    // while (getline(fin1, str1) || getline(fin2, str2))
    // {
    //     if (fin1) fout << str1 << " ";
    //     if (fin2) fout << str2 << endl;
    // }

    fin1.close();
    fin2.close();
    fout.close();
    return 0;
}
