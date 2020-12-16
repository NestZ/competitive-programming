#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	bool ans = true;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(arr[i] - 1 > i)ans = false;
	}
	if(ans){
		vector<int> v;
		for(int i = 0;i < n;i++)
			v.insert(v.begin() + arr[i] - 1, arr[i]);
		for(int i : v)cout << i << endl;
	}
	else cout << -1 << endl;
}
