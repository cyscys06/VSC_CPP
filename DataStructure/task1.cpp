// 코드 약간 수정함
#include <iostream>
#include <conio.h>
using namespace std;

// 1단부터 9단까지의 구구단 결과 출력
void sample99v0() { 
    cout << "간단 구구단 " << endl;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
    }
}

// 매개변수로 넣은 값들에 대한 구구단 결과 출력
void sample99v3(int is, int ie, int js, int je) {
    cout << "\n 간단 구구단 \n";
    for (int i = is; i <= ie; i++) {
        for (int j = js; j <= je; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
    }
}

// 매개변수로 넣은 값들에 대한 구구단 결과와, 계산 결과의 총합 반환
int sample99v4(int is, int ie, int js, int je) {
    cout << "\n <구구단: 시작단, 끝단, 시작값, 끝값 입력, 총 합계 반환> \n";
    int sum = 0;

    for (int i = is; i <= ie; i++) {
        for (int j = js; j <= je; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
            sum += i * j;
        }
    }

    return sum;
}

// sample99v4 함수에서 계산 결과의 총합을 저장하는 변수를 정적 변수로 선언한 버전
int sample99v5static(int is, int ie, int js, int je) {
    cout << "\n <구구단: 반환, static 합계누적> \n";

    static int sum = 0;

    for (int i = is; i <= ie; i++) {
        for (int j = js; j <= je; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
            sum += i * j;
        }
    }

    return sum;
}

// 사용자로부터 끝단, 시작단, 시작값, 끝값을 입력받음
void sample99v7cin(int* is, int* ie, int* js, int* je) {
    cout << "구구단의 시작 단을 입력: ";
    cin >> *is;
    cout << "구구단의 끝 단을 입력: ";
    cin >> *ie;
    cout << "구구단의 시작 값을 입력: ";
    cin >> *js;
    cout << "구구단의 끝 값을 입력: ";
    cin >> *je;

    cout << "입력한 값: " 
         << *is << ", "
         << *ie << ", "
         << *js << ", "
         << *je << "\n";
}

// sample99v7cin 함수에서 입력받은 값들을 사용하여 구구단 계산 결과의 총합을 반환
int sample99v7action() {
    cout << "\n <구구단: 함수로 입력과 계산> \n";
    int is, ie, js, je;

    sample99v7cin(&is, &ie, &js, &je);

    return sample99v4(is, ie, js, je);
}

int main() {
    const char* menu = R"(
    ----------------------------------
    1. 구구단
    2. 구구단: 함수 호출 3, 12, -1, 5
    3. 구구단: 함수 반환 - 합계
    4. 구구단: static 변수
    5. 구구단: 직접 입력 받기
    0. 종료
    ----------------------------------
    선택: )"; 

    char choose;
    int sum99 = -1;

    do {
        cout << menu;
        choose = _getch();

        switch (choose) {
            case '1':
                sample99v0();
                break;
            case '2':
                sample99v3(3, 12, -1, 5);
                break;
            case '3':
                sum99 = sample99v4(3, 12, -1, 5);
                cout << "sum99 = " << sum99 << endl;
                break;
            case '4':
                sum99 = sample99v5static(3, 12, -1, 5);
                cout << "sum99 = " << sum99 << endl;
                break;
            case '5':
                sum99 = sample99v7action();
                cout << "sum99 = " << sum99 << endl;
                break;
        }

        // cmd가 아닌 터미널에서는 오류 발생하므로, cmd에서만 실행할 것
        system("pause");
        system("cls");
    } while (choose != '0');

    cout << "\n == 프로그램 종료 == \n";

    return 0;
}