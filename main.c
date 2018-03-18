#include <stdio.h>
#include "life.h"
#include <stdlib.h>

int main(int argc, char ** argv){

FILE *main_file;
unsigned char c;
struct life a;
main_file = fopen(argv[1],"r");
const char* gens= argv[2];
int gens_num=strtol(gens,NULL,10);
unsigned char grid[401];
int count=0;
int count2=0;
int row=0;
int col=0;
unsigned char* byte;
int memory[3201];

if(main_file == NULL) {
      perror("Error in opening file");
      return(-1);
   }
   
   while(1) {
      c = (unsigned char)fgetc(main_file);
      if( feof(main_file) ) { 
         break ;
      }
      grid[count]= c;
	count++;
   }
   fclose(main_file);
count=0;count2=0;
//print_grid(grid);

//row=1; col=21;
//byte = &grid[get_char_index(row,col,grid)];

for(int i=1;i<=gens_num;i++){
	 for(row=1;row<=40;row++){
                for(col=1;col<=80;col++){
		if(is_alive(row,col,grid)==1){
                	if(top(row,col,grid)==1){count++;}
			if(bot(row,col,grid)==1){count++;}
			if(left(row,col,grid)==1){count++;}
			if(right(row,col,grid)==1){count++;}
			if(tld(row,col,grid)==1){count++;}
			if(trd(row,col,grid)==1){count++;}
			if(bld(row,col,grid)==1){count++;}
			if(brd(row,col,grid)==1){count++;}
			if(count<2||count>3){memory[count2]=0;}
			if(count==2 || count==3){memory[count2]=1;}
		//printf("[(%d,%d):alive:%d]",row,col,count);
		count=0;
		}else{
			if(top(row,col,grid)==1){count++;}
                        if(bot(row,col,grid)==1){count++;}
                        if(left(row,col,grid)==1){count++;}
                        if(right(row,col,grid)==1){count++;}
                        if(tld(row,col,grid)==1){count++;}
                        if(trd(row,col,grid)==1){count++;}
                        if(bld(row,col,grid)==1){count++;}
                        if(brd(row,col,grid)==1){count++;}
			if(count==3){memory[count2]=1;}
                        if(count!=3){memory[count2]=0;}
		//printf("[(%d,%d):dead:%d]",row,col,count);
		count=0;
		}
		count2++;
                }
		//	printf("\n");
        }	
	count2=0;count=0;
	
	 for(row=1;row<=40;row++){
                for(col=1;col<=80;col++){
		//	printf("%d",memory[count2]);
			count2++;
		}
		//printf("\n");
	}
	//printf("\n");

	count2=0;count=0;
	for(row=1;row<=40;row++){
		for(col=1;col<=80;col++){
			byte = &grid[get_char_index(row,col,grid)];
			if(memory[count2]==0){
				clear_cell(col,byte);
			}
			else{
				set_cell(col,byte);
			}
			count2++;
		}
	}
	//print_grid(i,grid);
	count2=0;count=0;	
}

print_grid(gens_num,grid);




return 0;
}
