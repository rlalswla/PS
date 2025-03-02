#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string N;
    cin >> N;
    int index;
    cin >> index;

    cout << N[index-1];

    return 0;
}