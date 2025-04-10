#include <iostream>
#include <vector> 
#include <algorithm>
#include <climits>
#include <string>
#include <stack>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();
    
    stack<char> s;


    for(int i = 0 ; i < N ; i++){
        string str;
        getline(cin, str);
        for(char i : str){
            if(!s.empty() && i == ')' && s.top() == '('){
                s.pop();
            }
            else{
                s.push(i);
            };
        }
        if(s.empty()){
            cout << "YES" <<"\n";
        } else{
            cout << "NO" <<'\n';
        }
        while(!s.empty()){
            s.pop();
        }
    }
    

    
    

    return 0;
}