#include <iostream>
#include "golf.h"
using namespace std;
const int MAX_PLAYERS = 5;  // 최대 선수 수

int main()
{
    golf ann("Ann Birdfree", 24); // 인자 가진 객체
    golf andy; // 인자 없는 객체
    golf players[MAX_PLAYERS]; // 배열 인덱스별로 선수에 대한 정보 저장
    int count = 0; // 선수 수
    
    cout << "첫번째 선수 정보:\n"; // 객체 ann의 인자 출력
    ann.showgolf(); 
    cout << endl;
    
    cout << "두번째 선수 정보:\n"; // andy의 인자가 없으므로 디폴트값이 출력
    andy.showgolf();
    cout << endl;
    
    cout << "추가 선수 정보 입력:\n"; // 사용자가 선택적으로 입력
    cout << "최대 " << MAX_PLAYERS << "명의 선수 정보를 입력할 수 있습니다.\n";
    cout << "추가 선수 입력을 종료하려면 빈 라인(엔터)를 입력하십시오.\n\n";
    
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        cout << "선수 #" << i+1 << ":\n";
        if (players[i].setgolf() == false) // 빈 이름 입력되면
            break;  
        count++;
    }
    
    cout << "\n추가로 등록된 선수 목록 (" << count << "명):\n";
    for (int i = 0; i < count; i++) // 입력한 정보들을 선수별로 모두 출력
    {
        cout << "선수 #" << (i + 1) << ":\n";
        players[i].showgolf();
        cout << endl;
    }

    if (count > 0)
    {
        int handicap;
        
        cout << "추가로 입력한 첫번째 선수의 변경할 핸디캡 값을 입력하십시오.\n";
        cin >> handicap;
        cin.get();
        players[0].sethandicap(handicap);
        
        cout << "변경 후:\n";
        players[0].showgolf();
    }
    
    cout << "\n프로그램을 종료합니다.\n";
    return 0;
}