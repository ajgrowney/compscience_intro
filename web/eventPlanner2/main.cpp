#include "exec.h"

/** \mainpage The Memory Leeks Project 1 - Event Planner
 *
 * \section intro_sec Introduction
 *
 * Welcome to the documentation for our Event Planner Project. Feel free to access the different class documentation by clicking the "Classes" link in the header.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: In Terminal, use the command: git clone https://github.com/brandonlammey/Project1.git
 * \subsection step2 Step 2: Navigate to the repository folder in your local directory. Use the command: cd ~/<folder you downloaded repo to>/Project1
 * \subsection step3 Step 3: Type "make" into the console to compile the program.
 * \subsection step4 Step 4: Type "./Project1" into the console to run the program!
 * \subsection step5 Optional Step 5: Type "make clean" if you ever feel like cleaning out the .o files in the directory.
 *
 */

int main()
{
    exec Executive;
    Executive.run();
    return(0);
}
