#include <stdio.h>
#include <stdlib.h> 

int sorted[1000000];
// 임시 배열을 main 안에 넣어서 동적으로 할당하는 방법도 생각해 볼 것. 


void m_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

// 합병정렬
int main() {
    int n;
    scanf("%d", &n);
    int * base = (int *)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &base[i]);
    }

    m_sort(base, 0, n-1);
    for(int i = 0; i < n; i++) {
        printf("%d ", base[i]);
    }

    free(base);
    return 0;
}

// 분할 & 정복 & 합병
void m_sort(int arr[], int left, int right) {
    if(left == right) return;
    int mid = (left + right) /2;

    m_sort(arr, left, mid);
    m_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

// 실제 정렬(리스트 합병)
void merge(int arr[], int left, int mid, int right) {
    int L, R, k, i;
    L = left;
    R = mid +1;
    k = left;

    while(L <= mid && R <= right) 
        sorted[k++] = (arr[L] <= arr[R]) ? arr[L++] : arr[R++];
    
    if(L > mid) {
        for(i = R; i <= right; i++)
            sorted[k++] = arr[i];
    } else {
        for(i = L; i <= mid; i++) 
            sorted[k++] = arr[i];
    }
    for(i = left; i <= right; i++) 
        arr[i] = sorted[i];

}