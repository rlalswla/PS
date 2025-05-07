#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K;
    cin >> N >> K;

    vector<pair<int,int>> v(N); // 보석 무게, 가치

    for (int i = 0; i < N ; i ++){
        int a,b;
        cin >> a >>b;
        v[i] = {a,b};
    }

    vector<int> backpack(K);

    for (int i = 0; i < K ; i ++){
        cin >> backpack[i];
    }

    sort(v.begin(), v.end());
    sort(backpack.begin(), backpack.end());

    int index = 0;
    priority_queue<int> q;
    long long ans = 0;


    for (int i = 0; i < K ; i ++){
        int limitWeigth = backpack[i];
        
        while (index < N && v[index].first <= limitWeigth) {
            q.push(v[index].second);
            index++;
        }
        

        if(!q.empty()){
            ans += q.top();
            q.pop();
        }
    }

    cout << ans;

    return 0;
}