// // 1. Hash
// // 20ms 38.43%, 10.7MB 29.63%.
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> hashMap;

//         for(int i = 0; i < nums.size(); i++){
//             auto search = hashMap.find(nums[i]);
//             if(search == hashMap.end()){
//                 hashMap.insert(make_pair(nums[i], 1));
//             }
//             else{
//                 search = hashMap.erase(search);
//             }
//         }

//         return (*hashMap.begin()).first;
//     }
// };


// // 2. Math. 2*(a+b+c)-(a+a+b+b+c)=c
// // 28ms 13.78%, 11MB 29.63%.
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int realSum = 0;
//         set<int> numSet;

//         for(int i = 0; i < nums.size(); i++){
//             numSet.insert(nums[i]);
//             realSum += nums[i];
//         }

//         int doubleSetSum = 0;
//         for(auto setItr : numSet){
//             doubleSetSum += setItr*2;
//         }

//         return doubleSetSum - realSum;
//     }
// };


// 3. Bit XOR
// 12ms 94.16%, 8.9MB 100.00%.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }

        return ans;
    }
};