#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N, M;
int ans = INT_MAX;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N ,M;
    cin >> N >> M;
    vector<int> v;
    vector<int> u;

    for(int i = 0 ; i < N ; i++){
        int temp ;
        cin >> temp;
        v.push_back(temp);
    }

    for(int i = 0 ; i < N ; i++){
        int temp ;
        cin >> temp;
        u.push_back(temp);
    }

    vector<pair<int,int>> table;

    for(int i = 0 ; i < N ; i++){
        table.push_back({v[i], u[i]});    
    }

    // sort(table.begin(), table.end(), [](pair<int,int> & a, pair<int,int> &b){
    //     if(a.second == b.second){
    //         return a.first > b.first;
    //     }
    //     return a.second < b.second;
    // });

    vector<int>dp(10001,0);
  
    for(int i = 0 ; i < N ; i++){
         for(int j = 10001 ; j >= 0 ; j--){
            if(j >= table[i].second)
            dp[j] = max(dp[j], dp[j-table[i].second]+ table[i].first);
         }
    }


    for(int i = 0 ; i < 10001 ; i++){
        if(dp[i] >= M){
            cout << i ;
            return 0 ;
        }
   }
    
   return 0;
}
