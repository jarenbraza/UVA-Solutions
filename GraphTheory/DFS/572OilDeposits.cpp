#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<char>>& graph, int i, int j) {

	if ((i >= 0) && (i < graph.size()) && (j >= 0) && (j < graph[i].size()) && graph[i][j] == '@') {

		graph[i][j] = '*';
		DFS(graph, i - 1, j - 1);
		DFS(graph, i - 1, j);
		DFS(graph, i - 1, j + 1);
		DFS(graph, i, j - 1);
		DFS(graph, i, j + 1);
		DFS(graph, i + 1, j - 1);
		DFS(graph, i + 1, j);
		DFS(graph, i + 1, j + 1);

	}

}

int main() {

	int m, n;

	cin >> m;

	while (cin && m != 0) {

		cin >> n;

		vector<vector<char>> graph(m, vector<char>(n));

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> graph[i][j];

		int count = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] == '@') {
					DFS(graph, i, j);
					count++;
				}
			}
		}

		cout << count << endl;

		cin >> m;

	}

	return 0;
}