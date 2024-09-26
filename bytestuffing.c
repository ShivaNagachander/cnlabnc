#include <stdio.h>
#include <string.h>
int main()
{
    char a[20],b[40];
    int i,n,j;
    printf("Enter the size of the frame: ");
    scanf("%d",&n);  
    printf("Enter the characters in the frame: \n");
    for (i=0;i<n;i++) 
    {
        scanf(" %c",&a[i]);
    }
    printf("FRAME: ");
    for (i=0;i<n;i++) 
    {
        printf("%c",a[i]);a
    }
    j=0;
    b[j++]='f';
    for (i=0;i<n;i++) 
    {
        if (a[i]=='f' || a[i]=='s') 
        {
            b[j++]='f';
            b[j++]=a[i];
        } 
        else 
        {
            b[j++]=a[i];
        }
    }
    b[j++]='f';
    b[j]='\0';
    printf("\nRESULT: ");
    for (i=0;i<j;i++) 
    {
        printf("%c", b[i]);
    }
    printf("\n");
    return 0;
}

Enter the size of the frame: 6
Enter the characters in the frame: 
h e l s o f
FRAME: helsof
RESULT: fhelfsofff
