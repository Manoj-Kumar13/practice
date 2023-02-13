class Solution:
    def countOdds(self, low: int, high: int) -> int:
        count = 0
        if not low&1 and not high&1:
            count = (high-low)//2
        elif low&1 and high&1:
            count = (high-low)//2 + 1
        else:
            count = (high-low+1)//2
        
        return count
      
      # ques link = https://leetcode.com/problems/count-odd-numbers-in-an-interval-range
