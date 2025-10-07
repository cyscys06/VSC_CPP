#ifndef NAMESP_H_
#define NAMESP_H_

namespace SALES
{
    const int QUARTERS = 4;
    
    class Sales 
    {
    private:
        double sales[QUARTERS]; // 분기별 판매액
        double average; // 평균
        double max; // 최대
        double min; // 최소
        
    public:
        Sales(); // 객체 인자 없을때
        Sales(const double ar[], int n); // 객체 인자 있을때
        void setSales(const double ar[], int n); // 비대화식(객체의 인자 전달)
        void setSales(); // 대화식(사용자 직접입력)
        void showSales() const; // 출력(읽기전용 데이터)
    };
}
#endif