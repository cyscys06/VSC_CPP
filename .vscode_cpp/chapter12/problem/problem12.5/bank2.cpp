#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
using namespace std;

const int MIN_PER_HR = 60; 

bool newcustomer(double x);

int main()
{
    std::srand(std::time(0)); 
    cout << "사례 연구: 히서 은행의 ATM\n";
    cout << "큐의 최대 길이를 입력하십시오: ";
    
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "시뮬레이션 시간 수를 입력하십시오: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "목표 평균 대기 시간을 입력하십시오: ";
    double target_wait;
    cin >> target_wait;

    double perhour = 1.0; // 시간당 평균 고객 수: 평균 대기 시간 = 60분 / 평균 고객 수
    double avg_wait = 0.0; // 디폴트트

    while (true)
    {
        Queue line(qs);
        double min_per_cust = MIN_PER_HR / perhour;

        Item temp;
        long turnaways = 0;
        long customers = 0;
        long served = 0;
        long sum_line = 0;
        int wait_time = 0;
        long line_wait = 0;

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);
                    line.enqueue(temp);
                }
            }
            if (wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;

            sum_line += line.queuecount();
        }

        if (served > 0)
            avg_wait = (double)line_wait / served;
        else
            avg_wait = 100.0;

        if (avg_wait > target_wait)
            break;

        perhour += 1.0;
    }

    cout << "목표 평균 대기 시간 " << target_wait << "분을 만족하는\n";
    cout << "시간당 평균 고객 수는 대략 " << (perhour) << "명입니다.\n";
    cout << "완료\n";

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
