#include "main.h"

int main()
{
    hashtable h[hash_size];
    int  flag[hash_size] = {0};               //依次记录每次key对应的下标,可以快速遍历已有的数据
    hash_new(h);

    Option_to_menu(h, flag);
    printf("Hello world!\n");
    return 0;
}

void Show_menu(void)
{
    printf("\n***************************************\n");
    printf("\n****欢迎使用FS员工信息管理系统V1.0*****\n");
    printf("\n***************************************\n");
    printf("\n**********1、录入员工信息**************\n");
    printf("\n**********2、显示员工信息**************\n");
    printf("\n**********3、查找员工信息**************\n");
    printf("\n**********4、修改员工信息**************\n");
    printf("\n**********5、删除员工信息**************\n");
    printf("\n**********6、退出员工系统**************\n");
    printf("\n***************************************\n");
    printf("\n********请输入前面的序号：*************\n");
}

/*添加员工信息*/
void Option_one(hashtable *h, int *flag)
{
    hashtable tempdata;
    int key = -1;
    int flag1 = 1;
    int i = 0;

    tempdata.name = (char*)malloc(sizeof(char)*20);
    printf("\n请依次输入员工信息\n");
    printf("\n员工姓名--请输入小写的字母拼音\n");
    do
    {
        scanf("%s", tempdata.name);
        while(tempdata.name[i] != '\0')
            i++;
        if(i > 9)
        {
            i = 0;
            printf("\n输入数据已越界，请重新输入，保证字符小于10个\n");
        }
        else
        {
            flag1 = 0;
        }
    }while(flag1);


    printf("\n员工年龄--请输入小于65535的正数\n");
    while(!(scanf("%d", &tempdata.age) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("你输入的数据有误，请输入小于65535的正数！\n");
    }

    printf("\n员工工龄--请输入小于65535的正数\n");
    while(!(scanf("%d", &tempdata.work_age) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("你输入的数据有误，请输入小于65535的正数！\n");
    }

    printf("\n员工薪资--请输入小于65535的正数\n");
    while(!(scanf("%d", &tempdata.salary) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("你输入的数据有误，请输入小于65535的正数！\n");
    }


    name_to_key(tempdata.name, &key);
    if(key < 0)
        exit(0);

    if(!hash_add(h, key, &tempdata, flag))
    {
        printf("\n已保存员工信息\n");
    }

    free(tempdata.name);
}

/*显示员工信息*/
void Option_two(hashtable *h, int *flag)
{
    printf("\n员工信息！\n");
    hash_show(h, flag);
}

/*查找员工信息*/
void Option_three(hashtable *h)
{
    char name[10];
    int flag = 1;
    int i = 0;

    printf("\n请输入员工的姓名，进行查询：\n");
    do
    {
        scanf("%s", name);
        while(name[i] != '\0')
            i++;

        if(i > 9)
        {
            printf("\n输入数据已越界，请重新输入，保证字符小于10个\n");
        }
        else
        {
            flag = 0;
        }
    }while(flag);

    if(!hash_query(h, name))
    {
        printf("\n成功查询！\n");
    }
    else
    {
        printf("\n当前没有这名员工信息！\n");
    }
}

/*修改员工信息*/
void Option_four(hashtable *h)
{
    hashtable temp;
    int flag1 = 1;
    int flag2 = 1;
    int i = 0;
    int j = 0;
    char *name = (char*)malloc(sizeof(char)*20);

    printf("\n请输入需要修改的员工姓名:\n");
    do
    {
        scanf("%s", name);
        while(name[i] != '\0')
            i++;
        if(i > 9)
        {
            printf("\n输入数据已越界，请重新输入，保证字符小于10个\n");
        }
        else
        {
            flag1 = 0;
        }
    }while(flag1);

    printf("\n请输入修改后的员工姓名:\n");
    do
    {
        scanf("%s", temp.name);
        while(temp.name[j] != '\0')
            j++;
        if(j > 9)
        {
            printf("\n输入数据已越界，请重新输入，保证字符小于10个\n");
        }
        else
        {
            flag2 = 0;
        }
    }while(flag2);

    printf("\n员工年龄--请输入小于65535的正数\n");
    while(!(scanf("%d", &temp.age) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("你输入的数据有误，请输入小于65535的正数！\n");
    }
    printf("\n员工工龄--请输入小于65535的正数\n");
    while(!(scanf("%d", &temp.work_age) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("你输入的数据有误，请输入小于65535的正数！\n");
    }
    printf("\n员工薪资--请输入小于65535的正数\n");
    while(!(scanf("%d", &temp.salary) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("你输入的数据有误，请输入小于65535的正数！\n");
    }

    if(!hash_modifi(h, name, &temp))
    {
        printf("\n成功修改！\n");
    }
    else
    {
        printf("\n当前没有这名员工信息！\n");
    }

    free(name);
}

/*清除数据，并未删除*/
void Option_five(hashtable *h)
{
    int flag = 1;
    char *temp = (char*)malloc(sizeof(char)*20);
    int i = 0;
    printf("\n请输入需要删除的员工姓名：\n");
    do
    {
        scanf("%s", temp);
        while(temp[i] != '\0')
            i++;

        if(i > 9)
        {
            printf("\n输入数据已越界，请重新输入，保证字符小于10个\n");
        }
        else
        {
            flag = 0;
        }
    }while(flag);

    if(!hash_clean(h, temp))
    {
        printf("\n已清除\n");
    }

    free(temp);
}

void Option_to_menu(hashtable *h, int *flag)
{
    Show_menu();
    int option = 0;
    while(!(scanf("%d", &option) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("你输入的数据有误，请重新输入1~6正数！\n");
    }

    switch(option)
    {
        case 1:
            Option_one(h, flag);
            Option_to_menu(h, flag);
            break;
        case 2:
            Option_two(h, flag);
            Option_to_menu(h, flag);
            break;
        case 3:
            Option_three(h);
            Option_to_menu(h, flag);
            break;
        case 4:
            Option_four(h);
            Option_to_menu(h, flag);
            break;
        case 5:
            Option_five(h);
            Option_to_menu(h, flag);
            break;
        case 6:
            printf("退出系统\n");
            exit(0);
            break;
        default:
            printf("请重新输入1~6\n");
            Option_to_menu(h, flag);
            break;
    }
}

