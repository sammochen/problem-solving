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

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
string to_string(bool b) {return b ? "true" : "false";}
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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

const ll nax = 1000; // sqrt

namespace SOLVE {
	VLL p(nax*nax, 1);
	
	void pp() {
		p[0] = 0;
		p[1] = 0;

		for (ll x = 2; x < nax; x++) {
			if (p[x] == 0) {
				continue;
			}
			
			for (ll f = 2; x * f < nax * nax; f++) {
				p[x*f] = 0;
			}
		}
	}
	
	ll c(ll x) {
		string s = to_string(x);
		ll n = s.size();
		s = s + s;
		REP(i,0,n) {
			if (!p[stoll(s.substr(i,n))]) return 0;
		}
		return 1;
	}
		
	void main() {
		if (p[0] == 1) pp();
		
		ll ans = 0;
		REP(i,1,nax*nax) {
			if (c(i)) ans++;
		}
		
		cout << ans << endl;
		
	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
