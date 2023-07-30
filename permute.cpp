#include <bits/stdc++.h>

using namespace std;

void display(char str[])
{
    for(int i=0; str[i]!= '\0'; i++)
    {
        cout<<str[i]<<" ";
    }
    cout<<endl;
}
void permute(char s[],int k)
{
    static char res[10];
    static int flag[10] = {0};
    int i;
    if(s[k] == '\0')
    {
        display(res);
    }else{
        for(i=0; s[i]!='\0';i++)
        {
            if(flag[i]==0)
            {
                res[k] = s[i];
                flag[i] = 1;
                permute(s,k+1);
                flag[i] = 0;
            }
       }
    }
}

int main()
{
    char str[] = "abc";
    permute(str,0);
    return 0;
}