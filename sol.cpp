#include <bits/stdc++.h>

using namespace std;
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		// create a set to store the important football matches
		set<int> s;
		// create a vector to store all the matches
		vector<int> all_matches;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			// use the set to store the important football matches
			s.insert(x);
			// insert all the matches in 1 vector
			all_matches.emplace_back(x);
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			// insert all the matches in 1 vector
			// also, no need to store the matches in this sequence to 's'
			all_matches.emplace_back(x);
		}
		// sort the vector in non-decreasing order to get the correct order of tv shows
		sort(all_matches.begin(), all_matches.end());
		// create a string to get the correct order of sequence and
		// start with letter 'f' (the football match)
		string sequence = "f";
		for (int i = 0; i < (int) all_matches.size(); i++) {
			if (s.find(all_matches[i]) != s.end()) {
				// if the current important event is equal to one of the elements
				// in the set (the set of important events of the football match)
				// then, concatenate the letter 'f' to the string
				sequence += "f";
			} else {
				// otherwise, concatenate the letter 'c'
				sequence += "c";
			}
		}
		int cnt = 0;
		for (int i = 0; i < (int) sequence.size() - 1; i++) {
			// count the number of times that the current letter is different from the next 
			// letter (this will be the number of times that it switched)
			if (sequence[i] != sequence[i + 1]) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
