#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n, tmp;
    stack<int> num;
    cin >> n;
    
    for(int i = 0; i<n; i++){
        cin >> tmp;

        if(tmp == 0) {
            num.pop();
        }
        else num.push(tmp);
    }

    
    if(num.empty()){
        cout << 0;
    }
    else
    {   
        tmp = 0;
        while(!num.empty())
        {   
            tmp += num.top();
            num.pop();
        }

        cout << tmp;
    }
}