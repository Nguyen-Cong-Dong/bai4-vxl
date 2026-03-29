#include <stdio.h>
//code da toi uu theo toc do thuc hien
//do phuc tap ca 2 ham O(n)
void to_lower_c(char *s) {
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s = *s + 32;
        }
        s++;
    }
}

int str_to_int_c(const char *s) {
    int result = 0;
    while (*s) {
        result = result * 10 + (*s - '0');
        s++;
    }
    return result;
}

int main(void) {
    char s1[] = "Ky thuat VXL";
    char s2[] = "125";
    int value;

    printf("s1 ban dau            : %s\n", s1);
    to_lower_c(s1);
    printf("s1 sau khi viet thuong: %s\n", s1);

    printf("s2 chuoi              : %s\n", s2);
    value = str_to_int_c(s2);
    printf("Gia tri so cua s2     : %d\n", value);

    return 0;
}

