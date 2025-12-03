#include<stdio.h>
#include<string.h>
struct employee_data{
	int employee_id;
	char name[20];
	char designation[20];
	int salary;
};
void display(struct employee_data emp[],int n);
void higest_salary(struct employee_data emp[],int n);
void search(struct employee_data emp[],int n);
void modify(struct employee_data emp[],int n);
int main(){
	int n=0;
	int choice=0;
	printf("\nenter the number of employee are there in your firm: ");
	scanf("%d",&n);
	struct employee_data emp[n];
	for(int i=0;i<n;i++){
		printf("\nenter employee id: ");
		scanf("%d",&emp[i].employee_id);
		getchar();
		printf("\nenter the name of employee: ");
		fgets(emp[i].name,sizeof(emp[i].name),stdin);
		getchar();
		printf("enter the designation of employee: ");
		fgets(emp[i].designation,sizeof(emp[i].designation),stdin);
		printf("\nenter salary: ");
		scanf("%d",&emp[i].salary);
	}
	do{
	
	printf("\nenter the choice if you want to modify or not (\n1=display data\n2=higest_salary\n3=search of emplyoee\n4=modification in salary\n5=exist) : ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
	display(emp,n);
	break;
	case 2:
    higest_salary(emp,n);
    break;
    case 3:
    search(emp,n);
    break;
    case 4:
     modify(emp,n);	
     break;
    case 5:
     	break;
	}
	
}while(choice==5);
  return 0;
}
void display(struct employee_data emp[],int n){

	for(int i=0;i<n;i++){
		printf("%d,%s,%s,%d\n",emp[i].employee_id,emp[i].name,emp[i].designation,emp[i].salary);
	}
}
void higest_salary(struct employee_data emp[],int n){

	int high=emp[0].salary;
	for(int i=1;i<n;i++){
		if(emp[i].salary>high){
			high=emp[i].salary;
			printf("%s at %s post having id:%d has the highest salary \n",emp[i].name,emp[i].designation,emp[i].employee_id);
		}else{
			printf("%s at %s post having id:%d has the highest salary \n",emp[0].name,emp[0].designation,emp[0].employee_id);
		}
	}
}
void search(struct employee_data emp[],int n){

	int emp_id;
	char name[20];
	printf("enter the id of person you want information for ");
	scanf("%d",&emp_id);
	getchar(); 
	printf("enter the name of person ");
	fgets(name,sizeof(name),stdin);
	
	for(int i=0;i<n;i++){
	if(strcmp(emp[i].name,name)==0 && emp[i].employee_id==emp_id){
		printf("%d,%s,%s,%d\n",emp[i].employee_id,emp[i].name,emp[i].designation,emp[i].salary);
	}
}
}
void modify(struct employee_data emp[],int n){

	float increment;
	printf("enter the increment you have to made in individual salary");
	scanf("%d",&increment);
	for(int i=0;i<n;i++){
		if(emp[i].salary<50000){
			emp[i].salary=emp[i].salary+(emp[i].salary*increment/100);
			printf("salary updated");
		}
	}
}

