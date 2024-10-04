class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trap(vector<int>& arr){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = arr.size();
        int left[n];
        int right[n];
        left[0]=arr[0];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]>arr[i]?left[i-1]:arr[i];
        }
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]>arr[i]?right[i+1]:arr[i];
        }
        int ans[n];
        
        for(int i=0;i<n;i++){
            ans[i]= (left[i]<right[i]?left[i]:right[i])-arr[i];
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=ans[i];
        }
        return sum;
        
       
        // code here
    }
};
