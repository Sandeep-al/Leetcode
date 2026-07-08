class StockSpanner {
public:
    // so i have to find index of prev strictly greater element
    stack<pair<int, int>> st;
    int curr_idx;
    StockSpanner() { curr_idx = -1; }

    int next(int price) {

        curr_idx++;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int idx = -1;
        if (!st.empty()) {
            idx = st.top().second;
        }
        st.push({price, curr_idx});
        if (idx == -1) {
            return curr_idx+1;
        } // pura stock empty hogaya

        return curr_idx - idx;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */