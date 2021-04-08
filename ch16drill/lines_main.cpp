/*
    g++ lines_main.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o lines_main `fltk-config --ldflags --use-images`
*/
#include "Lines_window.h"
#include "Graph.h"

int main()
{
    Lines_window win {Point{100,100}, 600, 400, "Lines"};
    
    return gui_main();
}

/*

1. Make a completely new project with linker settings for FLTK (as described in Appendix D).

2. Using the facilities of Graph_lib, type in the line-drawing program from
§16.5 and get it to run.

 3. Modify the program to use a pop-up menu as described in §16.7 and get
it to run.

 4. Modify the program to have a second menu for choosing line styles and
get it to run.

*/