solution.c
2022-04-09 16:58:36
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>




// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* call) {

    char forSplit[1000];
    strcpy(forSplit, call);
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(1000);
    int call_len = strlen(call);
    int pLen = 0;
    char * pattern = (char *)malloc(sizeof(char)*1000);


    for(int i = 1; i<=call_len; i++ ){

        int cnt = 0;

        char * tmp = (char *)malloc(sizeof(char)*i);
        // tmp = '';
        int s = 0;
        for(int k = s; k < s+i; k++){
            strcat(tmp,&forSplit[k]);
            pattern = tmp;
        }
        for(int j = 0; j < call_len-i; j++){

            char comp[1000] = '\0';
            strncpy(comp, forSplit[j], i);
            if(tmp == comp) {
                cnt += 1; 
            }

        }
        free(tmp);

        if(cnt >= pLen){
            pLen = cnt;
            pattern = tmp;
        }
        s++;


    }


    // split
    char * ptr = strtok(forSplit, pattern);
    while(ptr != NULL){
        strcpy(answer, ptr);
        ptr = strtok(NULL, pattern);
    }
    return answer;
}
