//  main.cpp skeleton
//  lab3
//
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018 Tarek Abdelrahman. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <valarray>

using namespace std;

#include "globals.h"
#include "shape.h"

// This is the shape array, to be dynamically allocated
shape** shapesArray;

// The number of shapes in the database, to be incremented
// everytime a shape is successfully created
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;


// ECE244 Student: you may want to add the prototype of
// helper functions you write here



void maxShapes(stringstream &s) {
   
    //sets the next integer as to the max number of shapes for the project
   
    s >> max_shapes;
           
    //checks if the number is positive
    if (max_shapes < 0) {
        cout << "Error" << endl;
        max_shapes = 0;
    }
           
    //print out the statement mentioning the max shapes and create an array of pointers of that size
    else {
        cout << "New database: max shapes is " << max_shapes << endl;
        shapesArray = new shape*[max_shapes];
               
        for (int i=0; i < max_shapes; i++) {
            shapesArray[i] = NULL;
        }
    }
}


void create(stringstream &s) {
   
    //Used to print output if all inputs are valid
    bool check = true;
   
    //CHECKS FOR NAME
   
    string name;
    s >> name;
   
    //Goes through list of names to determine if name is being repeated
    for (int i=0; i < max_shapes; i++) {
        if (shapesArray[i] != NULL){
            if ((*(shapesArray[i])).getName() == name) {
                cout << "Error: shape name exists" << endl;
                check = false;
                return ;
            }
        }
    }
   

    //Goes through list of key words to ensure name is not the same as keywords
    for (int i=0; i < NUM_KEYWORDS; i++) {
        if (keyWordsList[i] == name) {
            cout << "Error: invalid shape name" << endl;
            check = false;
            return ;
        }
    }
           

    //Ensures that name is not one of the type names
    for (int i=0; i < NUM_TYPES ; i++) {
        if (shapeTypesList[i] == name) {
            cout << "Error: invalid shape name" << endl;
            check = false;
            return ;
        }
    }
   

    //CHECKS FOR TYPE
   
    string type;
    s >> type;
   
    //Used to determine if input matches the type
    bool typeMatch = false;
   
    //Checks if there are too few arguments
    if (s.eof() == true) {
        cout << "Error: too few arguments" << endl;
        check = false;
        return ;
    }
   

    //Checks if the type matches one of the listed types
    for (int i=0; i < NUM_TYPES ; i++) {
        if (shapeTypesList[i] == type) {
            typeMatch = true;
        }
    }
   
    //Is used when the type name does not match one of the preset names
    if (typeMatch == false) {
        cout << "Error: invalid shape type" << endl;
        check = false;
        return ;
    }
   
    // CHECK FOR XLOC
   
    int xloc;
    s >> xloc;
    
    //Checks if there are enough arguments for the int value and if its an int
    if (s.fail() == true) {
        if (s.eof() == true) {
            cout << "Error: too few arguments" << endl;
            check = false;
            return ;
        }
        else {
            cout << "Error: invalid argument" << endl;
            return ;
        }  
    }
    
    //Checks for valid input
    if (xloc < 0) {
        cout << "Error: invalid value" << endl;
        check = false;
        return ;
    }
   

    // CHECK FOR YLOC
   
    int yloc;
    s >> yloc;
   
    //Checks if there are enough arguments for the int value and if its an int
    if (s.fail() == true) {
        if (s.eof() == true) {
            cout << "Error: too few arguments" << endl;
            check = false;
            return ;
        }
        else {
            cout << "Error: invalid argument" << endl;
            return ;
        }  
    }
   
    //Checks for valid input
    if (yloc < 0) {
        cout << "Error: invalid value" << endl;
        check = false;
        return ;
    }

   
    // CHECK FOR XSIZE
   
    int xsize;
    s >> xsize;
    
    //Checks if there are enough arguments for the int value and if its an int
    if (s.fail() == true) {
        if (s.eof() == true) {
            cout << "Error: too few arguments" << endl;
            check = false;
            return ;
        }
        else {
            cout << "Error: invalid argument" << endl;
            return ;
        }  
    }
   
    if (xsize < 0) {
        cout << "Error: invalid value" << endl;
        check = false;
        return ;
    }

    // CHECK FOR YSIZE
   
    int ysize;
    s >> ysize;
   
    //Checks for valid input
    if (ysize < 0) {
        cout << "Error: invalid value" << endl;
        check = false;
        return ;
    }
   
    
    
    
    if (s.fail() == false) {
        if (s.eof() == true) {
        if (check == true) {
            (shapesArray[shapeCount++]) = new shape(name, type, xloc, yloc, xsize, ysize);
            cout << "Created " << name << ": " << type << " " << xloc << " " << yloc << " " << xsize << " " << ysize << endl;
            return ;
        }
    }
    }
    else {
        cout << "Error: invalid argument" << endl;
            return ;
    }
    
   
    //CHECK FOR ANYMORE THAN EXPECTED VALUES
   
    string anymore;
    s >> anymore;
    
    //detects too many arguments
    if (s.eof() == true) {
        cout << "Error: too many arguments" << endl;
        check = false;
        return ;
    }
}

void move(stringstream &s) {
   
    bool check = true;
    
    
   
    //CHECKS FOR VALID NAME
   
    string name;
    s >> name;
   
    //detects if name matches name
    for (int i=0; i < max_shapes; i++) {
        if (shapesArray[i] != NULL){
            if ((*(shapesArray[i])).getName() != name) {
                cout << "Error: shape " << name  << " not found" << endl;
                check = false;
                return ;
            }
        }
    }
   
   
    
   
   
    // CHECK FOR XLOC
   
    int xloc;
    s >> xloc;
    
    //checks if there are more arguments
    if (s.eof() == true) {
        cout << "Error: too few arguments" << endl;
        check = false;
        return ;
    }
    
    //check if input is valid
    if (xloc < 0) {
        cout << "Error: invalid value" << endl;
        check = false;
        return ;
    }
   
    // CHECK FOR YLOC
   
    int yloc;
    s >> yloc;
    
    //check if input is valid
    if (yloc < 0) {
        cout << "Error: invalid value" << endl;
        check = false;
        return ;
    }
    
    
    //Prints out statement if correct inputs have been set and eof
    if (s.eof() == true) {
        if (check == true) {
            for (int i=0; i < max_shapes; i++) {
                if (shapesArray[i] != NULL){
                    if ((*(shapesArray[i])).getName() == name) {
                        if (s.eof() == true) {
                            if (check == true) {
                                ((*(shapesArray[i])).setXlocation(xloc));
                                ((*(shapesArray[i])).setYlocation(yloc));
                                cout << "Moved " << name << " to " << xloc << " " << yloc << endl;
                                return ;
                            }
                        }
                    }
                }
            }
        return ;
        }
    }

    //CHECKS FOR ANYMORE
   
    int anymore;
    s >> anymore;
   
    //too many arguments
    if (s.eof() == true) {
        cout << "Error: too many arguments" << endl;
        check = false;
        return ;
    }
}



//rotate function
void rotate(stringstream &s) {
   
    bool check = true;
    
    //checks if the input ends early
    if (s.eof() == true) {
        cout << "Error: too few arguments" << endl;
        check = false;
        return ;
    }
   
    //CHECKS FOR VALID NAME
   
    string name;
    s >> name;
   
    //Checks if the name matches one of the names
    for (int i=0; i < max_shapes; i++) {
        if (shapesArray[i] != NULL){
            if ((*(shapesArray[i])).getName() != name) {
                cout << "Error: shape name not found" << endl;
                check = false;
                return ;
            }
        }
    }
    
    //checks if there are too few arguments
    if (s.eof() == true) {
        cout << "Error: too few arguments" << endl;
        check = false;
        return ;
    }
   
    //CHECK FOR VALID ANGLE
   
    int angle;
    s >> angle;
    
    
    //checks if the value of rotation integer is valid
    if (angle < 0 || angle > 360) {
        cout << "Error: invalid value" << endl;
        check = false;
        return ;
    }
   
    //PRINT STATEMENT IF INPUTS ARE VALID
    
    if (s.eof() == true) {
        if (check == true) {
            for (int i=0; i < max_shapes; i++) {
                if (shapesArray[i] != NULL){
                    if ((*(shapesArray[i])).getName() == name) {
                        ((*(shapesArray[i])).setRotate(angle));
                        cout << "Rotated " << name << " by " << angle << endl;
                    }
                }
            }
        return ;
        }
    }
    
    //CHECKS FOR ANYMORE
   
    int anymore;
    s >> anymore;
    
    //checks if there are any more important arguments
    if (s.eof() == true) {
        cout << "Error: too many arguments" << endl;
        check = false;
        return ;
    }
}


void draw (stringstream &s) {
    
    
    bool check = true;
    
    //checks if too few arguments
    if (s.eof() == true) {
        cout << "Error: too few arguments" << endl;
        check = false;
        return ;
    }
   
    //CHECKS FOR VALID NAME
   
    string name;
    s >> name;
    
    
    //checks if we are at the last term
    if (s.eof() == true) {
        
        //if input is all, then draw all shapes
        if (name == "all") {
            cout << "Drew all shapes" << endl;
            for (int i=0; i < max_shapes; i++) {
                if (shapesArray[i] != NULL){
                    (*(shapesArray[i])).draw();
 
                }
            }
            return;
        }
        
        //if input is not all
        //draw shape based off of name or output invalid name
        else {
            for (int i=0; i < max_shapes; i++) {
                if (shapesArray[i] != NULL){
                    if ((*(shapesArray[i])).getName() == name) {
                        cout << "Drew " << name << endl;
                        (*(shapesArray[i])).draw();
                        return ;
                    }
                }
            }
        
            for (int i=0; i < max_shapes; i++) {
                if (shapesArray[i] != NULL){
                    if ((*(shapesArray[i])).getName() != name) {
                        cout << "Error: shape " << name << " not found" << endl;
                        check = false;
                        return ;
                    }
                }
            }
        }    
    }
    
    //CHECKS FOR ANYMORE
  
    //checks if too many arguments
    if (s.eof() == false) {
        cout << "Error: too many arguments" << endl;
        check = false;
        return ;
    }
    
}



//delete command
void delete_command(stringstream &s) {
    
    bool check = true;
    
    //checks if there are too few arguments
    if (s.eof() == true) {
        cout << "Error: too few arguments" << endl;
        check = false;
        return ;
    }
    
    string name;
    s >> name;
    
    //checks if we're at the last term
    if (s.eof() == true) {
        
        //if input is all, then delete all shapes
        if (name == "all") {
            for (int i=0; i < max_shapes; i++) {
                if (shapesArray[i] != NULL){
                    delete (shapesArray[i]);
                    shapesArray[i] = NULL;
                }
            }
            cout << "Deleted: all shapes"<< endl;
            return;
        }
        //if not all,
        //delete the name of the shape or output incorrect name
        else {
            for (int i=0; i < max_shapes; i++) {
                if (shapesArray[i] != NULL){
                    if ((*(shapesArray[i])).getName() == name) {
                        delete (shapesArray[i]);
                        shapesArray[i] = NULL;
                        cout << "Deleted shape " << name << endl;
                        return ;
                    }
                }
            }
        
            for (int i=0; i < max_shapes; i++) {
                if (shapesArray[i] != NULL){
                    if ((*(shapesArray[i])).getName() != name) {
                        cout << "Error: shape name not found" << endl;
                        check = false;
                        return ;
                    }
                }
            }
        }
        
    }
    
}





//main function that runs
int main() {

    string line;
    string command;
   
    cout << "> ";         // Prompt for input
    getline(cin, line);   // Get a line from standard input
   
   
    while (!cin.eof()) {
       
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so the flags are cleared
        stringstream lineStream (line);

        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
       
        //Depending on the command inputted by the user, one of the functions
        //are called
        if (command == "maxShapes") {
            maxShapes(lineStream);
        }
       
        if (command == "create") {
            create(lineStream);
        }
       
        if (command == "move") {
            move(lineStream);
        }
       
        if (command == "rotate") {
            rotate(lineStream);
        }
       
        if (command == "draw") {
            draw(lineStream);
        }
       
        if (command == "delete") {
            delete_command(lineStream);
        }
        
        //if none of the commands are inputted, output invalid command
        if (command != "maxShapes" && command != "create" && command != "move" && command != "rotate" && command != "draw" && command != "delete") {
            cout << "Error: invalid command" << endl;
        }
       
       
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);   // Get the command line
       
    }  // End input loop until EOF.
   
    return 0;
}