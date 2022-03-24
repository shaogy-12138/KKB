/*************************************************************************
	> File Name: statOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sat 26 Feb 2022 12:30:58 AM CST
 ************************************************************************/

#include "../file.h"
#include<time.h>
typedef struct stat sstat;
void getFileType(sstat *st){
    switch(st->st_mode & S_IFMT){
        case S_IFBLK:
            printf("b");
            break;
        case S_IFCHR:
            printf("c");
            break;
        case S_IFDIR:
            printf("d");
            break;
        case S_IFIFO:
            printf("p");
            break;
        case S_IFLNK:
            printf("l");
            break;
        case S_IFREG:
            printf("-");
            break;
        case S_IFSOCK:
            printf("s");
            break;
        default:
            printf("?");
            break;
    }
}


int main(int argc, char *argv[]){

    sstat st;
    if(argc < 2){
        printf("usage: cmd + filename/dirname\n");
        exit(1);
    }

    int n = stat(argv[1], &st);
    if(n){
        perror("STAT");
        exit(1);
    }
    
    getFileType(&st);
    printf("\nuid = %d\ngid = %d\nsize = %d\n", st.st_uid, st.st_gid, st.st_size);
    printf("Last status change: %s\n", ctime(&st.st_ctime));
    printf("Last access : %s\n", ctime(&st.st_atime));
    printf("Last modify : %s\n", ctime(&st.st_mtime));




    return 0;
}
