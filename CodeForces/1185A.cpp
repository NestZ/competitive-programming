#include<bits/stdc++.h>
using namespace std;

int main(){
    int d;
    int arr[3];
    int sum = 0;
    cin >> arr[0] >> arr[1] >> arr[2] >> d;
    sort(&arr[0],&arr[3]);
    if(abs(arr[0]-arr[1]) < d)sum += d - abs(arr[0]-arr[1]);
    if(abs(arr[2]-arr[1]) < d)sum += d - abs(arr[2]-arr[1]);

    cout << sum;

    return 0;
}