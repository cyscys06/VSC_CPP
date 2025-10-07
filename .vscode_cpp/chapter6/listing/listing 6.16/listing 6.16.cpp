#include <iostream>
#include <fstream> // 파일 입출력을 위한 클래스 
#include <cstdlib> // exit()함수를 위한 헤더파일
int main()
{
    using namespace std;

    const int size = 60;
    char filename[size];
    double value, sum = 0.0;
    int count = 0;
    
    ifstream inFile;
    cout << "데이터 파일의 이름을 입력하시오: ";
    cin.getline(filename, 60);
    inFile.open(filename); // inFile 객체를 파일에 연결
    if (!inFile.is_open()) // 파일 안열리면 true, 열리면 false
    {
        cout << filename << " 파일을 열 수 없습니다." << endl;
        cout << "프로그램을 종료합니다.\n";
        exit(EXIT_FAILURE); // exit(): 프로그램 종료 함수
    }
    inFile >> value;
    while (inFile.good()) // 입력이 양호하고 EOF(파일의 끝)가 아닌동안
    {
        ++count;
        sum += value;
        inFile >> value;
    }
    if (inFile.eof()) // EOF이면
    {
        cout << "파일 끝에 도달했습니다.\n";
    }
    else if (inFile.fail()) // 파일 입력에 실패하면
    {
        cout << "데이터 불일치로 입력이 종료되었습니다.\n";
    }
    else
    {
        cout << "알 수 없는 이유로 입력이 중료되었습니다.\n";
    }
    if (count == 0)
    {
        cout << "데이터가 없습니다.\n";
    }
    else
    {
        cout << "읽은 항목의 개수: " << count << endl;
        cout << "합계: " << sum << endl;
        cout << "평균: " << sum / count << endl;
    }
    inFile.close(); // 파일 처리 종료
    return 0;
}