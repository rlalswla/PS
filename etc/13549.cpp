#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int dp[100001];

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    int subin, dong;
    cin >> subin >> dong;

    if( subin == dong){
        cout << 0 <<'\n'; 
        return 0;
    }

    fill(dp, dp+100001, INT_MAX);
    
    deque<pair<int, int>> q;
    q.push_front(make_pair(subin,0));

    dp[subin] = 0;

    while(!q.empty()){
        int now  = q.front().first;
        int time = q.front().second;
        q.pop_front();

        if( now == dong){
            cout << time <<'\n';
            return 0;
        }

        if(now*2 <= 100000 && dp[now*2]>time){
            dp[now*2] =time;
            q.push_front(make_pair(now*2,time));
        }

        if(now-1 >= 0 && dp[now-1]>time+1){
            dp[now-1] =time+1;
            q.push_back(make_pair(now-1,time+1));
        }
        if(now+1 <= 100000 && dp[now+1]>time+1){
            dp[now+1]  = time+1;
            q.push_back(make_pair(now+1,time+1));
        }
        
    }


    return 0;
}