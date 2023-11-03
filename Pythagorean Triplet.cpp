class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    int ans[n];
	    for(int i=0;i<n;i++){
	        ans[i]=arr[i]*arr[i];
	    }
	    sort(ans,ans+n);
	    for(int i=n-1;i>1;i--){
	        int element=i,l=0,r=i-1;
	        while(l<r){
	            if(ans[l]+ans[r]==ans[element]) return true;
	            else if(ans[l]+ans[r]>ans[element])  r--;
	            else l++;
	        }
	    }
	    return false;
	}
};
