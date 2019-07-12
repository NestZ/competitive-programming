#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long ans[n] = {0};
    for(int i = 0;i < n;i++){
        long long  num;
        cin >> num;
        while(num != 1){
            if(num % 2 == 0)num /= 2;
            else if(num % 3 == 0)num = (2 * num) / 3;
            else if(num % 5 == 0)num = (4 * num) / 5;
            else {
                ans[i] = -1;
                break;
            }
            ans[i]++;
        }
    }
    for(int i = 0;i < n;i++)cout << ans[i] << '\n';
    return 0;
}