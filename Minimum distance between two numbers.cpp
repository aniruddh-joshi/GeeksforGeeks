
class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
       int ans=INT_MAX,xInd=-1,yInd=-1;
       for(int i=0;i<n;i++)
       {
           if(a[i]==x)
           {
               xInd=i;
           }
           else if(a[i]==y)
           {
               yInd=i;
           }
           if(xInd != -1 && yInd != -1)
           {
               ans=min(ans,abs(xInd-yInd));
           }
       }
       return ans==INT_MAX?-1:ans;
    }
};
