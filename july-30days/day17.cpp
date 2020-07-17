class Solution {
public:
    
    unordered_map<int, int> m;
    
    int partition(vector<int>& arr, int l, int r, int pivot){
        //move pivot to right most pisition
        //pivot is inside [l,r]
        int tmp = arr[r];
        arr[r] = arr[pivot];
        arr[pivot] = tmp;
        int sorted_position = l;
        for(int i = l; i < r; i++){
            if(m[arr[i]] < m[arr[r]]){
                tmp = arr[i];
                arr[i] = arr[sorted_position];
                arr[sorted_position] = tmp;
                sorted_position++;
            }
        }
        tmp = arr[sorted_position];
        arr[sorted_position] = arr[r];
        arr[r] = tmp;
        return sorted_position;
    }
    
    
    int quickSelect(vector<int>& arr, int l, int r, int k){
        if(l == r){
            return l;
        }
        if(l > r){
            return -1;
        }
        int n = arr.size();
        int pindex = l+rand()%(r-l);
        int partitionIndex = partition(arr, l, r, pindex);
        if(n-partitionIndex == k){
            return partitionIndex;
        }else if(n-partitionIndex < k){
            return quickSelect(arr, l, r-1, k);
        }else{
            return quickSelect(arr, l-1, r, k);
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //we choose pivot index and then we do partition
        //we can decide in which part there is a solution
        //if(k == (int)nums.size()) return nums;
        for(int x : nums) m[x]++;
        vector<int> arr; 
        for(pair<int, int> p : m){
            arr.push_back(p.first);
        }
        int n = arr.size();
        int indx = quickSelect(arr, 0, n-1, k);
        vector<int> res;
        for(int i = n-1; i >= max(indx,0); i--){
            res.push_back(arr[i]);
        }
        return res;
    }
};
