#include <cstdio>
#include <cstring>

inline bool is_digit(char c) { return c >= '0' && c <= '9'; }

inline int digit_to_int(char c) { return static_cast<int>(c - '0'); }

inline int char_to_int(char c) { return c - 'A' + 10; }

inline char int_to_char(int i) { return 'A' + i - 10; }

inline char int_to_digit(int i) { return '0' + i; }

int base_to_ten(char* number, int base) {
    int bs = 1;
    int tgt = 0;
    int val = 0;
    int str_len = strlen(number);
    for (int i = str_len - 1; i >= 0; --i) {
        if (is_digit(number[i])) {
            val = digit_to_int(number[i]);
        } else {
            val = char_to_int(number[i]);
        }
        tgt += val * bs;
        bs *= base;
    }
    return tgt;
}

int ten_to_base(int number, int base, char* buffer) {
    int pointer = 0;
    while (number > 0) {
        int remainder = number % base;
        char c = ' ';
        if (remainder >= 10) {
            c = int_to_char(remainder);
        } else {
            c = int_to_digit(remainder);
        }
        buffer[pointer++] = c;
        number /= base;
    }
    buffer[pointer] = '\0';
    return pointer;
}

int main() {
    char number[50];
    char buffer[50];
    int src_base = 0;
    int tgt_base = 0;
    scanf("%s %d %d", number, &src_base, &tgt_base);
    printf("Read %s\n", number);

    int tgt_val = base_to_ten(number, src_base);
    printf("%d\n", tgt_val);

    int buffer_len = ten_to_base(tgt_val, tgt_base, buffer);
    for (int i = buffer_len - 1; i >= 0; --i) {
        printf("%c", buffer[i]);
    }
    printf("\n");
}
