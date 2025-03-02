#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int computers ;
    cin >> computers;
    int N;
    cin >> N;
    
    vector<vector<int>>v(computers+1);

    for(int i = 0 ; i < N ; i ++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;

    q.push(1);

    vector<bool> visited(computers+1,false);
    visited[1]=true;
    int cnt=0;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(auto i : v[a]){
            if(visited[i] == false){
                visited[i] =true;
                cnt++;
                q.push(i);
            }
        }
    }
    cout << cnt;
    return 0;
}