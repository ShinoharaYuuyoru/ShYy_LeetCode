#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	int carry = 0;

	int doSum(int l1Val, int l2Val, int c)
	{
		int sum = 0;
		sum = l1Val + l2Val + c;

		if (sum >= 10)
		{
			carry = 1;
			sum = sum - 10;
		}
		else
		{
			carry = 0;
		}

		return sum;
	}

public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* lANS = new ListNode(-1);	// This is the HEAD of the ANS, which should delete finally. -1, 0 1 2 3 4 5 ... 9 -> 0 1 2 3 4 5 ... 9.

		ListNode* l1Iter = l1;
		ListNode* l2Iter = l2;
		ListNode* lANSIter = lANS;

		while (true)
		{
			if (l1Iter == NULL && l2Iter == NULL)
			{
				// Final add and END.
				if (carry == 1)
				{
					int sum = 0;
					sum = doSum(0, 0, carry);

					ListNode* newANSNode = new ListNode(sum);
					lANSIter->next = newANSNode;
					lANSIter = newANSNode;
				}

				break;
			}
			else
			{
				if (l1Iter == NULL && l2Iter != NULL)
				{
					// Just copy l2 to ANS.
					int sum = 0;
					sum = doSum(0, l2Iter->val, carry);

					ListNode* newANSNode = new ListNode(sum);
					lANSIter->next = newANSNode;
					lANSIter = newANSNode;

					l2Iter = l2Iter->next;
				}
				else
				{
					if (l1Iter != NULL && l2Iter == NULL)
					{
						// Just copy l1 to ANS.
						int sum = 0;
						sum = doSum(l1Iter->val, 0, carry);

						ListNode* newANSNode = new ListNode(sum);
						lANSIter->next = newANSNode;
						lANSIter = newANSNode;

						l1Iter = l1Iter->next;
					}
					else
					{
						// DO ADD and set to ANS.
						int sum = 0;
						sum = doSum(l1Iter->val, l2Iter->val, carry);

						ListNode* newANSNode = new ListNode(sum);
						lANSIter->next = newANSNode;
						lANSIter = newANSNode;

						l1Iter = l1Iter->next;
						l2Iter = l2Iter->next;
					}
				}
			}
		}

		ListNode* realANSHead = lANS->next;
		if (realANSHead == NULL)
		{
			realANSHead = new ListNode(0);
		}

		ListNode* deleteANSHead = lANS;
		free(deleteANSHead);

		return realANSHead;
	}
};

void trimLeftTrailingSpaces(string& input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void trimRightTrailingSpaces(string& input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

string listNodeToString(ListNode* node) {
	if (node == nullptr) {
		return "[]";
	}

	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* l1 = stringToListNode(line);
		getline(cin, line);
		ListNode* l2 = stringToListNode(line);

		ListNode* ret = Solution().addTwoNumbers(l1, l2);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}