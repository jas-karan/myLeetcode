class FileSystem {
public:
    struct Node{
        bool hasFile;
        string content;
        map<string,Node*>child;
        Node(){
            hasFile=false;
            content="";
        }
        
    };
    
    Node *root;
    FileSystem() {
        root = new Node();
    }
    
    vector<string> ls(string path) {
        Node*crawl=root;
        string t="";
        for(int i=1;i<path.length();i++){
            if(path[i]!='/') t+=path[i];
            else{
                crawl=crawl->child[t];
                t="";
            }
        }
        if(t!="") crawl=crawl->child[t];
        if(crawl->hasFile) return {t};
        vector<string>ans;
        for(auto e:crawl->child){
            ans.push_back(e.first);
        }
        return ans;
    }
    
    void mkdir(string path) {
        Node*crawl=root;
        string t="";
        for(int i=1;i<path.length();i++){
            if(path[i]!='/') t+=path[i];
            else{
                if((crawl->child).find(t)==(crawl->child).end()) crawl->child[t]=new Node();
                crawl=crawl->child[t];
                t="";
            }
        }
        if(t!=""){
            if((crawl->child).find(t)==(crawl->child).end()) crawl->child[t]=new Node();
        }
    }
    
    void addContentToFile(string path, string content) {
        Node*crawl=root;
        string t="";
        for(int i=1;i<path.length();i++){
            if(path[i]!='/') t+=path[i];
            else{
                crawl=crawl->child[t];
                t="";
            }
        }
        if(t!=""){
            if((crawl->child).find(t)==(crawl->child).end()) crawl->child[t]=new Node();
            crawl=crawl->child[t];
        }
        crawl->hasFile=true;
        crawl->content+=content;
    }
    
    string readContentFromFile(string path) {
        Node*crawl=root;
        string t="";
        for(int i=1;i<path.length();i++){
            if(path[i]!='/') t+=path[i];
            else{
                crawl=crawl->child[t];
                t="";
            }
        }
        if(t!="") crawl=crawl->child[t];
        return crawl->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */