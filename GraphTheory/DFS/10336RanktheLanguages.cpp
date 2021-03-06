#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool comparePair(pair<char, int>& p1, pair<char, int>& p2) {

	// If counts equal, sort alphabetically ascending
	if (p1.second == p2.second)
		return p1.first < p2.first;

	// Sort by counts by default
	return p1.second > p2.second;

}

bool validCoor(vector<vector<char>>& G, int i, int j) {

	return (i >= 0) && (i < G.size()) && (j >= 0) && (G.size() != 0) && (j < G[0].size());

}

/* Floods matching targets in path with 0 */
void floodFill(vector<vector<char>>& G, int i, int j, char target) {

	if (validCoor(G, i, j) && G[i][j] == target) {

		G[i][j] = '0';
		floodFill(G, i - 1, j, target);
		floodFill(G, i + 1, j, target);
		floodFill(G, i, j - 1, target);
		floodFill(G, i, j + 1, target);

	}


}

int main() {

	int T, rows, cols;
	char target;

	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> rows >> cols;

		vector<vector<char>> G(rows, vector<char>(cols));
		vector<pair<char, int>> res;
		map<char, int> hm;

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				cin >> G[i][j];

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < cols; j++) {

				char c = G[i][j];

				if (c != '0') {

					floodFill(G, i, j, c);
					hm[c]++;

				}

			}

		}

		for (map<char, int>::iterator it = hm.begin(); it != hm.end(); it++)
			res.push_back(make_pair(it->first, it->second));

		sort(res.begin(), res.end(), comparePair);

		cout << "World #" << t + 1 << endl;

		for (int i = 0; i < res.size(); i++)
			cout << res[i].first << ": " << res[i].second << endl;

	}

	return 0;
}

