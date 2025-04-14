#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <tuple>
using namespace std;

int N;

bool bf(vector<tuple<int,int,int>> &map){

    vector<int> dist(N+1);

    for(int i = 1 ; i<= N; i++){
        for(auto [s,e,t]: map){
            if(dist[e] > dist[s]+t ){
                dist[e] = dist[s]+t;
                if(i == N ){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while(test_case--){

        int  M , W;
        cin >> N >> M >> W;
    
        vector<tuple<int,int,int>> map;

        for(int i = 0 ; i < N ; i++){
            map.push_back({0,i+1,0});
        }
    
        for(int i = 0 ; i < M ; i++){
            int S,E,T;
            cin >> S >> E >> T;
            map.push_back({S,E,T});
            map.push_back({E,S,T});
        }
        for(int i = 0 ; i < W ; i++){
            int S,E,T;
            cin >> S >> E >> T;
            map.push_back({S,E,-T});
        }
    
        bool answer = bf(map);
        
        if(answer){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }

    }


    
    
    
    return 0;
}
