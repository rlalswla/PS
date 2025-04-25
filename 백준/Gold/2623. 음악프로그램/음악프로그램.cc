#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N+1);
    vector<int> inputDegree(N+1,0);
    vector<int> answer;
    inputDegree[0]=-1;

    for (int i = 0; i < M; i++) {
        int cnt;
        cin >> cnt;
        vector<int> singers(cnt);
        for (int j = 0; j < cnt; j++) {
            cin >> singers[j];
        }
        for (int j = 0; j < cnt - 1; j++) {
            v[singers[j]].push_back(singers[j + 1]);
            inputDegree[singers[j + 1]]++;
        }
    }
    
    queue<int>q;
    for(int k = 1 ; k < N+1 ; k++ ){
        if(inputDegree[k] == 0){
            q.push(k);
        }
    }
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        answer.push_back(idx);
        for(auto it : v[idx]){
            inputDegree[it]--;
            if(inputDegree[it] == 0){
                q.push(it);
            }    
        }
    }

    if(answer.size() == N){
        for(auto i : answer){
            cout << i << '\n';
        }

    }
    else{
        cout << 0;
    }



    return 0;
}
