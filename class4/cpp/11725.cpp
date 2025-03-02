#include <vector>
#include <string>
#include <iostream>

using namespace std;



void dfs (int parent, vector<vector<int>> &tree, vector<int> &parentStore){
    for(auto i : tree[parent]){
        if(parentStore[i] == -1){
            parentStore[i] = parent;
            dfs(i, tree, parentStore);
        }
    }
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //노드 개수 
    int totalNodes;
    cin >> totalNodes;

    vector<vector<int>> tree(totalNodes+1);

    vector<int> parentStore(totalNodes+1, -1);
    
    for(int i = 0; i < totalNodes-1; i++){
        int a;
        int b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
   

    dfs(1, tree, parentStore);

    for(int i =2 ; i < parentStore.size(); i++ ){
        cout<<parentStore[i]<<'\n';
    }

    return 0;
}

