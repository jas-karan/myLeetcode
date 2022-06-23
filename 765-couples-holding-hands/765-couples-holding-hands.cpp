class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = row.size();
        int n = row.size();
        int count = 0;

        for (int i = 0; i < n; i += 2)
        {
            int curr = row[i];
            int to_find;
            if (curr & 1)
                to_find = curr - 1;
            else
                to_find = curr + 1;
            
            int found_index;

            for (int j = i + 1; j < n; j++)
            {
                if (row[j] == to_find)
                {
                    found_index = j;
                    break;
                }
            }
            swap(row[i + 1], row[found_index]);
            if (found_index != i + 1)
                count++;
        }
        return count;
    }
};