/*
ID: nestz
LANG: C++14
TASK: sort3
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("sort3.out", "w", stdout);
	freopen("sort3.in", "r", stdin);
	
	int n;cin >> n;
	vector<int> arr(n);
	vector<int> s(n);
	vector<int> inv;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		s[i] = arr[i];
	}
	sort(s.begin(), s.end());
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(int i = 0;i < n;i++){
		if(arr[i] != s[i]){
			inv.push_back(arr[i]);
			if(arr[i] == 1)cnt1++;
			else if(arr[i] == 2)cnt2++;
			else cnt3++;
		}
	}
	int r1 = cnt1 - 1, l2 = cnt1, r2 = cnt1 + cnt2 - 1;
	int threeIn1 = 0;
	int threeIn2 = 0;
	int twoIn3 = 0;
	int twoIn1 = 0;
	int oneIn2 = 0;
	int oneIn3 = 0;
	for(int i = 0;i < inv.size();i++){
		if(inv[i] == 1){
			if(i >= l2 && i <= r2)oneIn2++;
			else if(i > r2)oneIn3++;
		}
		else if(inv[i] == 2){
			if(i >= 0 && i <= r1)twoIn1++;
			else if(i > r2)twoIn3++;
		}
		else{
			if(i >= 0 && i <= r1)threeIn1++;
			else if(i >= l2 && i <= r2)threeIn2++;
		}
	}
	int ans = 0;
	int rem = 0;
	ans += min(threeIn1, oneIn3);
	rem += abs(threeIn1 - oneIn3);
	ans += min(threeIn2, twoIn3);
	rem += abs(threeIn2 - twoIn3);
	ans += min(twoIn1, oneIn2);
	rem += abs(twoIn1 - oneIn2);
	ans += 2 * (rem / 3);
	cout << ans << endl;
}
