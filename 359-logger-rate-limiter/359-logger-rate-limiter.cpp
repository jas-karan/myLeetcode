class Logger {
public:
    unordered_map<string,int>time;
    
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(time.find(message)!=time.end() && timestamp-time[message]<10) 
            return false;
        else{
            time[message]=timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */