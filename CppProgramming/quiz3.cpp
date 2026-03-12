#include <iostream>
using namespace std;

int main() {
    // 가위바위보 게임
    // 0: 가위 1: 바위 2: 보
    // 내가 낼 패: 외부입력
    // 컴퓨터: srand((time(NULL));
    srand(time(NULL)); // 무작위 시드 생성

    int me, com;
    cin >> me;

    if (me == 0) { // 가위
        if (com == 0) {
            cout << "비김";
        } else if (com == 1) {
            cout << "컴퓨터가 이김";
        } else {
            cout << "사람이 이김";
        }
    } else if (me == 1) { // 바위
        if (com == 0) {
            cout << "사람이 이김";
        } else if (com == 1) {
            cout << "비김";
        } else {
            cout << "컴퓨터가 이김";
        }
    } else {
        if (com == 0) {
            cout << "컴퓨터가 이김";
        } else if (com == 1) {
            cout << "사람이 이김";
        } else {
            cout << "비김";
        }
    }

    return 0;
}