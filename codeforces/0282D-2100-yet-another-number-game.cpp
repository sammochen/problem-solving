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
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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

namespace SOLVE {	
	void a() {
		cout << "BitLGM" << endl;
		exit(0);
	}

	void b() {
		cout << "BitAryo" << endl;
		exit(0);
	}

	void main() {
		ll n;
		cin >> n;
		VLL A(n);
		REP(i,0,n) cin >> A[i];

		if (n == 1) {
			if (A[0] == 0) b();
			else a();
		} else if (n == 3) {
			if (A[0] ^ A[1] ^ A[2]) a();
			else b();
		} else {
			VVLL dp(301, VLL(301));
			dp[0][0] = 0;
			REP(i,0,301) {
				REP(j,0,301) {
					if (i == 0 && j == 0) continue;

					ll win = 0;
					// look for a losing situation
					REP(k,1,max(i,j) + 1) {
						if (i-k>=0 && dp[i-k][j] == 0) win = 1;
						if (j-k>=0 && dp[i][j-k] == 0) win = 1;
						if (i-k>=0 && j-k>=0 && dp[i-k][j-k] == 0) win = 1;
					}

					dp[i][j] = win;
				}
			}

			if (dp[A[0]][A[1]]) a();
			else b();
		}

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
