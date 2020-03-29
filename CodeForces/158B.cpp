#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	map<int, int> m;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		m[t]++;
	}
	int ans = 0;
	ans += m[2] / 2;
	m[2] = m[2] & 1;
	ans += m[4];
	ans += min(m[1], m[3]);
	int t = m[1];
	m[1] = max(0, m[1] - m[3]);
	m[3] = max(0, m[3] - t);
	if(m[1] > 0){
		if(m[2] > 0){
			if(m[1] <= 2)ans += 1;
			else ans += 1 + (m[1] - 2 + 3) / 4;
		}
		else ans += (m[1] + 3) / 4;
	}
	else ans += m[3] + m[2];
	cout << ans;
}
