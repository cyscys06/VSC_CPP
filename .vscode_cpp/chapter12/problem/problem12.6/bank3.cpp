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
    cout << "사례 연구: 히서 은행의 ATM(2대)\n";
    cout << "큐의 최대 길이를 입력하십시오: ";
    
    int qs;
    cin >> qs;
    Queue line1(qs); // 첫 번째 큐
    Queue line2(qs); // 두 번째 큐

    cout << "시뮬레이션 시간 수를 입력하십시오: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "시간당 평균 고객 수를 입력하십시오: ";
    double perhour;
    cin >> perhour;
    double min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    long line_wait = 0;

    int wait_time1 = 0; // 첫번째 ATM 대기시간
    int wait_time2 = 0; // 두번째 ATM 대기시간간

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (line1.isfull() && line2.isfull()) // ATM 2대 다 꽉차면면
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);
                if (line1.queuecount() <= line2.queuecount()) // 둘중에 짧은 줄에 섬
                    line1.enqueue(temp);
                else
                    line2.enqueue(temp);
            }
        }

        // 첫 번째 ATM 처리
        if (wait_time1 <= 0 && !line1.isempty())
        {
            line1.dequeue(temp);
            wait_time1 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time1 > 0)
            wait_time1--;

        // 두 번째 ATM 처리
        if (wait_time2 <= 0 && !line2.isempty())
        {
            line2.dequeue(temp);
            wait_time2 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time2 > 0)
            wait_time2--;

        sum_line += line1.queuecount() + line2.queuecount();
    }

    if (customers > 0)
    {
        cout << " 줄을 선 고객 수: " << customers << endl;
        cout << " 거래를 처리한 고객 수: " << served << endl;
        cout << " 발길을 돌린 고객 수: " << turnaways << endl;
        cout.precision(2);
        cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        cout.setf(std::ios_base::showpoint);
        cout << " 평균 큐의 길이: " << (double) sum_line / cyclelimit << endl;
        cout << " 평균 대기 시간: " << (double) line_wait / served << "분\n";
    }
    else
        cout << "고객이 없습니다.\n";

    cout << "완료\n";

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
