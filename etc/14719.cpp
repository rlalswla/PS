#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int W,H;
    cin >> H >> W;
    
    int answer =  0 ;

    vector<int> heights;

    for(int i = 0; i < W ; i++){
        int temp;
        cin >> temp;
        heights.push_back(temp);
    }

    for(int i = 0 ; i < W ; i++){
        int left = *max_element(heights.begin(), heights.begin()+i);
        int right = *max_element(heights.begin()+i+1, heights.end());
        int water = min (left,right);
        if(water > heights[i])
            answer += water - heights[i];
    }

    cout << answer <<'\n';
    return 0;
}