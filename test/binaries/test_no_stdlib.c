#include <sys/types.h>
#include <stdarg.h>

#define NULL 0
#define BOOL int
#define TRUE 1
#define FALSE 0

void write(int fd, const void *buf, size_t size)
{
    ssize_t ret;
    asm volatile
    (
        "syscall"
        : "=a" (ret)
        : "0"(1), "D"(fd), "S"(buf), "d"(size)
        : "rcx", "r11", "memory"
    );
}

void read(int fd, void *buf, size_t size)
{
    ssize_t ret;
    asm volatile
    (
        "syscall"
        : "=a" (ret)
        : "0"(0), "D"(fd), "S"(buf), "d"(size)
        : "rcx", "r11", "memory"
    );
}

void exit(int code)
{
    ssize_t ret;
    asm volatile
    (
        "syscall"
        : "=a" (ret)
        : "0"(60), "D"(code)
        : "rcx", "r11", "memory"
    );
}


size_t strlen(const char * str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

#define print(...) print_raw(__VA_ARGS__, "\n")
#define print_raw(...) print_raw(__VA_ARGS__, NULL)
void (print_raw)(const char * str, ...) {
    va_list args;
    va_start(args, str);
    write(1, str, strlen(str));
    char * arg;
    while (arg = va_arg(args, char *))
        write(1, arg, strlen(arg));
    va_end(args);
}

/*void (print)(const char * str, ...) {
    print_raw(str);
    print_raw("\n");
}*/

char getchar() {
    static char buf[1];
    read(0, buf, 1);
    return buf[0];
}

char * input() {
    static char buf[2048];
    static int buf_pos = 0;

    char * out_ptr = buf + buf_pos;
    char c;
    while ((c = getchar()) >= ' ')
        buf[buf_pos++] = c;
    buf[buf_pos++] = '\0';
    return out_ptr;
}

char * input_prompt(const char * prompt) {
    print_raw(prompt);
    input();
}


#define swap(a, b) a ^= b ^= a ^= b

char * int_to_string(int in) {
    static char buf[2048];
    static int buf_pos = 0;

    int initial_buf_pos = buf_pos;

    if (in == 0) {
        buf[buf_pos++] = '0';
        buf[buf_pos++] = '\0';
        return buf + initial_buf_pos;
    }
    BOOL negative = in < 0;
    int n = negative ? -in : in;
    int pos = 0;
    while (n > 0) {
        buf[buf_pos++] = n % 10 + '0';
        n /= 10;
    }
    if (negative)
        buf[buf_pos++] = '-';
    for (int i = 0; i < (buf_pos - initial_buf_pos) / 2; i++) {
        /*int tmp = buf[i];
        buf[i] = buf[buf_pos-1-i];
        buf[buf_pos-1-i] = tmp;*/
        swap(buf[initial_buf_pos + i], buf[buf_pos-1-i]);
    }
    buf[buf_pos++] = '\0';
    return buf + initial_buf_pos;
}

int string_to_int(char * str) {
    BOOL negative = *str == '-';
    if (negative)
        str++;

    int out = 0;
    for (char * c = str; *c != '\0'; c++) {
        out *= 10;
        out += *c - '0';
    }
    return negative ? -out : out;
}

char * bin(int n) {
    static char buf[2048];
    static int buf_pos = 0;

    char * out_ptr = buf + buf_pos;

    buf[buf_pos++] = '0';
    buf[buf_pos++] = 'b';
    BOOL non_zero = 0;
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        int b = n >> i & 1;
        non_zero |= b;
        if (non_zero)
            buf[buf_pos++] = b + '0';
    }
    if (!non_zero)
        buf[buf_pos++] = '0';
    buf[buf_pos++] = '\0';

    return out_ptr;
}

void calc() {
    char buf[32];
    print("Calculator! Ops: '+', '-', '*', '/'");
    int a = string_to_int(input_prompt("First numer: "));
    char * op = input_prompt("Operation: ");
    int b = string_to_int(input_prompt("Second numer: "));
    int res;
    switch (op[0]) {
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/': res = a / b; break;
    }
    print(int_to_string(a), " ", op, " ", int_to_string(b), " = ", int_to_string(res));
}

unsigned bitwise_and(unsigned a, unsigned b) {
    return a & b;
}

unsigned bitwise_or(unsigned a, unsigned b) {
    return a | b;
}

unsigned bitwise_xor(unsigned a, unsigned b) {
    return a ^ b;
}

void calc_bitwise() {
    char buf[32];
    print("Calculator! Ops: '&', '|', '^'");
    unsigned a = string_to_int(input_prompt("First numer: "));
    char * op = input_prompt("Operation: ");
    unsigned b = string_to_int(input_prompt("Second numer: "));
    unsigned (*fun)(unsigned, unsigned);
    switch (op[0]) {
        case '&': fun = bitwise_and; break;
        case '|': fun = bitwise_or; break;
        case '^': fun = bitwise_xor; break;
    }
    unsigned res = fun(a, b);
    print(int_to_string(a), "(", bin(a), ") ", op, " ", int_to_string(b), "(", bin(b), ") = ", int_to_string(res), "(", bin(res), ")");
}

int get_square() {
    int n = string_to_int(input_prompt("Insert a number to square: "));
    switch (n) {
    case 1:  return 1*1;
    case 2:  return 2*2;
    case 3:  return 3*3;
    case 4:  return 4*4;
    case 5:  return 5*5;
    case 6:  return 6*6;
    case 7:  return 7*7;
    case 8:  return 8*8;
    case 9:  return 9*9;
    case 10: return 10*10;
    case 11: return 11*11;
    case 12: return 12*12;
    case 13: return 13*13;
    case 14: return 14*14;
    case 15: return 15*15;
    case 16: return 16*16;
    case 17: return 17*17;
    case 18: return 18*18;
    case 19: return 19*19;
    case 20: return 20*20;
    case 21: return 21*21;
    }
    return -1;
}

int _start() {
    char buf[32];
    print("ciao!");
    int a = 2;
    a += 5;
    a *= 7;
    a /= 3;
    print(int_to_string(a));
    print(int_to_string(-a));
    char * in = input_prompt("Insert a number: ");
    print("Your number was ", in);
    int n = string_to_int(in);
    print("Your number times 2 is equal to ", int_to_string(n * 2));
    calc();
    calc_bitwise();
    print("Square: ", int_to_string(get_square()));
    exit(42);
}