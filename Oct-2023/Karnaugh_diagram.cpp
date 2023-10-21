//2023-10-21
//计科2班-李健豪

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 最小项
struct MinTerm {
    int value;
    bool used;

    MinTerm(int val) : value(val), used(false) {}
};

// 检查两个最小项是否只相差一个位数
bool isAdjacent(const MinTerm& a, const MinTerm& b) {
    int xorResult = a.value ^ b.value;
    int setBits = __builtin_popcount(xorResult);
    return setBits == 1;
}

// 获取两个最小项之间的公共位数位置
int getCommonBits(const MinTerm& a, const MinTerm& b) {
    int result = 0;
    int xorResult = a.value ^ b.value;
    while (xorResult) {
        result++;
        xorResult >>= 1;
    }
    return result - 1;
}

int main() {
    int numVariables;
    cout << "请输入变量的个数: ";
    cin >> numVariables;

    int numMinTerms;
    cout << "请输入最小项的数量: ";
    cin >> numMinTerms;

    vector<MinTerm> minTerms;

    for (int i = 0; i < numMinTerms; i++) {
        int minTermValue;
        cout << "请输入最小项 #" << i + 1 << ": ";
        cin >> minTermValue;
        minTerms.push_back(MinTerm(minTermValue));
    }

    // 存储已经化简的最小项
    vector<MinTerm> simplifiedMinTerms;

    // 化简
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < minTerms.size(); i++) {
            MinTerm& term1 = minTerms[i];
            if (term1.used) {
                continue;
            }
            for (int j = i + 1; j < minTerms.size(); j++) {
                MinTerm& term2 = minTerms[j];
                if (!term2.used && isAdjacent(term1, term2)) {
                    int commonBits = getCommonBits(term1, term2);
                    // 找到可以合并的最小项
                    term1.used = true;
                    term2.used = true;
                    int mergedTerm = term1.value & (~(1 << commonBits));
                    simplifiedMinTerms.push_back(MinTerm(mergedTerm));
                    changed = true;
                }
            }
        }
    }

    // 从simplifiedMinTerms中提取值并进行去重和排序
    vector<int> result;
    for (const MinTerm& term : simplifiedMinTerms) {
        result.push_back(term.value);
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    cout << "卡诺图的最简形式为: ";
    for (const int& minTerm : result) {
        cout << minTerm << " ";
    }

    cout << endl;

    return 0;
}
