#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string a,b;
    cin >> a>> b;

    int ans = INT_MAX;


    for(int start = 0 ; start <= b.length() - a.length(); start++){
        int cnt = 0;
        for(int i = 0 ; i < a.length(); i++){
            if(a[i] != b[i+start]){
                cnt++;
            }
        }
        ans = min(cnt,ans);
    }
    cout << ans;



    return 0;
}