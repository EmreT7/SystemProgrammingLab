#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Uc dosya ismi vermelisiniz\n");
        exit(-1);
    }

    
    int n;
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd < 0)
    {
        printf("Dosya acma hatasi\n");
        exit(-2);
    }
    char buf1[] = "Bu dosyayi Emre Turkmen yazabilir ve diger kullanicilar okuyabilir.\n";
    if((n = write(fd, buf1, sizeof(buf1)-1)) < 0)
    {
        printf("Yazma hatasi\n");
        exit(-3);
    }
    if (chmod(argv[1], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
    {
        printf("changemod hatasi\n");
        exit(-4);
    }

    
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd2 < 0)
    {
        printf("Dosya acma hatasi\n");
        exit(-2);
    }
    char buf2[] = "Bu dosyayi ben ve grup uyelerim okuyup yazabiliriz, digerleri sadece okuyabilir.\n";
    if((n = write(fd2, buf2, sizeof(buf2)-1)) < 0)
    {
        printf("Yazma hatasi\n");
        exit(-3);
    }
    if (chmod(argv[2], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP) < 0)
    {
        printf("changemod hatasi\n");
        exit(-4);
    }
	
	
    int fd3 = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd3 < 0)
    {
        printf("Dosya acma hatasi\n");
        exit(-2);
    }
    char buf3[] = "Bu dosyayi herkes okuyup yazabilir.\n";
    if((n = write(fd3, buf3, sizeof(buf3)-1)) < 0)
    {
        printf("Yazma hatasi\n");
        exit(-3);
    }
    if (chmod(argv[3], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)
    {
        printf("changemod hatasi\n");
	exit(-4);
        }
		close(fd);
		close(fd2);
		close(fd3);
		return 0;
}