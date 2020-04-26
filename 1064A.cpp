#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> arr(3);
	for(int i = 0;i < 3;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int a = arr[0] + arr[1];
	if(a > arr[2])cout << 0;
	else cout << arr[2] - a + 1;
}
