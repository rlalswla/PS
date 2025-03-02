#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    scanf("%d", &N);
    priority_queue<int , vector<int>, greater<int>> pq;
    
    for(int i = 0; i < N; i++){
        int a ;
        cin >> a ;
        pq.push(a);
    }

    int budget;
    cin >>budget;
    int ans;

    while(!pq.empty()){
        if(pq.top() >= budget/N ){
            cout << budget/N;
            return 0;
        }
        else{
            budget = budget - pq.top();
            ans = pq.top();
            pq.pop();
            N--;
        }
    }
    
    cout << ans;
    return 0;
}