#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, cnt;
    scanf("%d", &n);
    int *base = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++) scanf("%d", &base[i]);

    scanf("%d", &m);
    int *search = malloc(m*sizeof(int));

    for(int i = 0; i < m; i++) scanf("%d", &search[i]);


    for(int i = 0; i < m; i++) {
        cnt = 0;
        for(int j = 0; j < n; j++) {
            if(search[i] == base[j]) cnt++;
        }
        printf("%d\n", cnt);
    }

    free(base);
    free(search);
    return 0;
}