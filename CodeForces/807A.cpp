#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<pair<int, int>> arr;
	bool as = false;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		arr.push_back({a, b});
		if(a != b)return cout << "rated", 0;
		if(a > arr[i - 1].first)as = true;
	}
	if(as)cout << "unrated";
	else cout << "maybe";
}
