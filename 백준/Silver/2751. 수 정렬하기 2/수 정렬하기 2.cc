#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N ;
    cin >> N;

    set<int> s;

    for(int i = 0 ; i < N ; i ++){
        int a;
        cin >> a;
        s.insert(a);    
    }
    for(auto i : s){
        cout << i <<'\n';
    }



    return 0;
}