#include <iostream>
#include <vector> 
#include <algorithm>
#include <climits>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    unordered_map<int, int>m;


    for(int i = 0 ; i < N ; i++){
        int a;
        cin >> a;
        m[a]++;
    }
    
    cin >> N;

    for(int i = 0 ; i < N ; i++){
        int a;
        cin >> a;
        cout << m[a] << ' ';
    }

    
    

    return 0;
}