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

int _start() {
    print("hi! :)");
    const char * flag = "sup3rs3cr3tfl4g";
    int flag_len = strlen(flag);
    char * in = input_prompt("flag: ");
    for (int i = 0; i < flag_len; i++) {
        if (flag[i] != in[i])
            exit(1);
    }
    exit(0);
}
