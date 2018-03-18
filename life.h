#include <stdio.h>

struct life{};
	int is_alive(int row, int col, unsigned char grid[401]);
	int get_char_index (int row, int col, unsigned char grid[401]);
	void print_grid(int,unsigned char[401]);
	void print_char(int row,int col,unsigned char grid [401]);
	void clear_cell(int col,unsigned char*);
	void set_cell(int col,unsigned char*);
	int top(int row, int col, unsigned char grid[401]);
	int bot(int row, int col, unsigned char grid[401]);
	int left(int row, int col, unsigned char grid[401]);
	int right(int row, int col, unsigned char grid[401]);
	int tld(int row, int col, unsigned char grid[401]);
	int trd(int row, int col, unsigned char grid[401]);
	int bld(int row, int col, unsigned char grid[401]);
	int brd(int row, int col, unsigned char grid[401]);
