#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;cin >> n >> k;
	string s;cin >> s;
	vector<pair<int, int>> arr;
	char cur = s[0];
	int cnt = 1;
	int ans = 0;
	for(int i = 1;i < n;i++){
		if(s[i] == cur)cnt++;
		else{
			arr.emplace_back(cur - '0', cnt);
			cur = s[i];
			cnt = 1;
		}
		if(cur == '1')ans = max(ans, cnt);
	}
	arr.emplace_back(cur - '0', cnt);
	int len = arr.size();
	int fst = 0;
	if(arr[0].first == 1)fst = 1;
	int snd = fst;
	for(int i = 0;i < k - 1;i++){
		if(snd + 2 < len)
			snd += 2;
		else break;
	}
	vector<int> pre(len + 1);
	for(int i = 1;i <= len;i++){
		pre[i] = arr[i - 1].second;
		pre[i] += pre[i - 1];
	}
	if(fst >= len)cout << n;
	else{
		while(fst < len && snd < len){
			int res = pre[snd + 1];
			if(fst > 0)res -= pre[fst];
			if(fst > 0)res += arr[fst - 1].second;
			if(snd < len - 1)res += arr[snd + 1].second;
			ans = max(ans, res);
			fst += 2;
			snd += 2;
		}
		cout << ans;
	}
	cout << endl;
}
