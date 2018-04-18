#include <iostream>
#include <map>
using namespace std;

int main() {
	
	int n, op1, op2;

	cin >> n;

	while (cin && n != 0) {

		map<pair<int, int>, int> hm;

		for (int i = 0; i < n; i++) {

			cin >> op1 >> op2;

			pair<int, int> p = make_pair(op1, op2);

			hm[p]++;

		}

		map<pair<int, int>, int>::iterator it;

		bool valid = true;

		for (it = hm.begin(); it != hm.end(); it++) {

			// If this count does not match complement count, result is no
			pair<int, int> comp = make_pair((it->first).second, (it->first).first);
			if (it->second != hm[comp]) {
				valid = false;
				break;
			}

		}

		if (valid)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		cin >> n;

	}

	return 0;
}