#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare (int a ,int b){
    return a > b;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int goal;
    cin >> goal;
    vector<int> v;

    for(int i = 0; i < N; i++){
        int temp ;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    
    int left = 0;
    int right = v[N-1];
    int ans =0 ;
    
    

    while(left <= right){
        int mid = (left+right)/2;
        int total = 0;
        for(int i = 0 ; i < N; i++){
            if(v[i] > mid)
                total += v[i] - mid ;
        }
        if(total >= goal){
            ans = mid;
            left = mid +1;
            
        }
        else{
            right = mid -1;
        }
    }

    cout << ans <<'\n';

    return 0;
}