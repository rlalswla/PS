#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main (){
    int N;
    scanf("%d", &N);
    vector<bool> s(21, 0);
    char a[10];
    for(int i = 0; i < N; i++){
        scanf("%s", a);
        if(strcmp(a, "all") == 0){
            fill(s.begin(), s.end(), 1);
        }
        else if (strcmp(a, "empty") == 0){
            fill(s.begin(), s.end(), 0);
        }
        else {
            int b;
            scanf("%d", &b);
            if(strcmp(a, "add") == 0){
                s[b] = 1;
            }
            else if (strcmp(a, "check") == 0){
                printf("%d\n", s[b]);
            }
            else if (strcmp(a, "remove") == 0){
                s[b] = 0;
            }
            else if (strcmp(a, "toggle") == 0){
                s[b] = !s[b];
            }
        }
    }
    return 0;
}