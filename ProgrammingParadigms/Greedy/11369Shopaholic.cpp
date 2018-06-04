/* UVA 11369 - Shopaholic */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int T, n;

	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> n;

		vector<int> costs(n);

		for (int i = 0; i < n; i++)
			cin >> costs[i];

		sort(costs.begin(), costs.end(), [](int a, int b) {return a > b;});

		int res = 0;
		for (int i = 2; i < costs.size(); i += 3)
			res += costs[i];

		cout << res << endl;

	}

	return 0;
}
