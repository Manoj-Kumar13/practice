class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ans = []
        for x in range(1,n+1):
            if x % 15 == 0:
                ans.append("FizzBuzz")
            elif x % 5 == 0:
                ans.append("Buzz")
            elif x % 3 == 0:
                ans.append("Fizz")
            else:
                ans.append(str(x))
            
        return ans
      
# ques link : https://leetcode.com/problems/fizz-buzz/description/
