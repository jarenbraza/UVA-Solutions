#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> coor;

bool isValid(coor p) {

	return (p.first >= 0) && (p.second >= 0) && (p.first < 8) && (p.second < 8);

}

void addAdjNodes(pair<coor, int>& src, vector<vector<int>>& visited, queue<pair<coor, int>>& q) {

	int x = src.first.first;	// coor.x
	int y = src.first.second;	// coor.y

	// Generate possible knight moves
	vector<pair<int, int>> neighbors = {
		make_pair(x - 2, y - 1), make_pair(x - 2, y + 1),
		make_pair(x - 1, y - 2), make_pair(x - 1, y + 2),
		make_pair(x + 1, y - 2), make_pair(x + 1, y + 2),
		make_pair(x + 2, y - 1), make_pair(x + 2, y + 1)
	};

	// Push valid neighbors (with +1 distance of source node) onto queue
	for (pair<int, int> n : neighbors)
		if (isValid(n) && !visited[n.first][n.second])
			q.push(make_pair(n, src.second + 1));

}

int BFS(coor& src, coor& dest) {

	vector<vector<int>> visited(8, vector<int>(8, 0));

	queue<pair<coor, int>> q;
	q.push(make_pair(src, 0));

	while (!q.empty()) {
		
		pair<coor, int> p = q.front();

		visited[p.first.first][p.first.second] = 1;

		// Base Case: Destination finally reached
		if (p.first == dest)
			return p.second;

		addAdjNodes(p, visited, q);

		q.pop();

	}

	// Not found
	return 0;

}

int main() {
	
	string op1, op2;

	cin >> op1;

	while (cin) {

		cin >> op2;

		// Coordinates given as:   [ (a, b, ..., h) , (1, 2, ..., 8) ]
		// Make coordinates to be: [ (0, 1, ..., 7) , (0, 1, ..., 7) ] for operations
		coor c1 = make_pair(op1[0] - 'a', op1[1] - '1');
		coor c2 = make_pair(op2[0] - 'a', op2[1] - '1');

		cout << "To get from " << op1 << " to " << op2 << " takes " 
			<< BFS(c1, c2) << " knight moves." << endl;

		cin >> op1;

	}

	return 0;
}