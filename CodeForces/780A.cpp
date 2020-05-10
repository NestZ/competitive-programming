#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	set<int> s;
	int ans = 0;
	int curr = 0;
	for(int i = 0;i < 2 * n;i++){
		int t;cin >> t;
		if(s.count(t) == 0){
			s.insert(t);
			curr++;
		}
		else curr--;
		ans = max(ans, curr);
	}
	cout << ans;
}
