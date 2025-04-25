#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

long long ans = 1e18; //합친 값
long long aa,bb,cc; // 각각의 값
vector<long long> v;
long long N;

bool closer(long long a, long long b){
    if(a < 0 ){
        a = -a;
    }
    if( b < 0){
        b = -b;
    }
    return a < b;
}


void twoPointer(long long index){
    long long value  = v[index];


    long long left = index+1;
    long long right = N-1;
    

    
    while(left < right){
        if(value == v[left]){
            left++;
            continue;
        }else if(value == v[right]){
            right--;
            continue;
        }

        long long temp = value + v[left] + v[right];
        if(temp == 0){
            aa = value;
            bb = v[left];
            cc = v[right];
            vector<long long> result = {aa, bb, cc};
            sort(result.begin(), result.end());
            cout << result[0] << " " << result[1] << " " << result[2];
            return;
        }
        if(closer(temp,ans)){
            ans = temp;
            aa = value;
            bb = v[left];
            cc = v[right];
            
        }
        if(temp > 0){
            right--;
        }else{
            left++;
        }
       
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    v.resize(N);

    for(long long i = 0 ; i < N ; i++){
        cin >> v[i];
    }
     
    sort(v.begin(), v.end());

    for(long long i = 0 ; i < N ; i++){
        twoPointer(i);
    }

    vector<long long> result = {aa, bb, cc};
            sort(result.begin(), result.end());
            cout << result[0] << " " << result[1] << " " << result[2];



    return 0;
}
