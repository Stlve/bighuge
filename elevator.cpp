#include "elevator.h"
#include<cmath>
static int w;//������¼�����ǲ�����һ���˿ͣ� 
static int y��//������¼���µ��ǲ�����һ���˿ͣ� 
int lastup(int k)
{
	int last=0;
	last=people[k].final-people[k].floor+abs(n-people[k].floor)+time;
	return last; 
}

int lastdown(int k)
{
	int last=0;
	last=people[k].final-people[k].floor+abs(n-people[k].floor)+time;
	return last; 
}

int oneup(int k)
{
	int total,j,v,flag=0,begin=n,flo,oor=0;/*  flag�����ж��м�������beginΪһ��ʼ�Ĳ�����oorΪ��������*/ 
	flag=require(k);
	 if(flag==0){
	 	time=people[k].time+people[k].floor-begin;	
	 }
	 else {
	 	time=people[k].time+people[k].floor-begin+flag;
	 }
	 v=max(people);
	 u=min(people);
	 for(j=0;j<5;j++)
	 {
	 	if(ask[j].receive!=0&&ask[j].arrive==0)
	 	{
	 		for(flo=begin;flo<=v;flo++)
	 		{
	 			if(flo==people[j].final)
	 			ask[j].arrive=flo;
	 			sum[j]=ask[j].arrive-ask[j].receive;
			 }
		 }
	  } 
	  time+=flag+v-begin;
	  n=v; 
	  oor=sum[k];
	  return oor;
 }
 
 
 int onedown(k)
 {
 	int total,j,v,flag=0,begin=n,flo,oor=0;/*  flag�����ж��м�������beginΪһ��ʼ�Ĳ�����oorΪ��������*/ 
 	flag=require(k);
	 if(flag==0){
	 	time=people[k].time+begin-people[k].floor;	
	 }
	 else {
	 	time=people[k].time+begin-people[k].floor+flag;
	 }
	 v=max(people);
	 u=min(people);
	 for(j=0;j<5;j++)
	 {
	 	if(ask[j].receive!=0&&ask[j].arrive==0)
	 	{
	 		for(flo=begin;flo>=u;flo--)
	 		{
	 			if(flo==people[j].final)
	 			ask[j].arrive=flo;
	 			sum[j]=ask[j].receive-ask[j].arrive;
			 }
		 }
	  } 
	  time+=flag+begin-u;
	  n=u; 
	  oor=sum[k];
	  return oor;
 	
	  
  } 
 
 int require(int k)
 {
 	int j,k=0,f;
 	t=n;//�������ڲ��� 
 	for(j=k;j<5;j++)
	{
		for(f=people[k].time;f<(people[k].time+abs(people[k].floor-t));f++,n++){ 
		if(people[j].time==f&&people[j].floor==n)
		{
		   k++;
		   ask[j].receive=people[j].time;
		     
		}
	 } 
	 } 
 	return ask; 
 }
 
 int max(struct people[]) 
 {
 	int big=0,k;
 	for(k=0;k<5;k++)
 	{
 		if(ask[k].receive!=0)
 		{
 			if(big<=people[k].floor)
 		{	big=people[k].floor;
 			w=k;
			 } 	
		 }
	 }
	 return big;
 }
 
 int min(struct people[]) 
 {
 		int small=0,k;
 	for(k=0;k<5;k++)
 	{
 		if(ask[k].receive!=0&&ask[k].receive==0)
 		{
 			if(small>=people[k].floor)
 			small=people[k].floor;
 			y=k; 
 		}
 	}
 	return y;
 }
