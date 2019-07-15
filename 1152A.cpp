#include<bits/stdc++.h>
using namespace std;

int main(){
    int c,k,ce = 0,co = 0,ee = 0,eo = 0;
    cin >> c >> k;
    for(int i = 0;i < c;i++){
        int temp;
        cin >> temp;
        if(temp % 2 == 0)ce++;
        else co++;
    }
    for(int i = 0;i < k;i++){
        int temp;
        cin >> temp;
        if(temp % 2 == 0)ee++;
        else eo++;
    }
    cout << min(ce,eo) + min(ee,co);
    return 0;
}