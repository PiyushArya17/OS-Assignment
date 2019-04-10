











#include<stdio.h>
#include<conio.h>

int main()
{
int i,j,f=0,count = 0,k,l;
int process,resources;

printf("Enter no of Processes");
scanf("%d",&process);
printf("Enter no of Resource");
scanf("%d",&resources);


int Allocation[process][resources] ;
int max_available[process][resources];

int curr_need[process][resources] ;
int flags[process] ;
int available[resources] ;


for (i = 0; i < process; i++)
{
    flags[i] = 0;
}


printf("Enter Allocation \n");
// Allocation Input

for(i=0;i<process;i++)
{
 for(j=0;j<resources;j++)
 {
        scanf("%d",&Allocation[i][j]);
    } 
    printf("\n");
}

printf("Enter max_available curr_need \n");

// max_available curr_need Input

for(i=0;i<process;i++)
{
 for(j=0;j<resources;j++)
 {
        scanf("%d",&max_available[i][j]);
    } 
    printf("\n");
}
printf("Enter Available \n");

// Available Input
 for(j=0;j<resources;j++){
        scanf("%d",&available[i]);
    } 


//Calculating the Current curr_need of the Processes
for(i=0;i<=process;i++){
 for(j=0;j<=resources;j++){
        curr_need[i][j] = max_available[i][j] - Allocation[i][j];
    } 
}

//Calculating the flags for each process i.e will it execute or not
for(l = 0;l<2;l++){
for(i=0;i<process;i++){
 count =0;
 for(j=0;j<resources;j++){
    
     if(available[j] >= curr_need[i][j]){
         count++;
     }
    }
  if(flags[i]==0){
   if (count == 4) {
      flags[i] = 1; 

     for(k=0;k<4;k++){
         
    
        available[k] = available[k]+ Allocation[i][k]; 
    } 

   }
  }
     
}
}

//validating flags to check for Safe state or not
count = 0;
for(i=0;i<process;i++){

if(flags[i]==1){
    count++;
}
}
if(count == 5){
    printf("Program is in safe state");
}else{
    printf("Program is not in safe state");
    
}


return 0;
}
