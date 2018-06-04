#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool comparePair(pair<char, int>& p1, pair<char, int>& p2) {

	if (p1.second == p2.second)
		return p1.first < p2.first;

	return p1.second > p2.second;

}

bool isValid(vector<vector<char>>& G, int i, int j) {

	return (G.size() > 0) 
		&& (i >= 0) 
		&& (i < G.size()) 
		&& (j >= 0) 
		&& (j < G[0].size());

}

int floodFill(vector<vector<char>>& G, int i, int j, char target) {

	if (isValid(G, i, j) && G[i][j] == target) {

		G[i][j] = '.';
		return 1 + floodFill(G, i - 1, j, target)
			+ floodFill(G, i + 1, j, target)
			+ floodFill(G, i, j - 1, target)
			+ floodFill(G, i, j + 1, target);

	}

	else
		return 0;

}

int main() {

	int tc = 1, r, c;

	cin >> r >> c;
	
	while (cin) {

		if (r == 0 && c == 0)
			break;

		vector<vector<char>> G(r, vector<char>(c));
		vector<pair<char, int>> res;

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> G[i][j];

		for (int i = 0; i < r; i++) {

			for (int j = 0; j < c; j++) {

				char c = G[i][j];

				if (c != '.')
					res.push_back(make_pair(c, floodFill(G, i, j, c)));

			}

		}

		sort(res.begin(), res.end(), comparePair);

		cout << "Problem " << tc++ << ":" << endl;
		for (int i = 0; i < res.size(); i++)
			cout << res[i].first << " " << res[i].second << endl;

		cin >> r >> c;

	}

	return 0;
}