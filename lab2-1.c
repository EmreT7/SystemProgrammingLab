#include <stdio.h>

int main() {
        char inputs[4][100]; // liste
        int count = 0; // girdi sayisi

        printf("Lutfen 4 giris yapiniz. Girisi bitirmek icin Ctrl + D ye basiniz.\n");

        // 4 girdi almak icin dongu
        for(int i = 0; i < 4; i++) {
                printf("Giris %d;", i+1);
                // ctrl + d kontrolu
                if(fgets(inputs[i], sizeof(inputs[i]), stdin) == NULL) {
                        break;

                }
                count++;
        }

        //4ten az girildiyse
        if(count < 4) {
                printf("\n %d girdi yaptiniz:\n", count);
        } else {
                printf("\n 4 girdi yaptiniz, girdiler: \n");
        }

        for(int i = 0; i < count; i++) {
                printf("Input %d: %s", i+1, inputs[i]);
        }

        return 0;
}


//HOCANIN ÇALIŞMA YÖNTEMİ



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        if(argc != 5)
        {
                printf("Tam 4 girdi verilmelidir!\n");
                printf("%d girdi verdiniz.\n",argc-1);
                exit(-1);
        }
        int i;
        for(i = 1; i < argc; i++)
                printf("%d. girdi: %s\n",i,argv[i]);
        exit(0);
}
