#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int m;cin >> m;
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		int in = a - 1;
		arr[in]--;
		if(in > 0)arr[in - 1] += b - 1;
		if(in < n - 1)arr[in + 1] += arr[in] - b + 1;
		arr[in] = 0;
	}
	for(int i = 0;i < n;i++)cout << arr[i] << endl;
}
