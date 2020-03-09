#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	for(int j = 0;j < n;j++){
		int t;cin >> t;
		int arr[t];
		for(int i = 0;i < t;i++)cin >> arr[i];
		cout << "Case " << j + 1 << ": " << *max_element(arr, arr + t) << endl;
	}
}
