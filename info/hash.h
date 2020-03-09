#ifndef HASH_H_
#define HASH_H_

#define hash_size 30

typedef struct h
{
    char *name;                         //每次限制输入10个字符
    int  age;
    int  work_age;
    int  salary;
}hashtable;

void hash_new(hashtable *h);
int  hash_query(hashtable *h, char *query);
int  hash_add(hashtable *h, int key, hashtable *data, int *flag);
int  hash_clean(hashtable *h, char *clean);
void hash_show(hashtable *h, int *flag);
int  hash_modifi(hashtable *h, char *modifi, hashtable *data);
int  name_to_key(char *name, int *key);

#endif /* HASH_H_ */
