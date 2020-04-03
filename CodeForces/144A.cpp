#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int maxx = *max_element(arr.begin(), arr.end());
	int minn = *min_element(arr.begin(), arr.end());
	bool flag = false;
	int cmax = 0, cmin = 0;
	int imax = 0, imin = 0;
	for(int i = 0;i < n;i++){
		if(arr[i] == maxx && !flag){
			flag = true;
			cmax = i;
			imax = i;
		}
		if(arr[i] == minn){
			cmin = n - i - 1;
			imin = i;
		}
	}
	if(imax > imin)cmin--;
	cout << cmin + cmax;
}
