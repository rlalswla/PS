#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
            int a,b,c;
            cin>>a>>b>>c;
            vector<int> v;
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            sort(v.begin(), v.end());
            if(v[0] == 0 && v[2] == 0){
                return 0;
            }
                
            if(v[2]*v[2] == v[1]*v[1] +v[0]*v[0] ){
                cout <<"right" <<'\n';
            }
            else{
                cout <<"wrong" <<'\n';
            }
        
    }
    

    return 0;
}