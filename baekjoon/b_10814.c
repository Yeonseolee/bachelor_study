#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, *base, *search, cnt = 0;

    scanf("%d", &n);
    printf("%d\n", n);
    base = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d ", &base[i]);

    scanf("%d", &m);
    printf("%d\n", m);
    
    search = (int*)malloc(m*sizeof(int));
    for(int i = 0; i < m; i++) scanf("%d ", &search[i]);

    for(int i = 0; i < n; i++) printf("%d ", base[i]);
    printf("\n\n");
    for(int i = 0; i < m; i++) printf("%d ", search[i]);

    for(int i = 0; i < m; i++) {
        for(int j = 0; i < n; j++) {
            printf("search[%d] is: %d  |  base[%d] is: %d\n",i, j, search[i], base[j]);
            if(search[i] == base[j]) cnt++;
        }
        printf("\n\n");
        printf("%d\n", cnt);
    }

    free(base); free(search);
    return 0;
}