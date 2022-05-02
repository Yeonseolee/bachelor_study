#include <iostream>

using namespace std;


// int arr[32768][32768];

int visited = 0;
int ans = 0;

// x, y = 시작 위치
void check(int n, int x, int y, int r, int c){
    
    if(n == 1){
        int a = (r-y) * 2;
        int b = (c-x);
        visited += a + b;
        return ;
    }

    int mid = 1 << (n-1);
    int yComp = mid + y;
    int xComp = mid + x;
    // n1
    if( r < yComp && c < xComp){
        cout << "n1 ";
        check(n-1, x, y, r, c);
    } // n2
    else if(r < yComp && c >= xComp){
        cout << "n2 ";
        visited += (1 << 2*(n-1));
        check(n-1, x+mid, y, r, c);
    } // n3
    else if(r >= yComp && c < xComp){
        cout << "n3 ";
        visited += (1 << 2*(n-1))*2;
        check(n-1, x, y+mid, r, c);
    } // n4
    else if(r >= yComp && c >= xComp){
        cout << "n4 ";
        visited += (1 << 2*(n-1))*3;
        check(n-1, x+mid, y+mid, r, c);
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, c;
    cin >> n >> r >> c;

    check(n, 0, 0, r, c);
    cout << '\n';
    cout << visited;
    return 0;
} 