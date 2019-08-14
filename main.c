#include HEADER
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

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
    int sr1[100000], sr2[100000], result[200000];
    srand(time(NULL));
    for (i=0; i< 100000; i++) {
        sr1[i] = rand()%100;
        sr2[i] = rand()%100;
    }
    merge(sr1, sr2, result, 100000);
#endif
    return 0;

}
