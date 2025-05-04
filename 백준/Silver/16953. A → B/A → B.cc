#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N, M;
int ans = INT_MAX;
void bfs(int N , int M, int index){
    if( N  > M ){
        ans = -1;
        return;
    }
    if(N == M ){
        ans = min(ans, index);
        return;
    }
    string s = to_string(M);

    char c = s[s.length() - 1];
    if( c == '1'){
        if(s.length() == 1 ) return;
        string temp = s.substr(0, s.length()-1);
        int t = stoi(temp);
        bfs(N, t, index+1);
    }
     if(M %2 == 0){
        bfs(N, M/2, index+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    cin >> N >> M;
    
    bfs(N,M,1);
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}
