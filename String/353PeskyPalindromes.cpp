/* UVA 353 - Pesky Palindromes */

#include <iostream>
#include <set>
#include <string>
using namespace std;

bool isPalindrome(string s) {

	int i = (s.length() - 1) / 2;
	int j = s.length() / 2;

	while (i >= 0 && j < s.length()) {

		if (s[i] != s[j])
			return false;

		i--;
		j++;

	}

	return true;
}

int main() {

	string s;

	cin >> s;

	while (cin) {

		int count = 0;

		set<string> st;

		// Check possible palindromes of length 1 to s.len
		for (int i = 1; i <= s.length(); i++) {

			// Go across string and check is substr of length i is palindrome
			for (int j = 0; j < s.length() - i + 1; j++) {

				string _s = s.substr(j, i);
				if (isPalindrome(_s)) {
					
					if (st.find(_s) == st.end()) {
						st.insert(_s);
						count++;
					}
				}
			}
		}

		cout << "The string \'" << s << "\' contains " << count << " palindromes." << endl;

		cin >> s;

	}

	return 0;
}
