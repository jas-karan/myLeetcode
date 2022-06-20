class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
		int directly_satisfied = 0;

		for(int i = 0; i < n; i++) {
			if(!grumpy[i]) {
				directly_satisfied += customers[i];
				customers[i] = 0;
			}
		}

		int secretly_satisfied = 0, sum = 0;
		for(int i = 0; i < n; i++) {
			sum += customers[i];
			if(i>=X)
				sum -= customers[i-X];
			secretly_satisfied = max(secretly_satisfied, sum);
		}

		return directly_satisfied + secretly_satisfied;
    }
};