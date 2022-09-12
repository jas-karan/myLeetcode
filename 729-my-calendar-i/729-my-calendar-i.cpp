class MyCalendar {
public:
    set<pair<int,int>>bookings;
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto itr = bookings.lower_bound({start,end});
        if(itr!=bookings.end() && itr->second<end) return false;
        
        bookings.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */