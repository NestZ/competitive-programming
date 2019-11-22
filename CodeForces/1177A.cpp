#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    int count = 1;
    cin >> k;
    while(1){
        string s = to_string(count);
        if(k > s.length()){
            k -= s.length();
        }
        else{
            cout << s[k - 1];
            break;
        }
        count++;
    }
    return 0;
}