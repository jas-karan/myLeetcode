class Solution {
public:
    long long process(string &s1, string &s2, int ind){
    if(ind == s1.size()) return 0;          // If we reach to the end then we are done
    if(s1[ind] == s2[ind]) return process(s1, s2, ind+1);   // if equal then directly move to the next index

    long long ans = INT_MAX;;
    for(int i=ind+1; i<s1.size(); i++){
        swap(s1[i], s1[ind]);               // swap the 2 positions
        // if chars were already equal at index 'i', then even if we remove it will only give a higher no
        if(s1[ind]==s2[ind] && s1[ind]!=s2[i]){         
            long long t = 1 + process(s1, s2, ind+1);
            ans = min(ans, t);
        }
        swap(s1[i], s1[ind]);               // backtrack
    }
    return ans;
}

int kSimilarity(string s1, string s2) {
    string sf1, sf2;
    for(int i=0; i<s1.size(); i++){
        if(s1[i] != s2[i]){                 // remove all chars that are already common
            sf1 = sf1 + s1[i];
            sf2 = sf2 + s2[i];
        }
    }
    return process(sf1, sf2, 0);
}
};