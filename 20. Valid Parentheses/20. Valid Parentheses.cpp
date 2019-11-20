class Solution {
public:
	bool isValid(string s) {
		bool ANS = true;

		stack<char> STACK;
		int itr = 0;
		for (; itr < s.size(); itr++) {
			char nowChara = s[itr];
			if (nowChara == '(' || nowChara == '[' || nowChara == '{') {
				STACK.push(nowChara);
				continue;
			}
			if (nowChara == ')' || nowChara == ']' || nowChara == '}') {
				if (STACK.empty() == true) {
					ANS = false;
					break;
				}
				else {
					char stackTop = STACK.top();
					if (stackTop == '(' && nowChara == ')' || stackTop == '[' && nowChara == ']' || stackTop == '{' && nowChara == '}') {
						STACK.pop();
						ANS = true;
						continue;
					}
					else {
						ANS = false;
						break;
					}
				}
			}
		}

		if (itr == s.size() && STACK.empty() == true) {
			ANS = true;
		}
		else {
			ANS = false;
		}

		return ANS;
	}
};