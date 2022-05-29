class MyCalendar {
public:
    set<pair<int,int>>s; //sorted by end time ********* {end,start} **********
    
    MyCalendar() {}
    
    bool book(int start, int end) {
        //if there is some event that ends after curr event starts
        auto next = s.upper_bound({start,start});
        
        //and that starts before curr event ends (or starts) then it is not possible
        if(next!=s.end() && (*next).second<end) return false;
        
        s.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */