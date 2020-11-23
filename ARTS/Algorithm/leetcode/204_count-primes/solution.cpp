//Count the number of prime numbers less than a non-negative number, n. 
//
// 
// Example 1: 
//
// 
//Input: n = 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// 
//
// Example 2: 
//
// 
//Input: n = 0
//Output: 0
// 
//
// Example 3: 
//
// 
//Input: n = 1
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 0 <= n <= 5 * 106 
// 
// Related Topics Hash Table Math 
// 👍 2461 👎 684


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<int> primes = {2};
        for (int i = 3; i < n; i+=2) {
            bool is_prime = true;
            for (auto j : primes) {
                if (i % j == 0) {
                    is_prime = false;
                    break;
                }
                if (j * j >= i) {
                    break;
                }
            }
            if (is_prime) {
                primes.push_back(i);
            }
        }
        return primes.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

/* XXX 更快的筛法
    int countPrimes2(int n) {
        vector<bool> is_prime(n, true);

        int count = 0;
        for(long long i = 3; i < n; i += 2) {
            if(is_prime[i]) {
                count++;
                for(long long j = i * i; j < n; j += 2 * i) {
                    is_prime[j] = false;
                }
            }
        }

        return count + (n > 2 ? 1 : 0);
    }
*/
