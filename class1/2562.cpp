#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int max = 0;
    int inx=1,cnt = 1;
    int a;
    while(cnt != 11){
        if(max < a){
            max = a;
            inx = cnt;
        }
        cnt++;
    }
    cout << max <<'\n' << inx <<'\n';

    return 0;
}