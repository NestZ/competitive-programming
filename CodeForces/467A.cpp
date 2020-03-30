#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	int ans = 0;
	for(int i = 0;i < t;i++){
		int a,b;cin >> a >> b;
		if(b - a >= 2)ans++;
	}
	cout << ans;
}
