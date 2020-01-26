A C program to simulate Conway's game of life.

Simulates n by n cells undergoing the game of life.
Each cell is either populated or unpopulated, or alive or dead.
At each step in time, the following transitions occur:
1. Any live cell with fewer than two live neighbors die.
2. Any live cell with more than three live neighbors also die.
3. Any live cell with two or three live neighbors live.

Borders of the cells wrap around.

The program takes two inputs. The first is the name of the seed pattern file. The second is the number of steps in time for transitions.

Dead cells are marked with "." and live cells are marked with "x".
