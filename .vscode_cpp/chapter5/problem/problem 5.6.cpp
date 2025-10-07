#include <iostream>
#include <string>
int main()
{
    using namespace std;

    const int months = 12, years = 3;
    string TOTAL[years][months] = 
    {
        {"2025-jan","2025-feb","2025-mar","2025-apr","2025-may","2025-jun",
        "2025-jul","2025-aug","2025-sep","2025-oct","2025-nov","2025-dec",}, // TOTAL[0]
        {"2026-jan","2026-feb","2026-mar","2026-apr","2026-may","2026-jun",
        "2026-jul","2026-aug","2026-sep","2026-oct","2026-nov","2026-dec",}, // TOTAL[1]
        {"2027-jan","2027-feb","2027-mar","2027-apr","2027-may","2027-jun",
        "2027-jul","2027-aug","2027-sep","2027-oct","2027-nov","2027-dec",}  // TOTAL[2]
    };

    int num;
    int Y[years] = {0}; // 입력받은 연,월별 책 판매량을 연도별로 나눠 서로 다른 인덱스에 저장
    for(int y = 0; y < years; y++)
    {
       for(int m = 0; m < months; m++)
       {
            cout <<2024+y <<TOTAL[y][m] << "의 책 판매량을 입력하시오: ";
            cin >> num;
            Y[y] += num;
       }
       cout << 2024+y<<"년 총 판매량: " << Y[0] << "권" << endl;
    
    }
    
    cout << "2026년 총 판매량: " << Y[1] << "권" << endl;
    cout << "2027년 총 판매량: " << Y[2] << "권" << endl;

    cout << "2년째의 누적 판매량: " << Y[0] + Y[1]<< "권" << endl;
    cout << "3년째의 누적 판매량: " << Y[0] + Y[1] + Y[2] << "권" << endl;
    return 0;
}