//
//  brutal.cpp
//  spiral_matrix_basic
//
//  Created by pilhoon on 7/12/14.
//  Copyright (c) 2014 pilhoon. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    if(argc != 3) {
        printf("a.out nr nc\n");
        return 1;
    }
    
    int nr=atoi(argv[1]), nc=atoi(argv[2]);
    int **board = new int*[nr];
    for(int i=0; i<nr; i++) {
        board[i] = new int[nc];
    }
    for(int r=0; r<nr; r++) {
        for(int c=0; c<nc; c++) {
            board[r][c] = -1;
        }
    }
    
    enum direction { RIGHT, DOWN, LEFT, UP };
    int n=1;
    int r=0, c=0;
    direction d = RIGHT;
    while(true) {
        if(board[r][c] != -1)
            break;
        
        board[r][c] = n;
        n++;
        switch(d) {
            case RIGHT:
                if(c==nc-1 || board[r][c+1] != -1) { //turn right
                    d = DOWN;
                    r++;
                } else {
                    c++;
                }
                break;
            case DOWN:
                if(r==nr-1 || board[r+1][c] != -1) {
                    d = LEFT;
                    c--;
                } else {
                    r++;
                }
                break;
            case LEFT:
                if(c==0 || board[r][c-1] != -1) {
                    d = UP;
                    r--;
                } else {
                    c--;
                }
                break;
            case UP:
                if(r==0 || board[r-1][c] != -1) {
                    d = RIGHT;
                    c++;
                } else {
                    r--;
                }
                break;
        }
    }
    
    //memory delete process omitted. just troublesome.

    // print matrix
    /*
    for(int r=0; r < nr; r++) {
        for(int c=0; c<nc; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
    */
    return 0;
}


