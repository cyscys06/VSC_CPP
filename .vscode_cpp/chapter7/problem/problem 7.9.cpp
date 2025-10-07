#include <iostream>
using namespace std;

const int SLEN = 30;
struct student
{
    char fullname[SLEN]; // 이름
    char hobby[SLEN]; // 취미
    int ooplevel; // oop 레벨
};

int getinfo(student pa[], int n); // pa[]: student 구조체의 멤버 배열 n: 배열크기
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
    cout << "학급의 학생 수를 입력하십시오: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n') // 개행 만나면 루프 종료(cin.get이 한글자씩 인식)
    {
        continue;
    }
    student * ptr_stu = new student[class_size]; // 포인터 변수 ptr 및 new연산자를 통한 동적배열 선언(ptr_stu[class_size])
    int entered = getinfo(ptr_stu, class_size); // entered에 실제로 데이터가 입력된 학생 수가 할당됨
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]); // 어차피 반복은 이 for문에서 되므로 함수 안에서의 반복문 사용 여부는 생각 X
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    cout << "프로그램을 종료합니다.\n";
    delete[] ptr_stu; // 위에서 new 동적 배열을 선언했었다면 delete로 반드시 없애주기(안없애면 메모리 계속 남아있음)
    return 0;
}

int getinfo(student pa[], int n) // 학생들의 정보 입력
{
    cout << "학생들의 정보를 입력하시오.(학생이름에 빈칸입력시 종료)\n";
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "학생의 이름을 입력하시오: ";
        if (pa[i].fullname[0] == '\0')  // 널 문자(빈칸이후) 입력받으면 종료
        {                               // pa[i].fullname[0]: pa배열의 i번째 인덱스에 있는 멤버인                           
            cout << "입력을 종료합니다" // fullname 배열의 0번째 인덱스 = 학생 이름 입력할때 첫번째 원소(인덱스)
            break;                      // -> 별도 입력없이(빈줄로) 엔터 누르면 0번째 인덱스에 널 문자 저장되어(아무것도 없음) 조건식 충족 
        }
        cin.getline(pa[i].fullname, SLEN); // cin.getline(배열이름, 배열크기);
                                           // cin.getline에서 개행문자 읽고 바로 버리기때문에 따로 cin.get()쓸필요 X
        cout << "학생의 취미를 입력하시오: ";
        cin.getline(pa[i].hobby, SLEN); // SLEN: char형 배열 fullname과 hobby의 배열 크기
        cout << "학생의 oop 레벨을 입력하시오: ";
        cin >> pa[i].ooplevel;
        cin.ignore();
    }
    return i; // i: 실제로 데이터를 입력받은 학생들의 수(i가 곧 배열에 실제로 채워진 원소 수이다)
}

void display1(student st) // st: 구조체와 연결된 new형 동적배열 이름
{
    cout << st.fullname << endl; // ptr_stu[i].fullname과 같다
    cout << st.hobby << endl; // 단순히 구조체가 매개변수일때는 도트(.)사용
    cout << st.ooplevel << endl;
}

void display2(const student * ps) // ps: 구조체의 주소를 지시하는 포인터 이름
{
    cout << ps->fullname << endl;
    cout << ps->hobby << endl;
    cout << ps->ooplevel << endl;
}

void display3(const student pa[], int n) // pa[]: student 구조체의 멤버 배열 n: 배열크기
{
    for (int i = 0; i < n; i++)
    {
    cout << pa[i].fullname << endl;
    cout << pa[i].hobby << endl;
    cout << pa[i].ooplevel << endl;
    }
}