#include<iostream>
#include<stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;

void Pro_Manage();
void Left();
void Right();
void Num_Print();

int num[5] = { 1,2,0,3,4 }; // 숫자 배치
int rx;

int main() {
    system("cls");
	Num_Print();
	Pro_Manage();
    
    return 0;
}

void Pro_Manage() {
	char ch = 0;
	rx = 2;	// 가운데에서 시작

    while (true) {
        ch = _getch();	// 좌우키 입력

        if (ch == 27) {
            cout << "프로그램 종료\n";
            return;
        }
        
        if (ch == 0x00 || ch == 0xE0) { // 특수키 신호 있는지 먼저 확인
            ch = _getch();  // 특수키 신호면 다음으로 오는 입력한 키 값 처리
        } else {
            ch = _getch();
        } 
        
        if (ch == 75) {     // 좌키	
            if (rx == 0) {
                cout << "더 이상 왼쪽으로 움직일 수 없습니다.\n";
                return;
            }
            system("cls");
            Left();
            rx -= 1;
        }
        if (ch == 77) {     // 우키
            if (rx == 4) {
                cout << "더 이상 오른쪽으로 움직일 수 없습니다.\n";  
                return;
            }
            system("cls");
            Right();
            rx += 1;
        }
        Num_Print();
    }
}

void Left() { // 좌
	int tmp;
	
	tmp = num[rx - 1];  // num[rx - 1]값과 num[rx] 값을 스왑
	num[rx - 1] = num[rx];
	num[rx] = tmp;
}

void Right() { // 우
	int tmp;

	tmp = num[rx + 1]; // num[rx]값과 num[rx + 1] 값을 스왑
	num[rx + 1] = num[rx];
	num[rx] = tmp;		
}

void Num_Print() {
	for (int a = 0; a < 5; a++) {  // 전체 출력
		if (num[a] >= 3) { // 3 이상은 동그라미
			cout << "○";
		} else if (num[a] == 0) {  // 0은 속 채워진 별
			cout << "★";
		} else {
			cout << "☆"; // 1, 2는 빈 별
		}
	}
	cout << endl;
}
