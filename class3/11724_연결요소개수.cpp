#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector <bool> visited(1001,false);
int ans = 0;

void dfs(vector<vector<int>> &v , int index ){
    visited[index] = true;
    for(auto it : v[index]){
        if(visited[it] == false){
            dfs(v,it);
        }
    }
    
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int lines;
    cin >> lines;
    
    vector<vector<int>> v(N+1);
    for(int i = 0 ; i < lines ; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1 ; i < N+1 ; i++){
        if(visited[i] == false){
            dfs(v,i);
            ans++;
        }
    }
    cout << ans << '\n';


    return 0;
}