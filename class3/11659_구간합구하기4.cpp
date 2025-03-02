#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int time;
    cin >> time;

    vector<int> v;

    for(int i = 0; i < N; i++){
        int temp;
        cin>>temp;
        if(i != 0){
            v.push_back(temp+v[i-1]);
        }
        else{
            v.push_back(temp);
        }
    }
    for(int i = 0 ; i < time ; i++){
        int a,b;
        cin >>a >>b;
        int ans;
        if(a == 1){
            ans = v[b-1];
        }else{
            ans = v[b-1] - v[a-2];
        }
        cout << ans <<'\n';
    }



    return 0;
}