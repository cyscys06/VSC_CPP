#include <iostream>
#include "namesp.h"
using namespace std;

namespace SALES
{
    Sales::Sales() // 디폴트
    {
        for (int i = 0; i < QUARTERS; i++)
        {
            sales[i] = 0.0;
        }
        average = 0.0;
        max = 0.0;
        min = 0.0;
    }

    Sales::Sales(const double ar[], int n)
    {
        setSales(ar, n);
    }

    void Sales::setSales(const double ar[], int n)
    {
        int items = (n < QUARTERS) ? n : QUARTERS; // 삼항 연산자: n이 QUARTERS보다 작으면 n, 아니면 QUARTERS
        double sum = 0.0; // 총합

        for (int i = 0; i < items; i++) // 매개변수 ar배열 값 sales에 복사
        {
            sales[i] = ar[i];
        }
        for (int i = items; i < QUARTERS; i++) // sales배열의 남은(값이 할당되지 않은) 인덱스들 전부 0으로 초기화(i = items)
        {
            sales[i] = 0.0;
        }
        for (int i = 0; i < items; i++) // 총합 구하는 과정
        {
            sum += sales[i];
        }
        
        if (items > 0) // 입력된 값 있을때
        {
            average = sum / items; 
            
            max = sales[0]; // 최대 구하는 과정
            for (int i = 1; i < items; i++)
            {
                if (sales[i] > max)
                    max = sales[i];
            }
            min = sales[0]; // 최소 구하는 과정
            for (int i = 1; i < items; i++)
            {
                if (sales[i] < min)
                    min = sales[i];
            }
        }
        else // 입력된 값이 없을때
        {
            max = 0.0;
            min = 0.0;
            average = 0.0;
        }
    }
    
    void Sales::setSales()
    {
        cout << "4분기 판매액 정보를 입력하세요:\n";
        double temp[QUARTERS];
        
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << i + 1 << "분기 판매액: ";
            while (!(cin >> temp[i]))
            {
                cin.clear();
                while (cin.get() != '\n')
                    continue;
                cout << "숫자를 입력하세요: ";
            }
        }
        
        // 입력 버퍼 정리
        cin.get();
        
        // setSales 메서드를 활용하여 데이터 설정
        setSales(temp, QUARTERS);
    }
    
    // 모든 정보 출력 메서드
    void Sales::showSales() const
    {
        cout << "판매액 정보:\n";
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << i + 1 << "분기: " << sales[i] << endl;
        }
        
        cout << "평균 판매액: " << average << endl;
        cout << "최대 판매액: " << max << endl;
        cout << "최소 판매액: " << min << endl;
    }
}