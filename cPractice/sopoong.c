#include <stdio.h>
#include <stdio.h>

int main() {
    char YesOrNo = 'y';

    while(YesOrNo == 'y'){
        int N, sum = 0;
        printf("\nEnter integer value: ");
        scanf("%d", &N);

        for(; N > 0; N--) sum += N;

        printf("result is : %d\n", sum);
        printf("Do you want to run the program again? : ");
        scanf(" %c", &YesOrNo);
        if(YesOrNo == 'n') break;
    }

    return 0;
}
