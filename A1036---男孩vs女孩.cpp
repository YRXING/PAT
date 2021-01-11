#include<cstdio>
#include<cstring>

struct student{
    char name[20];
    char sex;
    char ID[20];
    int grad;
}stu;

int main(){
    char max_f_name[20],max_f_id[20]={""},min_m_name[20],min_m_id[20]={""};
    int k,max_f_grad=-101,min_m_grad=101;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%s %c %s %d",&stu.name,&stu.sex,&stu.ID,&stu.grad);
        if(stu.sex=='M'&&stu.grad<min_m_grad){
            min_m_grad = stu.grad;
            strcpy(min_m_name,stu.name);
            strcpy(min_m_id,stu.ID);
        }else if(stu.sex=='F'&&stu.grad>max_f_grad){
            max_f_grad = stu.grad;
            strcpy(max_f_name,stu.name);
            strcpy(max_f_id,stu.ID);
        }
    }
    if(max_f_grad==-101) printf("Absent\n");
    else    printf("%s %s\n",max_f_name,max_f_id);
    if(min_m_grad==101) printf("Absent\n");
    else  printf("%s %s\n",min_m_name,min_m_id);
    if(max_f_grad==-101||min_m_grad==101) printf("NA");
    else printf("%d",(max_f_grad-min_m_grad));
    return 0;
}
