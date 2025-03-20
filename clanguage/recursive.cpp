#include<iostream>

using namespace std;

int solve(int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n<0)
    {
        return 0;
    }
    int count=0;
    for(int i=1; i<=6; i++)
    {
        count+=solve(n-i);
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int result=solve(n);
    cout<<result<<endl;
}