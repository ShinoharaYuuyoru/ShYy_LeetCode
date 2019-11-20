class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ANS;

		if (digits.size() == 0) {
			return ANS;
		}

		vector<string> digitMap = {
			{""},       // 0
			{""},       // 1
			{"abc"},      // 2
			{"def"},      // 3
			{"ghi"},      // 4
			{"jkl"},      // 5
			{"mno"},      // 6
			{"pqrs"},      // 7
			{"tuv"},      // 8
			{"wxyz"}        // 9
		};

		// Initial total length of ANS.
		int itr = 0;
		int totalLength = 1;
		for (; itr < digits.size(); itr++) {
			totalLength = totalLength * digitMap[digits[itr] - 48].size();
		}

		int stringCounter = 0;
		for (; stringCounter < totalLength; stringCounter++) {
			string emptyString = "";
			ANS.push_back(emptyString);
		}

		// Start.
		itr = 0;
		for (; itr < digits.size(); itr++) {
			int cycleCnt = 0;      // How many times does this digit's numbers cycle.
			// Forward calculating cycleCnt.
			// 1*PI(Forward digit.string.size()). PI means accumulated multiplication.
			int idx = itr - 1;
			cycleCnt = 1;
			for (; idx >= 0; idx--) {
				cycleCnt = cycleCnt * digitMap[digits[idx] - 48].size();
			}

			int repeatCnt = 0;      // How many time does every character repeat.
			// Backward calculation repeatCnt.
			// 1*PI(Backward digit.string.size()). PI means accumulated multiplication.
			idx = itr + 1;
			repeatCnt = 1;
			for (; idx < digits.size(); idx++) {
				repeatCnt = repeatCnt * digitMap[digits[idx] - 48].size();
			}

			// Start adding characters to ANS.
			int nowDigit = digits[itr] - 48;
			int stringCounter = 0;
			int cycleCounter = 0;
			for (; cycleCounter < cycleCnt; cycleCounter++) {
				int charaItr = 0;
				for (; charaItr < digitMap[nowDigit].size(); charaItr++) {
					int repeatCounter = 0;
					for (; repeatCounter < repeatCnt; repeatCounter++) {
						ANS[stringCounter] = ANS[stringCounter] + digitMap[nowDigit][charaItr];
						stringCounter++;
					}
				}
			}
		}

		return ANS;
	}
};