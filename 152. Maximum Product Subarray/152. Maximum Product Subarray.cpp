class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
            If there is no zero in the A[].
                The answer must be A[0]*A[1]*...*A[i] OR A[j]*A[j+1]*...*A[n - 1]. (Try to prove yourself)
                    Prove:
                        We assum BIG LETTERS as positive (product) result, small letters as negative (product) result.
                        For every i, the splited two arrays:
                            There are only two patterns: One is "aBcD", and the other is "aBcDe".
                                For the first pattern, the maximum product would be "aBcD";
                                For the second patern, the maximum product would be "max (aBcD, BcDe)".
            Else, we have zero in the A[] (assum A[k] == 0).
                We could see A[0], A[1], ..., A[k-1] as an array and A[k+1], A[k+2], ..., A[n-1] is another.
        */
        int numsLength = nums.size();
        int ANS = INT_MIN;
        int frontSubArrayProduct = 0;
        int backSubArrayProduct = 0;

        for (int i = 0; i < numsLength; i++) {
            frontSubArrayProduct = frontSubArrayProduct ? frontSubArrayProduct * nums[i] : nums[i];
            backSubArrayProduct = backSubArrayProduct ? backSubArrayProduct * nums[numsLength - 1 - i] : nums[numsLength - 1 - i];

            if (frontSubArrayProduct > ANS) {
                ANS = frontSubArrayProduct;
            }
            if (backSubArrayProduct > ANS) {
                ANS = backSubArrayProduct;
            }
        }

        return ANS;
    }
};