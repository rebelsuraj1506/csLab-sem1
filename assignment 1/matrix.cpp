#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cout<<"Enter an element to find: ";
    cin>>x;//Entering an element to find.
    int n,i=0,j=0;
    cin>>n;//Taking matrix size.
    int mat[n][n];//Matrix initialization.
    int arr[n];
    //Matrix Values to be entered.
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    //Sorting row-wise the elements of matrix in ascending order.
    for(i=0;i<n;i++)
    {
        sort(mat[i],mat[i]+n);
    }
    //sorting column-wise the elements of matrix in descending order.
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            arr[j]=mat[j][i];
        }
        sort(arr,arr+n,greater<int>());
        for(j=0;j<n;j++)
        {
            mat[j][i]=arr[j];
        }
    }
    i=0;j=0;
    bool found=false;
    //To check whether the element to be searched is present or not.
    while(i<n && j<n)
    {
        if(x==mat[i][j]){
        found=true;
        break;}
        else if(x>mat[i][j])
        {
            j++;
        }
        else if(x<mat[i][j])
        {
            i++;
        }
    }
    //printing the elements after sorting row in ascending order and column in descending order.
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    if(found)
    cout<<"Found";
    else
    cout<<"Not Found";
    cout<<endl;
}