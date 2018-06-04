#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string s) {

	stack<char> stk;

	for (int i = 0; i < s.length(); i++) {

		// Opening parentheses
		if (s[i] == '(')
			stk.push(')');

		else if (s[i] == '[')
			stk.push(']');

		// Closing parentheses
		else {

			if (stk.empty() || (stk.top() != s[i]))
				return false;

			stk.pop();

		}

	}

	return stk.empty();
}

int main() {

	int T;
	string s;

	getline(cin, s);

	T = stoi(s);

	for (int t = 0; t < T; t++) {

		getline(cin, s);

		if (isBalanced(s))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}

	return 0;
}