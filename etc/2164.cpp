#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

int main (){
    int N;
    scanf("%d", &N);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque < int > cards;
    for(int i = 1; i < N+1; i++){
        cards.push_back(i);
    }

    bool discard = true;
    while(!(cards.size() == 1)){
        if ( discard == true ){
            cards.pop_front();
            discard = false;
        }
        else{
            int temp = cards.front();
            cards.pop_front();
            cards.push_back(temp);
            discard = true;
        }
    }
    cout << cards[0];
    return 0;
}