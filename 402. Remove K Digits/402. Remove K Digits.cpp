class Solution {
public:
	string removeKdigits(string num, int k) {
		auto stack = string();

		for (auto& i : num)
		{
			for (; stack.size() && stack.back() > i && k > 0; k--)
			{
				stack.pop_back();
			}
			stack.push_back(i);
		}

		for (; stack.size() && k > 0; k--)
		{
			stack.pop_back();
		}

		size_t firstNotZeroIdx = stack.find_first_not_of('0');
		return (firstNotZeroIdx == string::npos) ? "0" : stack.substr(firstNotZeroIdx);
	}
};