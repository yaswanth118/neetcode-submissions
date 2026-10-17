class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.size()!=0){
            pair<int,int> bk = v.back();
            v.push_back({val, min(val,bk.second)});
        } else {
            v.push_back({val, val});
        }
        

    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
private:
    vector<pair<int,int>> v;
};
