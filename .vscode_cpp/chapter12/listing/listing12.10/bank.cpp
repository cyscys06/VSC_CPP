#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60; // 시간당 분 수: 60분
using namespace std;
bool newcustomer(double x);

int main()
{
    std::srand(std::time(0)); // srand()의 무작위 초기화
    cout << "사례 연구: 히서 은행의 ATM\n";
    cout << "큐의 최대 길이를 입력하십시오: ";
    int qs; // ATM기에 줄설수 있는 최대 고객 수(이거보다 커지면 줄 못섬)
    cin >> qs;
    Queue line(qs);

    cout << "시뮬레이션 시간 수를 입력하십시오: ";
    int hours; // 시뮬레이션 시간 수
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours; // 시뮬레이션 주기 수

    cout << "시간당 평균 고객 수를 입력하십시오: ";
    double perhour; // 시간당 평균 고객 수
    cin >> perhour;
    double min_per_cust; // 평균 고객 도착 간격(분 단위)
    min_per_cust = MIN_PER_HR / perhour;

    Item temp; // 고객 데이터
    long turnaways = 0; // 발길 돌린 고객 수
    long customers = 0; // 줄선 고객 수
    long served = 0; // 거래 완료한 고객 수
    long sum_line = 0; // 줄선 길이
    int wait_time = 0; // 자기차례 될때까지 대기하는 시간 
    long line_wait = 0; // 고객들이 줄을 서서 대기한 누적 시간

    for (int cycle = 0; cycle < cyclelimit; cycle++) // 시뮬레이션 주기만큼 계속 반복
    {
        if (newcustomer(min_per_cust)) // 새 고객이 도착했으면
        {
            if (line.isfull()) // 줄 꽉찼으면
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle); // cycle은 도착 시간을 의미
                line.enqueue(temp); // 큐에 새 고객 추가
            }
        }
        if (wait_time <= 0 && !line.isempty()) // 기다린 시간이 0 이하고 줄에 누가 있으면
            {
                line.dequeue(temp); // 다음고객 받음
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
        if (wait_time > 0)
            wait_time --;
        sum_line += line.queuecount();
    } // for문
    // 결과출력
    if (customers > 0) // 고객 있으면
    {
        cout << " 큐에 줄을 선 고객 수: " << customers << endl;
        cout << " 거리를 처리한 고객 수: " << served << endl;
        cout << " 발길을 돌린 고객 수: " << turnaways << endl;
        cout << "       평균 큐의 길이: ";
        cout.precision(2); // 소수점 아래 두자리까지만 출력
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double) sum_line / cyclelimit << endl;
        cout << "       평균 대기 시간: " << (double) line_wait / served << "분\n";
    }
    else 
        cout << "고객이 없습니다.\n";
    cout << "완료\n";

    return 0;
}

// x: 고객의 평균 시간 간격(분 단위)
// 시간 내 고객 도착 시 리턴값 true
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1); // rand(): 0 ~ 32767 사이 값 반환환
}