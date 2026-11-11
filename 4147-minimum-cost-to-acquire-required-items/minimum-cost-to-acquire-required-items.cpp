class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        int mini_cost_for_both = min(costBoth, cost1 + cost2);
        long long starting_cost = 1LL * min(need1, need2) * mini_cost_for_both;
        int mini_amount=min(need1, need2);
        need1 -= mini_amount;
        need2 -= mini_amount;

        if (need1) {
            int mini_cost = min(costBoth, cost1);
            starting_cost += (1LL * need1 * mini_cost);
        }

        if (need2) {
            int mini_cost = min(costBoth, cost2);
            starting_cost += (1LL * need2 * mini_cost);
        }

        return starting_cost;
    }
};