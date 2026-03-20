#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

void Make_Num();
void Print_Num();
void Shuffle();

int nm[5] = {-1, -1, -1, -1, -1};

int main() {
    srand(time(NULL));
    Make_Num();
    Shuffle();
    Print_Num();
}

void Make_Num() {
    int i, tmp;
    int cn;
    int nm1;

    cn = 0;
    while(cn <= 4) {
        tmp = 0;
        nm1 = rand() % 10;
        for (i = 0; i < 5; i++) { // quiz5: 이거 for-loop문으로 변경
            if (nm[i] == nm1) {
                ++tmp;
            } 
        }
        if (tmp == 0) {
            nm[cn] = nm1;
            ++cn;
        }
    }
}

void Shuffle() {   
    cout << "패 섞으려면 스페이스바, 그냥 종료하려면 ESC 입력\n";
    char c;
    int idx1, idx2, i, tmp;
    
    while (true) {
        c = _getch();

        if (c == 27) {
            cout << "종료\n";
            return;
        } else if (c == 32) {
            cout << "패 섞기\n";
            for (i = 0; i < 30; i++) {
                idx1 = rand() % 5;
                idx2 = rand() % 5;

                if (idx1 != idx2) {
                    tmp = nm[idx1];
                    nm[idx1] = nm[idx2];
                    nm[idx2] = tmp;
                }
            }
        } 
        cout << "패섞기 결과: \n";
        Print_Num();
    }
}


void Print_Num() {
    int i;
    for (i = 0; i < 5; i++) { // quiz5: 이거 for-loop문으로 변경
        cout << nm[i] << endl;
    }
}