# Tic-Tac-Toe

This project is a simple implementation of the classic Tic-Tac-Toe game in the C programming language. The game allows two players to take turns placing "X" and "O" on a 3x3 board in the terminal.

## Project Structure

- `JogoDaVelhaGuilherme.c`: Main source code file.
- `jogodaVelha.txt`: Auxiliary text file (optional).

## Prerequisites

To compile and run the game, you will need:

- A C compiler (e.g., `gcc`)
- Access to a terminal or command prompt

## How to Compile and Run

1. Clone the repository:

   ```bash
   git clone https://github.com/GuinaF2/Tic-Tac-Toe.git
   cd Tic-Tac-Toe
   ```

2. Compile the source code:

   ```bash
   gcc JogoDaVelhaGuilherme.c -o tictactoe
   ```

3. Run the program:

   ```bash
   ./tictactoe
   ```

## How to Play

- Two players take turns entering positions from 1 to 9.
- The goal is to form a straight line (horizontal, vertical, or diagonal) with three of your marks.
- The game ends when one player wins or the board is full (a draw).

Example board positions:

```
 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9
```

This project is licensed under the MIT License.
