#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int sum = 0;
	bool flag = false;
	for(int i = 0;i < n;i++){
		if(arr[i] & 1){
			if(flag)arr[i] = (arr[i] - 1) / 2;
			else arr[i] = (arr[i] + 1) / 2;
			flag = !flag;
		}
		else{
			arr[i] = arr[i] / 2;
			sum += arr[i];
		}
	}
	for(int i : arr)cout << i << endl;
}
