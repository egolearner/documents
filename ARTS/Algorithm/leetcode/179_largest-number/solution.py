import functools
def cmper(a, b):
    if a+b < b+a:
        return 1
    return -1
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nstr = [str(i) for i in nums]
        nstr.sort(key=functools.cmp_to_key(cmper))
        r = ''.join(nstr)
        if r[0] == '0':
            return '0'
        return r

