#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		vector<vector<char>> arr(9 + 5, vector<char>(9 + 5));
		for(int i = 0;i < 9;i++){
			for(int j = 0;j < 9;j++){
				cin >> arr[i][j];
			}
		}
		arr[0][0] = arr[0][1];
		arr[4][1] = arr[4][2];
		arr[8][2] = arr[8][1];
		arr[1][4] = arr[1][5];
		arr[2][8] = arr[2][7];
		arr[5][5] = arr[5][4];
		arr[3][6] = arr[3][7];
		arr[6][3] = arr[6][4];
		arr[7][7] = arr[7][8];
		for(int i = 0;i < 9;i++){
			for(int j = 0;j < 9;j++){
				cout << arr[i][j];
			}
			cout << endl;
		}
	}
}
