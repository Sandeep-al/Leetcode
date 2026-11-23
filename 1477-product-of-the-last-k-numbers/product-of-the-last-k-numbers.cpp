class ProductOfNumbers {
public:
    vector<int> nums;

    ProductOfNumbers() {
        nums.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            nums.clear();
            nums.push_back(1);
        } else {
            nums.push_back(nums.back() * num);
        }
    }

    int getProduct(int k) {
        int n = nums.size();

        if (k >= n) {
            return 0;
        }

        return nums[n - 1] / nums[n - 1 - k];
    }
};