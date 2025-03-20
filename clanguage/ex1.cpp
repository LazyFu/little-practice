#include<iostream>
#include<vector>
using namespace std;

/*vector <string> findRelativeRanks(vector <int> &nums)
{
    vector <string> result;
    vector <int> temp=nums;
    sort(temp.begin(), temp.end(), greater<int>());
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i]==temp[0])
        {
            result.push_back("Gold Medal");
        }
        else if(nums[i]==temp[1])
        {
            result.push_back("Silver Medal");
        }
        else if(nums[i]==temp[2])
        {
            result.push_back("Bronze Medal");
        }
        else
        {
            result.push_back(to_string(find(temp.begin(), temp.end(), nums[i])-temp.begin()+1));
        }
    }
    return result;
}*/

/*vector <int> SquareArray(vector <int> &A)
{
    for(int i=0; i<A.size(); i++)
    {
        A[i]=A[i]*A[i];
    }
    sort(A.begin(), A.end());
    return A;
}*/

bool Permutation(string &A, string &B)
{
    if(A.size()!=B.size())
    {
        return false;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    return A==B;
}

int main()
{
    /*int n;
    cin>>n;
    vector <int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }
    vector<string> result=findRelativeRanks(nums);
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;*/

    /*vector <int> nums={-4,-1,0,3,10};
    vector <int> result=SquareArray(nums);
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;*/

    string A, B;
    cin>>A>>B;
    cout<<Permutation(A, B);
    return 0;
}