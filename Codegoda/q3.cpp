#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

int MOD = 1e9 + 7;
vector<pair<int, int>> inv(17);
int dp[17][1000001] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;cin >> n >> m;
  for(int i = 0;i <= n;i++)
    dp[0][i] = 1;
  for(int i = 1;i <= m;i++){
    cin >> inv[i].first >> inv[i].second;
  }
  for(int i = 1;i <= m;i++){
    for(int j = 0;j <= n;j++){
      if(j < inv[i].first)continue;
      int l = (j - inv[i].second - 1 >= 0 ? dp[i - 1][j - inv[i].second - 1] : 0);
      int r = (j - inv[i].first >= 0 ? dp[i - 1][j - inv[i].first] : 0);
      dp[i][j] = (r - l + MOD) % MOD;
      if(j > 0)dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
    }
  }
  cout << (dp[m][n] - dp[m][n - 1] + MOD) % MOD << endl;
}
