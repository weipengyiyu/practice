#include "main.h"

void Show_menu(void)
{
    printf("\n***************************************\n");
    printf("\n****��ӭʹ��FSԱ����Ϣ����ϵͳV1.0*****\n");
    printf("\n***************************************\n");
    printf("\n**********1��¼��Ա����Ϣ**************\n");
    printf("\n**********2����ʾԱ����Ϣ**************\n");
    printf("\n**********3������Ա����Ϣ**************\n");
    printf("\n**********4���޸�Ա����Ϣ**************\n");
    printf("\n**********5�����ϵͳ��Ϣ**************\n");
    printf("\n**********6���˳�Ա��ϵͳ**************\n");
    printf("\n***************************************\n");
    printf("\n********������ǰ�����ţ�*************\n");
}

/*���Ա����Ϣ*/
void Option_one(stack *s)
{
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->name = malloc(sizeof(char)*name_size);
    if(newnode == NULL)
    {
        printf("��̬�ڴ����ʧ�ܣ�");
        exit(-1);
    }

    printf("\n����������Ա����Ϣ\n");
    printf("\nԱ������\n");
    scanf("%s", newnode->name);
    printf("\nԱ������\n");
    scanf("%d", &newnode->age);
    printf("\nԱ������\n");
    scanf("%d", &newnode->work_age);
    printf("\nԱ��н��\n");
    scanf("%d", &newnode->salary);

    if(!push(s, newnode))
    {
        printf("\n�ѱ���Ա����Ϣ\n");
    }
}

/*��ʾԱ����Ϣ*/
void Option_two(stack *s)
{
    printf("\nԱ����Ϣ��\n");
    traverse(s);
}

/*����Ա����Ϣ*/
void Option_three(stack *s)
{
    char *name = malloc(sizeof(char)*name_size);
    printf("\n������Ա�������������в�ѯ��\n");
    scanf("%s", name);
    if(!query_name(s, name))
    {
        printf("\n�ɹ���ѯ��\n");
    }
    else
    {
        printf("\n��ǰû������Ա����Ϣ��\n");
    }
}

/*�޸�Ա����Ϣ*/
void Option_four(stack *s)
{
    char *name = malloc(sizeof(char)*name_size);
    printf("\n������Ա���������������޸ģ�\n");
    scanf("%s", name);
    if(!query_modifi(s, name))
    {
        printf("\n�ɹ��޸ģ�\n");
    }
    else
    {
        printf("\n��ǰû������Ա����Ϣ��\n");
    }
}

/*���ϵͳ��Ϣ*/
void Option_five(stack *s)
{
    clear(s);
    printf("\n���ϵͳ��Ϣ��գ�\n");
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
            printf("�˳�ϵͳ\n");
            exit(0);
            break;
        default:
            printf("����������1~6\n");
            Option_to_menu(s);
            break;
    }
}
