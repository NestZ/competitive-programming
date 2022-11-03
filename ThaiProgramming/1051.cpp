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

void print(int a) {
  vector<int> res;
  while(a > 0) {
    if (a & 1) res.push_back(1);
    else res.push_back(0);
    a >>= 1;
  }
  reverse(res.begin(), res.end());
  for (int i = 0;i < res.size();i++) {
    cout << res[i];
  }
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--) {
    int n, m;cin >> n >> m;
    vector<vector<int>> assump;
    vector<vector<int>> res;

    for(int i = 0;i < n;i++) {
      int cnt;cin >> cnt;
      vector<int> clause(18, -1);
      for(int j = 0;j < cnt;j++) {
        string s;cin >> s;
        char sign = s[0];
        char v = s[1];
        if(sign == '+') {
          if (clause[v - 'a'] == -1) clause[v - 'a'] = 1;
          else if (clause[v - 'a'] == 2) clause[v - 'a'] = 3;
        } else {
          if (clause[v - 'a'] == -1) clause[v - 'a'] = 2;
          else if (clause[v - 'a'] == 1) clause[v - 'a'] = 3;
        }
      }
      assump.push_back(clause);
    }

    for(int i = 0;i < m;i++) {
      int cnt;cin >> cnt;
      vector<int> clause(18, -1);
      for(int j = 0;j < cnt;j++) {
        string s;cin >> s;
        char sign = s[0];
        char v = s[1];
        if(sign == '+') {
          if (clause[v - 'a'] == -1) clause[v - 'a'] = 1;
          else if (clause[v - 'a'] == 2) clause[v - 'a'] = 3;
        } else {
          if (clause[v - 'a'] == -1) clause[v - 'a'] = 2;
          else if (clause[v - 'a'] == 1) clause[v - 'a'] = 3;
        }
      }
      res.push_back(clause);
    }

    bool ans = true;
    for (int i = 0;i < (1 << 16);i++) {

      bool is_assump = true;
      for (int j = 0;j < assump.size();j++) {
        bool is_clause = false;
        for (int k = 0;k < 16;k++) {
          if ((1 << k) & i) {
            if (assump[j][k] == 1 || assump[j][k] == 3) is_clause = true;
          } else {
            if (assump[j][k] == 2 || assump[j][k] == 3) is_clause = true;
          }
        }
        if (!is_clause) is_assump = false;
      }

      bool is_res = true;
      for (int j = 0;j < res.size();j++) {
        bool is_clause = false;
        for (int k = 0;k < 16;k++) {
          if ((1 << k) & i) {
            if (res[j][k] == 1 || res[j][k] == 3) is_clause = true;
          } else {
            if (res[j][k] == 2 || res[j][k] == 3) is_clause = true;
          }
        }
        if (!is_clause) is_res = false;
      }

      if (is_assump && !is_res) ans = false;
    }
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
}

//010
//100
//000

//-a +b
//-b +c
//-c