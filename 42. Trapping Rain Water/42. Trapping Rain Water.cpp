class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() < 3)
		{
			return 0;
		}

		int maxHeight = INT_MIN;
		int minHeight = INT_MAX;
		for (int itr0 = 0; itr0 < height.size(); itr0++)
		{
			if (height[itr0] > maxHeight)
			{
				maxHeight = height[itr0];
			}
			if (height[itr0] < minHeight)
			{
				minHeight = height[itr0];
			}
		}

		int trapWater = 0;

		for (int rain = minHeight + 1; rain <= maxHeight; rain++)
		{
			for (int itr1 = 0; itr1 < height.size() - 1; itr1++)
			{
				if (height[itr1] < rain)
				{
					continue;
				}
				else
				{
					int itr2 = itr1 + 1;
					while (itr2 < height.size())
					{
						if (height[itr2] < rain)
						{
							itr2++;
							continue;
						}
						else
						{
							trapWater = trapWater + (itr2 - itr1 - 1);

							itr1 = itr2;
							itr2 = itr1 + 1;
						}
					}
				}
			}
		}

		return trapWater;
	}
};