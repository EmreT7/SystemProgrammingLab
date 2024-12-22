#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
        if(argc != 2)
        {
                printf("Bir dosya ismi vermelisiniz\n");
                exit(-1);
        }
        int n;
        int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if(fd < 0)
        {
                printf("Dosya acma hatasi\n");
                exit(-2);
        }
        char buf[] = "Bu dosya sadece Dincer Erbas tarafindan okunabilir.\n";
        if(n = write(fd,buf,sizeof(buf)-1) < 0)
        {
                printf("Yazma hatasi\n");
                exit(-3);
        }
        close(fd);
        if (chmod(argv[1], S_IRUSR | S_IWUSR | S_IWGRP | S_IROTH) < 0)
        {
                printf("changemod hatasi\n");
                exit(-4);
        }
        fd = open(argv[1], O_WRONLY | O_APPEND);
        char buf2[] = "Dosyanin izinler degisti, artik grup arkadaslarim da yazabiliyor.";
        if(n = write(fd,buf2,sizeof(buf2)-1) < 0)
        {
                printf("Yazma hatasi\n");
                exit(-3);
        }

        close(fd);
        return 0;
}
