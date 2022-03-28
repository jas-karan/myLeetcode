class Solution {
public:
    unordered_map<int,vector<char>>mp;

void call(string digits,int i,vector<string>&ans,string curr){
	if(i==digits.length() && curr!=""){
		ans.push_back(curr);
		return;
	}
	int d = digits[i]-'0';
	for(char c:mp[d]){
		call(digits,i+1,ans,curr+c);
	}
}

vector<string> letterCombinations(string digits) {
    // add your logic here
	mp[2] = {'a','b','c'};
	mp[3] = {'d','e','f'};
	mp[4] = {'g','h','i'};
	mp[5] = {'j','k','l'};
	mp[6] = {'m','n','o'};
	mp[7] = {'p','q','r','s'};
	mp[8] = {'t','u','v'};
	mp[9] = {'w','x','y','z'};
	
	vector<string>ans;
	call(digits,0,ans,"");
	return ans;
}
};