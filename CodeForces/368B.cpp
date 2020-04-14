#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, m;cin >> n >> m;
	set<int> s;
	vector<int> arr(n, 0);
	vector<int> temp(n);
	for(int i = 0;i < n;i++)cin >> temp[i];
	for(int i = n - 1;i >= 0;i--){
		s.insert(temp[i]);
		arr[i] = s.size();
	}
	for(int i = 0;i < m;i++){
		int t;cin >> t;
		t--;
		cout << arr[t] << endl;
	}
}
