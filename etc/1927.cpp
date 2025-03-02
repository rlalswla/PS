#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    priority_queue <long long, vector<long long> , greater<long long>> pq;

    for(int i = 0; i < N; i++){
        long long a;
        cin >> a;
        if( a > 0 ){
            pq.push(a);
        }
        else{
            if(pq.empty() == true){
                cout << 0 <<'\n';
            }
            else{
                long long temp = pq.top();
                cout << temp <<'\n';
                pq.pop();
            }
        }
    }

    return 0;
}