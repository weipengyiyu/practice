#include "main.h"

void Show_menu(void)
{
    printf("\n***************************************\n");
    printf("\n****欢迎使用FS员工信息管理系统V1.0*****\n");
    printf("\n***************************************\n");
    printf("\n**********1、录入员工信息**************\n");
    printf("\n**********2、显示员工信息**************\n");
    printf("\n**********3、查找员工信息**************\n");
    printf("\n**********4、修改员工信息**************\n");
    printf("\n**********5、清空系统信息**************\n");
    printf("\n**********6、退出员工系统**************\n");
    printf("\n***************************************\n");
    printf("\n********请输入前面的序号：*************\n");
}

/*添加员工信息*/
void Option_one(stack *s)
{
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->name = malloc(sizeof(char)*name_size);
    if(newnode == NULL)
    {
        printf("动态内存分配失败！");
        exit(-1);
    }

    printf("\n请依次输入员工信息\n");
    printf("\n员工姓名\n");
    scanf("%s", newnode->name);
    printf("\n员工年龄\n");
    scanf("%d", &newnode->age);
    printf("\n员工工龄\n");
    scanf("%d", &newnode->work_age);
    printf("\n员工薪资\n");
    scanf("%d", &newnode->salary);

    if(!push(s, newnode))
    {
        printf("\n已保存员工信息\n");
    }
}

/*显示员工信息*/
void Option_two(stack *s)
{
    printf("\n员工信息！\n");
    traverse(s);
}

/*查找员工信息*/
void Option_three(stack *s)
{
    char *name = malloc(sizeof(char)*name_size);
    printf("\n请输入员工的姓名，进行查询：\n");
    scanf("%s", name);
    if(!query_name(s, name))
    {
        printf("\n成功查询！\n");
    }
    else
    {
        printf("\n当前没有这名员工信息！\n");
    }
}

/*修改员工信息*/
void Option_four(stack *s)
{
    char *name = malloc(sizeof(char)*name_size);
    printf("\n请输入员工的姓名，进行修改：\n");
    scanf("%s", name);
    if(!query_modifi(s, name))
    {
        printf("\n成功修改！\n");
    }
    else
    {
        printf("\n当前没有这名员工信息！\n");
    }
}

/*清空系统信息*/
void Option_five(stack *s)
{
    clear(s);
    printf("\n完成系统信息清空！\n");
}

void Option_to_menu(stack *s)
{
    Show_menu();
    int option = 0;
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            Option_one(s);
            Option_to_menu(s);
            break;
        case 2:
            Option_two(s);
            Option_to_menu(s);
            break;
        case 3:
            Option_three(s);
            Option_to_menu(s);
            break;
        case 4:
            Option_four(s);
            Option_to_menu(s);
            break;
        case 5:
            Option_five(s);
            Option_to_menu(s);
            break;
        case 6:
            printf("退出系统\n");
            exit(0);
            break;
        default:
            printf("请重新输入1~6\n");
            Option_to_menu(s);
            break;
    }
}
