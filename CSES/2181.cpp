#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

vector<vector<char>> up;
vector<vector<char>> down;
vector<vector<char>> mid;
int n, m;

void fuck_up(int col, vector<char> &cur){
  if(col > n)up.push_back(cur);
  else{
    if(col > 1 && cur.back() == '['){
      cur.push_back(']');
      fuck_up(col + 1, cur);
      cur.pop_back();
    }
    else{
      //start new
      for(int i : {0, 2}){
        if(i == 0 && col == n)continue;
        if(i == 0)cur.push_back('[');
        else cur.push_back('A');
        fuck_up(col + 1, cur);
        cur.pop_back();
      }
    }
  }
}

void fuck_down(int col, vector<char> &cur){
  if(col > n)down.push_back(cur);
  else{
    if(col > 1 && cur.back() == '['){
      cur.push_back(']');
      fuck_down(col + 1, cur);
      cur.pop_back();
    }
    else{
      //start new
      for(int i : {0, 3}){
        if(i == 0 && col == n)continue;
        if(i == 0)cur.push_back('[');
        else cur.push_back('V');
        fuck_down(col + 1, cur);
        cur.pop_back();
      }
    }
  }
}

void fuck_mid(int col, vector<char> &cur){
  if(col > n)mid.push_back(cur);
  else{
    if(col > 1 && cur.back() == '['){
      cur.push_back(']');
      fuck_mid(col + 1, cur);
      cur.pop_back();
    }
    else{
      //start new
      for(int i : {0, 2, 3}){
        if(i == 0 && col == n)continue;
        if(i == 0)cur.push_back('[');
        else if(i == 2)cur.push_back('A');
        else cur.push_back('V');
        fuck_mid(col + 1, cur);
        cur.pop_back();
      }
    }
  }
}

/*
 * 0 [
 * 1 ]
 * 2 A
 * 3 V
*/
bool check(vector<char> &u, vector<char> &d){
  for(int i = 0;i < n;i++){
    if(u[i] == 'A' && d[i] != 'V')return false;
    if(d[i] == 'V' && u[i] != 'A')return false;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  vector<char> cur;
  fuck_up(1, cur);
  fuck_down(1, cur);
  fuck_mid(1, cur);
  vector<vector<ll>> dp(m, vector<ll>(6000));
  vector<vector<ll>> mid_match_up(6000), down_match_up(100), down_match_mid(100), mid_match_mid(6000);
  for(int i = 0;i < (int)up.size();i++){
    for(int j = 0;j < (int)mid.size();j++){
      if(check(up[i], mid[j])){
        mid_match_up[j].push_back(i);
      }
    }
    for(int j = 0;j < (int)down.size();j++){
      if(check(up[i], down[j])){
        down_match_up[j].push_back(i);
      }
    }
  }
  for(int i = 0;i < (int)mid.size();i++){
    for(int j = 0;j < (int)mid.size();j++){
      if(check(mid[i], mid[j])){
        mid_match_mid[j].push_back(i);
      }
    }
    for(int j = 0;j < (int)down.size();j++){
      if(check(mid[i], down[j])){
        down_match_mid[j].push_back(i);
      }
    }
  }
  if(m == 1){
    if(n % 2 == 0)cout << 1;
    else cout << 0;
    cout << endl;
  }
  else if(n == 1){
    if(m % 2 == 0)cout << 1;
    else cout << 0;
    cout << endl;
  }
  else if(m == 2)cout << down.size() << endl;
  else{
    ll MOD = 1e9 + 7;
    ll ans = 0;
    for(int i = 0;i < (int)up.size();i++)
      dp[0][i] = 1;
    for(int i = 0;i < (int)mid.size();i++){
      for(int adj : mid_match_up[i]){
        dp[1][i] = (dp[1][i] + dp[0][adj]) % MOD;
      }
    }
    for(int i = 2;i < m - 1;i++){
      for(int j = 0;j < (int)mid.size();j++){
        for(int adj : mid_match_mid[j]){
          dp[i][j] = (dp[i][j] + dp[i - 1][adj]) % MOD;
        }
      }
    }
    for(int i = 0;i < (int)down.size();i++){
      for(int adj : down_match_mid[i]){
        dp[m - 1][i] = (dp[m - 1][i] + dp[m - 2][adj]) % MOD;
      }
    }
    for(int i = 0;i < (int)down.size();i++){
      ans = (ans + dp[m - 1][i]) % MOD;
    }
    cout << ans << endl;
  }
}
