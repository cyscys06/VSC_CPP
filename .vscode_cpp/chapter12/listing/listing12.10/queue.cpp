#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL;
    items = 0;
}

Queue::~Queue()
{
    Node * temp; // 임시 항목 생성(나중에 삭제)
    while (front != NULL) // 맨앞이 비지 않은동안(즉, 큐에 아직 뭐가 있으면)
    {
        temp = front; // 머리 항목 주소 임시 저장
        front = front->next; // front는 다음 노드 가리키는 포인터로 변경
        delete temp; // 임시 항목은 삭제
    }
}

bool Queue::isempty() const
{
    return items == 0; // 이게 조건식임, 만족하면 true 아니면 false
}

bool Queue::isfull() const
{
    return items == qsize; // 이게 조건식임, 만족하면 true 아니면 false
}

int Queue::queuecount() const
{
    return items; // 큐 항목수 반환
}

bool Queue::enqueue(const Item & item)
{
    if (isfull()) // 꽉찼으면
        return false; // 항목 추가 불가능
    Node * add = new Node; // 노드 생성
    add->item = item; // 사용자에게 입력받은 정보(매개변수) 할당
    add->next = NULL; // next 포인터는 NULL로 지정
    items++;
    if (front == NULL) // 맨앞 비었으면
        front = add; // 맨앞에 항목추가(어차피 같음)
    else // 맨앞 뭐 있으면
        rear->next = add; // 맨뒤에 추가
    rear = add; // 맨뒤가 곧 새로 추가하는 항목임
    return true;
}

bool Queue::dequeue(Item & item)
{
    if (front == NULL) // 비어있으면
        return false; // 항목 삭제 불가능
    item = front->item; // front 정보들 item에 복사
    items--;
    Node * temp = front; // 임시항목에 front 할당
    front = front->next; // 기존 front는 next에 옮겨놓음
    delete temp; // 임시항목 삭제 -> 결론적으로 front는 다음 노드로 옮겨짐
    if (items == 0)    
        rear == NULL;
    return true;
}

void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1; // rand()로 난수 생성, 3으로 나누면 나머지 0~2, 거기에 1 더하면 1~3까지의 랜덤한 수를 의미
    arrive = when;
}