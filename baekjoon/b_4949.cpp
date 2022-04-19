#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        char str[102];
        bool isBalance = true;
        stack<char> k;

        cin.getline(str, 102);
        int len = strlen(str);

        if(str[0] == '.' && len == 1) break;

        for(int i = 0; i<len; i++){

            if(str[i] == '(') k.push('(');
            else if(str[i] == ')'){
                if(!k.empty() && k.top() == '(') k.pop();
                else {
                    isBalance = false;
                    break;
                }
            } else if(str[i] == '[') k.push('[');
            else if(str[i] == ']') {
                if(!k.empty() && k.top() == '[') k.pop();
                else {
                    isBalance = false;
                    break;
                }
            }

        }

        if(k.empty() && isBalance) cout << "yes\n";
        else cout << "no\n";

    }


    return 0;
}
