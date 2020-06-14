#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c;cin >> n >> c;
	vector<pair<int, int>> arr(n, {0, 0});
	for(int i = 0;i < n;i++)cin >> arr[i].first;
	for(int i = 0;i < n;i++)cin >> arr[i].second;
	int l = 0;
	int r = 0;
	int pass = 0;
	for(int i = 0;i < n;i++){
		pass += arr[i].second;
		l += max(0, arr[i].first - (pass * c));
	}
	pass = 0;
	for(int i = n - 1;i >= 0;i--){
		pass += arr[i].second;
		r += max(0, arr[i].first - (pass * c));
	}
	if(l == r)cout << "Tie";
	else if(l < r)cout << "Radewoosh";
	else cout << "Limak";
}
