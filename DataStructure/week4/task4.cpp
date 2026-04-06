#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
 
#define MAX_EXPR 256
#define GLOBAL_STACK_SIZE 256
#define INITIAL_POS_STACK_CAPACITY 16
#define ANIMATION_DELAY_MS 250
 
/* ==========================
   공통 입력 함수
   ========================== */
void read_line(char* buf, int size)
{
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}
 
int read_int(const char* msg)
{
    char line[100];
    int value;
 
    while (1) {
        printf("%s", msg);
        read_line(line, sizeof(line));
        if (sscanf(line, "%d", &value) == 1) {
            return value;
        }
        printf("정수를 다시 입력하세요.\n");
    }
}
 
void pause_animation(int ms)
{
    Sleep(ms);
}
 
void clear_screen(void)
{
    system("cls");
}
 
/* =====================================================
   1. 괄호 검사 : 전역 배열 스택 사용
   ===================================================== */
char g_stack[GLOBAL_STACK_SIZE];
int g_top = -1;
 
void g_init_stack(void)
{
    g_top = -1;
}
 
int g_is_empty(void)
{
    return (g_top == -1);
}
 
int g_is_full(void)
{
    return (g_top == GLOBAL_STACK_SIZE - 1);
}
 
int g_push(char item)
{
    if (g_is_full()) {
        printf("전역 배열 스택이 가득 찼습니다.\n");
        return 0;
    }
    g_stack[++g_top] = item;
    return 1;
}
 
int g_pop(char* item)
{
    if (g_is_empty()) {
        return 0;
    }
    *item = g_stack[g_top--];
    return 1;
}
 
int is_open_bracket(char ch)
{
    return ch == '(' || ch == '[' || ch == '{';
}
 
int is_close_bracket(char ch)
{
    return ch == ')' || ch == ']' || ch == '}';
}
 
int is_match(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
 
int check_brackets_global(const char* str)
{
    int i;
    char ch;
    char open_ch;
 
    g_init_stack();
 
    for (i = 0; str[i] != '\0'; i++) {
        ch = str[i];
 
        if (is_open_bracket(ch)) {
            printf("%c 를 만나서 전역 배열 스택에 push 합니다.\n", ch);
            g_push(ch);
        }
        else if (is_close_bracket(ch)) {
            printf("%c 를 만나서 스택의 맨 위 괄호와 비교합니다.\n", ch);
 
            if (!g_pop(&open_ch)) {
                printf("비교할 여는 괄호가 없으므로 실패입니다.\n");
                return 0;
            }
 
            printf("스택에서 꺼낸 괄호는 %c 입니다.\n", open_ch);
 
            if (!is_match(open_ch, ch)) {
                printf("괄호의 짝이 맞지 않으므로 실패입니다.\n");
                return 0;
            }
        }
    }
 
    if (!g_is_empty()) {
        printf("검사가 끝났는데 여는 괄호가 스택에 남아 있습니다.\n");
        return 0;
    }
 
    return 1;
}
 
void demo_bracket_check(void)
{
    char expr[MAX_EXPR];
 
    printf("\n[1. 괄호 검사 - 전역 배열 스택 사용]\n");
    printf("설명: 가장 간단한 스택 구현으로도 괄호 검사가 가능합니다.\n");
    printf("예시: { A[(i+1)]=0; }\n");
    printf("입력: ");
    read_line(expr, sizeof(expr));
 
    if (check_brackets_global(expr)) {
        printf("결과: 괄호 검사 성공\n");
    }
    else {
        printf("결과: 괄호 검사 실패\n");
    }
}
 
/* =====================================================
   2. 중위 -> 후위 변환 및 계산 : 구조체 배열 스택 사용
   ===================================================== */
typedef struct {
    char data[MAX_EXPR];
    int top;
} CharStack;
 
typedef struct {
    int data[MAX_EXPR];
    int top;
} IntStack;
 
void init_char_stack(CharStack* s)
{
    s->top = -1;
}
 
int is_char_empty(CharStack* s)
{
    return (s->top == -1);
}
 
int push_char(CharStack* s, char item)
{
    if (s->top >= MAX_EXPR - 1) {
        printf("문자 스택이 가득 찼습니다.\n");
        return 0;
    }
    s->data[++(s->top)] = item;
    return 1;
}
 
int pop_char(CharStack* s, char* item)
{
    if (is_char_empty(s)) {
        return 0;
    }
    *item = s->data[(s->top)--];
    return 1;
}
 
int peek_char(CharStack* s, char* item)
{
    if (is_char_empty(s)) {
        return 0;
    }
    *item = s->data[s->top];
    return 1;
}
 
void init_int_stack(IntStack* s)
{
    s->top = -1;
}
 
int is_int_empty(IntStack* s)
{
    return (s->top == -1);
}
 
int push_int(IntStack* s, int item)
{
    if (s->top >= MAX_EXPR - 1) {
        printf("정수 스택이 가득 찼습니다.\n");
        return 0;
    }
    s->data[++(s->top)] = item;
    return 1;
}
 
int pop_int(IntStack* s, int* item)
{
    if (is_int_empty(s)) {
        return 0;
    }
    *item = s->data[(s->top)--];
    return 1;
}
 
int precedence(char op)
{
    switch (op) {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    }
}
 
int is_operator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
 
int infix_to_postfix_struct(const char* infix, char* postfix)
{
    CharStack s;
    int i;
    int k = 0;
    char ch;
    char top_op;
 
    init_char_stack(&s);
 
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
 
        if (isspace((unsigned char)ch)) {
            continue;
        }
        else if (isdigit((unsigned char)ch)) {
            while (isdigit((unsigned char)infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' ';
            i--;
        }
        else if (ch == '(') {
            push_char(&s, ch);
        }
        else if (ch == ')') {
            while (1) {
                if (!pop_char(&s, &top_op)) {
                    printf("괄호가 올바르지 않습니다.\n");
                    return 0;
                }
                if (top_op == '(') {
                    break;
                }
                postfix[k++] = top_op;
                postfix[k++] = ' ';
            }
        }
        else if (is_operator(ch)) {
            char peek_op;
            while (!is_char_empty(&s)) {
                peek_char(&s, &peek_op);
                if (precedence(peek_op) >= precedence(ch)) {
                    pop_char(&s, &top_op);
                    postfix[k++] = top_op;
                    postfix[k++] = ' ';
                }
                else {
                    break;
                }
            }
            push_char(&s, ch);
        }
        else {
            printf("지원하지 않는 문자 '%c' 가 있습니다.\n", ch);
            return 0;
        }
    }
 
    while (!is_char_empty(&s)) {
        pop_char(&s, &top_op);
        if (top_op == '(') {
            printf("괄호가 올바르지 않습니다.\n");
            return 0;
        }
        postfix[k++] = top_op;
        postfix[k++] = ' ';
    }
 
    postfix[k] = '\0';
    return 1;
}
 
int eval_postfix_struct(const char* postfix, int* result)
{
    IntStack s;
    int i = 0;
 
    init_int_stack(&s);
 
    while (postfix[i] != '\0') {
        if (isspace((unsigned char)postfix[i])) {
            i++;
            continue;
        }
 
        if (isdigit((unsigned char)postfix[i])) {
            int value = 0;
            while (isdigit((unsigned char)postfix[i])) {
                value = value * 10 + (postfix[i] - '0');
                i++;
            }
            printf("피연산자 %d 를 정수 스택에 push 합니다.\n", value);
            push_int(&s, value);
        }
        else if (is_operator(postfix[i])) {
            int a;
            int b;
            int temp;
            char op = postfix[i];
 
            if (!pop_int(&s, &b) || !pop_int(&s, &a)) {
                printf("수식이 올바르지 않습니다.\n");
                return 0;
            }
 
            switch (op) {
            case '+':
                temp = a + b;
                break;
            case '-':
                temp = a - b;
                break;
            case '*':
                temp = a * b;
                break;
            case '/':
                if (b == 0) {
                    printf("0으로 나눌 수 없습니다.\n");
                    return 0;
                }
                temp = a / b;
                break;
            default:
                return 0;
            }
 
            printf("%d %c %d = %d 계산 후 다시 스택에 push 합니다.\n", a, op, b, temp);
            push_int(&s, temp);
            i++;
        }
        else {
            printf("후위 표기식 계산 중 오류가 발생했습니다.\n");
            return 0;
        }
    }
 
    if (!pop_int(&s, result) || !is_int_empty(&s)) {
        printf("수식이 올바르지 않습니다.\n");
        return 0;
    }
 
    return 1;
}
 
void demo_infix_postfix_calc(void)
{
    char infix[MAX_EXPR];
    char postfix[MAX_EXPR * 2];
    int result;
 
    printf("\n[2. 중위 표기식 -> 후위 표기식 변환 및 계산 - 구조체 배열 스택 사용]\n");
    printf("설명: 문자 스택과 정수 스택을 분리해서 관리하는 것이 깔끔합니다.\n");
    printf("정수, +, -, *, /, 괄호만 지원합니다.\n");
    printf("예시: (2+3)*4+9\n");
    printf("입력: ");
    read_line(infix, sizeof(infix));
 
    if (!infix_to_postfix_struct(infix, postfix)) {
        printf("중위 표기식을 후위 표기식으로 변환하지 못했습니다.\n");
        return;
    }
 
    printf("후위 표기식: %s\n", postfix);
 
    if (eval_postfix_struct(postfix, &result)) {
        printf("최종 계산 결과: %d\n", result);
    }
    else {
        printf("후위 표기식 계산에 실패했습니다.\n");
    }
}
 
/* =====================================================
   3. 동적 미로 생성 및 탐색 : 동적 스택 + 동적 미로 사용
   ===================================================== */
typedef struct {
    int r;
    int c;
} Position;
 
typedef struct {
    Position* data;
    int top;
    int capacity;
} PosStack;
 
typedef struct {
    int size;
    char** cell;
} Maze;
 
void init_pos_stack(PosStack* s, int capacity)
{
    if (capacity < 1) {
        capacity = 1;
    }
 
    s->data = (Position*)malloc(sizeof(Position) * capacity);
    if (s->data == NULL) {
        printf("동적 스택 메모리 할당 실패\n");
        exit(1);
    }
 
    s->top = -1;
    s->capacity = capacity;
}
 
void free_pos_stack(PosStack* s)
{
    if (s->data != NULL) {
        free(s->data);
        s->data = NULL;
    }
    s->top = -1;
    s->capacity = 0;
}
 
int is_pos_empty(PosStack* s)
{
    return (s->top == -1);
}
 
int push_pos(PosStack* s, Position item)
{
    Position* temp;
 
    if (s->top >= s->capacity - 1) {
        s->capacity *= 2;
        temp = (Position*)realloc(s->data, sizeof(Position) * s->capacity);
        if (temp == NULL) {
            printf("동적 스택 크기 확장 실패\n");
            return 0;
        }
        s->data = temp;
        printf("동적 스택 크기를 확장했습니다. 현재 용량: %d\n", s->capacity);
    }
 
    s->data[++(s->top)] = item;
    return 1;
}
 
int pop_pos(PosStack* s, Position* item)
{
    if (is_pos_empty(s)) {
        return 0;
    }
 
    *item = s->data[(s->top)--];
    return 1;
}
 
int init_maze(Maze* m, int n)
{
    int i;
 
    m->size = n;
    m->cell = (char**)malloc(sizeof(char*) * n);
    if (m->cell == NULL) {
        return 0;
    }
 
    for (i = 0; i < n; i++) {
        m->cell[i] = (char*)malloc(sizeof(char) * n);
        if (m->cell[i] == NULL) {
            int j;
            for (j = 0; j < i; j++) {
                free(m->cell[j]);
            }
            free(m->cell);
            m->cell = NULL;
            return 0;
        }
    }
 
    return 1;
}
 
void free_maze(Maze* m)
{
    int i;
 
    if (m->cell != NULL) {
        for (i = 0; i < m->size; i++) {
            free(m->cell[i]);
        }
        free(m->cell);
        m->cell = NULL;
    }
 
    m->size = 0;
}
 
void fill_maze_with_walls(Maze* m)
{
    int r;
    int c;
 
    for (r = 0; r < m->size; r++) {
        for (c = 0; c < m->size; c++) {
            m->cell[r][c] = '1';
        }
    }
}
 
void print_maze(Maze* m)
{
    int r;
    int c;
 
    for (r = 0; r < m->size; r++) {
        for (c = 0; c < m->size; c++) {
            printf("%c ", m->cell[r][c]);
        }
        printf("\n");
    }
}
 
int pick_random_open_cell(Maze* m, int* out_r, int* out_c)
{
    int r;
    int c;
    int count = 0;
    int target;
 
    for (r = 1; r < m->size - 1; r++) {
        for (c = 1; c < m->size - 1; c++) {
            if (m->cell[r][c] == '0') {
                count++;
            }
        }
    }
 
    if (count == 0) {
        return 0;
    }
 
    target = rand() % count;
    count = 0;
 
    for (r = 1; r < m->size - 1; r++) {
        for (c = 1; c < m->size - 1; c++) {
            if (m->cell[r][c] == '0') {
                if (count == target) {
                    *out_r = r;
                    *out_c = c;
                    return 1;
                }
                count++;
            }
        }
    }
 
    return 0;
}
 
int generate_connected_maze(Maze* m)
{
    int n = m->size;
    int r;
    int c;
    int branch_count;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
    int i;
 
    if (n < 5) {
        printf("N은 5 이상이어야 합니다.\n");
        return 0;
    }
 
    fill_maze_with_walls(m);
 
    r = 1;
    c = 1;
    m->cell[r][c] = '0';
 
    while (!(r == n - 2 && c == n - 2)) {
        int can_down = (r < n - 2);
        int can_right = (c < n - 2);
 
        if (can_down && can_right) {
            if (rand() % 2 == 0) {
                r++;
            }
            else {
                c++;
            }
        }
        else if (can_down) {
            r++;
        }
        else if (can_right) {
            c++;
        }
 
        m->cell[r][c] = '0';
    }
 
    branch_count = n * n / 2;
 
    for (i = 0; i < branch_count; i++) {
        int base_r;
        int base_c;
        int dir;
        int nr;
        int nc;
 
        if (!pick_random_open_cell(m, &base_r, &base_c)) {
            break;
        }
 
        dir = rand() % 4;
        nr = base_r + dr[dir];
        nc = base_c + dc[dir];
 
        if (nr >= 1 && nr <= n - 2 && nc >= 1 && nc <= n - 2) {
            if (m->cell[nr][nc] == '1') {
                m->cell[nr][nc] = '0';
            }
        }
    }
 
    m->cell[1][0] = 'e';
    m->cell[1][1] = '0';
    m->cell[n - 2][n - 2] = '0';
    m->cell[n - 2][n - 1] = 'x';
 
    return 1;
}
 
void push_location(PosStack* s, Maze* m, int r, int c)
{
    Position p;
 
    if (r < 0 || r >= m->size || c < 0 || c >= m->size) {
        return;
    }
 
    if (m->cell[r][c] == '0' || m->cell[r][c] == 'x') {
        p.r = r;
        p.c = c;
        push_pos(s, p);
 
        if (m->cell[r][c] == '0') {
            m->cell[r][c] = '+';
        }
    }
}
 
void draw_maze_frame(Maze* m, int step, int cur_r, int cur_c)
{
    clear_screen();
    printf("[3. 동적 미로 생성 및 탐색 - 애니메이션]\n");
    printf("단계: %d\n", step);
    printf("현재 위치: (%d, %d)\n", cur_r, cur_c);
    printf("기호 설명: 1=벽, 0=아직 가지 않은 길, e=입구, x=출구, +=스택 후보, .=방문한 위치\n\n");
    print_maze(m);
    fflush(stdout);
}
 
void explore_maze(Maze* m)
{
    Position here;
    Position next;
    PosStack s;
    int step = 0;
 
    here.r = 1;
    here.c = 0;
    init_pos_stack(&s, INITIAL_POS_STACK_CAPACITY);
 
    draw_maze_frame(m, step, here.r, here.c);
    pause_animation(700);
 
    while (m->cell[here.r][here.c] != 'x') {
        int r = here.r;
        int c = here.c;
 
        step++;
 
        if (m->cell[r][c] != 'e') {
            m->cell[r][c] = '.';
        }
 
        push_location(&s, m, r - 1, c);
        push_location(&s, m, r + 1, c);
        push_location(&s, m, r, c - 1);
        push_location(&s, m, r, c + 1);
 
        draw_maze_frame(m, step, r, c);
        pause_animation(ANIMATION_DELAY_MS);
 
        if (is_pos_empty(&s)) {
            printf("\n더 이상 갈 수 있는 곳이 없어서 탐색 실패입니다.\n");
            free_pos_stack(&s);
            return;
        }
 
        pop_pos(&s, &next);
        here = next;
    }
 
    draw_maze_frame(m, step, here.r, here.c);
    printf("\n출구 x 를 찾았습니다. 미로 탐색 성공!\n");
    free_pos_stack(&s);
}
 
void demo_maze_generation_and_search(void)
{
    Maze maze;
    int n;
 
    printf("\n[3. 동적 미로 생성 및 탐색 - 동적 스택 + 동적 미로 사용]\n");
    printf("설명: N 입력에 따라 N x N 미로를 동적으로 만들고, 도달 가능한 경로를 보장합니다.\n");
    printf("또한 탐색 중 필요한 위치를 동적 스택으로 관리합니다.\n");
 
    n = read_int("미로 크기 N을 입력하세요 (N x N, 5 이상): ");
    if (n < 5) {
        printf("N은 5 이상이어야 합니다.\n");
        return;
    }
 
    if (!init_maze(&maze, n)) {
        printf("미로 메모리 할당 실패\n");
        return;
    }
 
    if (!generate_connected_maze(&maze)) {
        printf("미로 생성 실패\n");
        free_maze(&maze);
        return;
    }
 
    printf("\n생성 직후 미로입니다. 이때 길은 0 으로 표시됩니다.\n\n");
    print_maze(&maze);
    printf("\n엔터를 누르면 미로 탐색 애니메이션을 시작합니다...");
    getchar();
 
    explore_maze(&maze);
    printf("\n엔터를 누르면 메뉴로 돌아갑니다...");
    getchar();
 
    free_maze(&maze);
}
 
void print_menu(void)
{
    printf("\n====================================================\n");
    printf(" 스택의 응용 실습 프로그램\n");
    printf("====================================================\n");
    printf("1. 괄호 검사 (전역 배열 스택)\n");
    printf("2. 중위 표기식 -> 후위 표기식 변환 및 계산 (구조체 배열 스택)\n");
    printf("3. 동적 미로 생성 및 탐색 (동적 스택 + 동적 미로)\n");
    printf("0. 종료\n");
    printf("====================================================\n");
}
 
int main(void)
{
    int menu;
 
    srand((unsigned int)time(NULL));
 
    while (1) {
        print_menu();
        menu = read_int("메뉴를 선택하세요: ");
 
        switch (menu) {
        case 1:
            demo_bracket_check();
            break;
        case 2:
            demo_infix_postfix_calc();
            break;
        case 3:
            demo_maze_generation_and_search();
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 메뉴입니다. 다시 선택하세요.\n");
        }
        system("pause");
        clear_screen();
    }
}