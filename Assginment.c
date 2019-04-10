#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void *function(void *vargp);
int main(){
int num;
printf("Enter a number");
scanf("%d",&num);

pthread_t thread1;
pthread_create(&thread1,NULL,function,(void *)num);
pthread_join(thread1,NULL);

return 0;
}

void *function( void *num1){
int d = (int)num1;
int i,flag=0;

for(i=2;i<=d/2;++i){
if(d%i==0){
    flag = 1;
    break;
}
}
if (flag==0) {
printf("It is a Prime Number");
}else{
printf("It is not a Prime Number");
}

}