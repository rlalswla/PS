#include <iostream>

using namespace std;

int main (){
    int a,b,c,d;
    cin >> a >>b >> c >>d ;
    int row = (a-1) / (c+1);
    int col = (b-1)/(d+1);
    cout << (row+1)*(col+1);
}