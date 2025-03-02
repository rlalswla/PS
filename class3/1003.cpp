#include <vector>
#include <string>
#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int,int>> dp(41);
    dp[0] = {1,0};
    dp[1]= {0,1};

    int N;
    cin >> N;
    for(int i = 2; i < 41 ; i++){
        dp[i].first = dp[i-1].first + dp[i-2].first;
        dp[i].second = dp[i-1].second + dp[i-2].second;
    }

    for(int i = 0; i < N; i++){
      
        
        int a;
        cin >> a;
        cout << dp[a].first << " " << dp[a].second << '\n';
    }

    return 0;
}