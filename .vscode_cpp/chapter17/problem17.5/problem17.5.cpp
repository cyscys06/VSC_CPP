#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>
using namespace std;

void input(set<string> & s, ifstream & ob); // 파일에서 추출, 세트에 저장

int main()
{
    ifstream fin1("mat.dat");
    ifstream fin2("pat.dat");
    ofstream fout("matnpat.dat");

    if (fin1.fail() || fin2.fail() || fout.fail())
    {
        cout << "파일 연결에 실패했습니다." << endl;
        return 0;
    }

    set<string> Mat, Pat;
    ostream_iterator<string> Cout(cout, " "); // 모니터 출력용
    ostream_iterator<string> Fout(fout, "\n"); // 파일 출력용
    // 출력할 값을 string으로 지정함

    input(Mat, fin1);
    input(Pat, fin2);

    cout << "Mat의 친구목록\n";
    copy(Mat.begin(), Mat.end(), Cout);
    cout << endl;

    cout << "Pat의 친구목록\n";
    copy(Pat.begin(), Pat.end(), Cout);
    cout << endl;

    set<string> MatPat;
    set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), insert_iterator(MatPat, MatPat.begin())); // 합집합

    copy(MatPat.begin(), MatPat.end(), Fout); 
    return 0;
}

void input(set<string> & s, ifstream & ob)
{
    string temp;
    while (getline(ob, temp))
    {
        if (temp == "q") 
        {
            break;
        }
        s.insert(temp);
    }
}
