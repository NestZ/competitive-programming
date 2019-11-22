#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("test.in.txt", "r", stdin);
    
    int n,sum=0;
    cin>>n;
    for(int i=0 ;i<n;i++){
        string name;
        cin>>name;
        if(name=="Tetrahedron") sum+=4;
        if(name=="Cube" )sum+=6;
        if(name=="Octahedron" ) sum+=8;
        if(name=="Dodecahedron" )sum+=12;
        if(name=="Icosahedron") sum+=20;
    }
    cout<<sum;
}