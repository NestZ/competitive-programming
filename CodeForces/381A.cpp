#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int s = 0;
	int d = 0;
	int l = 0;
	int r = n - 1;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int t = 1;
	while(l <= r){
		if(arr[l] < arr[r]){
			if(t & 1)s += arr[r--];
			else d += arr[r--];
		}
		else{
			if(t & 1)s += arr[l++];
			else d += arr[l++];
		}
		t++;
	}
	cout << s << ' ' << d;
}
