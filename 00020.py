class Solution:
    def isValid(self, s: str) -> bool:
        total = []
        dect = {')': '(', ']': '[', '}': '{'}
        for x in s:
            if x in ('(','[','{'):
                total.append(x)
            else:
                if len(total) == 0:
                    return False
                elif dect[x] == total[-1]:
                    total.pop(-1)
                else:
                    return False
        if len(total) == 0:
            return True
