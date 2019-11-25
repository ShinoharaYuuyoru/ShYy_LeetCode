class Solution {
private:
	vector<string> ANS;
public:
	vector<string> generateParenthesis(int n) {
		string nowStr = "";

		generateString(n, n, nowStr);

		return ANS;
	}

	void generateString(int left, int right, string nowStr) {
		if (left > right) {
			// left should always <= right!
			cout << "CRITICAL ERROR: left > right!" << endl;

			exit(1);
		}
		else if (left == right) {
			// left == right
			if (left == 0) {
				// left == right == 0
				// Generate.
				ANS.push_back(nowStr);
			}
			else {
				// left == right > 0
				nowStr.push_back('(');
				generateString(left - 1, right, nowStr);
			}
		}
		else {
			// left < right
			if (left > 0) {
				// left > 0 && right > 0
				// Add '('
				nowStr.push_back('(');
				generateString(left - 1, right, nowStr);

				// Or add ')'
				nowStr.pop_back();
				nowStr.push_back(')');
				generateString(left, right - 1, nowStr);
			}
			else {
				// left == 0 && right > 0
				// Add ')'
				nowStr.push_back(')');
				generateString(left, right - 1, nowStr);
			}
		}

		return;
	}
};