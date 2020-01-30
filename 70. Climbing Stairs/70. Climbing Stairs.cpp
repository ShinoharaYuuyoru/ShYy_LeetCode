// // Brute Force
// // TLE: O(2^n)
// class Solution {
// public:
//     int climbStairs(int n) {
//         return climb_stairs(0, n);
//     }

//     int climb_stairs(int i, int n) {
//         if (i > n){
//             // Out of the destination.
//             return 0;
//         }
//         else if (i == n){
//             // Reach the destination.
//             return 1;
//         }
//         else{
//             // Still climing...
//             return climb_stairs(i + 1, n) + climb_stairs(i + 2, n);
//         }
//     }
// };


// // Recursion with Memorization
// // TLE: O(n)
// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> memo(n+1, 0);

//         return climb_stairs(0, n, memo) ;
//     }

//     int climb_stairs(int i, int n, vector<int> memo){
//         if (i > n){
//             // Out of destination
//             return 0;
//         }
//         else if (i == n){
//             // Reach destination
//             return 1;
//         }
//         else if (memo[i] > 0){
//             // There is a record in memory
//             return memo[i];
//         }
//         else{
//             // Still climing...
//             memo[i] = climb_stairs(i+1, n, memo) + climb_stairs(i+2, n, memo);
//             return memo[i];
//         }
//     }
// };

// // DP
// // O(n); O(n)
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n == 1){
//             return 1;
//         }
//         else if (n == 2) {
//             return 2;
//         }
//         else{
//             vector<int> dp(n+1, 0);
//             dp[1] = 1;
//             dp[2] = 2;
//             for(int climb = 3; climb <= n; climb++){
//                 dp[climb] = dp[climb - 1] + dp[climb - 2];
//             }

//             return dp[n];
//         }
//     }
// };


// Fibonacci
// O(n); O(1)
class Solution {
public:
	int climbStairs(int n) {
		if (n == 1) {
			return 1;
		}
		else if (n == 2) {
			return 2;
		}
		else {
			int first = 1;
			int second = 2;
			for (int i = 3; i <= n; i++) {
				int third = first + second;
				first = second;
				second = third;
			}

			return second;
		}
	}
};


// // Binets Method
// // Skip...
// class Solution {
// public:
//     int climbStairs(int n) {

//     }
// };