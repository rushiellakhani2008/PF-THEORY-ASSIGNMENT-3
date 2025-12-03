#include<stdio.h>
float calculate_fuel(int fuel,int consumption,int recharge,int solar_bouns,int planet,int total_planet);

int main(){
int fuel=0,consumption=0,recharge=0,solar_bonus=0, planet=0, total_planet=0;
	
printf("enter the amount of fuel , consumption , recharge , solar_bonus , planet at which it start , total planet :");
scanf("%d %d %d %d %d %d",&fuel,&consumption,&recharge,&solar_bonus,&planet,&total_planet);
calculate_fuel(fuel,consumption,recharge,solar_bonus,planet,total_planet);
return 0;
}



float calculate_fuel(int fuel,int consumption,int recharge,int solar_bouns,int planet,int total_planet){
	int choice=0;
	int fur=0;

	if(fuel==0||planet==total_planet||fur==1){
		return 1;
	}
	fuel=fuel-consumption;
	printf("\nenter the planet hase gravitational pull(1=yes and 2=no) :");
	scanf("%d",&choice);
	
	if(choice==1){
		fuel=fuel+recharge;
	}
	if(planet%4==0){
		fuel=fuel+solar_bouns;
	}
	printf("planet %d = fuel remainig = %d\n",planet,fuel);
	if(fuel>consumption){
		printf("space craft is good to go\n");
		
	}else{
		printf("space craft can't further travel");
	fur++;
	
	}
	calculate_fuel(fuel,consumption,recharge,solar_bouns,(planet+1),total_planet);
}
