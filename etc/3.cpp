#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main (){
    int N;
    scanf("%d", &N);
    vector<pair<int,int>> hw;

    
    for(int i = 0; i < N; i++){
        int a;
        int b;
        scanf("%d %d", &a, &b);
        hw.push_back(make_pair(a,b));
    }

    for(auto i : hw){
        int count = 0;

        for(auto j : hw){
            if(j.first > i.first && j.second > i.second){
                count++;
            }
        }
        cout << count+1 <<' ';
    }


    return 0;
}