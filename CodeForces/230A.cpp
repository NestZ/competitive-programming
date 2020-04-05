#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int s, n;cin >> s >> n;
	bool flag = true;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	sort(arr.begin(), arr.end());
	for(int i = 0;i < n;i++){
		if(s <= arr[i].first){
			flag = false;
			break;
		}
		else s += arr[i].second;
	}
	cout << (flag ? "YES" : "NO");
}
