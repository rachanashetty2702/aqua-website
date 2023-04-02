
#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, keylen, meslen, flag = 0;
    char ip[100], key[30], temp[30], quot[30], rem[30], key1[30];
    printf("Enter the data word");
    scanf("%s", ip);
    printf("Enter the generator");
    scanf("%s", key);
    keylen = strlen(key);
    meslen = strlen(ip);
    strcpy(key1, key);
    for (i = 0; i < keylen - 1; i++)
    {
        ip[meslen + i] = '0';
    }
    for (i = 0; i < keylen; i++)
        temp[i] = ip[i];
    for (i = 0; i < meslen; i++)
    {
        quot[i] = temp[0];
        if (quot[i] == '0')
            for (j = 0; j < keylen; j++)
                key[j] = '0';
        else
            for (j = 0; j < keylen; j++)
                key[j] = key1[j];
        for (j = keylen - 1; j > 0; j--)
        {
            if (temp[j] == key[j])
                rem[j - 1] = '0';
            else
                rem[j - 1] = '1';
        }
        rem[keylen - 1] = ip[i + keylen];
        strcpy(temp, rem);
    }
    strcpy(rem, temp);
    printf("quotient is \n");
    for (i = 0; i < meslen; i++)
        printf("%c", quot[i]);
    printf("\n remander is \n");
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);
    printf("\n");
    char temp1[20];
    printf("Enter the received data");
    scanf("%s", temp1);
    for (i = 0; i < keylen; i++)
        temp[i] = temp1[i];
    for (i = 0; i < meslen; i++)
    {
        quot[i] = temp[0];
        if (quot[i] == '0')
            for (j = 0; j < keylen; j++)
                key[j] = '0';
        else
            for (j = 0; j < keylen; j++)
                key[j] = key1[j];
        for (j = keylen - 1; j > 0; j--)
        {
            if (temp[j] == key[j])
                rem[j - 1] = '0';
            else
                rem[j - 1] = '1';
        }
        rem[keylen - 1] = temp1[i + keylen];
        strcpy(temp, rem);
    }
    strcpy(rem, temp);
    printf("quotient is \n");
    for (i = 0; i < meslen; i++)
        printf("%c", quot[i]);
    printf(" \n remander is \n");
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);
    flag = 0;
    for (i = 0; i < keylen - 1; i++)
    {
        if (rem[i] == '1')
            flag = 1;
        else
            flag = 0;
    }
    if (flag == 0)
        printf("\n no error\n");
    else
        printf(" \n error detected\n");
    return 0;
}