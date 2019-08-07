#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,D,M,g,p,b;
    cin >> A >> D >> M >> g >> p >> b;
    if(g >= A && (g + p - A) >= D && (g + p + b) - (A + D) >= M)cout << "YES";
    else cout << "NO";
    return 0;
}