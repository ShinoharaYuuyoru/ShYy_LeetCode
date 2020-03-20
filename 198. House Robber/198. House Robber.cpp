class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            There are only two action at each shop: Rob or Not.
        */
        int prePre = 0;
        int pre = 0;

        for (int i = 0; i < nums.size(); i++) {
            int now = max(prePre + nums[i], pre);

            prePre = pre;
            pre = now;
        }

        return pre;
    }
};