#include "main.h"

static int count = 0;

//*��ʼ��hash_size���洢�ռ�,�����ռ任ȡʱ��*/
void hash_new(hashtable *h)
{
    int i;
    for(i = 0; i < hash_size; i++)
    {
       h[i].name = (char*)malloc(sizeof(char)*10);
       h[i].age = 0;
       h[i].work_age = 0;
       h[i].salary = 0;
    }
}

/*ȡ���һ���ַ�����Ϊkey�ļ�ֵ*/
int name_to_key(char *name, int *key)
{
    int i = 0;

    while(name[i] != '\0')
        i++;

    if(i > 9)
    {
        //printf("\n����������Խ�磬���������룬��֤�ַ�С��10��\n");
        return 0;
    }

    *key = name[i-1];

    return 1;
}

/*���һ��Ԫ��*/
int hash_add(hashtable *h, int key, hashtable *data, int *flag)
{
    hashtable *temp = NULL;
    temp = h;
    int index;
    int i = 0;
    int iflag = 1;

    index = key % 13;
    do
    {
        if(temp[index].age == 0)
        {
            iflag = 0;
            strcpy(temp[index].name, data->name);
            temp[index].age = data->age;
            temp[index].work_age = data->work_age;
            temp[index].salary = data->salary;
        }
        else
        {
            index = (key + i)% 13;
            i++;
            if(i > 5)
            {
            	printf("\n�Ѿ�������5�Σ�������������\n");
            	break;
            }
        }
    }while(iflag);

    flag[count] = index;
    count++;

    return 0;
}

/*ͨ����ֵ���ҵ��±꣬�ٽ�����ʾ����*/
int hash_query(hashtable *h, char *query)
{
    hashtable *temp = NULL;
    temp = h;
    int index;
    int i = 0;
    int iflag = 1;
    int key = -1;
    int re = 0;

    name_to_key(query, &key);

    index = key % 13;
    do
    {
        if((temp[index].age != 0) && (strcmp(temp[index].name, query) == 0))
        {
            iflag = 0;
            printf("name: %s\t", temp[index].name);
            printf("age: %d\t", temp[index].age);
            printf("work_age: %d\t", temp[index].work_age);
            printf("salary: %d\n", temp[index].salary);
        }
        else
        {
            index = (key + i)% 13;
            i++;
            if(i > 5)
            {
            	printf("\n������������\n");
            	re = 1;
            	break;
            }
        }
    }while(iflag);

    return re;
}

/*ͨ����ֵ���ҵ��±꣬�ٽ����޸ģ� �޸ĺ������������洢��*/
int hash_modifi(hashtable *h, char *modifi, hashtable *data, int *flag)
{
    hashtable *temp = NULL;
    temp = h;
    int index;
    int i = 0;
    int iflag = 1;
    int key = -1;
    int re = 0;

    name_to_key(modifi, &key);

    index = key % 13;
    do
    {
        if((temp[index].age != 0) && (strcmp(temp[index].name, modifi) == 0))
        {
            iflag = 0;
            memset(temp[index].name,0, sizeof(char)*10);
            temp[index].age = 0;
            temp[index].work_age = 0;
            temp[index].salary = 0;
        }
        else
        {
            index = (key + i)% 13;
            i++;
            if(i > 5)
            {
            	printf("\n�Ѿ�������5�Σ�������������\n");
            	re = 1;
            	break;
            }
        }
    }while(iflag);

    name_to_key(data->name, &key);
    hash_add(h, key, data, flag);
    return re;
}

/*������ݣ���δɾ��*/
int hash_clean(hashtable *h, char *clean)
{
    hashtable *temp = NULL;
    temp = h;
    int index;
    int i = 0;
    int iflag = 1;
    int key = -1;

    name_to_key(clean, &key);

    index = key % 13;
    do
    {
        if((temp[index].age != 0) && (strcmp(temp[index].name, clean) == 0))
        {
            iflag = 0;
            memset(temp[index].name, 0, sizeof(char)*10);
            temp[index].age = 0;
            temp[index].work_age = 0;
            temp[index].salary = 0;
        }
        else
        {
            index = (key + i)% 13;
            i++;
            if(i > 5)
            {
            	printf("\n�Ѿ�������5�Σ�������������\n");
            	break;
            }
        }
    }while(iflag);

    return 0;
}

void hash_show(hashtable *h, int *flag)
{
	int i;
	for(i = 0; i < count; i++)
	{
		if(h[flag[i]].age != 0)
		{
			printf("name: %s\t", h[flag[i]].name);
			printf("age: %d\t", h[flag[i]].age);
			printf("work_age: %d\t", h[flag[i]].work_age);
			printf("salary: %d\n", h[flag[i]].salary);
		}
	}
}
