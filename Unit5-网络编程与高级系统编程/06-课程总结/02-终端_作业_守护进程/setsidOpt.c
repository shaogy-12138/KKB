/*************************************************************************
	> File Name: setsidOpt.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Tue 12 Apr 2022 11:46:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>



int main(){


    pid_d pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }

    if(pid){
        // 父进程
        exit(0);

    }else{
        // 子进程
        
        pid_t nsid = setsid();
        printf("new session id = %d\n", nsid);
        
        if(chdir("/")<0){
            perror("chdir");
            exit(1);
        }

        close(0);
        open("/dev/null", O_RDWR);
        dup2(0, 1);
        dup2(0, 2);

        while(1){
            sleep(1);
        }
    }
    return 0;
}
