#include <stdio.h>
#define COLS 20
#define ROWS 10

  void draw(char room[ROWS][COLS]){
    for(int i = 0; i < ROWS;  i++){
      for(int j = 0; j < COLS; j++){
        printf("%c",room[i][j]);
      }
      puts("");
    }

  }

  void init_room(char room[ROWS][COLS]){
    for(int i = 0; i < ROWS;  i++){
      for(int j = 0; j < COLS; j++)
        if(i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1){
            room[i][j] = '#';   
        }else{
          room[i][j] = '.';
        }
      }
      room[ROWS/2][COLS/2] = '@';
    }

  void read_input(){
    getchar();
  }

  void enemies(){

  }

  void apply_rules(){

  }

void game_loop(){
  char room[ROWS][COLS];
 

  init_room(room);
  while(1){
    draw(room);
    read_input();
    enemies();
    apply_rules();
  }
}
void game(){
  game_loop();
}

void menu(){
  char option;
  do {
    puts("N - New game");
    puts("C - Credits");
    puts("Q - Exit");
    scanf("%c", &option );
    getchar();
    switch(option){
      case 'N':
        game();
      break;
      case 'C':

      break;
    }
  } while(option != 'Q');
}
int main(int argc, char const *argv[]) {
  // Print a welcome message
  printf("Welcome to the Roguelike Game!\n");
  menu();
  return 0;
}
