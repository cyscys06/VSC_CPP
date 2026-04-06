#include<iostream>
#include<stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

void Pro_Manage();
void Input_Num();
template<typename T>
T Add(T a);

using namespace std;

int main()
{
	Pro_Manage();

	return 0;
}

void Pro_Manage()
{
	Input_Num();
}

void Input_Num()  // 첫 번째 값 입력
{
	double num1;
	double rst;
	int nm;

	cout << "Input First Number" << endl;
	cin >> num1;

	nm = int(num1);  // 첫 번째 수의 실수, 정수 판별
	rst = num1 - nm; // 소수점 이하 판단
	
	if (rst > 0) {
		num1 = Add(num1);  // 실수 합
        cout << num1 << endl;
	}
	else {
		nm = Add(nm); // 정수 합
        cout << nm << endl;
	}
}

template<typename T>
T Add(T a) 
{
	T nm1, tot = a;
	char ch;	

	ch = 0;

	while (ch != '=') {  // = 판별
		cin >> ch;
		if (ch != '=') cin >> nm1;  // 연속 입력 판별
		if (ch == '+') {
			tot = tot + nm1;
		}
	}
	return tot;
}
