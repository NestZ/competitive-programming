#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int cnt = 0;
	int curr = 0;
	int mx = -1;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		cnt += t;
		if(t == 0)curr++;
		else curr--;
		mx = max(mx, curr);
		curr = max(0, curr);
	}
	cout << cnt + mx;
}
