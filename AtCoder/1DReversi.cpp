#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	vector<char> arr;
	arr.push_back(s[0]);
	for(int i = 1;i < n;i++){
		if(arr.back() != s[i])
			arr.push_back(s[i]);
	}
	cout << arr.size() - 1 << endl;
}
