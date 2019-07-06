#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    int ans;
    cin >> num;
    while(true){
        int sum = num % 10 + ((num / 10) % 10) + ((num / 100) % 10) + num / 1000;
        if(sum % 4 == 0){
            ans = num;
            break;
        }
        num++;
    }
    cout << ans;
    return 0;
}