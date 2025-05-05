#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<pair<int,int>> v;

    for(int i = 0 ; i < N ; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    vector<vector<int>> dp(N, vector<int> (N,0));

    for(int length = 2 ; length < N+1 ; length++){
        for(int i = 0 ; i <= N-length ; i++){ //시작점
            int j = i + length -1;
            dp[i][j] = INT_MAX;

            for( int k = i ; k < j ; k++){
                int cost = dp[i][k] + dp[k+1][j] + v[i].first * v[k].second * v[j].second;
                dp[i][j] = min(dp[i][j] , cost);
            }
        }
    }
    
    cout << dp[0][N-1] << '\n';


    return 0;
}