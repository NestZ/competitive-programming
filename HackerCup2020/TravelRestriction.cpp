#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("out.txt", "w", stdout);
	freopen("test2.in", "r", stdin);

	int t;cin >> t;
	for(int q = 0;q < t;q++){
		int n;cin >> n;
		string I;cin >> I;
		string O;cin >> O;
		vector<vector<char>> arr(n, vector<char>(n));
		for(int i = 0;i < n;i++){
			for(int j = i;j < n;j++){
				if(i == j)arr[i][j] = 'Y';
				else{
					if(arr[i][j - 1] == 'N')arr[i][j] = 'N';
					else{
						if(I[j] == 'Y' && O[j - 1] == 'Y')arr[i][j] = 'Y';
						else arr[i][j] = 'N';
					}
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i - 1;j >= 0;j--){
				if(arr[i][j + 1] == 'N' || (i > 0 && arr[i - 1][j] == 'N'))arr[i][j] = 'N';
				else{
					if(I[j] == 'Y' && O[j + 1] == 'Y')arr[i][j] = 'Y';
					else arr[i][j] = 'N';
				}
			}
		}
		cout << "Case #" << q + 1 << ":\n";
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				cout << arr[i][j];
			}
			cout << endl;
		}
	}	
}
