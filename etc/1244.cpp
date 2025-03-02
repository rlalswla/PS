#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main (){
    int N; //스위치 개수
    scanf("%d", &N);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> switchs;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        switchs.push_back(temp);
    }
    
    int n;
    cin >> n;
    vector <pair<int,int>> peoples(n);
    for(int i = 0 ; i < n ; i ++){
        int sex, num;
        cin >> sex >>num;
        num = num-1;
        // 남자일때 
        if(sex == 1){
            num = num +1;
            for( int j = 1 ; j < N ; j++){
                if(num*j-1 > N-1){
                    break;
                }
                else{
                    switchs[num*j-1] = !switchs[num*j-1];
                }
            }
            
        }
        //여자일때
        else if(sex == 2){
            int left = num;
            int right = num;
            switchs[num] = !switchs[num]; // Toggle the central switch

            while(true){
                left--;
                right++;
                if(left < 0 || right >= N) break;
                if(switchs[left] == switchs[right]){
                    switchs[left] = !switchs[left];
                    switchs[right] = !switchs[right];
                } else {
                    break;
                }
            }
        }
    }
    
    // Output the switch states with 20 per line
    for(int i = 0; i < N; i++){
        cout << switchs[i] << ' ';
        if((i + 1) % 20 == 0) cout << '\n';
    }



    return 0;
}