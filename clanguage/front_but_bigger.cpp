#include<iostream>
#include<vector>

using namespace std;

//合并区间
long long mergeCount(vector<int>& a, int left, int mid, int right) {
    int i = left, j = mid;
    long long count = 0;
    vector<int> temp;
    while(i < mid && j < right) {
        if(a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            count += (mid - i); // a[i...mid-1] 都大于 a[j]
            j++;
        }
    }
    while(i < mid) {
        temp.push_back(a[i++]);
    }
    while(j < right) {
        temp.push_back(a[j++]);
    }
    for (int k = left; k < right; k++) {
        a[k] = temp[k - left];
    }
    return count;
}

//归并排序
long long mergeSortCount(vector<int>& a, int left, int right) {
    if(right - left <= 1) return 0;
    int mid = left + (right - left) / 2;
    long long count = mergeSortCount(a, left, mid);
    count += mergeSortCount(a, mid, right);
    count += mergeCount(a, left, mid, right);
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long count=mergeSortCount(a,0,n);
    cout<<count<<endl;
    return 0;
}