#include <bits/stdc++.h>

using namespace std;

void merge(int arr[],int l,int mid,int h)
{
    int i = l, j = mid+1, k=l;
    int ar[h+1];
    while( i<=mid && j<=h)
    {
        if(arr[i] < arr[j])
            ar[k++] = arr[i++];
        else
            ar[k++] = arr[j++];
    }
    while(i<=mid)
        ar[k++] = arr[i++];
    
   while(j<=h)
        ar[k++] = arr[j++];

    for(int m=l; m<=h; m++)
        arr[m] = ar[m];

}


void mergesort(int arr[],int n)
{
    int p,l,h,mid,i;
    for(p=2; p<=n; p*=2)
    {
        for(i=0; i+p-1<n; i+=p)
        {
            l = i;
            h = i+p-1;
            mid = (l + h) / 2;
            merge(arr,l,mid,h);
        }
    }
    if(p/2 < n){
        merge(arr,0,p/2-1,n-1);
    }
}

int main(){
    int arr[] = {45,78,67,97,87};
    int len = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr,len);
    cout<<endl<<endl;
    for(int i=0; i<len; i++)
    {
        cout<<arr[i]<<" ";
    }   
}