#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	cout << (n + 1) / 2 - 1 << endl;
	vector<int> arr(n);
	vector<int> c(n);
	for(int i = 0;i < n;i++)cin >> c[i];
	sort(c.begin(), c.end());
	int curr = 0;
	for(int i = 1;i < n;i+=2){
		arr[i] = c[curr];
		curr++;
	}
	for(int i = 0;i < n;i+=2){
		arr[i] = c[curr];
		curr++;
	}
	for(int i = 0;i < n;i++){
		cout << arr[i] << ' ';
	}
}
