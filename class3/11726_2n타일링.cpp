#include <vector>
#include <string>
#include <iostream>

using namespace std;
vector<int>dp;

int fibonacci(int n){
    if(dp[n] != -1)
        return dp[n];
    int temp = (fibonacci(n-1) + fibonacci(n-2)) % 10007;
    dp[n]=temp;
    // cout <<temp <<" ";
    return temp;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    dp.resize(N+2, -1);
    dp[0]=1;
    dp[1]=1;
    cout << fibonacci(N) <<'\n';

    
    return 0;
}