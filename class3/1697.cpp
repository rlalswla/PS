#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;

    int subin, dong;
    cin >> subin >>dong;
    
    queue <int> q;
    q.push(subin);

    vector<int> cnt (100001,INT_MAX);
    cnt[subin] = 0;

    while(!q.empty()){
        
        int nowsubin = q.front();
        if(nowsubin == dong){
            cout << cnt[nowsubin] << '\n';
            return 0;
        }
        q.pop();
        if(nowsubin < 100000 && cnt[nowsubin+1] > cnt[nowsubin] + 1){
            cnt[nowsubin + 1] = cnt[nowsubin]+1;
            q.push(nowsubin + 1);
        }
        if(nowsubin >= 1 && cnt[nowsubin-1] > cnt[nowsubin] + 1){
            cnt[nowsubin -1] = cnt[nowsubin]+1;
            q.push(nowsubin -1);
        }
        if(nowsubin < 50001 && cnt[nowsubin*2] > cnt[nowsubin] + 1){
            cnt[nowsubin *2] = cnt[nowsubin]+1;
            q.push(nowsubin*2);
        }
    }

    return 0;
}