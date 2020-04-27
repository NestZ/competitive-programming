#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	map<int, int> m;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		m[arr[i]]++;
	}
	sort(arr.begin(), arr.end());
	cout << arr[n - 1] << ' ';
	for(int i = n - 2;i >= 0;i--){
		if(arr[n - 1] % arr[i] != 0){
			cout << arr[i];
			break;
		}
		else if(arr[n - 1] % arr[i] == 0){
			if(m[arr[i]] == 2){
				cout << arr[i];
				break;
			}
		}
	}
}
