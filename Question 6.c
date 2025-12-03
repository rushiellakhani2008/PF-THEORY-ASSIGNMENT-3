#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student{
    int Student_ID;
    char* Name;
    char* Batch;
    char* Membership;
    char* Registration_Date;
    char* Date;
    char* Interest;
};
void Register();
void Update_membership();
void Delete();
void View_reg();
void Generate_batch_reports();
int main(){
    int option=0;
    do{
        printf("Enter the choice\n1:For the registration\n2:Update the membership\n3:delete registration\n4:View registration\n5:Generate batch wise report\n6:Exit:");
        scanf("%d",&option);
        getchar(); 
        switch(option){
            case 1:
                Register();
                break;
            case 2:
                Update_membership();
                break;
            case 3:
                Delete();
                break;
            case 4:
                View_reg();
                break;
            case 5:
                Generate_batch_reports();
                break;
            case 6:
                break;
        }
    }while(option != 6);
    return 0;
}
void Register(){
    FILE* fs=fopen("student_record","a");
    struct Student s;
    s.Name = (char*)malloc(100*sizeof(char));
    s.Batch = (char*)malloc(50*sizeof(char));
    s.Membership = (char*)malloc(50*sizeof(char));
    s.Registration_Date = (char*)malloc(50*sizeof(char));
    s.Date = (char*)malloc(50*sizeof(char));
    s.Interest = (char*)malloc(50*sizeof(char));
    printf("Enter the student id:");
    scanf("%d",&s.Student_ID);
    getchar();
    printf("Enter the name of student:");
    fgets(s.Name,100,stdin);
    printf("Enter the batch of student:");
    fgets(s.Batch,50,stdin);
    printf("Enter the membership of student:");
    fgets(s.Membership,50,stdin);
    printf("Enter the registration date:");
    fgets(s.Registration_Date,50,stdin);
    printf("Enter the date of birth:");
    fgets(s.Date,50,stdin);
    printf("Enter the interest of student (ACM/IEE/BOTH):");
    fgets(s.Interest,50,stdin);
    fprintf(fs,"%d,%s,%s,%s,%s,%s,%s", s.Student_ID, s.Name, s.Batch,s.Membership,s.Registration_Date,s.Date, s.Interest);
    fclose(fs);
    free(s.Name);
    free(s.Batch);
    free(s.Membership);
    free(s.Registration_Date);
    free(s.Date);
    free(s.Interest);
}
void Update_membership(){
    FILE* fs=fopen("student_record","r");
    FILE* ts=fopen("temp_record","w");
    struct Student s;
    char check[300];
    int ID=0;
    s.Name = (char*)malloc(100*sizeof(char));
    s.Batch = (char*)malloc(50*sizeof(char));
    s.Membership = (char*)malloc(50*sizeof(char));
    s.Registration_Date = (char*)malloc(50*sizeof(char));
    s.Date = (char*)malloc(50*sizeof(char));
    s.Interest = (char*)malloc(50*sizeof(char));  
    char* mem_typ = (char*)malloc(50*sizeof(char));
    printf("Enter the student id:");
    scanf("%d",&ID);
    getchar();
    while(fgets(check,sizeof(check),fs)){
        sscanf(check,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",&s.Student_ID, s.Name,s.Batch, s.Membership, s.Registration_Date,s.Date,s.Interest);
        if(ID == s.Student_ID){
            printf("Enter the membership type you want to update:");
            fgets(mem_typ,50,stdin);
            strcpy(s.Membership, mem_typ);
        }
        fprintf(ts,"%d,%s,%s,%s,%s,%s,%s",s.Student_ID,s.Name,s.Batch,s.Membership,s.Registration_Date,s.Date,s.Interest);
    }
    fclose(fs);
    fclose(ts);
    remove("student_record");
    rename("temp_record","student_record");
    free(s.Name);
    free(s.Batch);
    free(s.Membership);
    free(s.Registration_Date);
    free(s.Date);
    free(s.Interest);
    free(mem_typ);
}

void Delete(){
    FILE* fs=fopen("student_record","r");
    FILE* ts=fopen("temp_record","w");
    struct Student s;
    char check[300];
    int ID=0;
    s.Name = (char*)malloc(100*sizeof(char));
    s.Batch = (char*)malloc(50*sizeof(char));
    s.Membership = (char*)malloc(50*sizeof(char));
    s.Registration_Date = (char*)malloc(50*sizeof(char));
    s.Date = (char*)malloc(50*sizeof(char));
    s.Interest = (char*)malloc(50*sizeof(char));
    printf("Enter the student id you want to delete:");
    scanf("%d",&ID);
    while(fgets(check,sizeof(check),fs)){
        sscanf(check,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",&s.Student_ID,s.Name, s.Batch,s.Membership, s.Registration_Date,s.Date,s.Interest);
        if(ID != s.Student_ID){
            fprintf(ts,"%d,%s,%s,%s,%s,%s,%s",s.Student_ID,s.Name,s.Batch, s.Membership,s.Registration_Date,s.Date,s.Interest);
        }
    }
    fclose(fs);
    fclose(ts);
    remove("student_record");
    rename("temp_record","student_record");
    free(s.Name);
    free(s.Batch);
    free(s.Membership);
    free(s.Registration_Date);
    free(s.Date);
    free(s.Interest);
}
void View_reg(){
    FILE* fs=fopen("student_record","r");
    struct Student s;
    char check[300];
    s.Name = (char*)malloc(100);
    s.Batch = (char*)malloc(50);
    s.Membership = (char*)malloc(50);
    s.Registration_Date = (char*)malloc(50);
    s.Date = (char*)malloc(50);
    s.Interest = (char*)malloc(50);
    while(fgets(check,sizeof(check),fs)){
        sscanf(check,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",&s.Student_ID,s.Name,s.Batch,s.Membership,s.Registration_Date,s.Date,s.Interest);

        printf("STUDENT ID:%d, STUDENT NAME:%s, BATCH:%s, MEMBERSHIP:%s, REG DATE:%s, DOB:%s, INTEREST:%s\n",s.Student_ID,s.Name,s.Batch,s.Membership,s.Registration_Date,s.Date,s.Interest);
    }
    fclose(fs);
    free(s.Name);
    free(s.Batch);
    free(s.Membership);
    free(s.Registration_Date);
    free(s.Date);
    free(s.Interest);
}
void Generate_batch_reports(){
    FILE* fs=fopen("student_record","r");
    struct Student s;
    char check[300];
    s.Name = (char*)malloc(100*sizeof(char));
    s.Batch = (char*)malloc(50*sizeof(char));
    s.Membership = (char*)malloc(50*sizeof(char));
    s.Registration_Date = (char*)malloc(50*sizeof(char));
    s.Date = (char*)malloc(50*sizeof(char));
    s.Interest = (char*)malloc(50*sizeof(char));
    char* batch = (char*)malloc(50*sizeof(char));
    int count=0;
    printf("Enter the batch you want to generate report for:");
    fgets(batch,50,stdin);
    while(fgets(check,sizeof(check),fs)){
        sscanf(check,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",&s.Student_ID,s.Name,s.Batch,s.Membership,s.Registration_Date,s.Date,s.Interest);
        if(strcmp(batch,s.Batch) == 0){
            count++;
           printf("STUDENT ID:%d, STUDENT NAME:%s, BATCH:%s, MEMBERSHIP:%s, REG DATE:%s, DOB:%s, INTEREST:%s\n",s.Student_ID,s.Name,s.Batch,s.Membership,s.Registration_Date,s.Date,s.Interest);
        }
    }
    printf("The number of students from batch %s are: %d\n", batch, count);
    fclose(fs);
    free(s.Name);
    free(s.Batch);
    free(s.Membership);
    free(s.Registration_Date);
    free(s.Date);
    free(s.Interest);
    free(batch);
}

