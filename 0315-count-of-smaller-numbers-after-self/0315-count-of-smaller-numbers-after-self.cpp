#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        oset<int>s;
        int n = nums.size();
        vector<int>cnt(n,0);
        
        for(int i=n-1;i>=0;i--){
            cnt[i] = s.order_of_key(nums[i]);
            
            s.insert(nums[i]);
        }
        return cnt;
    }
};