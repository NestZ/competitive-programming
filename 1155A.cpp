#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0;i < n - 1;i++){
        if(s[i] > s[i + 1]){
            cout << "YES\n" << i + 1 << ' ' << i + 2;
            break;
        }
        else if(i == n - 2)cout << "NO";
    }
    return 0;
}