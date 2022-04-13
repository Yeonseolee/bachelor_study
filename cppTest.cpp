#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 백준 9012번. 잘 푼 것 확인할 것. 피드백 필요
int main(void) {
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        stack<char> evalVps;
        string x, answer;
        int stop = 1;
        cin >> x;
        for(char element : x){

            if(evalVps.empty() && element == ')'){
                
                stop = 0;

            } else {

                if(element == '(') evalVps.push(element);
                else if(element == ')') evalVps.pop();

            }
        }
        if(evalVps.empty() && (stop != 0)){
            answer = "YES";
        } else answer = "NO";

        cout << answer << endl;

    }


    return 0;
}
