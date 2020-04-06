#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, m;cin >> n >> m;
	int ans = 0;
	int d = 1;
	while(n >= 1){
		n--;
		if(d % m == 0)n++;
		d++;
		ans++;
	}
	cout << ans;
}
