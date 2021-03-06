/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	map<VLL,ll> done;
	map<VLL,ll> dp;

	ll get(ll ind, ll oneleft, ll prev, const VLL & A) {
		if (ind == A.size() && oneleft == 0) return 0;
		if (ind == A.size()) return inf;
		if (done[{ind,oneleft,prev}]) return dp[{ind,oneleft,prev}];
		
		ll ans = inf;
		// put a 0 down
		if (A[ind] == -1 || A[ind] == 0) {
			ll cost = prev == -1 ? 0 : prev;
			ans = min(ans, get(ind+1, oneleft, 0, A) + cost); // use 0
		}
		// put a 1 down
		if (A[ind] == -1 || A[ind] == 1) {
			ll cost = prev == -1 ? 0 : !prev;
			ans = min(ans, get(ind+1, oneleft - 1, 1, A) + cost); // use 1
		}

		done[{ind,oneleft,prev}] = 1;
		dp[{ind,oneleft,prev}] = ans;
		return ans;
	}
	void main() {
		ll n;
		cin >> n;
		VLL A(n);
		REP(i,0,n) {
			cin >> A[i];
			A[i] = A[i] == 0 ? -1 : A[i] % 2 ? 1 : 0;
		}

		ll ans = get(0,n - n/2, -1, A);
		cout << ans << endl;
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
