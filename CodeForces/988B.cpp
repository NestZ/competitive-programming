#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool cmp(string a, string b){
	return a.length() < b.length();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<string> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end(), cmp);
	bool flag = true;
	for(int i = 0;i < n - 1;i++){
		if(arr[i + 1].find(arr[i]) == string::npos)flag = false;
	}
	if(flag){
		cout << "YES" << endl;
		for(string s : arr)cout << s << endl;
	}
	else cout << "NO" << endl;
}
