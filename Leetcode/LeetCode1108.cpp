// IP 地址无效化
#include <string>
using namespace std;

// string库中的replace方法：s.replace(int p0, int n0, const char *s2)
// 删除从p0开始的n0个字符，然后在p0处插入串s2
class Solution {
   public:
    string defangIPaddr(string address) {
        string s = address, src = ".", target = "[.]";
        size_t pos = 0, src_len = src.size(), target_len = target.size();
        while ((pos = s.find(src, pos)) != string::npos) {
            s.replace(pos, src_len, target);
            pos += target_len;
        }
        return s;
    }
};