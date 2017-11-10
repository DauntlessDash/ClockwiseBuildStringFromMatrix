#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

//Takes a matrix of integers and makes a string with the entries of the matrix appended in clockwise order.
//Matrix is an array of integers that will be converted into the string.
//NumRows is the number of rows from Matrix, NumColumns is the number of columns from Matrix
//OutBuffer is the output for string and it is guaranteed to be valid and large enough to hold all data.
void BuildStringFromMatrix(int* Matrix, int NumRows, int NumColumns, char* OutBuffer){
    
    int firstr = 0; //Index of first row that hasn't been added to string.
    int firstc = 0; //Index of first column that hasn't been added to string.
    int lastr = NumRows; //Index of last row that hasn't been added to string.
    int lastc = NumColumns; //Index of last column that hasn't been added to string.
    int i; //Iterator for loops
    
    std::ostringstream temp; //Creating ostringstream to feed input from matrix.
    
    //Continue loop as long as there is still rows and columns that haven't been inputed into string yet.
    while(firstc < lastc && firstr < lastr)
    {
        //Iterate through the top row from left to right and add each element to stringstream
        for(i=firstc; i<lastc; ++i)
        {
            temp << Matrix[(firstr*NumColumns+i)]; //Takes value from Martrix[firstr][i] and adds to temp.
            temp << ", ";
        }
        firstr++;//Remove the row that was just added to temp from the matrix.
        
        //Iterate through the right column from top to bottom and add each element to stringstream.
        for(i=firstr; i<lastr; ++i)
        {
            temp << Matrix[(i*NumColumns+(lastc-1))]; //Takes value from Martrix[i][lastc-1] and adds to temp.
            temp << ", ";
        }
        lastc--;//Remove the column that was added to temp from the matrix.
        
        if(firstr<lastr)
        {
            //Iterate through the bottom row from right to left and add each element to stringstream.
            for(i=lastc-1; i>=firstc; i--) 
            {
                temp << Matrix[((lastr-1)*NumColumns)+i]; //Takes value from Martrix[lastr-1][i] and adds to temp.
                temp << ", ";
            }
            lastr--;//Remove the row that was added to temp from the matrix.
        }
        
        if(firstc < lastc)
        {
            //Iterate through the left column from bottom to top and add each element to stringstream.
            for(i=lastr-1; i>=firstr; --i)
            {
                temp << Matrix[(i*NumColumns)+firstc]; //Takes value from Martrix[i][firstc] and adds to temp.
                temp << ", ";
            }
            firstc++; //Remove the column that was added to temp from the matrix.
        }
        
    }
    strcpy(OutBuffer, temp.str().c_str()); //Copies the string from temp into the OutBuffer
    OutBuffer[strlen(OutBuffer)-2]='\0'; //Removes the extra ',' at the end of string and adds null terminator.
    return;
}


