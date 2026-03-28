#include <unistd.h>
#include <stdio.h>
#include <termios.h>

void enableRawMode(void) {
  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  raw.c_lflag = raw.c_lflag & ~(ECHO);
  // ECHO is 1000, so ~ECHO is ...110111, And-ing with the existing c_lflag is basically setting the 4th bit to 0.
  // So , essentially, setting the fourth bit to 0.

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);i
  // TCSAFLUSH means that apply the changes to termios struct referenced right now.
  // And do not wait for 
  
  //TCSAFLUSH argument specifies when to apply the change: 
  //in this case, 
  //it waits for all pending output to be written to the terminal, 
  //and also discards any input that hasn’t been read.
}

int main(void) {

    enableRawMode();
    char c;
    while(read(STDIN_FILENO, &c, 1) == 1 && c!= 'q');
    // Read the char from the user and always read unitl Ctrl-C or Ctrl-D is pressed. 
    // This is cooked mode. [ Canonical mode]
    // Where user can only press ENTER to send input to the Program.
    return 0;
}


