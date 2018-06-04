#include <algorithm> // min
#include <iomanip>   // setprecision
#include <iostream>  // cin, cout
#include <map>
#include <vector>
using namespace std;

struct coor {
	int x;
	int y;
	coor(int X, int Y) : x(X), y(Y) {}
};

void floydWarshall(vector<vector<int>>& dist) {

	int V = dist.size();

	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

}

// Averages values as a double from integer array
double calculateNumClicks(vector<vector<int>>& dist) {

	int sum = 0;

	for (int i = 0; i < dist.size(); i++)
		for (int j = 0; j < dist[i].size(); j++)
			sum += dist[i][j];

	double result = sum;

	// Rounds to three decimal places
	return result / (dist.size() * (dist.size() - 1));

}

int main() {

	int T = 1, n1, n2;

	cin >> n1 >> n2;

	while (cin && n1 != 0 && n2 != 0) {

		vector<vector<int>> dist;
		vector<coor> C;
		map<int, int> m;
		int idx = 0;

		// Collect test case input
		while (cin && n1 != 0 && n2 != 0) {

			// Assign indices to coordinates
			if (m.find(n1) == m.end()) m[n1] = idx++;
			if (m.find(n2) == m.end()) m[n2] = idx++;

			C.push_back(coor(m[n1], m[n2]));

			cin >> n1 >> n2;

		}

		// Set diagonal to 0, connections to 1, and the rest to INT_MAX
		dist = vector<vector<int>>(m.size(), vector<int>(m.size(), INT16_MAX));
		for (coor c : C)
			dist[c.x][c.y] = 1;
		for (int i = 0; i < m.size(); i++)
			dist[i][i] = 0;

		floydWarshall(dist);

		cout << "Case " << T++ << ": average length between pages = " << fixed 
			<< setprecision(3) << calculateNumClicks(dist) << " clicks" << endl;

		cin >> n1 >> n2;

	}

	return 0;
}