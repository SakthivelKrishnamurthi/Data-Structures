#include<bits/stdc++.h>

using namespace std;

int partition(int arr[], int lb, int ub)
{
    int temp,x = arr[ub];
    int i = lb - 1;
    for(int j=lb; j<ub; j++)
    {
        if(arr[j] < x)
        {
            i = i+1;
           swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[ub]);
    return i+1;
}


void quicksort(int arr[], int lb, int ub)
{
    if(lb < ub)
    {
    int q = partition(arr,lb,ub);
    quicksort(arr,lb,q-1);
    quicksort(arr,q+1,ub);
    }
}

int main(){
    
    int arr[] = {45,78,67,98,87};
    int len = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,len-1);
    cout<<endl<<endl;
    for(int i=0; i<len; i++)
        cout<<arr[i]<<" ";
    return 0;
}