#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int lenn = n + 10;
    int ans[lenn];
    for(int i = 0;i < n;i++){
        int len;
        cin >> len;
        int lenlen = len + 10;
        char c[lenlen];
        cin >> c;
        for(int j = 0;j <= len - 11;j++){
            if(c[j] == '8' && len - j >= 11){
                ans[i] = 1;
                break;
            }
            if(j == len - 11)ans[i] = 0;
        }
    }
    for(int i = 0;i < n;i++){
        if(ans[i] == 1)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}