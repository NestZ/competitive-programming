#include<bits/stdc++.h>
using namespace std;

int main(){
        int n;
        cin>>n;
        int arr[n];
        int check [100]={0};
        for (int i=0;i<n;i++){
                cin>>arr[i];
        }
        sort(arr,arr+n);
        int k,f=0;
        cin>>k;
        int temp;
        for(int i=0;i<k;i++){
                cin>>temp;
                for(int j=0;j<n;j++){
                        if(temp==arr[j]) {
                                cout<<j+check[j]+1<<"\n";
                                check[j]+=1;
                                break;
                        }
                }
        }
}