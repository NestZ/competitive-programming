#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(7);
	int sum = 0;
	int lst = 0;
	for(int i = 0;i < 7;i++){
		cin >> arr[i];
		sum += arr[i];
		if(arr[i] > 0)lst = i;
	}
	n %= sum;
	if(n == 0)return cout << lst + 1, 0;
	for(int i = 0;i < 7;i++){
		n -= arr[i];
		if(n <= 0)return cout << i + 1, 0;
	}
}
