//
//  joey.cpp
//  spiral_matrix_joey
//
//  Created by pilhoon on 7/13/14.
//  Copyright (c) 2014 pilhoon. All rights reserved.
//

#include <cstdio>
#include <cstdlib>

#define ALLOC_CHECK(x)  if((x)==NULL) { printf("allocation fail\n"); return 1;}

void dp(long* longp, long length, int stride) {
    for(int i=0; i<length; i++) {
        if(i % stride ==0) printf("\n");
        printf("%ld ", longp[i]);
    }
}

int main(int argc, const char * argv[])
{
    if(argc != 3) {
        printf("a.out nr nc\n");
        return 1;
    }
    
    int nr=atoi(argv[1]), nc=atoi(argv[2]);
    
    //generate base serise
    int stride = nc;
    int rlimit = nr-1, climit = nc-1;
    const long BOARD_LEN = (long)nr*nc;
    int *base_serise = new int[BOARD_LEN-1];
	ALLOC_CHECK(base_serise)

    long cur_idx = 0;
    for(int i=0; i<climit; i++) {
        base_serise[cur_idx] = 1;
        cur_idx++;
    }
    
    int cur_sign = -1;
    while(true) {
        for(int i=0; i<rlimit; i++) {
            base_serise[cur_idx] = -1 * cur_sign * stride;
            cur_idx++;
        }
        for(int i=0; i<climit; i++) {
            base_serise[cur_idx] = cur_sign * 1;
            cur_idx++;
        }
        
        cur_sign = -cur_sign;
        rlimit--;
        climit--;
        
        if(rlimit == -1 || climit==-1)
            break;
    }
    
    long *semi_serise = new long[BOARD_LEN];
	ALLOC_CHECK(semi_serise);

    semi_serise[0] = 0;
    for(long i=1; i<BOARD_LEN; i++) {
        semi_serise[i] = semi_serise[i-1] + base_serise[i-1];
    }
    
    //delete[] base_serise;
    
    
    long *final_serise = new long[BOARD_LEN];
	ALLOC_CHECK(final_serise);

    //inverse permutation
    for(long i=0;i < BOARD_LEN; i++) {
        final_serise[semi_serise[i]] = i;
    }
    
	printf("%ld\n", final_serise[BOARD_LEN-1]); // meaningless. prevent optimization
//	dp(final_serise, BOARD_LEN, nc);
//    delete[] semi_serise;
//    delete[] final_serise;
    return 0;
}

