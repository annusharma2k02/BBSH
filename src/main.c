#include "libraries.h"

int main()
{
    set_root_path();
    setupHist();

    int no_of_done = 0;

    while (true)
    {
        setbuf(stdout, NULL);
        printPrompt();
        input();

        // if (no_of_done >= 10)
        // {
            writeHist();
        //     no_of_done = 0;
        // }
    }

    return 0;
}