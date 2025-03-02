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
    
    int max1 = -1000001;
    int min1 = 1000001;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        max1 = max(max1, a);
        min1 = min(min1,a);
    }
    cout << min1 << " " << max1<<'\n';
    return 0;
}