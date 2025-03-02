#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin >> a>>b;
    unordered_map<string,int> m;

    for(int i = 0; i < a; i++){
        string s;
        cin >>s;
        m[s]++;
    }
    for(int i = 0; i < b; i++){
        string s;
        cin >>s;
        m[s]++;
    }
    vector<string> v;
    for(auto i : m){
        if(i.second == 2){
            v.push_back(i.first);
        }
    }
    sort(v.begin(), v.end());
    cout <<v.size() <<'\n';
    for(auto i : v){
        cout << i <<'\n';
    }


    return 0;
}