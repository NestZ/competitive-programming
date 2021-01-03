#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MOD = 1e9 + 7;

int mod_pow(int e){
	int res = 1;
	for(int i = 0;i < e;i++){
		res = res * 2 % MOD;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	bool valid = true;
	vector<int> cnt(n);
	for(int i = 0;i < n;i++){
		int num;cin >> num;
		cnt[num]++;
	}
	if(n & 1){
		if(cnt[0] != 1)valid = false;
		else{
			for(int i = 2;i < n;i++){
				if(i & 1){
					if(cnt[i] != 0)valid = false;
				}
				else{
					if(cnt[i] != 2)valid = false;
				}
			}
		}
	}
	else{
		if(cnt[0] != 0)valid = false;
		else{
			for(int i = 1;i < n;i++){
				if(i & 1){
					if(cnt[i] != 2)valid = false;
				}
				else{
					if(cnt[i] != 0)valid = false;
				}
			}
		}
	}
	if(valid)cout << mod_pow(n / 2);
	else cout << 0;
	cout << endl;
}
