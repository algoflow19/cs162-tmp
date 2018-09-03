#include <stdio.h>
#include <sys/resource.h>
#include<sys/time.h>

int main() {
    struct rlimit lim;
    getrlimit(RLIMIT_STACK,&lim);
    printf("stack size: %lu\n", lim.rlim_cur);
    getrlimit(RLIMIT_NPROC,&lim);
    printf("process limit: %ld\n", lim.rlim_cur);
    getrlimit(RLIMIT_NOFILE,&lim);
    printf("max file descriptors: %ld\n", lim.rlim_cur);
    return 0;
}
