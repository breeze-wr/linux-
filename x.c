#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void* thread_func(void*args)
{
    printf("hello,this is thread: %d %ld\n",getpid(),pthread_self());
    return NULL;
}



int main()
{
    pthread_t thread_id;
    pthread_create(&thread_id,NULL,thread_func,NULL);
    printf("hello ,this is thread:%d %ld\n",getpid(),pthread_self());
    sleep(1);
    return 0;
    
}
