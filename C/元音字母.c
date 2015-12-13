#include "stdio.h"

void yuan(char *s,char *s2)
{
    int i=0,j=0;
   while(*(s+i)!='\0'){
        if(*(s+i)=='a'||*(s+i)=='e'||*(s+i)=='i'||*(s+i)=='o'||*(s+i)=='u'||*(s+i)=='A'||*(s+i)=='E'||*(s+i)=='I'||*(s+i)=='O'||*(s+i)=='U'){
            *(s2+j) = *(s+i);
            j++;
        }         
            
        i++;
       
    }
    *(s2+j)='\0';//添加结束标志
}

int main()
{
    char str[81], str2[81];
    gets(str);
    yuan(str,str2);
    printf("%s", str2);
    return 0;
} 