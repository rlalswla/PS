#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> takeTime;
vector<vector<int>> preBuild;
vector<int> dp;

int build(int goal){
    int maxValue = INT_MIN;
    if(dp[goal] != -1){
        return dp[goal];
    }    
    if(preBuild[goal].size() == 0){
        dp[goal] = takeTime[goal];
        return dp[goal];
    }

    for(auto i : preBuild[goal]){
        if(dp[i] == -1){
            int va = build(i);
            maxValue = max(va, maxValue);
        }else{
            maxValue = max(dp[i], maxValue);
        }
    }

    maxValue += takeTime[goal];
    dp[goal] = maxValue;
    return maxValue;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for(int i = 0 ; i < T; i ++){

        int N, K;
        cin >> N >> K;

         takeTime.assign(N+1 , -1);
         preBuild.assign(N+1,{});

         dp.assign(N+1, -1);

        for(int j = 1 ; j <= N ; j++){
            cin >> takeTime[j];
        }

        for(int j = 0 ; j < K ; j++){
            int a,b;
            cin >> a >>b;
            preBuild[b].push_back(a);
        }

        int goal;
        cin >> goal;

        cout << build(goal) << '\n';



    }
    

    
    return 0;
}
