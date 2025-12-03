#include<stdio.h>
float calculate_Repayement(float loan,float interest,int year,float installment,float total);

int main(){
	float loan=0,interest=0,installment=0;
	int years=0;
	float total=0;
	printf("Enter how much loan a person had taken and at what interest it had been taken(it should be in decimal form):  ");
	scanf("%f %f",&loan,&interest);
	printf("enter the amount of years ");
	scanf("%d",&years);
	installment=loan/years;
	calculate_Repayement(loan,interest,years,installment,total);
	
	
	return 0;
	
}
float calculate_Repayement(float loan,float interest,int year,float installment,float total){
	float pay=0;
	if(loan == 0|| year==0 ){
		return 1;
	}
	loan = loan - installment;
	pay=installment + (loan*interest);
	printf("the amount person have to pay: %.3f\n",pay);
	printf("Year %d:Remaning Loan=%.3f\n",(year-1),loan);
	total=total+pay;
	pay+calculate_Repayement(loan,interest,(year-1),installment,total);
}
