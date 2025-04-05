#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int N;
    cin >> N;
    vector<pair<int,string>> v;

    for(int i = 0; i < N; i++){
        int age;
        string name;
        cin >> age ;
        cin >> name ;
        v.push_back(make_pair(age, name));
    }

    stable_sort(v.begin(), v.end(), [](auto i , auto j){
        return i.first < j.first;
    });

    for(auto i : v){
        cout << i.first << ' '  << i.second <<'\n';
    }
    

    return 0;
}