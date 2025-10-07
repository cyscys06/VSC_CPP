#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
private:
    long arrive;
    int processtime;
public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
    struct Node { Item item; struct Node * next; }; // 노드 설정: 1. 노드 각각의 정보 2. 다음 노드를 지시하는 포인터 next(중요)
    enum { Q_SIZE = 10 }; // 큐 크기
    Node * front; // 맨앞
    Node * rear; // 맨뒤
    int items; // 큐 항목 수
    const int qsize; // 큐에 넣을 수 있는 최대 항목 수
    Queue(const Queue & q) : qsize(0) {} 
    Queue & operator=(const Queue & q) { return * this; } // =연산자 오버로딩
public:
    Queue(int qs = Q_SIZE);
    ~Queue(); // 파괴자
    bool isempty() const; // 비었는지 검사
    bool isfull() const; // 꽉찼는지 검사
    int queuecount() const; // 큐 수 카운트
    bool enqueue(const Item & item); // 항목 추가
    bool dequeue(Item & item); // 항목 삭제
};
#endif
