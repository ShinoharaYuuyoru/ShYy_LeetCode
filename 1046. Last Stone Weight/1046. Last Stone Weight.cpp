class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		sort(stones.begin(), stones.end(), greater<int>());

		while (stones.size() > 1)
		{
			int stoneY = stones[0];
			int stoneX = stones[1];
			stones.erase(stones.begin());
			stones.erase(stones.begin());

			if (stoneX == stoneY)
			{
				continue;
			}
			else
			{
				int newStone = stoneY - stoneX;
				stones.push_back(newStone);
				sort(stones.begin(), stones.end(), greater<int>());
			}
		}

		if (stones.size() > 1)
		{
			cout << "Final stone size error!" << endl;
			exit(1);
		}
		else if (stones.size() == 1)
		{
			int finalStone = stones[0];

			return finalStone;
		}
		else
		{
			return 0;
		}
	}
};