#include <stdio.h>
//Da toi uu
//O(n)
void to_lower_asm(char *s) {
    __asm__ volatile (
        ".intel_syntax noprefix\n"
        "mov rdi, %[p]\n"           // rdi = con tro den dau chuoi
        "L1:\n"
        "mov al, byte ptr [rdi]\n"  // lay 1 ky tu
        "test al, al\n"             // neu = 0 thi ket thuc
        "jz L2\n"
        "cmp al, 'A'\n"             // neu < 'A' thi bo qua
        "jb L3\n"
        "cmp al, 'Z'\n"             // neu > 'Z' thi bo qua
        "ja L3\n"
        "add al, 32\n"              // 'A'..'Z' -> 'a'..'z'
        "mov byte ptr [rdi], al\n"  // ghi lai vao chuoi
        "L3:\n"
        "inc rdi\n"
        "jmp L1\n"
        "L2:\n"
        ".att_syntax prefix\n"
        :
        : [p] "r"(s)
        : "rdi", "rax", "memory"
    );
}

int str_to_int_asm(const char *s) {
    int result;
    __asm__ volatile (
        ".intel_syntax noprefix\n"
        "xor eax, eax\n"              // result = 0
        "mov rdi, %[p]\n"             // rdi = con tro den chuoi so
        "L4:\n"
        "movzx edx, byte ptr [rdi]\n" // edx = s[i]
        "test dl, dl\n"               // gap '\0' thi dung
        "jz L5\n"
        "sub edx, '0'\n"              // doi '0'..'9' -> 0..9
        "lea eax, [eax + eax*4]\n"    // eax = old*5
        "lea eax, [edx + eax*2]\n"    // eax = digit + old*10
        "inc rdi\n"
        "jmp L4\n"
        "L5:\n"
        ".att_syntax prefix\n"
        : "=&a"(result)
        : [p] "r"(s)
        : "rdi", "rdx", "memory"
    );
    return result;
}

int main(void) {
    char s1[] = "Ky thuat VXL";
    char s2[] = "125";
    int value;

    printf("s1 ban dau            : %s\n", s1);
    to_lower_asm(s1);
    printf("s1 sau khi viet thuong: %s\n", s1);

    printf("s2 chuoi              : %s\n", s2);
    value = str_to_int_asm(s2);
    printf("Gia tri so cua s2     : %d\n", value);

    return 0;
}