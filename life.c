#include "life.h"
#include <stdio.h>
int is_alive(int row, int col, unsigned char grid[401]){
	int index = get_char_index(row,col,grid);
	unsigned char value = grid[index];
	int bit_number= 7-((col-1)%8);
	unsigned char mask = 1 << bit_number;

	if((value & mask)==0){
		return 0;
	}else{
		return 1;
	} 	
}
int get_char_index (int row, int col, unsigned char grid[401]){
	int real;
	row--;col--;
	real=(row*10)+(col/8);
	return real;
}

void print_grid(int gen,unsigned char grid[401]){
	int row;
	int col;
	printf("```````````````````````````````Alfredo's Game of Life`````````````````````````````\n");
	printf("----------------------------------------------------------------------------------\n");
	printf("|Generation:  %d                                                                  |\n",gen);
	printf("----------------------------------------------------------------------------------\n");
	
	for(row=1;row<=40;row++){
		printf("|");
		for(col=1;col<=80;col++){
			if(is_alive(row,col,grid)==0){
				//printf("[%d]",col);
				printf(" ");
			}
			if(is_alive(row,col,grid)==1){
				printf("O");
			}
		}
		printf("|\n");		
	}
	printf("----------------------------------------------------------------------------------\n");

}
void print_char(int row,int col,unsigned char grid[401]){
	for(int i=0;i<8;i++){
		if(is_alive(row,col,grid)==0){
                                //printf("[%d]",col);
                   printf(" ");
                }
                if(is_alive(row,col,grid)==1){
                   printf("O");
                }
	col++;
	}
	printf("\n");
//07 16 25 34 43 52 61 70
}

void clear_cell(int col,unsigned char* cha){
	int bit_number= 7-((col-1)%8);
	unsigned int mask = ~(1 << bit_number);
	*cha=*cha & mask;	
}

void set_cell(int col,unsigned char* cha){
        int bit_number= 7-((col-1)%8);
        unsigned int mask = 1 << bit_number;
        *cha=*cha | mask;
}

int top(int row, int col, unsigned char grid[401]){
	if(row<=1){return 0;}
	else{
	int out=is_alive(row-1,col,grid);
	return out;
	}
}

int bot(int row, int col, unsigned char grid[401]){
        if(row>=40){return 0;}
        else{
        int out=is_alive(row+1,col,grid);
        return out;
        }
}

int left(int row, int col, unsigned char grid[401]){
        if(col<=1){return 0;}
        else{
        int out=is_alive(row,col-1,grid);
        return out;
        }
}

int right(int row, int col, unsigned char grid[401]){
        if(col>=80){return 0;}
        else{
        int out=is_alive(row,col+1,grid);
        return out;
        }
}

int tld(int row, int col, unsigned char grid[401]){
        if(row<=1||col<=1){return 0;}
        else{
        int out=is_alive(row-1,col-1,grid);
        return out;
        }
}

int trd(int row, int col, unsigned char grid[401]){
        if(row<=1||col>=80){return 0;}
        else{
        int out=is_alive(row-1,col+1,grid);
        return out;
        }
}

int bld(int row, int col, unsigned char grid[401]){
        if(row>=40||col<=1){return 0;}
        else{
        int out=is_alive(row+1,col-1,grid);
        return out;
        }
}

int brd(int row, int col, unsigned char grid[401]){
        if(row>=40||col>=80){return 0;}
        else{
        int out=is_alive(row+1,col+1,grid);
        return out;
        }
}

























