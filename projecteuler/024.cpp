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

namespace SOLVE {
	void main() {
		ll n = 10;
		
		VLL f(n+1);
		f[0] = 1;
		REP(i,1,n+1) f[i] = f[i-1] * i;
		
		string ans = "";
		
		VLL used(n); // used digits
		
		ll x = 999999; // 0-indexed
		REP(i,0,n) { // the ten digits
			ll d = x / f[n - 1 - i];
			x %= f[n - 1 - i];
			
			ll cnt = -1; // find the d'th free number
			REP(j,0,10) {
				cnt += (used[j] == 0);
				if (cnt == d) {
					used[j] = 1;
					ans += to_string(j);
					break;
				}
			}
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
