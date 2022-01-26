class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        int sz = m+n;
        
        // half elements are smaller than median and half are larger
        // we select half smaller elements
        // but from where? how many from 'a' and how many from 'b'?
        // we select some elements from 'a' and rest of smaller from 'b'
        // we binary search the cut in 'a'
        if(m>n) return findMedianSortedArrays(b,a);
        int l=0,h=m;
        
        while(l<=h){
            
            int cut_a = (l+h)/2;
            int cut_b = (sz+1)/2 - cut_a;  //remaining half of smaller half
            
            int left_a = (cut_a==0)? INT_MIN : a[cut_a-1];
            int right_a = (cut_a==m)? INT_MAX : a[cut_a];
            int left_b = (cut_b==0)? INT_MIN : b[cut_b-1];
            int right_b = (cut_b==n)? INT_MAX : b[cut_b];
            
            //both the left values should be smaller than right values
            //to make sure that we select smaller half.
            
            if(left_a<=right_b && left_b<=right_a){
                
                //then return median
                if(sz%2==0){
                    return (max(left_a,left_b)+min(right_a,right_b))/2.0;
                }
                else return max(left_a,left_b);
            }
            
            else if(left_a>right_b){  //then more elements from b has to be taken
                h=cut_a-1;
            }
            
            else if(left_b>right_a){
                l=cut_a+1;
            }
        }
        
        return 0.0;
    }
};