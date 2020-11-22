#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		string a, b;cin >> a >> b;
		vector<int> have(26);
		vector<int> need(26);
		bool ans = true;
		for(int i = 0;i < n;i++)have[a[i] - 'a']++;
		for(int i = 0;i < n;i++)need[b[i] - 'a']++;
		for(int i = 0;i < 26;i++){
			if(have[i] < need[i] || (have[i] - need[i]) % k)
				ans = false;
			have[i + 1] += have[i] - need[i];
		}
		if(ans)cout << "Yes";
		else cout << "No";
		cout << endl;
	}
}
