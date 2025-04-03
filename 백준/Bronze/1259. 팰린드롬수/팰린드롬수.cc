#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool pel(int a){
    string s = to_string(a);
    int start = 0;
    int end = s.length()-1;
    while(start < end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a;

    while(cin >> a ){
        if(a == 0){
            return 0;
        }
        if(pel(a) == false){
            cout <<"no"<<'\n';
        }else{
            cout <<"yes"<<'\n';
        }

    }

    return 0;
}