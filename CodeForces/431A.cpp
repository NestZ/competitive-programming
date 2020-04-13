#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	vector<int> arr;
	for(int i = 0;i < 4;i++){
		int n;cin >> n;
		arr.push_back(n);
	}
	string s;cin >> s;
	int n = s.length();
	int ans = 0;
	for(int i = 0;i < n;i++){
		ans += arr[s[i] - '0' - 1];
	}
	cout << ans;
}
