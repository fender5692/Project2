/**
* Text User Interface Program
*
* @author Forrest Williams
* @author Conner Shields
*/

#include <cstdlib>
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include <menu.h>
#include <string>
#include <panel.h>
#include <cerrno>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

//void print_in_middle(WINDOW *win, int starty, int startx, int width, const char *string, chtype color);
/**
* Main method for program
*
*/
int main(const int argc, const char * argv []){

  initscr();//open window
  
  WINDOW * myPad;
  int row, col;
  getmaxyx(stdscr, row, col);
  myPad = newpad(row + 1000, col);
  keypad(myPad, TRUE);
  const int BUFF_SIZE = 1024; // size of data buffer
  char buffer [BUFF_SIZE];    // data buffer 
  int readVal = 0;

  

  int pos = 0;
  //If file is given to upon initialization of program//
  if(argc == 2){
    string fn = "";
    fn = argv[1];               // Set the filename
    
    ifstream myfile(fn.c_str());
    string line;
    //Check for valid file//
    if (myfile.is_open())
    {
      //Loops through text in file and prints to screen//
      while ( getline (myfile,line) )
      {
        wprintw(myPad, line.c_str());
        wprintw(myPad, "\n");
      }
      myfile.close();
      prefresh(myPad, pos, 0, 0, 0, row -1, col);
    }
  
    else printw("Unable to open file");
  }//if
  int ch;
    //cursor position//
  int x = 0;
  int y = 0;
  
  while(1){
    ch = wgetch(myPad);
      switch(ch){
      case KEY_UP:
        if(y != 0){
          y--;
          wmove(myPad, y, x);
          prefresh(myPad, pos, 0 , 0, 0, y, x);
        }//if
      break;
      
      case KEY_DOWN:
        y++;
        wmove(myPad, y, x);
        prefresh(myPad, pos, 0, 0, 0, y, x);
      break;
      
      case KEY_RIGHT:
        if(x != col){
          x++;
        }//if
        else{
          x = 0;
          y++;
        }//else
        wmove(myPad, y, x);
        prefresh(myPad, pos, 0, 0, 0, y, x);
        
        break;
      
      case KEY_LEFT:
        if(x != 0){
          x--;
        }//if
        else{
          x = col;
          y--;
        }//else
        wmove(myPad, y, x);
        prefresh(myPad, pos, 0, 0, 0, y, x);
        break;
        
      case '\b' :
        wdelch(myPad);
        if(x != 0){
          x--;
        }//if
        else{
          x = col;
          y--;
        }//else
        prefresh(myPad, pos, 0, 0, 0, y, x);
        
        
      default:
        waddch(myPad, ch);
        x++;
        prefresh(myPad, pos, 0, 0, 0, row -1, col);
        break;

      }//switch
    }//while
    

  
  
  
/*
  //Moves page up and down if file is to big.//
  while(1){
    
    switch(ch){
      case KEY_UP:
        pos--;
        prefresh(myPad, pos, 0, 0, 0, row -1, col);
        ch = wgetch(myPad);
      break;
      
      case KEY_DOWN:
      pos++;
      prefresh(myPad, pos, 0, 0, 0, row -1, col);
      ch = wgetch(myPad);
      break;
      
    }//switch 
  }//while 
  */
  
  //Close window and exit program//
  endwin();             
  return EXIT_SUCCESS;
}//main
