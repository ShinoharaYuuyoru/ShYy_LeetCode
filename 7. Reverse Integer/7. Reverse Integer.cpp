class Solution {
public:
	int reverse(int x) {
		if (x == 0)
		{
			return 0;
		}
		else
		{
			long long int ANS = 0;

			int dupli = x;
			for (; dupli != 0;)
			{
				ANS = ANS * 10 + dupli % 10;
				dupli = dupli / 10;
			}

			if (x > 0)
			{
				if (ANS > INT_MAX)
				{
					return 0;
				}
				else
				{
					return (int)ANS;
				}
			}
			else
			{
				if (ANS < INT_MIN)
				{
					return 0;
				}
				else
				{
					return (int)ANS;
				}
			}
		}
	}
};