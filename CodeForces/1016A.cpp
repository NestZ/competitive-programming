#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	int rem = 0;
	vector<int> ans;
	for(int i = 0;i < n;i++){
		int em = m - rem;
		int t;cin >> t;
		int curr = 0;
		if(t >= em){
			curr++;
			t -= em;
			curr += t / m;
			ans.push_back(curr);
			rem = t % m;
		}
		else{
			rem += t;
			ans.push_back(0);
		}
	}
	for(int i : ans)cout << i << ' ';
}
