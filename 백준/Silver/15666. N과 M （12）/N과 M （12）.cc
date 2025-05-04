#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N, M;
vector<int> v;

vector<int> seq;


void btrk(int start, int depth){
    if(depth == M){
        for(auto it : seq){
            cout << it << " ";
        }
        cout << '\n';
        return ;
    }

    for(int i = start ; i < N ; i++){
        seq.push_back(v[i]);
        btrk(i, depth+1);
        seq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    N = v.size();
    
    btrk(0,0);


    return 0;
}
