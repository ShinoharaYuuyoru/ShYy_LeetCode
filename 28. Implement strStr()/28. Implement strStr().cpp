class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty() == true) {
			return 0;
		}
		if (haystack.empty() == true) {
			return -1;
		}

		bool findFlag = false;
		int ANS = 0;
		int searchPtr = 0;
		while (searchPtr < haystack.size()) {
			if (searchPtr + needle.size() - 1 >= haystack.size()) {
				break;
			}
			else {
				// The remained string size is >= than needle.size()
				int needleSearchPtr = 0;
				if (haystack[searchPtr] == needle[needleSearchPtr]) {
					// First chara equal.
					// Check remain.
					int subSearchPtr = searchPtr + 1;
					needleSearchPtr = 1;
					while (true) {
						if (needleSearchPtr < needle.size()) {
							if (haystack[subSearchPtr] == needle[needleSearchPtr]) {
								subSearchPtr++;
								needleSearchPtr++;
								continue;
							}
							else {
								// NO.
								// needleSearchPtr < needle.size()
								break;
							}
						}
						else {
							// OK.
							// needleSearchPtr == needle.size()
							break;
						}
					}

					// End check.
					if (needleSearchPtr == needle.size()) {
						// OK.
						findFlag = true;
						ANS = searchPtr;
						break;
					}
					else {
						// NO.
						searchPtr++;
						continue;
					}
				}
				else {
					searchPtr++;
					continue;
				}
			}
		}

		// return.
		if (findFlag == true) {
			return ANS;
		}
		else {
			return -1;
		}
	}
};