#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

// 최대공약수(GCD) 구하는 함수 - 유클리드 호제법 이용
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 최소공배수(LCM) 구하는 함수
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b; 
    cin >> a >> b;
    
    cout << gcd(a, b) << '\n';
    cout << lcm(a, b) << '\n';
    
    return 0;
}