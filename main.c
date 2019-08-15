#include HEADER
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int sr1[10000000], sr2[10000000], result[20000000];

int main(void)
{
#if defined(PI)
    printf("pid: %d\n", getpid());
    sleep(10);
    compute_pi_baseline(50000000);
#elif defined(MATRIX)
    static int array[10000][10000] = {0};
    matrix(10000,10000,array);
#elif defined(BRANCH)
    int i;
    srand(time(NULL));
    for (i=0; i< 10000000; i++) {
        sr1[i] = rand()%100;
        sr2[i] = rand()%100;
    }
    merge(sr1, sr2, result, 10000000);
#endif
    return 0;

}
