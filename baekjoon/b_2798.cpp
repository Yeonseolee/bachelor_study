#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int n, m;
    vector<int> card;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int tmp; 
        cin >> tmp;
        card.push_back(tmp);
    }

    int maxSimilarM = 0;
    for(int i = 0; i< n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++) {

                int isM = card[i]+card[j]+card[k];

                if(isM <= m && maxSimilarM < isM){
                    
                    maxSimilarM = isM;

                }

            }
        }
    }

    cout << maxSimilarM;



    return 0;
}