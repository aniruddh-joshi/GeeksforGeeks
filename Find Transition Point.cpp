class Solution{
    public:
        int transitionPoint(int arr[], int n) {
        if(n==1){
            if(arr[0]==1){
                return 0;
            }
            return -1;
        }
        for(int i =0 ; i < n ; i++){
            if(arr[i]==1){
                return i;
            }
        }
        return -1;
    }
};
