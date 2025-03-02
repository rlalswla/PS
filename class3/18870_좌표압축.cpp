#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int,int>a , pair<int,int> b){
        return a.second < b.second;
}
int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int,int>> v;

    for(int i = 0; i < N; i++){
        int temp ;
        cin >> temp;
        v.push_back(make_pair(i,temp));
    }

    sort(v.begin(),v.end(),compare);

    vector<int> ans (N);

    int inx = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0 && v[i].second != v[i - 1].second) {
            inx++;
        }
        ans[v[i].first] = inx;
    }

    for (auto i : ans){
        cout << i << " " ;
    }
    return 0;
}