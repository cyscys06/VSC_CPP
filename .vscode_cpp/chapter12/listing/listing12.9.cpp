#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;

class JustTesting
{
private:
    string words;
    int number;
public:
    JustTesting(const string & s = "Just Testing", int n = 0);
    ~JustTesting();
    void Show() const;
};

int main()
{
    char * buffer = new char[BUF]; // buffer를 미리 힙 영역에 할당해놓고
    JustTesting *pc1, *pc2;

    pc1 = new (buffer) JustTesting; // pc1을 buffer 메모리에 할당함
    pc2 = new JustTesting("Heap1", 20); // new로 아예 새로운 힙 영역에 새로 할당함

    cout << "메모리 블록 주소:\n" << "buffer: " << (void *) buffer << "    heap: " << pc2 << endl;
    cout << "메모리 내용:\n";
    cout << pc1 << ": ";
    pc1->Show(); // 포인터로 메서드, 멤버 등에 접근하려면 -> 사용(포인터만 해당)
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;
    pc3 = new (buffer + sizeof (JustTesting)) JustTesting("Bad Idea", 6);
    pc4 = new JustTesting("Heap2", 20);
    
    cout << "메모리 내용:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2; 
    delete pc4; 
    
    // 위치지정 new들의 명시적 파괴
    pc3->~JustTesting();
    pc1->~JustTesting();
    delete [] buffer;
    cout << "종료\n";
    return 0; 
}

JustTesting::JustTesting(const string & s, int n)
{
    words = s;
    number = n;
    cout << words << " 생성\n";
}

JustTesting::~JustTesting()
{
    cout << words << " 파괴\n";
}

void JustTesting::Show() const
{
    cout << words << ", " << number << endl;
}
