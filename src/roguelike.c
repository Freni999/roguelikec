#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COLS 20
#define ROWS 10

typedef struct {
  int x;
  int y;
}coord;

typedef struct {
  int life;
  coord pos;
  char name[10];
  char symbol;
}player;

typedef struct {
  int life;
  coord pos;
  char symbol;
}monster;

enum keys{
  key_up = 'w',
  key_down = 's',
  key_left = 'a',
  key_right = 'd'
};

typedef enum {
  up,
  down,
  left,
  right
}direction;
void
 cls(){
  system("clear");
}

int get_random(int start , int finish){
  srand(time(0));
  int randoom = start + (random() % finish);
  return randoom;
} 

void draw(char room[ROWS][COLS], player p){
  cls();
  for(int i = 0; i < ROWS;  i++){
    for(int j = 0; j < COLS; j++){
      if(i == p.pos.y && j == p.pos.x){
          printf("%c",p.symbol);
      }else{
        printf("%c",room[i][j]);
      }
    }
    puts("");
  }

}

void init_room(char room[ROWS][COLS], player *p){
  for(int i = 0; i < ROWS;  i++){
    for(int j = 0; j < COLS; j++){
      if(i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1){
          room[i][j] = '#';   
      }else{
        room[i][j] = '.';
      }
   }
  }
  //p->name = "Gonzalo";
  p->pos.y =ROWS/2;
  p->pos.x = COLS/2;
  p->symbol = '$';
  //room[ROWS/2][COLS/2] = '@';
}

direction read_input(){
  char c = getchar();
  switch(c){
    case key_up:
      return up;
    break;
    case key_down:
    return down;
    break;
    case key_left:
      return left;
    break;
    case key_right:
    return right;
    break;
  }
  
  
}

void enemies(){

}

void apply_rules(){

}

void game_loop(){
char room[ROWS][COLS];
player hero;

direction d;
init_room(room, &hero);
while(1){
  draw(room, hero);
  d = read_input();
  switch(d){
    case up:
    hero.pos.y = hero.pos.y-1;
    break;
    case down:
    hero.pos.y = hero.pos.y+1;
    break;
    case left:
    hero.pos.x = hero.pos.x-1;
    break;
    case right:
    hero.pos.x = hero.pos.x+1;
    break;
  }
  enemies();
  apply_rules();
}
}
void game(){
game_loop();
}

void menu(){
char option = 'N';
do {
  puts("N - New game");
  puts("C - Credits");
  puts("Q - Exit");
  //scanf("%c", &option );
  // getchar();
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
