/*
Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
/*
XXX 理解错了题目，貌似不能用long类型
class Solution {
public:
    int reverse(int x) {
        int64_t xx = x;
        bool negtive = false;
        if (xx < 0) {
            negtive = true;
            xx = -xx;
        }
        int64_t result = 0;
        while (xx) {
            result = result * 10 + xx%10;
            xx = xx/10;
        }
        // XXX use xx instead of result
        if (negtive) {
            result = -result;
        }
        //XXX no LL
        if ( result < -(1LL << 31)  ||  result  >=  (1LL << 31)-1) {
            result = 0;
        }
        return static_cast<int>(result);
    }
};
*/
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x) {
            int digit = x%10;
            x /= 10;
            if ((result == INT_MAX/10  && digit > INT_MAX%10) ||
                    (result == INT_MIN/10  && digit < INT_MIN%10) ||
                    (result > INT_MAX/10) ||
                    (result < INT_MIN/10)) {
                return 0;
            }
            result = result * 10 + digit;
        }
        return result;
        
    }
};
