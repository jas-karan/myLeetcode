class Log {
public:
    string msg;
    int time;
    
    Log(string s,int t){
        msg=s;
        time=t;
    }
};

class Logger {
public:
    deque<Log>window;
    set<string>set;
    
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        while(!window.empty() && timestamp-window.front().time>=10){
            string s = window.front().msg;
            window.pop_front();
            set.erase(s);
        }
        if(set.find(message)!=set.end()) return false;
        Log l =  Log(message,timestamp);
        window.push_back(l);
        set.insert(message);
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */