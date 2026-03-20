#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
using namespace std;
#define NUM_STUDENTS 10

typedef struct studentTag {
    char name[10];
    int age;
    double gpa;
} Student;

void fillArrStds(Student arrStds[], int n, const char* namePrefix);
void printArrStds(Student arrStds[], int n);
void fillArrStds(Student* pArrStds[], int n, const char* namePrefix);
void printArrStds(Student* pArrStds[], int n);
void printAddrDiff(const char* labelA, void* a, const char* labelB, void* b);
void printCoreAddresses(Student arrStds[], Student* pStds, Student** pArrStds);

int main() {
    Student* p;
    Student arrStds[NUM_STUDENTS];
    Student* pStds;
    Student** pArrStds;

    p = (Student*)malloc(sizeof(Student));
    pStds = (Student*)malloc(sizeof(Student) * NUM_STUDENTS);
    pArrStds = (Student**)malloc(sizeof(Student*) * NUM_STUDENTS);

    if (p == NULL || pStds == NULL || pArrStds == NULL) {
        fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
        exit(1);
    }

    fillArrStds(arrStds, NUM_STUDENTS, "김");
    printArrStds(arrStds, NUM_STUDENTS);

    printf("------------------------------\n");
    fillArrStds(pStds, NUM_STUDENTS, "이");
    printArrStds(pStds, NUM_STUDENTS);

    printf("------------------------------\n");
    fillArrStds(pArrStds, NUM_STUDENTS, "박");
    printArrStds(pArrStds, NUM_STUDENTS);

    printCoreAddresses(arrStds, pStds, pArrStds);

    free(p);
    free(pStds);
    for (int i = 0; i < NUM_STUDENTS; i++)
        free(pArrStds[i]);
    free(pArrStds);

    return 0;
}

void fillArrStds(Student arrStds[], int n, const char* namePrefix) {
    string nameStr, nPrefix = namePrefix;

    for (int i = 0; i < n; i++) {
        nameStr = nPrefix + to_string(i) + "동";
        strcpy_s(arrStds[i].name, nameStr.c_str());
        arrStds[i].age = i;
        arrStds[i].gpa = i % 101;
    }
}

void printArrStds(Student arrStds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d %.1f\n", arrStds[i].name, arrStds[i].age, arrStds[i].gpa);
    }
}

void fillArrStds(Student* pArrStds[], int n, const char* namePrefix) {
    string nameStr, nPrefix = namePrefix;

    for (int i = 0; i < n; i++) {
        pArrStds[i] = (Student*)malloc(sizeof(Student));
        if (pArrStds[i] == NULL) {
            fprintf(stderr, "메모리 할당 실패\n");
            exit(1);
        }

        nameStr = nPrefix + to_string(i) + "동";
        strcpy_s(pArrStds[i]->name, nameStr.c_str());
        pArrStds[i]->age = i;
        pArrStds[i]->gpa = i % 101;
    }
}

void printArrStds(Student* pArrStds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d %.1f\n", pArrStds[i]->name, pArrStds[i]->age, pArrStds[i]->gpa);
    }
}

void printAddrDiff(const char* labelA, void* a, const char* labelB, void* b) {
    uintptr_t ua = (uintptr_t)a;
    uintptr_t ub = (uintptr_t)b;

    printf("%s = %p (0x%" PRIxPTR ")\n", labelA, a, ua);
    printf("%s = %p (0x%" PRIxPTR ")\n", labelB, b, ub);

    if (ub >= ua) {
        printf("차이    = %" PRIxPTR " bytes (0x%" PRIxPTR ")\n\n", ub - ua, ub - ua);
    } else {
        printf("차이    = -%" PRIxPTR " bytes (-0x%" PRIxPTR ")\n\n", ua - ub, ua - ub);
    }
}

void printCoreAddresses(Student arrStds[], Student* pStds, Student** pArrStds)
{
    printf("\n================ 핵심 주소 비교 ================\n");
    printf("sizeof(Student) = %zu bytes (0x%zX)\n", sizeof(Student), sizeof(Student));
    printf("sizeof(Student*) = %zu bytes (0x%zX)\n\n", sizeof(Student*), sizeof(Student*));

    printf("[1] arrStds : 정적 배열 (Student가 연속)\n");
    printAddrDiff("arrStds[0]", &arrStds[0], "arrStds[1]", &arrStds[1]);

    printf("[2] pStds : malloc으로 한 번에 할당 (Student가 연속)\n");
    printAddrDiff("pStds", pStds, "pStds+1", pStds + 1);

    printf("[3] pArrStds : Student* 배열 (포인터 값들이 연속)\n");
    printAddrDiff("pArrStds", pArrStds, "pArrStds+1", pArrStds + 1);

    printf("[4] pArrStds가 가리키는 실제 Student 주소\n");
    printAddrDiff("pArrStds[0]", pArrStds[0], "pArrStds[0]+1", pArrStds[0] + 1);

    printf("[5] pArrStds[0]+1 과 pArrStds[1] 비교\n");
    printAddrDiff("pArrStds[0]+1", pArrStds[0] + 1, "pArrStds[1]", pArrStds[1]);

    printf("[6] pArrStds[0] 과 pArrStds[1] 실제 값\n");
    printAddrDiff("pArrStds[0]", pArrStds[0], "pArrStds[1]", pArrStds[1]);

    printf("설명:\n");
    printf("- arrStds[0] -> arrStds[1] 증가는 sizeof(Student)\n");
    printf("- pStds -> pStds+1 증가는 sizeof(Student)\n");
    printf("- pArrStds -> pArrStds+1 증가는 sizeof(Student*)\n");
    printf("- pArrStds[0] -> pArrStds[0]+1 증가는 sizeof(Student)\n");
    printf("- pArrStds[1]은 별도 malloc 결과라서 pArrStds[0]+1 과 보통 다름\n");
    printf("================================================\n\n");
}