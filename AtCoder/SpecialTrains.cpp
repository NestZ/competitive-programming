#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> c(n - 1);
	vector<int> s(n - 1);
	vector<int> f(n - 1);
	vector<int> ans(n);
	for(int i = 0;i < n - 1;i++){
		cin >> c[i] >> s[i] >> f[i];
	}
	for(int i = 0;i < n - 1;i++){
		int cur = 0;
		for(int j = i;j < n - 1;j++){
			if(cur <= s[j])cur += s[j] - cur;
			else{
				if((cur - s[j]) % f[j] != 0)
					cur += f[j] - (cur - s[j]) % f[j];
			}
			cur += c[j];
		}
		ans[i] = cur;
	}
	for(int i : ans)cout << i << endl;
}
