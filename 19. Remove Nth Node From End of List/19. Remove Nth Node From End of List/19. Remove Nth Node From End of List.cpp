#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;



struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int allCounter = 0;

		ListNode* iter = head;
		for (; iter != NULL;)
		{
			allCounter++;
			iter = iter->next;
		}

		int deletePosition = allCounter - n + 1;
		if (deletePosition == 1)
		{
			// Delete the head node.
			ListNode* newHead = head->next;
			delete head;

			return newHead;
		}
		else
		{
			ListNode* iterBefore = head;
			iter = head->next;
			for (int i = 2;;)
			{
				if (i == deletePosition)
				{
					break;
				}
				else
				{
					iterBefore = iterBefore->next;
					iter = iter->next;
					i++;
				}
			}

			iterBefore->next = iter->next;
			delete iter;

			return head;
		}
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

int stringToInteger(string input) {
	return stoi(input);
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
		ListNode* head = stringToListNode(line);
		getline(cin, line);
		int n = stringToInteger(line);

		ListNode* ret = Solution().removeNthFromEnd(head, n);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}