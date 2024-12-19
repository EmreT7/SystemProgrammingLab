#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char *argv[])
{
        if(argc != 2)
        {
                printf("Bir dosya ismi vermelisiniz\n");
                exit(-1);
        }
        int n;
        int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
        if(fd < 0) {
                printf("Dosya acma hatasi\n");
                exit(-2);
        }
        char buf[26] = "Bu dosya yeni olusturuldu.";
        if(n = write(fd,buf,sizeof(buf)-1) < 0)
        {
                printf("Yazma hatasi\n");
                exit(-3);
        }
        close(fd);
        fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, FILE_MODE);
        char buf2[25] = "Dosyanin ikinci satiri.\n";

        write(fd, buf2, sizeof(buf2));
        close(fd);
        return 0;
}
