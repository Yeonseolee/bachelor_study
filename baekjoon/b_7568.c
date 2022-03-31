#include <stdio.h>

// 배열의 순서는 변하지 않고 새로운 순서를 만들어내야함. 

int main() {
    int n, base[50][2], cnt[50] = {0};
    scanf("%d", &n);
    for(int i = 0; i<n; i++) scanf("%d %d", &base[i][0], &base[i][1]);

    for(int i = 0; i< n; i++) {
        for(int j = 0; j < n; j++) {
            if(base[i][0] < base[j][0] && base[i][1] < base[j][1])
                cnt[i] += 1;
        }
    }

    for(int i = 0; i< n; i++) printf("%d ", cnt[i]+1);
}