#include <iostream>
#include <string>
using namespace std;

/* Returns true if s1 is a subsequence of s2, false otherwise */
bool isSubsequence(string s1, string s2) {

	int n1 = s1.length();
	int n2 = s2.length();

	if (n1 > n2)
		return false;

	int i1 = 0;
	int i2 = 0;

	while (i1 < n1 && i2 < n2) {

		// Character match
		if (s1[i1] == s2[i2])
			i1++;

		i2++;

	}

	// True if all of s1 found in s2, false otherwise
	return (i1 == n1);

}

int main() {

	string s1, s2;

	cin >> s1;

	while (cin) {

		cin >> s2;

		if (isSubsequence(s1, s2))
			cout << "Yes" << endl;

		else
			cout << "No" << endl;

		cin >> s1;

	}

	return 0;
}