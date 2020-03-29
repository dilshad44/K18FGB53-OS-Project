#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,m,i,j=0,p=0;
float avg=0.0,avg1=0.0,t;
printf("Enter the total number of process that is to be executed:");
scanf("%d",&n);
m=n;
struct process
{
	int process[n], bursttime[n], arrivaltime[n], waittime, turntime;
} pp;
for(i=0;i<n;i++)
{
printf("\nPlease enter the Arrival time of the process %d :",i);
scanf("%d",&pp.arrivaltime[i]);
if(pp.arrivaltime[i]==0){
	printf("*Wrong arrival time8**\n");
	printf("\nEnter again : ");
	scanf("%d",&pp.arrivaltime[i]);
}
printf("\nPlease enter the burst time of the process %d :",i);
scanf("%d",&pp.bursttime[i]);
printf("\n\n");
pp.process[i]=i+1;
}
//Sorting of the Given process
for(i=0;i<n;i++)
{
	int temp=0,temp1=0,temp2=0;
	for(j=i+1;j<n;j++)
{
		if(pp.bursttime[i]>pp.bursttime[j])
{
			temp=pp.bursttime[i];
			temp1=pp.arrivaltime[i];
			temp2=pp.process[i];
			pp.bursttime[i]=pp.bursttime[j];
			pp.arrivaltime[i]=pp.arrivaltime[j];
			pp.process[i]=pp.process[j];
			pp.bursttime[j]=temp;
			pp.arrivaltime[j]=temp1;
			pp.process[j]=temp2;
		}
		else
{
			continue;
		}		
}
}
pp.turntime=0;
pp.waittime=0;
//Printing the remainig process and calculating the waiting time and turn around time
do{
printf("\n\n");	
printf("\n\t========================================================================================================\n");

printf("\n\n\t\t\t*******The Processes Are********* \n\n");
printf("\n\t\t\tProcess \tArrival time \t Burst time  \n");

for(i=0;i<n;i++){
	
	printf("\t\t\tP%d\t\t %d \t\t\t %d\n",pp.process[i],pp.arrivaltime[i],pp.bursttime[i]);\
	
}

printf("\n\n\t\t\t**************");
printf("\n\n\t\t\tProcess p%d  is done!!!!\n\n",pp.process[0]);
printf("\t\t\t**************\n");

if(p==0){
	pp.turntime=pp.bursttime[0];
	pp.waittime=0;
	
}
else{

t=pp.turntime-pp.arrivaltime[0];
if(t<0.0){
	pp.waittime=0.0;
	pp.turntime=pp.turntime+pp.bursttime[0];
}
else{
	pp.waittime=pp.turntime-pp.arrivaltime[0];
	pp.turntime=pp.turntime+pp.bursttime[0];
}



}
for(j=0;j<n;j++){
pp.process[j]=pp.process[j+1];
pp.bursttime[j]=pp.bursttime[j+1];
pp.arrivaltime[j]=pp.arrivaltime[j+1];

}
avg=avg+pp.waittime;
avg1=pp.turntime;
printf("\t\t\tTurn Around time : %f",pp.turntime);
printf("\t\t\t\tWaiting time : %f\n",pp.waittime);	

sleep(2);
n=n-1;
p++;
}while(n!=0);

//Showing the average waiting time and Turnaround time


printf("\n\n\n\n");
printf("\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Final Result ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
printf("\t===========================================================================================");
avg=avg/m;
printf("\n\n\t\tAverage Waiting time : %f",avg);
avg1=avg1/m;
printf("\t\t\tAverage Turnaround time : %f",avg1);





if(n==0){
	printf("\n\n\n\t\t\t\t\t\t\tThank You");
}


return 0;
}


