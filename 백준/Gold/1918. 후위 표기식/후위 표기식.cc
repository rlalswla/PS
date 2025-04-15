#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int priority(char c) {
    if(c == '(') return 0;
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;

    stack <char> st;
    for(char i : s){
        if(i <= 'Z' && i >= 'A' ){
            cout << i;
        }
        else if (i == '('){
            st.push(i);
        }
        else if (i == ')'){
            while(!st.empty()){
                char top = st.top();
                st.pop();
                if(top == '('){
                    break;
                }else{
                    cout << top;
                }
            }
        }else {
            while (!st.empty() && priority(st.top()) >= priority(i)) {
                cout << st.top();
                st.pop();
            }
            st.push(i);
        }
        
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    
    
    return 0;
}
