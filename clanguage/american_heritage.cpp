#include <iostream>
#include <string>
using namespace std;

void printPostOrder(const string &pre, const string &in) {
    if(pre.empty() || in.empty()) return;
    // 先序遍历的第一个字符即为根节点
    char root = pre[0];
    // 在中序遍历中找到根节点的位置
    size_t pos = in.find(root);
    if(pos == string::npos) return; // 输入有误
    // 左子树对应的先序和中序
    string leftPre = pre.substr(1, pos);
    string leftIn = in.substr(0, pos);
    // 右子树对应的先序和中序
    string rightPre = pre.substr(pos + 1);
    string rightIn = in.substr(pos + 1);
    
    // 递归打印左子树和右子树的后序序列
    printPostOrder(leftPre, leftIn);
    printPostOrder(rightPre, rightIn);
    // 最后输出根节点
    cout << root;
}

int main(){
    string pre, in;
    cin >> in;
    cin >> pre;
    printPostOrder(pre, in);
    cout << endl;
    return 0;
}