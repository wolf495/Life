# Life
This project mimics the process of evolution, 
a 40 x 80 grid is formed with 'O' marking a living cell, and the grid is redrawn a certain 
number of times based on the following rules...  
Any live cell with fewer than two neighbors is dead in the next generation.
Any live cell with more than three neighbors is dead in the next generation.
Any live cell with two or three neighbors survives.
Any empty cell with exactly three neighbors becomes live in the next generation.
Any empty cell with a number of neighbors not equal to three remains empty...
Each redrawing is another generation. 

The input is a file of 400 chars, which the program will read the individual bits to decide where to draw 
cells.

Included are test files of blinkers, glider,random and still. 

The command is './run [file] [generations]'
where [file] is the file with the initial 400 chars, and where [generations] is how many iterations
should the program run through.
