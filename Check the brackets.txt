#include <stdio.h>
#include<math.h>
void Fun()
{
	int dl,i, count=0;
	char str[100];
	printf("Enter string:\n");
    gets(str);
    dl =strlen(str);
    for (i=0;i<dl;i++)
    {
        if (str[i]=='(')
                count++;
        if (str[i]==')')
            count--;
    }

	if (count==0)
        printf("All good");
        else if (count<0)
        printf("lack '(' ,in an amount %d",abs(count));
        else if(count>0)
        printf("lack ')' ,in an amount %d",count);

}

int main()
{
Fun();
return 0;
}
