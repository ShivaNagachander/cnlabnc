#include <stdio.h>
#include <string.h>
void main()
{
    char data[20],stuffed[50] = "",flag[10],delim[10];
    int i,n,pos;
    printf("Enter the size of the frame: ");
    scanf("%d",&n);
    printf("Enter the frame: ");
    scanf("%s",data);
    printf("Enter the delimiter: ");
    scanf("%s",delim);
    printf("Enter the flag bit: ");
    scanf("%s",flag);
    printf("Enter the position where the flag bit should be inserted: ");
    scanf("%d",&pos);
    strcat(stuffed, delim);
    for (i = 0;i<n;i++)
    {
        if (i==(pos-1))
        {
            strcat(stuffed,flag);
        }
        char temp[2];
        temp[0]=data[i];
        temp[1]='\0';
        strcat(stuffed,temp);
    }
    strcat(stuffed,delim);
    printf("After Stuffing: %s\n",stuffed);
}
