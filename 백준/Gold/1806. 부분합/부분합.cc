#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    cin >> N >>S ;

    vector<int> seq;
    for(int i = 0 ; i < N ; i++){
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }
    int left = 0;
    int right = 0;

    int sum = seq[0];
    int shortest = INT_MAX;

    if(seq[0] > S){
        cout << 1;
        return 0;
    }

    while(right != N){
        if(sum < S){
            right++;
            sum += seq[right];
        }
        else{
            if(right-left+1 < shortest){
                shortest = right-left+1;
            }
            sum -= seq[left];
            left++;
        }
    }

    if(shortest == INT_MAX){
        cout << 0 ;
        return 0;
    } else{
        cout << shortest;
        return 0;
    }

    

    
    
    return 0;
}
