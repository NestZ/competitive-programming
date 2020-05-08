#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	set<int> s;
	vector<int> arr;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		s.insert(t);
	}
	for(int i : s)arr.push_back(i);
	if(s.size() == 1)cout << 0;
	else if(s.size() == 2){
		if((arr[1] - arr[0]) % 2 == 0)cout << (arr[1] - arr[0]) / 2;
		else cout << arr[1] - arr[0];
	}
	else if(s.size() == 3){
		if(arr[2] - arr[1] == arr[1] - arr[0])cout << arr[1] - arr[0];
		else cout << -1;
	}
	else cout << -1;
}
