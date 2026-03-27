#include <unistd.h>
#include <stdio.h>

int main() {
    char c;
    while(read(STDIN_FILENO, &c, 1) == 1);
    // Read the char from the user and always read unitl Ctrl-C or Ctrl-D is pressed.
    //
    // This is cooked mode. [ Canonical mode]
    // Where user can only press ENTER to send input to the Program.
    return 0;
}



