#include <iostream>
#include <time.h>
using namespace std;

void swap(int& a, int& b);

int main() {
    srand(time(NULL));
    int a = rand() % 100, b = rand() % 100; // 100 미만 난수

    swap(a, b);
    for (int i = a; i <= b; i++) {
        cout << i << endl;
    }

    return 0;
}

void swap(int& a, int& b) {
    int temp;
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    } 
}