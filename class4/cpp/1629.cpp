#include <vector>
#include <string>
#include <iostream>

using namespace std;

long long divsqu(long long a, long long b, long long c){
    if (b == 0) return 1; 
    if (b == 1) return a % c;

    long long half = divsqu(a,b/2,c);
    long long res  = half*half%c;

    if(b%2 == 1){
        res = res*a;
        res = res%c;
    }
    return res;
    
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;
    
    cout << divsqu(a,b,c) << '\n';


    return 0;
}