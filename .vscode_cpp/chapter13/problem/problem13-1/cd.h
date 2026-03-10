#ifndef CD_H_
#define CD_H_

class Cd {
    private: 
        char performers[50]; // 연주자 이름
        char label[20]; // 라벨 이름
        int selections; // 수록곡 수
        double playtime; // 연주 시간(분 단위)
    public: 
        Cd(char* s1, char* s2, int n, double x); // 사용자 정의 생성자
        Cd(const Cd & d); // 사용자 정의 생성자
        Cd(); // 디폴트 생성자
        ~Cd(); // 디폴트 파괴자
        virtual void Report() const; // cd 안의 데이터를 출력하는 함수
        Cd & operator=(const Cd & d); // 대입 연산자 오버로딩
};

#endif