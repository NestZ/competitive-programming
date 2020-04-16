#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	vector<int> temp(n, 0);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int l = -1;
	int r = -1;
	for(int i = 0;i < n - 1;i++){
		if(l == -1 && arr[i] > arr[i + 1])l = i;
		if(r == -1 && arr[i] < arr[i + 1] && l != -1)r = i;
	}
	if(l != -1 && r == -1)r = n - 1;
	if(l == -1 && r == -1)return cout << "yes" << endl << 1 << ' ' << 1, 0;
	reverse(arr.begin() + l, arr.begin() + r + 1);
	for(int i = 0;i < n - 1;i++){
		if(arr[i] > arr[i + 1])return cout << "no", 0;
	}
	cout << "yes" << endl << l + 1 << ' ' << r + 1;
}
