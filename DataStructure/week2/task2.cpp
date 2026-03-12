#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void printMenu() {
    cout << "====================================================\n";
    cout << "   재귀 / 반복 / DP / 하노이 메뉴\n";
    cout << "====================================================\n";
    cout << "1. factorial (일반 재귀)\n";
    cout << "2. factorial_tail (꼬리 재귀)\n";
    cout << "3. 거듭제곱 (반복문)\n";
    cout << "4. 거듭제곱 (분할 정복 재귀)\n";
    cout << "5. fibonacci (일반)\n";
    cout << "6. fibonacci (타뷸레이션)\n";
    cout << "7. 하노이 탑\n";
    cout << "8. factorial vs factorial_tail 호출 흐름 trace\n";
    cout << "9. 거듭제곱 수행시간 비교\n";
    cout << "10. fibonacci 수행시간 비교\n";
    cout << "0. 종료\n";
    cout << "====================================================\n";
}

void waitAndClear() {
    cout << "\n계속하려면 Enter를 누르세요...";
    cin.ignore(10000, '\n');
    cin.get();
    system("cls"); 
}

void indent(int depth) {
    for (int i = 0; i < depth; i++) {
        cout << " ";
    }
}

double factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    }
    return (double)n * factorial_recursive(n - 1);
}

double factorial_tail_helper(int n, double acc) {
    if (n == 0 || n == 1) {
        return acc;
    }
    return factorial_tail_helper(n - 1, acc * (double)n);
}

double factorial_tail(int n) {
    return factorial_tail_helper(n, 1.0);
}

double power_iterative(double base, int exp) {
    double result = 1.0;
    
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

double power_fast_recursive(double base, int exp) {
    double half;

    if (exp == 0) {
        return 1.0;
    } else if (exp == 1) {
        return base;
    }

    half = power_fast_recursive(base, exp / 2);

    if (exp % 2 == 0) {
        return half * half;
    } else {
        return half * half * base;
    }
}

double fibonacci_recursive(int n) {
    if (n == 0) {
        return 0.0;
    } else if (n == 1) {
        return 1.0;
    }
    
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

double fibonacci_tabulation(int n) {
    double prev2 = 0.0, prev1 = 1.0, current = 0.0;
    
    if (n == 0) {
        return 0.0;
    } else if (n == 1) {
        return 1.0;
    }

    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

double factorial_trace(int n, int depth) {
    double sub, result;

    indent(depth);
    cout << "factorial(" << n << ") 호출\n";

    if (n == 0 || n == 1) {
        indent(depth);
        cout << "return 1\n";
        return 1.0;
    }

    sub = factorial_trace(n - 1, depth + 1);
    result = (double)n * sub;

    indent(depth);
    cout << "return " << n << " * " << sub << " = " << result << endl;

    return result;
}

double factorial_tail_trace(int n, double acc, int depth) {
    indent(depth);
    cout << "factorial_tail(n = " << n << ", acc = " << acc << ") 호출\n";

    if (n == 0 || n == 1) {
        indent(depth);
        cout << "return " << acc << endl;
        return acc;
    }

    indent(depth);
    cout << "다음 호출: factorial_tail(n = " << n - 1 << ", acc = " << acc * (double)n << ")\n";

    return factorial_tail_trace(n - 1, acc * (double)n, depth + 1);
}

void checkTimePerformance(double x, int n, int repeat, double (*fptr)(double, int)) {
    clock_t start, stop;
    double duration;
    volatile double sink = 0.0;
    
    start = clock();

    for (int i = 0; i < repeat; i++) {
        sink = fptr(x, n);
    }

    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "수행시간은 " << duration << "초입니다.\n";

    if (sink == -1.234567) {
        cout << sink;
    }
}

double power_iterative_adapter(double x, int n) {
    return power_iterative(x, n);
}

double power_fast_recursive_adapter(double x, int n) {
    return power_fast_recursive(x, n);
}

double fibonacci_recursive_adapter(double x, int n) {
    return fibonacci_recursive(n);
}

double fibonacci_tabulation_adapter(double x, int n) {
    return fibonacci_tabulation(n);
}

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "원판 1: " << from << " -> " << to << endl;
        return;
    }

    hanoi(n - 1, from, aux, to);
    cout << "원판 " << n << ": " << from << " -> " << to << endl;
    hanoi(n - 1, aux, to, from);
}

double hanoi_move_count(int n) {
    if (n == 1) {
        return 1.0;
    }

    return 2.0 * hanoi_move_count(n - 1) + 1.0;
}

int main(void) {
    int menu;
    int n, exp, repeat;
    double base;

    while (1) {
        printMenu();
        cout << "메뉴 선택: ";

        cin >> menu;

        if (menu < 0 || menu > 10) { // 잘못된 입력
            cout << "입력이 잘못되었습니다.\n";
            return 0;
        }

        switch (menu) {
        case 1:
            cout << "n 입력: ";
            cin >> n;

            if (n < 0) {
                cout << "0 이상의 정수를 입력하세요.\n";
                break;
            }

            printf("factorial_recursive(%d) = %.0f\n", n, factorial_recursive(n));
            break;

        case 2:
            printf("n 입력: ");
            scanf_s("%d", &n);

            if (n < 0) {
                printf("0 이상의 정수를 입력하세요.\n");
                break;
            }

            printf("factorial_tail(%d) = %.0f\n", n, factorial_tail(n));
            break;

        case 3:
            printf("밑(base) 입력: ");
            scanf_s("%lf", &base);
            printf("지수(exp) 입력: ");
            scanf_s("%d", &exp);

            if (exp < 0) {
                printf("지수는 0 이상의 정수를 입력하세요.\n");
                break;
            }

            printf("power_iterative(%.2f, %d) = %.6f\n",
                base, exp, power_iterative(base, exp));
            break;

        case 4:
            printf("밑(base) 입력: ");
            scanf_s("%lf", &base);
            printf("지수(exp) 입력: ");
            scanf_s("%d", &exp);

            if (exp < 0) {
                printf("지수는 0 이상의 정수를 입력하세요.\n");
                break;
            }

            printf("power_fast_recursive(%.2f, %d) = %.6f\n",
                base, exp, power_fast_recursive(base, exp));
            break;

        case 5:
            printf("n 입력 (일반 재귀는 0~40 권장): ");
            scanf_s("%d", &n);

            if (n < 0) {
                printf("0 이상의 정수를 입력하세요.\n");
                break;
            }

            printf("fibonacci_recursive(%d) = %.0f\n", n, fibonacci_recursive(n));
            break;

        case 6:
            printf("n 입력: ");
            scanf_s("%d", &n);

            if (n < 0) {
                printf("0 이상의 정수를 입력하세요.\n");
                break;
            }

            printf("fibonacci_tabulation(%d) = %.0f\n", n, fibonacci_tabulation(n));
            break;

        case 7:
            printf("원판 개수 입력: ");
            scanf_s("%d", &n);

            if (n <= 0) {
                printf("1 이상의 정수를 입력하세요.\n");
                break;
            }

            printf("총 이동 횟수: %.0f\n", hanoi_move_count(n));

            if (n <= 15) {
                printf("[이동 과정 출력]\n");
                hanoi(n, 'A', 'C', 'B');
            }
            else {
                printf("원판 수가 커서 이동 과정 출력은 생략했습니다. (15 이하 권장)\n");
            }
            break;

        case 8:
            printf("trace용 n 입력 (예: 4~6): ");
            scanf_s("%d", &n);

            if (n < 0) {
                printf("0 이상의 정수를 입력하세요.\n");
                break;
            }

            printf("\n=== 일반 재귀 factorial 호출 흐름 ===\n");
            factorial_trace(n, 0);

            printf("\n=== 꼬리 재귀 factorial_tail 호출 흐름 ===\n");
            factorial_tail_trace(n, 1.0, 0);

            printf("\n설명:\n");
            printf("- 일반 재귀는 재귀 호출이 끝난 뒤 곱셈 수행.\n");
            printf("- 꼬리 재귀는 누적값을 넘기고 바로 다음 호출 수행.\n");
            printf("- 실제 스택 재사용 여부는 컴파일러 최적화에 따라 달라질 수 있음.\n");
            break;

        case 9:
            printf("밑(base) 입력: ");
            scanf_s("%lf", &base);
            printf("지수(exp) 입력: ");
            scanf_s("%d", &exp);
            printf("반복 횟수(repeat) 입력: ");
            scanf_s("%d", &repeat);

            if (exp < 0 || repeat <= 0) {
                printf("지수는 0 이상, 반복 횟수는 1 이상이어야 합니다.\n");
                break;
            }

            printf("\n=== 거듭제곱 수행시간 비교 ===\n");
            printf("[반복문 버전]\n");
            checkTimePerformance(base, exp, repeat, power_iterative_adapter);

            printf("[분할 정복 재귀 버전]\n");
            checkTimePerformance(base, exp, repeat, power_fast_recursive_adapter);

            printf("\n결과값 확인:\n");
            printf("power_iterative(%.2f, %d) = %.6f\n", base, exp, power_iterative(base, exp));
            printf("power_fast_recursive(%.2f, %d) = %.6f\n", base, exp, power_fast_recursive(base, exp));
            break;

        case 10:
            printf("n 입력 (일반 재귀는 0~40 권장): ");
            scanf_s("%d", &n);
            printf("반복 횟수(repeat) 입력: ");
            scanf_s("%d", &repeat);

            if (n < 0 || repeat <= 0) {
                printf("n은 0 이상, 반복 횟수는 1 이상이어야 합니다.\n");
                break;
            }

            printf("\n=== fibonacci 수행시간 비교 ===\n");
            printf("[일반 재귀]\n");
            checkTimePerformance(0.0, n, repeat, fibonacci_recursive_adapter);

            printf("[tabulation]\n");
            checkTimePerformance(0.0, n, repeat, fibonacci_tabulation_adapter);

            printf("\n결과값 확인:\n");
            printf("fibonacci_recursive(%d) = %.0f\n", n, fibonacci_recursive(n));
            printf("fibonacci_tabulation(%d) = %.0f\n", n, fibonacci_tabulation(n));
            break;

        case 0:
            printf("프로그램 종료\n");
            return 0;

        default:
            printf("잘못된 메뉴입니다.\n");
            break;
        }

        waitAndClear();
    }

    return 0;
}
