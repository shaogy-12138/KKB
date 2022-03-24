/*************************************************************************
	> File Name: ls_al.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 10 Mar 2022 08:55:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<time.h>


int main(int argc, char *argv[]){

    struct stat *st;
    char *file_name = (argc < 2) ? "." : argv[1];

    int sd = stat(file_name, st);
    printf("%d\n", fd);
    if(sd < 0){
        perror("stat");
        exit(1);
    }

    switch(st->st_mode & S_IFMT){
        case S_IFBLK:{
            printf("Block device\n");
        }break;
        case S_IFCHR:{
            printf("character device\n");
        }break;
        case S_IFDIR:{
            printf("Directory\n");
        }break;
        case S_IFLNK:{
            printf("symlink file\n");
        }break;
        case S_IFIFO:{
            printf("FIFO/pipe\n");
        }break;
        case S_IFREG:{
            printf("Regular\n");
        }break;
        case S_IFSOCK:{
            printf("Socket\n");
        }break;
        default:{
            printf("unknown?\n");
        }
    }


    long int file_ino = (long)st->st_ino;
    printf("inode = %ld\n", file_ino);

    int uid = st->st_uid, gid = st->st_gid;
    printf("uid = %d, gid = %d", uid, gid);
    long int file_size = (long)st->st_size;
    printf("file size = %ld\n", file_size);


    printf("ctime: %s\n", ctime(&st->st_ctime));
    printf("atime: %s\n", ctime(&st->st_atime));
    printf("mtime: %s\n", ctime(&st->st_mtime));
    return 0;
}
