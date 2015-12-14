#include <stdio.h>
#include<string.h>
int main()
{
    FILE *fp;
    char str[10000][11];
    int i=0,j,n =0;
    char temp[11];

    if((fp=fopen("case1.in","r"))==NULL){
        
    }
       
    while((fgets(str[n],11,fp))!=NULL){
        n++;
    }
       fclose(fp); 
       for(i=0;i<n;i++){
           for(j=i+1;j<n;j++){
               if(strcmp(str[i],str[j])>0){
                   strcpy(temp,str[i]);
                   strcpy(str[i],str[j]);
                   strcpy(str[j],temp);
               }
           }
       }
       if((fp=fopen("answer.txt","w"))==NULL){
          
       }
       for(i=0;i<n;i++){
           fputs(str[i],fp);
       }
       fclose(fp);
       return 0;
    }    
      