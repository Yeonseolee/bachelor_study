#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    int n;
    stack<int> sList;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string command;
        int data;
        cin >> command;

        if(command.compare("push") == 0) {
            cin >> data;
            sList.push(data);
        }
        else if(command.compare("pop") == 0) {

            if(sList.empty()) cout << "-1\n";
            else {
                cout << sList.top() << '\n';
                sList.pop();
            }
        } 
        else if(command.compare("size") == 0) {
            cout << sList.size() << '\n';
        }
        else if(command.compare("empty") == 0) {;
            cout << sList.empty() << '\n';
        }
        else if(command.compare("top") == 0) {
            if(sList.empty()) cout << "-1\n";
            else cout << sList.top() << '\n';
        }
    }

    return 0;
}