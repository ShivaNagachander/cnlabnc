#include<stdio.h>
void main()
{
    int a[15];
    int i,j,k,n,c=0,pos=0;
    printf("Enter the frame length: ");
    scanf("%d",&n);
    printf("Enter input frame:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            c++;
            if(c==5)
            {
                pos=i+1;
                c=0;
                for(j=n;j>=pos;j--)
                {
                    k=j+1;
                    a[k]=a[j];
                }
                a[pos]=0;
                n=n+1;
            }
        }
        else
        c=0;
    }
    printf("DATA AFTER STUFFING: ");
    for(i=0;i<n;i++)
    printf("%d",a[i]);
    }


Enter the frame length: 9
Enter input frame:
1 1 1 1 1 1 1 1 1
DATA AFTER STUFFING: 1111101111

