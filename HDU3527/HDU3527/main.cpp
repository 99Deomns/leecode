#include <iostream>
#include <vector>

using namespace std;

vector<string> A, B, C, ans;
int main() {
	int a, b, c;
	string s;
	while (cin >> a >> b >> c) {
		A.clear(); B.clear(); C.clear(); ans.clear();
		for (int i = 0; i < a; i++)
		{
			cin >> s;
			A.push_back(s);
		}
		for (int i = 0; i < b; i++)
		{
			cin >> s;
			B.push_back(s);
		}
		for (int i = 0; i < c; i++)
		{
			cin >> s;
			C.push_back(s);
		}
	}
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < c; j++) {
			if (B[i] == C[j]) {
				ans.push_back(B[i]);
			}
		}
	}
	if (ans.size()) {
		for (int i = 0; i < ans.size(); i++) {
			cout << "×¥²¶£º " << ans[i] << endl;
		}
	}
	else {
		cout << "no enemy!" << endl;
	}
	

	return 0;
}