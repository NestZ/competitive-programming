#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		if(!((n / 2) & 1) && n > 2){
			int curr = 2;
			vector<int> ans;
			for(int i = 0;i < n / 2;i++){
				ans.push_back(curr);
				curr += 2;
			}
			for(int i = 0;i < n / 2 - 1;i++){
				ans.push_back(ans[i] - 1);
			}
			ans.push_back(ans[n - 2] + n / 2 + 2);
			cout << "YES" << endl;
			for(int i : ans)cout << i << ' ';
			cout << endl;
		}
		else cout << "NO" << endl;
	}
}
