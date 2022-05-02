#include <iostream>

using namespace std;

unsigned int set = 0;

void add(int x){
    set |= (1 << x);
}

void remove(int x){
    set &= ~(1 << x);
}

int check(int x){
    return (set & (1<<x)) ? 1 : 0;
}

void toggle(int x){
    if(check(x)) remove(x);
    else add(x);
}

void all(void){
    set = (1<<21)-1;
}

void empty(void){
    set = 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;
    for(int i = 0; i<n; i++){
        char command[7];
        cin >> command;

        if(command[1] == 'l') all();
        else if(command[1] == 'm') empty();
        else {
            cin >> x;
            if(command[1] == 'd') add(x);
            else if(command[1] == 'e') remove(x); 
            else if(command[1] == 'h') cout << check(x) << '\n';
            else if(command[1] == 'o') toggle(x);
        }
        
    }

    return 0;
}

