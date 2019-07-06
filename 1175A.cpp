#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long unsigned int arr[n];
    for(int i = 0;i < n;i++){
        long long unsigned int num;
        long long unsigned int k;
        long long unsigned int count = 0;
        cin >> num >> k;
        if(k > num){
            arr[i] = num;
            continue;
        }
        while(num != 0){
            long long unsigned int minus = num % k;
            if(minus == 0){
                num /= k;
                count++;
            }
            else{
                num -= minus;
                count += minus;
            }
        }
        arr[i] = count;
    }
    for(int i = 0;i < n;i++)cout << arr[i] << '\n';

    return 0;
}