#include<iostream>
using namespace std;
const string encryptMapping="QWERTYUIOPASDFGHJKLZXCVBNM";

string encrypt(string s)
{
    string result="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            result+=encryptMapping[s[i]-'A'];
        }
        else if(s[i]>='a' && s[i]<='z')
        {
            result+=encryptMapping[s[i]-'a'];
        }
    }
    return result;
}

int main()
{
    string s="This is a secret message, can you encrypt it?";
    string test="At dawn, the sun rose over the rolling hills, casting golden light across the valley. Birds chirped melodiously as the world awakened, promising new beginnings and endless possibilities.";

    string result=encrypt(s);
    string testResult=encrypt(test);
    cout<<result<<endl;
    cout<<testResult<<endl;
    return 0;
}