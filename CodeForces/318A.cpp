#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
int main(){
	ll n,k;cin >> n >> k;
	if(k <= (n + 1) / 2)cout << k * 2 - 1;
	else cout << (k - (n + 1) / 2) * 2;
}
