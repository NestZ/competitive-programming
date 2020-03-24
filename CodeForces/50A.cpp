#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n,m;cin >> n >> m;
	int ans = n * m;
	if(ans & 1)ans--;
	cout << ans / 2;
}
