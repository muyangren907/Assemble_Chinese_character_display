#include "bits/stdc++.h"
using namespace std;
int main()
{
    int i, j, k, offset;
    int flag;
    unsigned char buff[32];
    unsigned char word[5];
    unsigned char key[] ={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
    FILE *fzk = fopen("hzk16", "rb");
    if(!fzk)
    {
        fprintf(stderr, "open hzk16 error\n");
        return 1;
    }
    while(1)
    {
        for(;;)
        {
            fgets((char*)word, 3, stdin);
            if(*word == '\n')
                break;
            offset = (94*(unsigned int)(word[0]-0xa0-1)+(word[1]-0xa0-1))*32;
            fseek(fzk, offset, SEEK_SET);
            fread(buff, 1, 32, fzk);
            for(k=0; k<16; k++)
                for(j=0; j<2; j++)
                    for(i=0; i<8; i++)
                        flag = buff[k*2+j]&key[i];
            cout<<endl<<"DB ";
            for(k=0; k<15; k++)
                printf("0%02XH,", buff[k]);
            printf("0%02XH\nDB ", buff[15]);
            for(k=16; k<31; k++)
                printf("0%02XH,", buff[k]);
            printf("0%02XH\n", buff[31]);
        }
    }
    fclose(fzk);
    return 0;
}
