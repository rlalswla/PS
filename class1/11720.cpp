#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string a;
    cin >> a;
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += a[i]-'0';
    }
    cout <<ans <<'\n';

    return 0;
}