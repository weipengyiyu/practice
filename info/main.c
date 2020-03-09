#include "main.h"

int main()
{
    hashtable h[hash_size];
    int  flag[hash_size] = {0};               //���μ�¼ÿ��key��Ӧ���±�,���Կ��ٱ������е�����
    hash_new(h);

    Option_to_menu(h, flag);
    printf("Hello world!\n");
    return 0;
}

void Show_menu(void)
{
    printf("\n***************************************\n");
    printf("\n****��ӭʹ��FSԱ����Ϣ����ϵͳV1.0*****\n");
    printf("\n***************************************\n");
    printf("\n**********1��¼��Ա����Ϣ**************\n");
    printf("\n**********2����ʾԱ����Ϣ**************\n");
    printf("\n**********3������Ա����Ϣ**************\n");
    printf("\n**********4���޸�Ա����Ϣ**************\n");
    printf("\n**********5��ɾ��Ա����Ϣ**************\n");
    printf("\n**********6���˳�Ա��ϵͳ**************\n");
    printf("\n***************************************\n");
    printf("\n********������ǰ�����ţ�*************\n");
}

/*���Ա����Ϣ*/
void Option_one(hashtable *h, int *flag)
{
    hashtable tempdata;
    int key = -1;
    int flag1 = 1;
    int i = 0;

    tempdata.name = (char*)malloc(sizeof(char)*20);
    printf("\n����������Ա����Ϣ\n");
    printf("\nԱ������--������Сд����ĸƴ��\n");
    do
    {
        scanf("%s", tempdata.name);
        while(tempdata.name[i] != '\0')
            i++;
        if(i > 9)
        {
            i = 0;
            printf("\n����������Խ�磬���������룬��֤�ַ�С��10��\n");
        }
        else
        {
            flag1 = 0;
        }
    }while(flag1);


    printf("\nԱ������--������С��65535������\n");
    while(!(scanf("%d", &tempdata.age) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("���������������������С��65535��������\n");
    }

    printf("\nԱ������--������С��65535������\n");
    while(!(scanf("%d", &tempdata.work_age) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("���������������������С��65535��������\n");
    }

    printf("\nԱ��н��--������С��65535������\n");
    while(!(scanf("%d", &tempdata.salary) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("���������������������С��65535��������\n");
    }


    name_to_key(tempdata.name, &key);
    if(key < 0)
        exit(0);

    if(!hash_add(h, key, &tempdata, flag))
    {
        printf("\n�ѱ���Ա����Ϣ\n");
    }

    free(tempdata.name);
}

/*��ʾԱ����Ϣ*/
void Option_two(hashtable *h, int *flag)
{
    printf("\nԱ����Ϣ��\n");
    hash_show(h, flag);
}

/*����Ա����Ϣ*/
void Option_three(hashtable *h)
{
    char name[10];
    int flag = 1;
    int i = 0;

    printf("\n������Ա�������������в�ѯ��\n");
    do
    {
        scanf("%s", name);
        while(name[i] != '\0')
            i++;

        if(i > 9)
        {
            printf("\n����������Խ�磬���������룬��֤�ַ�С��10��\n");
        }
        else
        {
            flag = 0;
        }
    }while(flag);

    if(!hash_query(h, name))
    {
        printf("\n�ɹ���ѯ��\n");
    }
    else
    {
        printf("\n��ǰû������Ա����Ϣ��\n");
    }
}

/*�޸�Ա����Ϣ*/
void Option_four(hashtable *h)
{
    hashtable temp;
    int flag1 = 1;
    int flag2 = 1;
    int i = 0;
    int j = 0;
    char *name = (char*)malloc(sizeof(char)*20);

    printf("\n��������Ҫ�޸ĵ�Ա������:\n");
    do
    {
        scanf("%s", name);
        while(name[i] != '\0')
            i++;
        if(i > 9)
        {
            printf("\n����������Խ�磬���������룬��֤�ַ�С��10��\n");
        }
        else
        {
            flag1 = 0;
        }
    }while(flag1);

    printf("\n�������޸ĺ��Ա������:\n");
    do
    {
        scanf("%s", temp.name);
        while(temp.name[j] != '\0')
            j++;
        if(j > 9)
        {
            printf("\n����������Խ�磬���������룬��֤�ַ�С��10��\n");
        }
        else
        {
            flag2 = 0;
        }
    }while(flag2);

    printf("\nԱ������--������С��65535������\n");
    while(!(scanf("%d", &temp.age) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("���������������������С��65535��������\n");
    }
    printf("\nԱ������--������С��65535������\n");
    while(!(scanf("%d", &temp.work_age) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("���������������������С��65535��������\n");
    }
    printf("\nԱ��н��--������С��65535������\n");
    while(!(scanf("%d", &temp.salary) && getchar() == '\n'))
    {
        while(getchar() != '\n');
        printf("���������������������С��65535��������\n");
    }

    if(!hash_modifi(h, name, &temp))
    {
        printf("\n�ɹ��޸ģ�\n");
    }
    else
    {
        printf("\n��ǰû������Ա����Ϣ��\n");
    }

    free(name);
}

/*������ݣ���δɾ��*/
void Option_five(hashtable *h)
{
    int flag = 1;
    char *temp = (char*)malloc(sizeof(char)*20);
    int i = 0;
    printf("\n��������Ҫɾ����Ա��������\n");
    do
    {
        scanf("%s", temp);
        while(temp[i] != '\0')
            i++;

        if(i > 9)
        {
            printf("\n����������Խ�磬���������룬��֤�ַ�С��10��\n");
        }
        else
        {
            flag = 0;
        }
    }while(flag);

    if(!hash_clean(h, temp))
    {
        printf("\n�����\n");
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
        printf("�������������������������1~6������\n");
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
            printf("�˳�ϵͳ\n");
            exit(0);
            break;
        default:
            printf("����������1~6\n");
            Option_to_menu(h, flag);
            break;
    }
}

