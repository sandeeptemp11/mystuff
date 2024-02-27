vector<vector<int>> pairSum(vector<int> &ele, int s){
   // why not count all equal elements and place the counts, to make cleaner solution
   vector <vector<int>> ans;
   sort(ele.begin(), ele.end());
   int n = ele.size();
   int i = 0;
   vector <int> arr, count;
   while(i < n){
       arr.push_back(ele[i++]);
       int c = 1;
       while(i < n && ele[i] == ele[i-1]) {c++;i++;}
       count.push_back(c);
   }
   i = 0;
   int j = arr.size()-1;
   while(i < j){
       if(arr[i] + arr[j] == s){
           for(int k = 0; k < count[i] * count[j];k++) ans.push_back({arr[i], arr[j]});
           i++; j--;
       }else if(arr[i] + arr[j] > s) j--;
       else i++;
   }
   if(i == j && 2*arr[i] == s) for(int k = 0; k < count[i]*(count[i] - 1)/2; k++) ans.push_back({arr[i], arr[i]});
   return ans;
}
