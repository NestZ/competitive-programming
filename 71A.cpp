#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("test.in.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        if(name.length()>10) cout<<name[0]<<name.length()-2<<name[name.length()-1]<<"\n";
        else cout<<name<<"\n";
    }
}