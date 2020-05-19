#include "TreeDB.h"
#include <ostream>
#include <iostream>
#include <sstream>


    // the default constructor, creates an empty database.
    TreeDB::TreeDB(){
        root = nullptr;
    } 
   
    // the destructor, deletes all the entries in the database.
    TreeDB::~TreeDB() {
        clear();
        root = nullptr;
    }
   
   
   
   
   
   
   
   
   
   
    // inserts the entry pointed to by newEntry into the database. 
    // If an entry with the same key as newEntry's exists 
    // in the database, it returns false. Otherwise, it returns true.
    bool TreeDB::insert(DBentry* newEntry) {
        
        if (root == nullptr) {
            root = new TreeNode(newEntry);
            return true;
        }
        else {
            return insertHelp(root, newEntry);
        }
        
    }   
   
   
   
    // used to insert a newEntry using the name as key
    bool TreeDB::insertHelp(TreeNode* ptr, DBentry* newEntry) {

       
        // return false when a node has the same name as the key
        if (ptr->getEntry()->getName() == newEntry->getName()) {
            return false;
        }
       
        // if root has children, go to left child depending on key
        else if (newEntry->getName() < ptr->getEntry()->getName()) {
           
            // check if left child has any children
            // if no children, insert node here
            if (ptr->getLeft() == nullptr) {
                ptr->setLeft(new TreeNode(newEntry));
                return true;
            }
           
            // recursively check for left children until at the point
            // where node is to be inserted
            else {
                return insertHelp(ptr->getLeft(), newEntry);
            }
        }
       
        // if root has children, go to right child depending on key
        else if (newEntry->getName() > ptr->getEntry()->getName()) {
            
            // check if right child has any children
            // if no children, insert node here
            if (ptr->getRight() == nullptr) {
                ptr->setRight(new TreeNode(newEntry));
                return true;
            }
            
            // recursively check for right children until at the point
            // where node is to be inserted
            else {
                return insertHelp(ptr->getRight(), newEntry);
            }
        }
        
        
    }

  
   
   
   
   
   
   
   
   
   
    // searches the database for an entry with a key equal to name.
    // If the entry is found, a pointer to it is returned.
    // If the entry is not found, the nullptr pointer is returned.
    // Also sets probesCount
    DBentry* TreeDB::find(string name) {
        probesCount = 0;
        
        if (root == nullptr) {
            return nullptr;
        }
        else {
            return findHelp(root, name);
            //return temp;
        }
        
    }
   
   
    // used to find a node with the same name as the one given
    DBentry* TreeDB::findHelp(TreeNode* ptr, string name) {
      
       
        // increase count by 1 since we are pointing to a new node
        probesCount = probesCount + 1;

        
        if (ptr == nullptr) {
            return nullptr;
        }
        
        // return false when a node has the same name as the key
        else if (ptr->getEntry()->getName() == name) {
            return ptr->getEntry();
        }

        
        // if root has children, go to left child depending on key
        else if (name < ptr->getEntry()->getName()) {
            return findHelp(ptr->getLeft(), name);  
        }

        //if root has children, go to right child depending on key
        else if (name > ptr->getEntry()->getName() ) {
            return findHelp(ptr->getRight(), name);
        }
        
        
                
       
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

    // deletes the entry with the specified name (key)  from the database.
    // If the entry was indeed in the database, it returns true.
    // Returns false otherwise.
    // See section 6 of the lab handout for the *required* removal method.
    // If you do not use that removal method (replace deleted node by
    // maximum node in the left subtree when the deleted node has two children)
    // you will not match exercise's output.
    bool TreeDB::remove(string name) {
        
        //if root is nullptr, return false since there is no list
        if (root == nullptr) {
            return false;
            //////////////////////////////////////////////////////////////////////////////TODO
        }
        
        //otherwise find before the one that is to be deleted
        else {
            return removeHelp(root, name, root);
            
        }
        
        
        
         
    }
	
    
    bool TreeDB::removeHelp(TreeNode* toDelete, string name, TreeNode* prev) {
        
        
        
        //pointer to a TreeNode that stores necessary nodes when deleting
        TreeNode* holder = nullptr;
        
        
        // if name < parent, go through left children
        if (name < toDelete->getEntry()->getName() && toDelete->getLeft() != nullptr) {
            return removeHelp(toDelete->getLeft(), name, toDelete);
        }
       
        // if name > parent, go through right children
        else if (name > toDelete->getEntry()->getName() && toDelete ->getRight() != nullptr) {
            return removeHelp(toDelete->getRight(), name, toDelete);  
        }


        //when the parent points to node with same name, delete node
        else if (name == toDelete->getEntry()->getName()) {

            //case 1 where node has no children
            if (toDelete->getLeft() == nullptr && toDelete->getRight() == nullptr) {
                
                
                if(prev->getRight() == toDelete) {
                    prev->setRight(nullptr);
                }
                else {
                    prev->setLeft(nullptr);
                }
                
                //delete parent and free memory leaks
                delete toDelete;
                toDelete = nullptr;

                
                return true;
            }

            //case 2.1 where one child is left child
            else if (toDelete->getLeft() != nullptr && toDelete->getRight() == nullptr) {
                
                if (prev->getRight() == toDelete) {
                    prev->setRight(toDelete->getLeft());
                }
                else if (prev->getLeft() == toDelete) {
                    prev->setLeft(toDelete->getLeft());
                }
                
                
                delete toDelete;
                toDelete = nullptr;
                

                //return the right child
                return true;
                
            }

            //case 2.2 where one child is right child
            else if (toDelete->getRight() != nullptr && toDelete->getLeft() == nullptr) {
                
                if (prev->getRight() == toDelete) {
                    prev->setRight(toDelete->getRight());
                }
                else if (prev->getLeft() == toDelete) {
                    prev->setLeft(toDelete->getRight());
                }
                
                
                
                delete toDelete;
                toDelete = nullptr;

                //return the right child
                return true;

            }

            //case 3 where there are 2 children - use max or left child
            else if (toDelete->getRight() != nullptr && toDelete->getLeft() != nullptr) {
                
                
                
                

                //finds max node from the left child
                TreeNode* holder=toDelete->getLeft();
                TreeNode* parentholder=toDelete->getLeft();
                //holder = maxNode(toDelete->getLeft(),prevMax);
                while (holder != nullptr) {
                    parentholder = holder;
                    holder = holder -> getRight();
                    
                }
                
                if (prev->getRight() == toDelete) {
                    prev->setRight(holder);
                    
                }
                else if (prev->getLeft() == toDelete) {
                    prev->setLeft(holder);
                   
                    
                }
                if (parentholder == toDelete->getLeft()) {
                    holder->setLeft(toDelete->getRight());
      
                }
                else {
                    parentholder->setRight(nullptr);
                    holder->setRight(toDelete->getRight());
                    holder->setLeft(toDelete->getLeft());
                }
                //prevMax = nullptr;
                //delete the node to be deleted and free memory leaks
            
                delete toDelete;
                toDelete = nullptr;

            }  
        }
    }



    TreeNode* TreeDB::maxNode(TreeNode* parent, TreeNode*& prevMax) {

        if (parent->getRight() != nullptr) {
            prevMax=parent;
            return maxNode(parent->getRight(), prevMax);
        }
        
        else {
            return parent;
            
        }

    }
        
        
    
        
        
        
        
        
        
        
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
   
   
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
   
   
   
   
   
   
   
   
   
    //  deletes all the entries in the database.
    void TreeDB::clear() {
        
        if (root == nullptr) {
            return;
        }
        else {
            clearHelp(root);
        }
        root = nullptr;
    }
   
   
    // used to delete the entire BST
    void TreeDB::clearHelp(TreeNode* ptr) {
        
        // if the ptr points to a node, then proceed to delete
        if (ptr != nullptr) {
            
            // if the node has a left child, recursively delete left children
            if (ptr->getLeft() != nullptr) {
                clearHelp(ptr->getLeft());
            }
           
            // if the node has a right child, recursively delete right children
            if (ptr->getRight() != nullptr) {
                clearHelp(ptr->getRight());
            }
            
            // once the node has no children, delete the node
            delete ptr;
        }   
    }
   
   
   
   
   
   
   
   
   
   
   
   
   
  
   
   
   
    // prints the number of probes stored in probesCount
    void TreeDB::printProbes() const {
        cout << probesCount << endl;
    }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    // computes and prints out the total number of active entries
    // in the database (i.e. entries with active==true).
    void TreeDB::countActive () const {
        int count = 0;
        
        count = countActiveHelp(root);
        
        cout << count << endl;
        
    } 

   
    // used to count all of the active nodes in the list
    int TreeDB::countActiveHelp(TreeNode* ptr) const {
        int count = 0;
        if (ptr == nullptr) {
            
            return 0;
        }
        // if ptr points to nothing, nothing happens
        if (ptr->getEntry() == nullptr) {
            return 0;
        }
        
        // if ptr points to something,
        else {
            
            
            count += countActiveHelp(ptr->getLeft());
            
            count += countActiveHelp(ptr->getRight());
            
            // increase count by 1 if active
            if (ptr->getEntry()->getActive() == true) {
                return count + 1;
            }
            
           
             
        }
    }
        
        
        
        
        
        
        
        
        
        
        
        
        
 
   
   
   
   
   
   
   
   

   
   
   
   
   
    // Prints the entire tree, in ascending order of key/name
    ostream& operator<< (ostream& out, const TreeDB& rhs) {
        
        rhs.printHelp(rhs.root);
        
        return out;
    }
    
    
    // used to print the list in order from left to right
    void TreeDB::printHelp(TreeNode* ptr) const {
        
        // if ptr points to nullptr, dont do anything
        if (ptr == nullptr) {
            
        }
        
        // if ptr points to ptr, move to left most child recursively and print
        // then traverse to right child after
        else {
            printHelp(ptr->getLeft());
            cout << *(ptr->getEntry()) << endl;
            printHelp(ptr->getRight());
        }
       
    }