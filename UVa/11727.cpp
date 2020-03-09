#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	for(int i = 0;i < n;i++){
		int arr[3];cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);
		cout << "Case " << i + 1 << ": " << arr[1] << endl;
	}
}
