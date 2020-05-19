/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: khanab56
 *
 * Created on December 2, 2019, 1:34 AM
 */


#include <iostream>
#include <string>
#include "TreeDB.h"
#include <sstream>

using namespace std;




int main() {

    string line;
    string command;
    TreeDB tree;
   
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
        if (command == "insert") {
            string name;
            lineStream >> name;
            
            unsigned int IPaddress;
            lineStream >> IPaddress;
            
            string activeText;
            lineStream >> activeText;
            
            bool active = true;
            
            
    
            if (activeText == "active") {
                active = true;
            }
            else {
                active = false;
            }
    
    
            DBentry* input = new DBentry(name, IPaddress, active);

            
            if (tree.insert(input)) {
                cout << "Success" << endl;
            }
            else {
                cout << "Error: entry already exists" << endl;
                delete input;
                input == nullptr;
            }
            
            
        }
        
        

        
        else if (command == "find") {
            
            
            string name;
            lineStream >> name;
            DBentry* temp = tree.find(name);
            
            
            if (temp != nullptr) {
                cout << *temp << endl;
            }
            else {
                cout << "Error: entry does not exist" << endl;
            }
            
            
        }
        

        else if (command == "printall") {
            
            cout << tree << endl;
            
            
        }
        
        else if (command == "remove") {
            
            string name;
            lineStream >> name;
            
            if (tree.find(name) != nullptr) {
                if (tree.remove(name)) {
                  cout << "Success"  << endl;
                } 
            }
            else {
                cout << "Error: entry does not exist" << endl;
            }
            
            
            
            
            
        }
        
        
        if (command == "printprobes") {
            
            string name;
            lineStream >> name;
            
            if (tree.find(name) != nullptr) {
              
                tree.printProbes();

            }
            else {
                cout << "Error: entry does not exist" << endl;
            }
            
            
        }
        
        if (command == "removeall") {
            tree.clear();
            cout << "Success" << endl;
        }
        
        
        if (command == "countactive") {
            tree.countActive();
        }
        
        if (command == "updatestatus") {
            
            string name;
            lineStream >> name;
            
            string activeText;
            lineStream >> activeText;
            
            bool active = true;
            
            if (activeText == "active") {
                active = true;
            }
            else {
                active = false;
            }
            
            
            
            DBentry* input = tree.find(name);

            
            if (input != nullptr) {
                input->setActive(active);
                cout << "Success" << endl;
            }
            else {
                cout << "Error: entry does not exist" << endl;
                
            }
            
            
            
            
            
            
        }
            
        
        
        
       
        
       
       
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);   // Get the command line
       
    }  // End input loop until EOF.
   
    return 0;
}

