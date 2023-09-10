#include <iostream>
#include <vector>
#include <algorithm>

int calculateLCM(int a, int b) {
    return (a * b) / std::__gcd(a, b);
}

int countPairsWithLCM(std::vector<int>& arr1, std::vector<int>& arr2, int k) {
    int count = 0;
    int n = arr1.size();
    int m = arr2.size();

    // 计算arr2中所有元素的LCM
    int lcmArr2 = arr2[0];
    for (int i = 1; i < m; i++) {
        lcmArr2 = calculateLCM(lcmArr2, arr2[i]);
    }

    for (int i = 0; i < n; i++) {
        // 检查k是否是arr1[i]的因子，并且k/lcmArr2是arr1[i]的因子
        if (k % arr1[i] == 0 && calculateLCM(arr1[i], k / lcmArr2) == k) {
            count++;
        }
    }

    return count;
}

int main() {
    std::vector<int> arr1 = {2, 3, 4};
    std::vector<int> arr2 = {5, 6, 8};
    int k = 12;

    int result = countPairsWithLCM(arr1, arr2, k);
    std::cout << "满足最小公倍数等于 " << k << " 的元素组合数量为: " << result << std::endl;

    return 0;
}
