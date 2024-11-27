#User function Template for python3

class Solution:
    def missingNumber(self,arr):
        arr=set(arr)
        i=1
        while i in arr:
            i+=1
        return i


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    T = int(input())
    while (T > 0):
        arr = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.missingNumber(arr))
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends