#include <iostream>
#include <vector> 
#include <algorithm>
#include <climits>

using namespace std;

bool bi(vector<int> &v, int value){
    int left = 0;
    int right = v.size()-1;
    int mid ;
    while(left <= right){
        mid = (left+right)/2;
        if(v[mid] == value){
            return true;
        }
        else if(v[mid] > value){
            right = mid-1;
        }else{
            left = mid+1;
        }

    }
    return false;


}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int min1, max1 ;
    vector<int>v;
    for(int i = 0 ; i < N ; i++){
        int a;
        cin >>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    cin >> N;
    

    for(int i = 0 ; i < N ; i++){
        int a;
        cin >>a;
        if(bi(v, a)){
            cout << 1 <<'\n';
        }
        else{
            cout << 0 <<'\n';
        }
    }
    

    
    

    return 0;
}