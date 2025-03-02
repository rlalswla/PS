#include <vector>
#include <string>
#include <iostream>

using namespace std;
int N;
int ans =0;

void dfs(int number){
    if(number ==  N){
        ans ++;
    }
    else if(number > N){
        return ;
    }
    dfs(number+1);
    dfs(number+2);
    dfs(number+3);
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        ans =0;
        cin >>N;
        dfs(0);
        cout << ans <<'\n';
    }
    
    
    
    

    return 0;
}