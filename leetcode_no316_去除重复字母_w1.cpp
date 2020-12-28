/* ------------------------------------------------------------------|
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters 相同

 

示例 1：

输入：s = "bcabc"
输出："abc"
示例 2：

输入：s = "cbacdcbc"
输出："acdb"
 

提示：

1 <= s.length <= 104
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	贪心+栈法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.6 MB, 在所有 C++ 提交中击败了92.08%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string removeDuplicateLetters(string s) {
    int vis[26] = { 0 };
    int num[26] = { 0 };
    for (const char& c : s) {
        num[c - 'a']++;
    }

    string res;
    for (const char& c : s) {
        //如果当前字符不在栈里
        if (!vis[c - 'a']) {
            //判断栈是否为空，当前字符是否比栈顶元素小
            while (!res.empty() && c < res.back()) {
                //如果当前字符比栈顶元素小的话，判断栈顶元素是否大于0
                //大于0说明后面还有栈顶元素可以入栈，此时的栈顶元素可以出栈
                //不然的话就说明栈顶元素已经是最后一个了
                if (num[res.back() - 'a'] > 0) {
                    //栈顶元素剩余数量大于0，就弹出栈顶元素，将存在状态改为0
                    vis[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                else {
                    break;
                }
            }
            //将当前元素的存在状态改为1，当前元素入栈
            vis[c - 'a'] = 1;
            res.push_back(c);
        }
        //将当前元素的剩余数量减1
        num[c - 'a']--;
    }
    return res;
}