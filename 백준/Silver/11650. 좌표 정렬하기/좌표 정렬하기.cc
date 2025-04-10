#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N ;
    vector<pair<int,int>> v;

    for(int i = 0 ; i < N ; i++){
        int a , b;

        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b){
        if(a.first == b.first){
            return b.second > a.second;
        }
        return a.first < b.first;
    });

    for( auto i : v){
        cout << i.first << " " << i.second <<'\n';
    }
    
    

    return 0;
}