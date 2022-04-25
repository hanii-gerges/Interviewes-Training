#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

#define ll long long
#define ull unsigned long long
#define ld long double
#define all(vec) (vec).begin(),(vec).end()
#define allr(vec) (vec).rbegin(),(vec).rend()5
#define viewVec(vec) for(auto i:(vec))cout << i << " ";cout << endl
#define viewPVec(vec) for(auto i:(vec))cout << i.first << " " << i.second << endl
#define PI 3.14159265
#define endl "\n"

using namespace std;

ll  a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x,y, z;
ll ans = 0, sum = 0, mn = 1e18, mx = 0, cnt = 0;
const ll M = 1000000007;

ll gcd(ll a, ll b) {if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a*b) / gcd(a, b);}

vector<int>vec;
vector<int>dp(100000, -1);

ll solve (int idx) {
  int local_k = k;
  ll mn = 1e18;
  for (int i = idx+1; i < n; i++)
  {
    if(!local_k) break;
    ll res = 0;
    if (dp[i] != -1) {
      res = abs(vec[idx] - vec[i]) + dp[i];
    }
    else {
      res = abs(vec[idx] - vec[i]) + solve(i);
    }
    mn = min(mn, res);
    local_k--;
  }

  if (idx == n-1) {
    dp[idx] = 0;
  }
  else {
    dp[idx] = mn;
  }
  return dp[idx];
}

int main()
{
  // freopen("testCase.txt","r",stdin);
  cin >> n;
  cin >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> x;
    vec.push_back(x);
  }

  ans = solve(0);
  cout << ans << endl;

  return 0;
}
