#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, b, d;cin >> n >> b >> d;
	int ans = 0;
	int curr = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t <= b)curr += t;
		if(curr > d){
			ans++;
			curr = 0;
		}
	}
	cout << ans;
}
