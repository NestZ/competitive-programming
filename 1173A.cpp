#include<bits/stdc++.h>
using namespace std;

int main(){
    int up,down,unknow;
    cin >> up >> down >> unknow;
    if(up > down + unknow)cout << '+';
    else if(down > up + unknow)cout << '-';
    else if(down == up && unknow == 0)cout << '0';
    else if(up + unknow > down || down + unknow > up)cout << '?';
    return 0;
}