vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector <vector<int>> ans;
   sort(arr.begin(), arr.end());
   int i = 0, j = arr.size()-1;
   while(true){
       while(i < j && arr[i] + arr[j] != s){
           while(i < j && arr[i] + arr[j] > s) j--;
           while(i < j && arr[i] + arr[j] < s) i++;
       }

       if(i < j){
           // arr[i] + arr[j] = s
           int freql = 1; i++;
           while(i < j && arr[i] == arr[i-1]){
               i++; freql++;
           }
           int freqr = 1; j--;
           // for very subtle reason we have i <= j in  below expression in while loop
           while(i <= j && arr[j] == arr[j+1]){
               j--; freqr++;
           }
           int count = freql * freqr;
           if(arr[i-1] == arr[j+1]) count = (freql + freqr)*(freql + freqr - 1)/2;
           while(count--) ans.push_back({arr[i-1], arr[j+1]});
       }else break;
   }

   return ans;
}
