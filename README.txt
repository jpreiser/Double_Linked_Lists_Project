To compile the code, type 'make' into the command line.

To run, type './main <input file>' into the command line.

To clean the directory, type 'make clean' into the command line.

Currently this prgram only runs with int-input.txt, int-input2.txt, 
float-input.txt, and string-input.txt. To modify the lists, either change
these files directly or manipulate them within the program. 

The program supports ints, floats, and std::string types only. 

The pseudo code for my deleteSubsection function is:
    create delelter node
    assign deleter to head
    traverse the list
        if the value of deleter is between the upper and lower bound, 
            delete
        else
            move to next node

Since this simply walks through the list and checks all the values, it is O(n).


The pseudo code for my mode operation is:
    create a traversal node
    step through the list  
        temp = traverse->next  
        if (values are the same)
            count++
        move temp forward until it is nullptr.
        if a new max is discovered, assign it and save the value to return.
    return the mode item
    unless all items occur once

Upon looking at it now, I realize that my check for matching values also goes
until it reaches the nullptr, and so is traversing the whole list from the starting 
point and is therefore n(n-1) which is O(n^2). 


The psuedo code for my swapAlt function is:
    create temp node
    assign value of temp->data to even
    assign value of temp->next->data to odd
    assign value of even to temp->next->data
    assign value of odd to temp->data
    move temp forward two until nullptr is reached by temp or temp->next

This code looks at evey other node until the end of the list is reached, and 
so is O(n/2) or simply O(n).


