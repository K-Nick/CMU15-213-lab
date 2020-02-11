#include<stdio.h>

int main() {
    int a, b;
    a = 228;
    printf("%x %x\n", a>>31, a^(a>>31));
    printf("%d %d\n", a>>31, a^(a>>31));
    return 0;
}