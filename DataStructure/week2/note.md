## 재귀 호출
- 호출된 함수가 다시 자기 자신을 호출하는 알고리즘
- 함수들의 재귀적 호출의 종료 조건은 베이스케이스(함수가 반환하는 가장 최소 단위의 값)에 도달하는 것
- 재귀 함수가 다음에 호출할 함수가 존재한다면, 현재 함수의 호출은 계속 스택에 남아있게 됨
  -> 마지막 재귀 함수가 베이스케이스에 도달한 경우, 가장 마지막에 호출된 함수부터 차례대로 스택에서 제거되는 구조(후입선출)

## 재귀 vs 반복
- 대부분의 재귀는 반복으로도 구현 가능

재귀
```
int factorial(int n) {
    if (n <= 1) {
        return 1; // 0! = 1! = 1
    } else {
        return (n * factorial(n - 1)); // n! = n * (n-1)!
    }
}
```

반복
```
int factorial_iter(int n) { // ex) 5! 이면
    int v = 1;
    for (int k = n; k > 0; k--) {
        v *= k; 
        /* v = 1 * 5 = 5
           v = 5 * 4 = 20
           v = 20 * 3 = 60
           v = 60 * 2 = 120
           v = 120 * 1 = 120
        */
    } 

    return v;
}
```

### 하지만 재귀가 더 효율적인 경우가 있다
- 정수 x에 대해 x^n의 값을 구하는 예제

반복
```
double slow_power(double x, int n) { // x: 밑, n:지수 
    double result = 1.0;
    for (int i = 0; i < n; i++) { // 시간복잡도 O(n)
        result = result * x;
    }

    return result; 
}
```

재귀
```
double power(double x, int n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        return power(x*x, n/2); // 지수가 짝수인 경우, x^n = (x*x)^(n/2) ex) 3^4 = (3*3)^(4/2) = 9^2 = 81
    } else {
        return x*power(x*x, (n-1)/2);
    }
    // 시간복잡도 O(logn)
}
```


## 피보나치 수열
- f(n) = f(n - 1) + f(n - 2)
- 중복되는 값이 존재함(베이스케이스가 여러번 계산에 사용되므로 중복이 존재)
- n 값이 커질수록 중복값이 더욱 많아지고, 중복값에 대한 연산 시간 또한 기하급수적으로 증가함(시간낭비)
  -> 중복되는 값을 기록하면 재계산하지 않아도 되므로, 연산 시간이 단축됨(DP-메모이제이션 방식)

반복(중간값 저장)
```
int fib_iter(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } // 베이스케이스

    int pp = 0, p = 1, result = 0; // 차례대로 f(n - 2), f(n - 1)최종값

    for (int i = 2; i <= n; i++) { // f(2)부터 f(n)까지 반복
        result = p + pp; // f(n) = f(n - 1) + f(n - 2) 
        pp = p; // f(n - 2) = f(n - 1)로 갱신
        p = result; // f(n - 1) = f(n)로 갱신
    } // 반복

    return result;
}
```

### 메모이제이션
- 한번 계산한 값을 배열에 저장해 두고 다음에 같은 값이 필요할 때 배열에서 꺼내 쓰는 방식
- 한번 계산한 값은 다시 계산하지 않음
  -> array[n]에 해당하는 값만 조회하여 이미 계산한 값이 있는지 검색하므로, 시간도 O(1)밖에 안걸림
- 연산 시간 효율적으로 단축 가능
- 재귀적인 top-down 방식으로 진행

메모이제이션
```
#include <iostream>

int memo[100];
 
int fib_memo(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    if (memo[n] != -1) { // 계산한 값이 존재할 경우
        return memo[n]; // 해당 값을 계산에 사용
    }

    // 처음 계산하는 경우
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2); // 계산한 값을 배열에 저장
    // 호출 저장 영역은 스택 구조이므로, 베이스케이스부터 시작하여 낮은 값들이 점점 배열에 저장되면서 위로 올라감

    return memo[n]; // 계산한 값 반환
}

int main() {
    for (int i = 0; i < 100; i++) {
        memo[i] = -1; // 처음은 모두 -1로 초기화
    }

    cout << fib_memo(6) << endl;

    return 0;
}
```


### 타뷸레이션
- 가장 작은 값부터 시작해서 차례대로 위로 올라가는 방식(bottom-up방식)
- 메모이제이션과 달리 반복분을 사용하여 구현
- 구현이 단순, 호출 스택 안쌓임

타뷸레이션
```
#include <iostream>

int fib_tab(int n) {
    if (n == 0) {
        return 0;
    }

    int dp[100];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // 피보나치 수열 점화식과 같음
        // 이거 2차원 이상으로 확장하면 DP
    }

    return dp[n];
}

int main() {
    cout << fib_tab(6) << endl;

    return 0;
}
```

## 하노이 탑 문제
- 원판을 쌓을 수 있는 막대 A, B, C가 존재
- 막대 A에 쌓여있는 원판 n개를 막대 C로 옮기는 문제
- 조건:
- 1. 한번에 하나의 원판만 이동 가능
- 2. 맨 위에 있는 원판만 이동 가능
- 3. 크기가 작은 원판 위에 그보다 큰 원판을 쌓을 수 없음
- 4. 중간의 막대 B를 임시적으로 이용할 수 있으나 1, 2, 3번 조건을 지켜야 함

### 해결
- 한 사이클을 재귀적으로 반복한다.
- 사이클:
- 1. 막대 C를 임시 버퍼로 사용하여 막대 A에 쌓여있는 n-1개의 원판을 B로 옮긴다.
- 2. 막대 A의 가장 큰 원판을 C로 옮긴다.
- 3. 막대 A를 임시 버퍼로 사용하여 막대 B에 쌓여있는 n-1개의 원판을 막대 C로 옮긴다. 

- 이때, 사이클에서 옮기는 n-1개의 원판에 대해 동일한 사이클을 적용시킨다.
- 사이클을 함수로 보면, 맨 처음 매개변수는 n일것
- 그러면 재귀적으로 호출할 함수에는 매개변수로 n-1을 전달하면 됨
- 이후에는 n-2, n-3, ... 반복

사이클 함수(슈도 코드)
```
// 막대 from에 쌓여있는 n개의 원판을 막대 tmp를 사용하여 막대 to로 옮긴다
void hanoi_tower(int n, char from, char tmp, char to) {
    if (n == 1) { // 쌓여있는 원판이 1개인 경우
        // from에서 to로 원판을 옮긴다
    } else { // 쌓여있는 원판이 2개 이상인 경우
        hanoi_tower(n - 1, from, to, tmp); // 우선 to를 임시로 하여 n - 2개의 원판을 tmp에 옮긴다
        // 이후 from에 있는 한 개의 원판을 to로 옮긴다
        hanoi_tower(n - 1, tmp, from, to); // 이후 tmp에 있는 n - 2개의 원판을 from을 임시로 하여 to로 옮긴다
    }
}
```

사이클 함수 최종 구현
```
// 가장 작은 원판: 1
// 커질수록 숫자 1씩 증가
#include <iostream>

void hanoi_tower(int n, char from, char tmp, char to) {
    if (n == 1) { // 베이스케이스
        cout << "원판 1을 " << from << " 에서 " << to << " 으로 옮긴다.\n";
    } else {
        hanoi_tower(n-1, from, to, tmp);
        cout << "원판 " << n << " 을 " << from << " 에서 " << to << " 로 옮긴다.\n";
        hanoi_tower(n-1, tmp, from, to);
    }   
}

int main() {
    hanoi_tower(4, 'A', 'B', 'C');
    return 0;
}
```