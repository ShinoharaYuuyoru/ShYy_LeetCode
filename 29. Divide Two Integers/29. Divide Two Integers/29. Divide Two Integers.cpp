#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	//// Refer to: https://www.jianshu.com/p/7bba031b11e7
	//// This is the solution using bit calculation.
	//// But this not work for the problem because of the range of the test case is too strict.
	//// Just for learning.

	//int add(int num1, int num2)
	//{
	//	int sum = num1 ^ num2;
	//	int carry = (num1 & num2) << 1;

	//	while (carry != 0)
	//	{
	//		int a = sum;
	//		int b = carry;
	//		sum = a ^ b;
	//		carry = (a & b) << 1;
	//	}

	//	return sum;
	//}

	//int substract(int num1, int num2)
	//{
	//	int substractor = add(~num2, 1);
	//	int result = add(num1, substractor);

	//	return result;
	//}

	//int multiply(int num1, int num2)
	//{
	//	int absNum1 = abs(num1);
	//	int absNum2 = abs(num2);

	//	int product = 0;
	//	while (absNum2 > 0)
	//	{
	//		if ((absNum2 & 0x1) > 0)
	//		{
	//			product = add(product, absNum1);
	//		}

	//		absNum1 = absNum1 << 1;
	//		absNum2 = absNum2 >> 1;
	//	}

	//	if ((num1 ^ num2) < 0)
	//	{
	//		product = add(~product, 1);
	//	}

	//	return product;
	//}

	//int divide(int dividend, int divisor)
	//{
	//	int absDividend = abs(dividend);
	//	int absDivisor = abs(divisor);

	//	int quotient = 0;
	//	int remainder = 0;

	//	for (int i = 31; i >= 0; i--)
	//	{
	//		if ((absDividend >> i) >= absDivisor)
	//		{
	//			quotient = add(quotient, 1 << i);
	//			absDividend = substract(absDividend, absDivisor << i);
	//		}
	//	}

	//	if ((dividend ^ divisor) < 0)
	//	{
	//		quotient = add(~quotient, 1);
	//	}

	//	// Will not be returned.
	//	remainder = dividend > 0 ? absDividend : add(~absDividend, 1);
	//	//cout << "Remainder: " << remainder << endl;

	//	return quotient;
	//}


	// Thanks for the solution: https://leetcode.com/problems/divide-two-integers/discuss/314856/C%2B%2B-0ms-100-using-log()
	int divide(int dividend, int divisor)
	{
		int sign = (dividend < 0 ^ divisor < 0) ? -1 : 1;

		long lDividend = labs(dividend);
		long lDivisor = labs(divisor);

		long res = exp(log(lDividend) - log(lDivisor));

		if (res > INT_MAX)
		{
			return sign == 1 ? INT_MAX : INT_MIN;
		}

		return sign * (int)res;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int dividend = stringToInteger(line);
		getline(cin, line);
		int divisor = stringToInteger(line);

		int ret = Solution().divide(dividend, divisor);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}