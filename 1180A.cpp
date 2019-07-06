#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        if(i == 1){
            ans += 1;
        }
        else{
            ans += 4 * (i - 1);
        }
    }
    cout << ans;
    return 0;
}