#include <iostream>
using namespace std;
int main()
{
    double degree, minute, second;
    cout << "위도를 도, 분, 초 단위로 입력하시오:" << endl;
    cout << "먼저, 도각을 입력하시오:__\b\b";
    cin >> degree;
    cout << "다음에, 분각을 입력하시오:__\b\b";
    cin >> minute;
    cout << "끝으로, 초각을  입력하시오:__\b\b";
    cin >> second;

    const double weedo1 = degree;
    const double weedo2 = minute / 60;
    const double weedo3 = second / 3600;
    const double weedo = weedo1 + weedo2 + weedo3;
    cout << degree << "도, " << minute << "분, " << second << "초 = " << weedo << "도" << endl; 
    return 0;
}