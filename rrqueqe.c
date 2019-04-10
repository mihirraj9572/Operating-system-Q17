#include<stdio.h>
//#include<conio.h>
int main()
 {
   int x,m,pr[10],ppr[10],pbt[10],wt[10],t[10],awt,att,i,at[10],tq;
 
   //m is number of process
   //pr is process
   //ppr is process priority
   //pbt is process burst time
   //wt is wait time
   // t is turnaround time
   //awt is average waiting time
   //att is average turnaround time
   //at is arrival time
   //tq is time qunatum
 
 
   printf("Enter the number of process");
   scanf("%d",&m);
   printf("Enter time quantum");
   scanf("%d",&tq);
   printf("\nEnter burst time : time priorities : Arrival time  \n");
 
   for(i=0;i<m;i++)
    {
      
      printf("\n Process %d ",i+1);
      
      scanf("%d %d %d",&pbt[i],&ppr[i],&at[i]);
	  pr[i]=i+1;
    }
 
//sorting on the basis of priority
int j;
  for(i=0;i<m-1;i++)
   {
     for(j=i+1;j<m;j++)
     {
       if(ppr[i]<ppr[j])
       {
     x=ppr[i];
     ppr[i]=ppr[j];
     ppr[j]=x;
     x=pbt[i];
     pbt[i]=pbt[j];
     pbt[j]=x;
     x=pr[i];
     pr[i]=pr[j];
     pr[j]=x;
      }
     
   }
}
wt[0]=0;
awt=0;
t[0]=pbt[0];
att=t[0];
for(i=1;i<m;i++)
 {
 	if(tq<m || tq>m) {
	 
   wt[i]=t[i-1];
   awt+=wt[i];
   t[i]=wt[i]+pbt[i];
   att+=t[i];
	 }
 }
 
 //Gantt chrat
 printf("\n");
 printf("Gantt chart\n");
 for(i=0;i<m;i++)
 {
 	printf("P %d ",pr[i]);
 }
//Displaying the process
 
printf("\n\nProcess \t Burst Time \t Wait Time \t Turn Around Time   Priority \tArrival time \n");
for(i=0;i<m;i++){
printf("\n  %d",pr[i]); printf("\t\t %d",pbt[i]); printf("\t\t %d",wt[i]); printf("\t\t %d",t[i]); printf("\t\t %d",ppr[i]); printf("\t\t %d",at[i]);

}
awt/=m;
att/=m;
printf("\n Average Wait Time : %d ",awt);
printf("\n Average Turn Around Time : %d",att);
//getch();
}