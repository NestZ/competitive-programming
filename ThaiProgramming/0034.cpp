#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;cin >> A >> B >> C;
    for(int a = 1;a <= 100;a++){
        for(int b = -100;b <= 100;b++){
            for(int c = 1;c <= 100;c++){
                for(int d = -100;d <= 100;d++){
                    if(A == a * c && B == a * d + b * c && C == b * d)return cout << a << " " << b << " " << c << " " << d, 0;
                }
            }
        }
    }
    cout << "No Solution";
}