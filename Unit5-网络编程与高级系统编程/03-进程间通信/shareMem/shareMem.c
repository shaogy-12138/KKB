/*************************************************************************
	> File Name: shareMem.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Tue 22 Mar 2022 10:45:33 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
#include<strings.h>
#include<sys/wait.h>
int main(void){

    key_t key = ftok("../fifoOpt/readFifo.c", 99);  // 利用一个文件中的字段和工程号获得一个key值
    if(key < 0){
        perror("ftok");
        exit(1);
    }
    printf("key = %0x\n", key);

    int shmid = shmget(key, 20, IPC_CREAT | 0666); // shmget返回内存块id
    if(shmid < 0){
        perror("shmget");
        exit(1);
    }
    printf("%d\n", shmid);

    
    char *shmp = shmat(shmid, NULL, 0);
    if(shmp < 0){
        perror("shmat");
        exit(1);
    }
   
    perror("shmat");
    printf("shmp = %p\n", shmp);


    //snprintf(shmp, 7, "hello\n");
    //printf("%s", shmp);
    //


    bzero(shmp, 20);
    pid_t  pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }
    perror("fork");

    if(pid){
        // parent
        while(1){

            scanf("%s", shmp);
            if(!strcmp(shmp, "quit")){
                break;
            }
        }

        wait(NULL);
    }else{
        //child
        while(1){
            if(!strcmp(shmp, "quit")){
                break;
            }
            if(*shmp){
                    
                printf("[%s]", shmp);
                bzero(shmp, 20); // 每次读取后清空
            }
            sleep(1);
        }

    }

    shmdt(shmp);


    return 0;
}
