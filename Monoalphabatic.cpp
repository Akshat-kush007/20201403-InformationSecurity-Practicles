#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{

    char plain[200], encr[200], decr[200];
    int ch, flag[26];
    char ch1;
    char per[26];
    int i,j,size,k=0,a=0;
    char pos;

    // Input the plaintext
    printf("\nEnter the plain text : ");
    cin.getline(plain, 100);
    size=strlen(plain);

    // Generate a random permutation of the alphabet
    for(i=0;i<26;i++)
        flag[i]=0;

    for(i=0;i<26;i++)
    {
        a=rand()%26;
        while(flag[a]==1)
            a=rand()%26;
        flag[a]=1;
        per[i]=(char)(a+97);
    }

    // Encrypt the plaintext using the permutation
    for(j=0;j<size;j++)
    {
        ch=plain[j];
        ch=ch-97;
        ch1=per[ch];
        encr[j]=ch1;
    }

    printf("\nPermuted array is: ");
    for(i=0;i<26;i++)
    {
    printf("%c ",per[i]);
    }
    // Print the encrypted text
    printf("\nThe encrypted string is: ");
    for(i=0;i<size;i++)
    {
        printf("%c",encr[i]);
    }

    // Decrypt the ciphertext using the permutation
    i=0;
    while(i<size)
    {
        a=0;
        while(a!=26)
        {
            if(per[a]==encr[i])
            {
                decr[i]=a+97;
                break;
            }
            a++;
        }
        i++;
    }
    decr[i]='\0';

    // Print the decrypted text
    printf("\nDecrypted string: %s\n",decr);
    return 0;
}
