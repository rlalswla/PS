#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector <int> v(6,0);
    for(int i = 0; i < 6; i++){
        int a;
        cin >> a;
        v[i] = a;
        
    }
    int shirts,pens;
    cin >> shirts >>pens;

    int ans=0;
    for(auto it : v){
        ans += (it + shirts -1)/shirts;
    }
    cout <<ans <<'\n';
    cout << N/pens <<" "  << N % pens <<'\n';

    return 0;
}