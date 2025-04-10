#include <unordered_map>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

#define I_MAX 100000000

vector<int> dijk(vector<vector<int>> &graph, int start){
    vector<int>  dist(graph.size(),I_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;
    q.push({0,start});

    while(!q.empty()){

        int start = q.top().second;
        int weight = q.top().first;
        q.pop();
        
        for(int it = 0 ; it < graph.size() ; it++){
            if(graph[start][it] != I_MAX){
                if((dist[it] > weight + graph[start][it])){
                    q.push({weight+graph[start][it], it});
                    dist[it] = weight+graph[start][it];
                }
            }
        }
    }

    return dist;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Q ;
    cin >> Q;

    vector<bool> isMade(30001, false);
    vector<bool> isCancel(30001, false);
    unordered_map <int, pair<int,int>> id2dest;
    
    vector<vector<int>> graph;
    vector <int> d;

    //가치, id
    struct compare {
        bool operator()(pair <int,int> &a , pair<int,int> &b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> item; 

    for( int i = 0 ; i < Q ; i ++){
        int commandId;
        cin >> commandId;
        switch (commandId)
        {
            case 100 :
                int n ,m ;
                cin >> n >> m;
                graph.resize(n,vector<int>(n,I_MAX));
                for(int r = 0 ; r < m ; r++){
                    int v,u,w;
                    cin >> v >> u >> w;
                    graph[v][u] = min(w, graph[v][u]);
                    graph[u][v] = min(w, graph[u][v]);
                }
             
                d = dijk(graph, 0);

           
                break;
            case 200:
                int id, revenue, dest;
                cin >> id >> revenue >> dest;
                item.push({revenue - d[dest], id});
                isMade[id] = true;
                id2dest[id] = {revenue, dest};

            
                break;
            case 300 :
                int canId;
                cin >> canId;
                if(isMade[canId]) isCancel[canId] = true;
                break;
            case 400 :
                while(1){
                    if(item.empty()){
                        cout << -1 <<'\n';
                        break;
                    }
                    
                    
                    int a = item.top().first;
                    int b = item.top().second;
                   
                    if(a < 0 ) {
                        cout << -1 << '\n';
                        break;
                    }
                    item.pop();        
    
                    if(!isCancel[b]){
                        cout << b <<endl;
                        break;
                    }
                }
                break;
            case 500:
                int start ;
                cin >> start;
                d = dijk(graph, start); 
                vector<int>temp;
                 while(!item.empty()){
                    int id = item.top().second ;
                    item.pop();
                    temp.push_back(id);
                 }   
                 for(auto id : temp){
                    item.push({id2dest[id].first - d[id2dest[id].second] , id});
                     
                 }
                break;
        }

    }


    return 0;
}