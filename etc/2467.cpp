#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector <int> numbers(N);
    for(int i = 0; i < N; i++){
        cin>>numbers[i];
    }
    sort(numbers.begin(), numbers.end());

    int left = 0;
    int right = N-1;
    int closes = INT_MAX;
    int ansleft=0;
    int ansright=0;

    while(left < right){        
        if(abs(closes) > abs(numbers[left] + numbers[right])){
            closes = numbers[left] + numbers[right];
            ansleft = left;
            ansright =right;
        }
        if(numbers[left] + numbers[right] > 0){
            right--;
        }
        else{
            left++;
        }
    }
    cout << numbers[ansleft] <<" "<< numbers[ansright] <<'\n';
    
    return 0;
}