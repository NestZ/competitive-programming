#include<bits/stdc++.h>
using namespace std;

int n,start,sameCount = 0;
int G[110][110] = {0};
bool visited[110] = {0};
bool ans = false;

void dfs(int a){
        visited[a] = 1;
        if(G[a][start] == 1)ans = true;
        for(int i = 0;i < n;i++){
                if(!visited[i] && G[a][i] == 1)dfs(i);
        }
}

int main(){
        int m;
        cin >> n >> m;
        for(int i = 0;i < m;i++){
                int t1,t2;
                cin >> t1 >> t2;
                G[t1][t2] = 1;
        }
        cin >> start;
        dfs(start);
        if(ans)cout << "YES";
        else cout << "NO";
        return 0;
}