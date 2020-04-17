#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n;i++){
		if(i == 0){
			cout << abs(arr[i] - arr[i + 1]) << ' ' << abs(arr[i] - arr[n - 1]);
		}
		else if(i == n - 1){
			cout << abs(arr[i] - arr[i - 1]) << ' ' << abs(arr[i] - arr[0]);
		}
		else{
			cout << min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
			cout << ' ';
			cout << max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
		}
		cout << endl;
	}
}
