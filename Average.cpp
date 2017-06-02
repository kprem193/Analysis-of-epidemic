#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int array1[60][4];
int main()
{
    FILE *fr,*frs,*fri,*frr;
    char a[100],temp1[100];
    int v=1,temp,i=0,j=0,n=20,k,naya=0;

    fr=fopen("Result.txt","r+");
    frs=fopen("sResult.dat","w+");
    fri=fopen("iResult.dat","w+");
    frr=fopen("rResult.dat","w+");

    for(k=0;k<n*4;k++)
    {
        i=0;
        naya=0;
        while(1)
        {
            fscanf(fr,"%s",a);
            if(!strcmp(a,"Recovered"))
            {
                while(1)
                {
                    j=0;
                    fscanf(fr,"%s",temp1);

                    if(!strcmp(temp1,"END"))
                         break;

                    array1[i][j++]=naya++;

                    fscanf(fr,"%d",&temp);
                    array1[i][j++]+=temp;

                    fscanf(fr,"%d",&temp);
                    array1[i][j++]+=temp;

                    fscanf(fr,"%d",&temp);
                    array1[i++][j]+=temp;                   

                }
                if(!strcmp(temp1,"END"))
                    break;
            }
            if(!strcmp(temp1,"END"))
                break;
        }
    }

       
    for(i=0;i<60;i++)
            for(j=0;j<4;j++)
                if(j!=0)
                    array1[i][j]/=20;

    for(i=0;i<60;i++)
    {
            fprintf(frs,"%d\t%d\n",array1[i][0],array1[i][1]);
            fprintf(fri,"%d\t%d\n",array1[i][0],array1[i][2]);
            fprintf(frr,"%d\t%d\n",array1[i][0],array1[i][3]);
    }

    fclose(fr);
    fclose(frs);
    fclose(fri);
    fclose(frr);
    
    return 0;
}
