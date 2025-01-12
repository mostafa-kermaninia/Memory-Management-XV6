#include "types.h"
#include "user.h"

#define SHM_ID 2

void fact_nfork(int n){
    int *shm_id = open_sharedmem(SHM_ID);
    // shm_id[0] = 0;

    for(int i = 0; i < n; i++){
        if(!fork()){
            int mult_val = i + 1;
            // baz krdn
            // zarb dr meghdare khoone hafeze
            // bastan
            exit();
        }
        else 
            continue;
    }
    for (int i = 0; i < n; i++)
        wait();

    //printf(1, "fact(%d) = %d with %d processes", n, addr[0], n);
    //syscall close shared mem
}

void fact_oneprocess(int n){
    //syscall open shared mem

    for(int i = 0; i < n; i++){
        int mult_val = i + 1;
        // baz krdn
        // zarb dr meghdare khoone hafeze
        // bastan
    }

    //printf(1, "fact(%d) = %d with one process", n, addr[0]);
    //syscall close shared mem
}

int main(int argc, char *argv[]){
    if (argc != 2){
        printf(1, "USAGE: facttest #n");
        exit();
    }

    int n = atoi(argv[1]);
    fact_nfork(n);
    fact_oneprocess(n);

    exit();
}