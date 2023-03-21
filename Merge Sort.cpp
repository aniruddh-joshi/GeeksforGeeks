class Solution
{
    public:
    void merge(int arr[], int s, int m, int e)
    {
        int l1=m-s+1;
        int l2=e-m;
        int*t1=new int[l1];
        int*t2=new int[l2];
        int k=s;
        for(int i=0;i<l1;i++) t1[i]=arr[k++];
        for(int i=0;i<l2;i++) t2[i]=arr[k++];
        k=s;
        int i=0, j=0;
        while(i<l1 && j<l2){
            if(t1[i]<t2[j]) arr[k++]=t1[i++];
            else arr[k++]=t2[j++];
        }
            while(i<l1){
                arr[k++]=t1[i++];
            }
            while(j<l2){
                arr[k++]=t2[j++];
            }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return ;
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
};
