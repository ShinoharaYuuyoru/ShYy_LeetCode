class Solution {
public:
	string intToRoman(int num) {
		string table[4][10] = {
			{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
			{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
			{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
			{"", "M", "MM", "MMM"}
		};

		string numInRoman;
		int counter = 0;
		for (; num > 0;)
		{
			int temp = num % 10;
			numInRoman = table[counter][temp] + numInRoman;       // Must in this add order.
			num = num / 10;
			counter++;
		}

		return numInRoman;
	}
};