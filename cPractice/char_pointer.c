#define _CRT_SECURE_NO_WARNINGS    // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>

int main()
{
    int a = 1, *b;
    char *s1 = "hello";
    b = &a;
    printf("%d\n", b);
    printf("%d\n", b+1);
    printf("%s\n", s1);
    printf("%s\n", s1+1);

    char s2[5] = "abcd";
    printf("%d %d\n", sizeof(s1), sizeof(s2));
    printf("%s", s2[4]);
    return 0;
}