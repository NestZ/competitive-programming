#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	vector<int> v(n, false);
	for(int i = 0;i < n;i++){
		int curr = i;
		while(!v[curr]){
			v[curr] = true;
			curr = arr[curr] - 1;
		}
		cout << curr + 1 << ' ';
		v = vector<int>(n, false);
	}
}
