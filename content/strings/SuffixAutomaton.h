/**
 * Author: Pedro Mesquita
 * Date: 2026-08-23
 * License: CC0
 * Source: https://cp-algorithms.com/string/suffix-automaton.html
 * Description: Suffix Automaton, a compressed form of all substrings of a given string.
 * Time: construction takes $O(N log K)$,
 * where $N =$ size of the string and $K =$ size of the alphabet.
 * getDiffStrings() is $O(N)$.
 * Status: tested on Yosupo "Number of Substrings" and CSES "Finding Patterns"
 */
#pragma once

struct SuffixAutomaton {
	struct State {
		int len, link;
		map<char, int> next;
	};
	int m;
	vector<State> st;
	SuffixAutomaton(string s): m(1), st(2 * sz(s)) {
		st[0].len = 0, st[0].link = -1;
		int last = 0;
		for (char c : s) {
			int cur = m++, p = last;
			st[cur].len = st[last].len + 1;
			while (p != -1 && !st[p].next.count(c)) {
				st[p].next[c] = cur;
				p = st[p].link;
			}
			if (p == -1) st[cur].link = 0;
			else {
				int q = st[p].next[c];
				if (st[p].len + 1 == st[q].len) st[cur].link = q;
				else {
					int clone = m++;
					st[clone].len = st[p].len + 1;
					st[clone].next = st[q].next;
					st[clone].link = st[q].link;
					while (p != -1 && st[p].next[c] == q) {
						st[p].next[c] = clone;
						p = st[p].link;
					}
					st[q].link = st[cur].link = clone;
				}
			}
			last = cur;
		}
	}
	ll getDiffStrings() {
		ll tot = 0;
		rep(i, 1, m) tot += st[i].len - st[st[i].link].len;
		return tot;
	}
};
