#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

bool isBicolorable(vector<list<int>>& G) {

	// 0 = Not Visited, 1 = Color #1, 2 = Color #2
	vector<int> color(G.size(), 0);
	
	queue<int> q;

	if (G.size() != 0) {
		q.push(0);
		color[0] = 1;
	}

	while (!q.empty()) {

		// Current color
		int src = q.front();

		for (list<int>::iterator it = G[src].begin(); it != G[src].end(); it++) {

			// Not-Bicolorable (pair of adjacent nodes forced to have same color)
			if (color[*it] == color[src])
				return false;

			// Push unvisited neighbors
			if (color[*it] == 0)
				q.push(*it);

			// Set neighbors to opposite color
			color[*it] = (color[src] == 1) ? 2 : 1;

		}

		q.pop();

	}

	return true;

}


int main() {

	int n, l, op1, op2;

	cin >> n;

	while (cin && n != 0) {

		vector<list<int>> graph(n);

		cin >> l;

		for (int i = 0; i < l; i++) {
			
			cin >> op1 >> op2;

			graph[op1].push_back(op2);
			graph[op2].push_back(op1);

		}

		if (isBicolorable(graph))
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;


		cin >> n;

	}

	return 0;
}