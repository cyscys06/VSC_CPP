#ifndef GOLF_H_ // 헤더 가드
#define GOLF_H_
const int len = 40;

class golf 
{
private:
    char fullname[len];
    int handicap;
    
public:
    golf(); // 디폴트 생성자
    golf(const char* name, int hc); // 사용자 정의 생성자
    int setgolf();
    void sethandicap(int hc);
    void showgolf() const;
};
#endif