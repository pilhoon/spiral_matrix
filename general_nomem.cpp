//
//  general_nomem.cpp
//  spiral_matrix_joey
//
//  Created by pilhoon on 7/14/14.
//  Copyright (c) 2014 pilhoon. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define ALLOC_CHECK(x)  if((x)==NULL) { printf("allocation fail\n"); return 1;}

using std::min;

int min4(int a, int b, int c, int d) {
    return min(min(a,b), min(c,d));
}

void print_mat(long** m, int h, int w) {
	for(int r=0; r<h; r++) 
	{
		for(int c=0; c<w; c++)
		{
			printf("%ld\t", m[r][c]);
		}
		printf("\n");
	}
}

int main(int ac, char** av) {
	if(ac != 3)
	{
		printf("usage: %s row_num col_num \n", av[0]);
		return 1;
	}

    int nr, nc;
    nr = atoi(av[1]);
    nc = atoi(av[2]);
	long scratch =0 ; //just prevent calc result from optimization
/*    long** board = new long*[nr];
    ALLOC_CHECK(board)
    for(int r=0; r<nr; r++) 
    {
        board[r] = new long[nc];
        ALLOC_CHECK(board[r])
    }
*/
    const int N_0 = 2*(nr+nc)-4;
    //N_k = N_0 - 8k 
    //sigma N_k = (n+1)*N_0 - (4*n*(n+1))

    for(int r=0; r<nr; r++) 
    {
        for(int c=0; c<nc; c++) 
        {
            //general formular
            //1. get circle order
            int nth_circle = min4(r,c,nr-1-r,nc-1-c);
            //2. get former numbers' sum (former circles). former circles # = nth_circle -1
            long sigma = (nth_circle)*N_0  - (4*(nth_circle-1)*nth_circle);
            //3. get my order
            int my_order =0;
            if(r== nth_circle || (nc-1-c) == nth_circle) 
            {
                my_order = c - nth_circle + r - nth_circle;
            }
            else 
            {
                //my_order = nc - 2*nth_circle + nr - 2*nth_circle + (nc - nth_circle -c) + (nr - nth_circle - r);
                //         = 2*nc + 2*nr - 6*nth_circle -r -c
                my_order = 2*(nc + nr -2 - (3*nth_circle)) -r -c;
            }
            // store result
 //           board[r][c] = sigma + my_order;
 			scratch = sigma + my_order;
        }
		if(r%1000 == 0)
			printf("complete row %d\n", r); //view progress
    }

	//print_mat(board, nr, nc);
	return 0;
}
