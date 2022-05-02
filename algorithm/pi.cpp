#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> getPartialMarch(const string& N){
    int m = N.size();
    vector<int> pi(m, 0);

    for(int begin = 1; begin < m; begin++){
        for(int i = 0; i+begin < m; i++){
            if(N[begin + i] != N[i]) break;
            cout << "begin : " << begin << " | i : " << i << "\n";
            cout << "N[begin + i] = " << "N["<< begin+i <<"] : " << N[begin + i] << " | N[i] = " << "N[" << i << "] : "<< N[i] << '\n';
            cout << "pi[begin + i] = " << "pi[" << begin+i << "] : " << pi[begin + i] << " | i + 1 = " << i+1 << " : " << i + 1 << "\n\n";
            pi[begin + i] = max(pi[begin + i], i+1);
        }
    }
    return pi;
}

int main(void) {
    string tmp = "aabaabac";
    vector<int> pi = getPartialMarch(tmp);
    for(int i = 0; i <pi.size(); i++) {
        cout << i << " | " << pi[i] << "\n";
    }
    
    return 0;
}