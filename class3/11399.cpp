#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector <int> v;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i = 0 ; i < N ;  i ++){
        ans += (N-i)*v[i];
    }
    cout <<ans <<'\n';

    return 0;
}