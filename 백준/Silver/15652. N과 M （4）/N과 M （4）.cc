#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N, M;
vector<int> seq;


void btrk(int start, int depth){
    if(depth == M){
        for(auto it : seq){
            cout << it << " ";
        }
        cout << '\n';
        return ;
    }

    for(int i = start ; i < N+1 ; i++){
        seq.push_back(i);
        btrk(i, depth+1);
        seq.pop_back();
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    cin >> N >> M;

    btrk(1,0);


    return 0;
}
