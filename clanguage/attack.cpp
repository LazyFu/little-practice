#include<iostream>
using namespace std;

void calculate(string s)
{
    int freq[26] = {0};
    int total = 0;
    // 遍历字符串，统计每个字母的出现次数
    for (char c : s) 
    {
        c = toupper(c); 
        freq[c - 'A']++;
        total++;
    }
    // 输出每个字母的概率
    cout << "Letter frequencies:" << endl;
    for (int i = 0; i < 26; i++) {
        cout << char('A' + i) << ": ";
        if(total > 0)
            cout <<(double)freq[i] / total;
        else
            cout << "0";
        cout << endl;
    }
}

int main()
{
    string secret;
    cin>>secret;
    calculate(secret);
    return 0;
}