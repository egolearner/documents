/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 *
 * https://leetcode.com/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (33.07%)
 * Likes:    411
 * Dislikes: 337
 * Total Accepted:    58.5K
 * Total Submissions: 177K
 * Testcase Example:  '8'
 *
 *
 * Given a positive integer n and you can do operations as follow:
 *
 *
 *
 *
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 *
 *
 *
 *
 * What is the minimum number of replacements needed for n to become 1?
 *
 *
 *
 *
 * Example 1:
 *
 * Input:
 * 8
 *
 * Output:
 * 3
 *
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 *
 *
 *
 * Example 2:
 *
 * Input:
 * 7
 *
 * Output:
 * 4
 *
 * Explanation:
 * 7 -> 8 -> 4 -> 2 -> 1
 * or
 * 7 -> 6 -> 3 -> 2 -> 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    unordered_map<long, int> mem{{1, 0}, {2, 1}};
    int integerReplacement(long n) {
        auto it = mem.find(n);
        if (it != mem.end()) {
            return it->second;
        }
        int val;
        if ((n & 1) == 0) {
            val = integerReplacement(n / 2) + 1;
        } else {
            val = min(integerReplacement(n + 1), integerReplacement(n - 1)) + 1;
        }
        mem[n] = val;
        return val;
    }
    int integerReplacement(int n) {
        return integerReplacement((long)n);
    }
};
// @lc code=end

/* XXX
INT_MAX没处理好。
从头到尾记录导致TLE

# 通过(N&3)==3判断奇数的方向
class Solution {
public:
    int integerReplacement(int n) {
        int count=0;
        long N=n;
        while(N!=1)
        {
        if (N%2==0)
        {count++;N=N/2;}
        else
        {
            if(N==3){count+=2;break;}
            else
            {
                if((N&3)==3)
                    N+=1;
                else
                    N-=1;
                count++;
            }
        }
        }
       return count;
    }
};

# 利用库的bit操作函数
class Solution {
public:
    int nob( long long int n)
    {
        int cnt = 0;
        while(n>0)
        {
            n = n&(n-1);
            cnt++;

        }
        return cnt;
    }
    int integerReplacement(int n)
    {
        int cnt = 0;
        if(n == INT_MAX)
        {
            return 32;
        }
        while(n!=1)
        {
            if(n&1)
            {
                if((nob((long long int)(n+1)) > nob(n-1)) ||(n==3))
                {
                    n--;
                }
                else
                {
                    n++;
                }
                cnt++;
                 cout<<n<<" "<<cnt<<endl;
            }
            else
            {
                int i = ffs(n);
                n = n>>(i-1);
                cnt += (i-1);
                 cout<<n<<" "<<cnt<<endl;
            }
        }
        return cnt;
    }
};
*/

