#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    char ** s = new char*[n];
    for(int i = 0; i<n; i++){
        s[i] = new char[50];
        cin >> s[i];
    }

    for(int i = 0; i < n; i++) {
        
    }
}