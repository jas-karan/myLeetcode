class Solution {
public:

    //idea : obviously use hashmap for lookup
    //two hashmaps: another one to see if longurl is already encoded
    
    unordered_map<string,string>longDB,shortDB;
    
    //we can create any random code for longurl of a fix length and use that
    //we also should make sure that random code is diff for diff longurls
    
    string getCode(string longUrl){
        string code="";
        for(int i=0;i<6;i++){
            code+=(char)(rand()%256);
        }
        
        return code;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(longDB.find(longUrl)!=longDB.end()){
            return longDB[longUrl];
        }
        
        string code = getCode(longUrl);
        while(shortDB.find(code)!=shortDB.end()) code=getCode(longUrl);
        
        longDB[longUrl] = code;
        shortDB[code] = longUrl;
        
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortDB[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));