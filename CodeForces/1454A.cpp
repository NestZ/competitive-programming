#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> ans;
		for(int i = n;i >= 1;i--){
			ans.push_back(i);
		}
		if(n & 1)swap(ans[n / 2], ans[n / 2 - 1]);
		for(int i : ans)cout << i << ' ';
		cout << endl;
	}
}
