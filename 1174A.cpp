#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int lenght = n * 2;
    int arr[lenght];
    for(int i = 0;i < lenght;i++){
        cin >> arr[i];
    }
    sort(&arr[0],&arr[lenght]);
    if(arr[0] == arr[lenght - 1]){
        cout << "-1";
    }
    else{
        for(int i = 0;i < lenght;i++){
            cout << arr[i] << ' ';
        }
    }
    return 0;
}