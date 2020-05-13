#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> arr(4);
	for(int i = 0;i < 4;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	if(arr[2] < arr[0] + arr[1] ||
		arr[3] < arr[0] + arr[1] ||
		arr[3] < arr[0] + arr[2] ||
		arr[3] < arr[1] + arr[2])cout << "TRIANGLE";
	else if(arr[2] == arr[0] + arr[1] ||
			arr[3] == arr[0] + arr[1] ||
			arr[3] == arr[0] + arr[2] ||
			arr[3] == arr[1] + arr[2])cout << "SEGMENT";
	else cout << "IMPOSSIBLE";
}
