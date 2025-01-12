#include "types.h"
#include "user.h"

#define SHM_ID 2

void fact_nfork(int n)
{
    int *shmem = (int *)open_sharedmem(SHM_ID);
    shmem[0] = 1;

    for (int i = 0; i < n; i++)
    {
        if (!fork())
        {
            int *shmem_child = (int *)open_sharedmem(SHM_ID);
            shmem_child[0] *= (i + 1);
            close_sharedmem(SHM_ID);
            exit();
        }
        else
            continue;
    }
    for (int i = 0; i < n; i++)
        wait();
        
    printf(1, "fact(%d) = %d for %d processes\n", n, shmem[0], n);
    close_sharedmem(SHM_ID);
}

void fact_oneprocess(int n)
{
    int *shmem = (int *)open_sharedmem(SHM_ID);
    shmem[0] = 1;

    for (int i = 0; i < n; i++)
    {
        shmem[0] *= (i + 1);
    }

    printf(1, "fact(%d) = %d with one processes\n", n, shmem[0], n);
    close_sharedmem(SHM_ID);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf(1, "USAGE: facttest #n");
        exit();
    }

    int n = atoi(argv[1]);
    fact_nfork(n);
    fact_oneprocess(n);

    exit();
}