#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr;
	arr.push_back(0);
	arr.push_back(1);
	int i = 0;
	for(i = 2;;i++){
		arr.push_back(arr[i - 1] + arr[i - 2]);
		if(arr[i] >= n)break;
	}
	if(n == 0)cout << "0 0 0";
	else if(n == 1)cout << "1 0 0";
	else cout << arr[i - 2] << ' ' << arr[i - 2] << ' ' << arr[i - 3];
}
