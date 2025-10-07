#include <iostream>


int main() {
    using namespace std;
    
    int rows;
    cout << "출력할 행 수를 입력하십시오: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++) // i = 0에서 시작하면 첫째 행이 전부 마핌표로 출력됨 
    {
        for (int j = 1; j <= rows - i; j++) 
            cout << "."; // 마침표를 출력하는 for문
        for (int k = 1; k <= i; k++) 
            cout << "*";  // 별표를 출력하는 for문
        cout << endl;
    }
    return 0;
}
