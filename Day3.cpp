#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 5000

int S[MAX],I[MAX],R[MAX],A[MAX][MAX],node=4942,i,tr=60,re=85,temp[MAX],edge=13188;

int CheckI()
{
    for(i=0;i<node;i++)
       if(I[i]==1)
            return 1;
    return 0;
}

void Transmit(int k)
{
    int r=rand();
    r=r%101;
    if(r<tr)
    {
        temp[k]=1;
    }
}

void Recover(int j)
{
    int r=rand();
    r=r%101;
    if(r<re)
    {
        I[j]=0;
        R[j]=1;
    }
}

int main()
{
   int j,k,counter=0,t, nSusceptible=0,nInfected=0,nRecovered=0,counter1=0;
   FILE *fs,*fi,*fr,*fdata,*fresult;
   srand(time(NULL));

   fs = fopen("Susceptible.txt","r+");
   for(i=0;i<node;i++)
       fscanf(fs,"%d",&S[i]);
   fclose(fs);

   fi = fopen("Infected.txt","r+");
   for(i=0;i<node;i++)
       fscanf(fi,"%d",&I[i]);
   fclose(fi);

   fr = fopen("Recovered.txt","r+");
   for(i=0;i<node;i++)
       fscanf(fr,"%d",&R[i]);
   fclose(fr);

   fdata = fopen("PowerData.csv","r+");
   for(i=0;i<edge;i++)
    {
        fscanf(fdata,"%d,%d,%d",&j,&k,&t);
        A[j][k]=t;
    }
   fclose(fdata);

   fresult=fopen("Result.txt","a");
   fprintf(fresult,"Timestamp      Susceptible    Infected       Recovered\n");
   while(CheckI())
   {
        counter1++;    
        fprintf(fresult,"%5d          ",counter++);

        for(j=0;j<node;j++)
            nSusceptible+=S[j];
        fprintf(fresult,"%5d          ",nSusceptible);

        for(j=0;j<node;j++)
            nInfected+=I[j];
        fprintf(fresult,"%5d          ",nInfected);

        for(j=0;j<node;j++)
            nRecovered+=R[j];
        fprintf(fresult,"%5d          \n",nRecovered);

       for(j=0;j<node;j++)
       {
          if(I[j]==1)
          {
            Recover(j);
            for(k=0;k<node;k++)
                if(A[j][k]==1 && I[k]==0 && S[k]==1)
                    Transmit(k);
          }
       }

       for(j=0;j<node;j++)
       {
           if(temp[j]==1)
           {
               S[j]=0;
               I[j]=1;
               temp[j]=0;
           }
       }

       nSusceptible=0;
       nInfected=0;
       nRecovered=0;
   }
   fprintf(fresult,"%5d          ",counter++);

    for(j=0;j<node;j++)
        nSusceptible+=S[j];
    fprintf(fresult,"%5d          ",nSusceptible);

    for(j=0;j<node;j++)
        nInfected+=I[j];
    fprintf(fresult,"%5d          ",nInfected);

    for(j=0;j<node;j++)
        nRecovered+=R[j];
    fprintf(fresult,"%5d          \n",nRecovered);

    for(i=counter1;i<60;i++)
    {
        fprintf(fresult,"%5d          ",counter++);
        fprintf(fresult,"%5d          ",nSusceptible);
        fprintf(fresult,"%5d          ",nInfected);
        fprintf(fresult,"%5d          \n",nRecovered);
    }

        
   fprintf(fresult,"\n\nEND\n\n");
   fclose(fresult);
   printf(" END");
   return 0;
}

