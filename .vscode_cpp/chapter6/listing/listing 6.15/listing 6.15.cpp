#include <iostream>
#include <fstream> 
// file의 in&out을 위해 헤더파일 불러옴

int main()
{
    using namespace std;
    char automobile[50];
    int year;
    double a_price, d_price; 

    ofstream outFile; // 출력을 위해 객체 outFile생성(outFile을 cout처럼 사용가능)
    outFile.open("carinfo.txt"); // "carinfo.txt" 파일에 연결

    cout << "자동차 메이커와 차종을 입력하시오: ";
    cin.getline(automobile, 50);
    cout << "연식을 입력하시오: ";
    cin >> year;
    cout << "구입 가격을 입력하시오: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios::showpoint); // setf: 서식 플래그를 생성
                               // showpoint: 단항 서식 플래그의 종류 중 하나
    outFile << "메이커와 차종: " << automobile << endl;
    outFile << "연식: " << year << endl;
    outFile << "구입 가격: " << a_price << endl;
    outFile << "현재 가격: " << d_price << endl;

    outFile.close(); // 파일 처리 종료
    return 0;
}