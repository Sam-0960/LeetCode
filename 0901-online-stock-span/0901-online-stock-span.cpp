class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind = -1;
    StockSpanner() {
        ind = -1;
        st = stack<pair<int,int>>();
    }
    
    int next(int price) {
        ind = ind +1;
        int ans = 0;
        while(!st.empty() && st.top().second <= price) st.pop();
        if(st.empty()) ans = ind +1;
        else ans = ind - st.top().first;
        st.push(make_pair(ind,price));
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */