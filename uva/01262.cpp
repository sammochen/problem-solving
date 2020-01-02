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
	cin >> s;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	void run(string word, VVLL A, vector<string> & ans) {
		if (word.length() == 5) {
			ans.push_back(word);
			return;
		}
		REP(i,0,A[word.length()].size()) {
			char c = A[word.length()][i] + 'A';
			
			run(word + c, A, ans);
		}
	}
	void main() {
		ll k;
		in(k);
		
		VVLL freq(5, VLL(26));
		REP(i,0,12) {
			string s;
			in(s);
			REP(j,0,5) {
				freq[j][s[j] - 'A'] |= (1LL << (i/6));
			}
		}

		VVLL A(5);
		REP(i,0,5) {
			REP(j,0,26) {
				if (freq[i][j] == 3) A[i].push_back(j);
			}
		}

		// generate all from both, and store into sets
		vector<string> ans;
		run("", A, ans);

		if (k > ans.size()) cout << "NO" << endl;
		else cout << ans[k-1] << endl;

	}
}


signed main() {
	ll t;
	t = 1;
	in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
