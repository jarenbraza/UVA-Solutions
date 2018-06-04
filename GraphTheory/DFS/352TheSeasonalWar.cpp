#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<char>>& graph, int i, int j) {

	if ((i >= 0) && (i < graph.size()) && (j >= 0) && (j < graph[i].size()) && graph[i][j] == '1') {

		graph[i][j] = '0';
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

	int m, n, set = 1;

	cin >> m;

	while (cin && m != 0) {

		vector<vector<char>> graph(m, vector<char>(m));

		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				cin >> graph[i][j];

		int count = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] == '1') {
					DFS(graph, i, j);
					count++;
				}
			}
		}

		cout << "Image number " << set << " contains " << count << " war eagles." << endl;

		set++;

		cin >> m;

	}

	return 0;
}