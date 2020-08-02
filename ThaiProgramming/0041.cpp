#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    float diff = 2 - sqrt(3);
    if(n == 1)printf("%.6f", 2.0);
    else if(n % 2 == 0)printf("%.6f", (float)n);
    else if(n == 3)printf("%.6f", (float)n - diff + 1);
    else if(n > 3)printf("%.6f", (float)n - 2 * diff + 1);
}