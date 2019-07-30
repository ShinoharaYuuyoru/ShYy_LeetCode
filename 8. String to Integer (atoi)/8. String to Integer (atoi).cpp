class Solution {
public:
	int myAtoi(string str) {
		// Delete frontlead space.
		string::iterator leadSpaceDltItr;
		for (leadSpaceDltItr = str.begin();;)
		{
			if (*leadSpaceDltItr == ' ')
			{
				leadSpaceDltItr = str.erase(leadSpaceDltItr);
			}
			else
			{
				break;
			}
		}

		// Start from:
		// '-'+any_number
		// '+'+any_number
		// ' '
		// any number
		smatch start;
		regex startE("(^[ 0-9])|(^[-\\+][0-9]+)");

		if (!regex_search(str, start, startE))
		{
			return 0;
		}
		else
		{
			smatch m;
			regex e("(\\+?\\d+)|(-?\\d+)");

			regex_search(str, m, e);

			string numStr = m[0];

			int position = m.position(0);
			if (numStr[0] == '-' || numStr[0] == '+')
			{
				// e.g. -+2 -> return 0;
				if (position - 1 >= 0)
				{
					if (str[position - 1] == '+' || str[position - 1] == '-')
					{
						return 0;
					}
				}
			}
			else
			{
				// e.g. - 321 -> return 0;
				if (position - 1 >= 0)
				{
					if (!(str[position - 1] == '+' || str[position - 1] == '-'))
					{
						return 0;
					}
				}
			}

			// Valid case
			if (numStr[0] == '-')
			{
				// -123456789
				long long int finalNum = 0;
				string::iterator itr;
				for (itr = numStr.begin() + 1; itr != numStr.end(); itr++)
				{
					finalNum = finalNum * 10 - ((*itr) - 48);
					if (finalNum < INT_MIN)
					{
						return INT_MIN;
					}
					else
					{
						continue;
					}
				}

				return (int)finalNum;
			}
			else if (numStr[0] == '+')
			{
				// +123456789
				long long int finalNum = 0;
				string::iterator itr;
				for (itr = numStr.begin() + 1; itr != numStr.end(); itr++)
				{
					finalNum = finalNum * 10 + ((*itr) - 48);

					if (finalNum > INT_MAX)
					{
						return INT_MAX;
					}
					else
					{
						continue;
					}
				}

				return (int)finalNum;
			}
			else
			{
				// 123456789
				long long int finalNum = 0;
				string::iterator itr;
				for (itr = numStr.begin(); itr != numStr.end(); itr++)
				{
					finalNum = finalNum * 10 + ((*itr) - 48);

					if (finalNum > INT_MAX)
					{
						return INT_MAX;
					}
					else
					{
						continue;
					}
				}

				return (int)finalNum;
			}
		}
	}
};