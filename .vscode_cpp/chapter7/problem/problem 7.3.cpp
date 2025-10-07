#include <iostream>
using namespace std;
const int SIZE = 40;

struct box // 구조체 선언
{
    char maker[SIZE];
    float height;
    float width;
    float length;
    float volume;
};
void a(box va);
double b(box * members); // members: box 구조체를 지시하는 포인터

int main()
{
    box value;
    cout << "정보를 입력하시오:\n";
    cout << "maker: ";
    cin.getline(value.maker, SIZE); // .전: main함수에서 구조체형으로 선언한 변수명
    cout << "height: ";   // .후: 선언한 변수를 저장할 구조체의 멤버명
    cin >> value.height;
    cout << "width: ";
    cin >> value.width;
    cout << "length: ";
    cin >> value.length;
    b(&value);
    a(value);
}

double b(box * members)
{
    members->volume = members->height * // members에서 구조체 box를 지시하고 있으므로
    members->width * members->length;   // 앞에 box를 붙일 필요가 없다
    return members->volume; // 구조체를 포인터로 지시할때는 '.'대신 '->'사용
}

void a(box members)
{
    cout << "\n입력한 정보:\n";
    cout << "maker: " << members.maker << endl;
    cout << "height: " << members.height << endl;
    cout << "width: " << members.width << endl;
    cout << "length: " << members.length << endl;
    cout << "volume: " << members.volume << endl;
}