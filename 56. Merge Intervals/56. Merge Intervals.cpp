class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), compare);

		vector<vector<int>> ANS;

		int itr = 0;
		for (itr = 0; itr < intervals.size();)
		{
			int start = intervals[itr][0];
			int end = intervals[itr][1];

			int itr2 = 0;
			for (itr2 = itr + 1; itr2 < intervals.size(); itr2++)
			{
				int start2 = intervals[itr2][0];
				int end2 = intervals[itr2][1];

				if (end >= start2)
				{
					if (end >= end2)
					{
						continue;
					}
					else
					{
						end = end2;
					}
				}
				else
				{
					break;
				}
			}

			vector<int> interval(2, 0);
			interval[0] = start;
			interval[1] = end;
			ANS.push_back(interval);

			itr = itr2;
		}

		return ANS;
	}

private:
	static bool compare(const vector<int>& a, const vector<int>& b)
	{
		// Ascending for [0] and [1] postion
		if (a[0] < b[0])
		{
			return true;
		}
		else if (a[0] == b[0])
		{
			if (a[1] < b[0])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};