class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string prefix = "";

		if (strs.size() == 0)
		{
			return prefix;
		}
		else
		{
			vector<string>::iterator itr = strs.begin();
			prefix = *itr;
			for (itr++; itr != strs.end(); itr++)
			{
				while (1)
				{
					size_t index = (*itr).find(prefix);
					if (index != 0)
					{
						// Not found.
						prefix.pop_back();
						if (prefix == "")
						{
							// If already has no prefix.
							return prefix;
						}
					}
					else
					{
						break;
					}
				}
			}

			return prefix;
		}
	}
};