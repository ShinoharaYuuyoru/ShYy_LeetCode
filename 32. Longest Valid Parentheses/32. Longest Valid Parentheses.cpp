class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty() == true) {
			return 0;
		}

		int ANS = 0;

		int mainPtr = 0;
		for (; mainPtr < s.size();) {
			if (s[mainPtr] == ')') {
				mainPtr++;
				continue;
			}
			else {
				// The valid parentheses should start from '('
				int parenthesesLength = 0;
				int endPtr = 0;
				parenthesesLength = getParenthesesLength(s, &mainPtr, &endPtr);

				if (parenthesesLength)
					if (parenthesesLength > ANS) {
						ANS = parenthesesLength;
					}

				mainPtr = endPtr;
			}
		}

		return ANS;
	}

	int getParenthesesLength(string s, int* startPtr, int* endPtr) {
		// s[*start] should must start from '('
		// The function will return the max parentheses length from a '('
		// And return endPtr.
		int parenthesesGroup = 0;       // Return parenthesesGroup*2.

		// Already have one left bracket. Queue.
		int leftBracketNum = 1;

		// Iterator.
		int itr = *startPtr;

		// If push '(' when there is no left bracket, record this break point.
		int breakPoint = itr + 1;
		int tempParenthesesGroup = 0;

		// Start iteration.
		for (itr = itr + 1; itr < s.size(); itr++) {
			if (s[itr] == '(') {
				if (leftBracketNum == 0) {
					// Break point recording.
					breakPoint = itr;
					parenthesesGroup = tempParenthesesGroup;
				}

				leftBracketNum++;

				continue;
			}
			else {
				// s[itr] == ')'
				if (leftBracketNum == 0) {
					// Left bracket queue already empty.
					// Invalid.
					break;
				}
				else {
					// Valid.
					leftBracketNum--;
					tempParenthesesGroup++;

					continue;
				}
			}
		}

		if (leftBracketNum == 0) {
			// Traversed the whole string and there is no left bracket remained.
			*endPtr = itr;
			parenthesesGroup = tempParenthesesGroup;
		}
		else {
			// Traversed the whole string, but there are some left brackets remained.
			// We should return the break point where the last time left bracket num == 0.
			*endPtr = breakPoint;
		}

		return parenthesesGroup * 2;
	}
};