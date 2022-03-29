class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
	    string prev = "1",curr="";
	
	    while(--n){
		    int cnt = 1;
		    char c=prev[0];
		    for(int i=1;i<prev.length();i++){
			    if(prev[i]==prev[i-1]) cnt++;
			    else{
				    curr+=(to_string(cnt)+c);
				    c=prev[i];
				    cnt=1;
			    }
		    }
		    curr+=(to_string(cnt)+c);
		    prev=curr;
		    curr="";
	    }
	
	    return prev;
    }
};