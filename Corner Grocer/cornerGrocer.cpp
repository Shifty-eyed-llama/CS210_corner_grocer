
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

void PrintMenu() { // Prints a menu with user selectable choices
    cout << "Please select an option" << endl;
    cout << "1: Find specific item." << endl;
    cout << "2: Find three items." << endl;
    cout << "3: Histogram of items." << endl;
    cout << "4: Quit program." << endl;
}

// void MenuOne() {  // Function requires additional work to be functional
//     string userIn;
    
//     cout << "Please enter the item you are looking for." << endl;
    
//     cin >> userIn;
    
//     auto search = GroceryItem.find(userIn);
        
//     if (search != GroceryItem.end()){
//         cout << userIn << " " << GroceryItem[groceryItem] << endl;
//     }
//     else {
//         cout << "Sorry " << userIn << " was not found." << endl;
//     }
    
// }

string PrintHistogram(int count){ // creates histogram given integer count
    string histogram = "";
    
    for(int i = 0; i < count; i++){
        histogram = histogram + '#';
    }
    return histogram;
}


int main() {
    ifstream streamIN;  // our input text file
    ofstream streamOUT; // created data file
    
    string groceryItem; // from txt file
    int groceryCount;
    int userChoice;    // for menu options
    string item1;     // variable for each item
    string item2;
    string item3;
    
    // Initialize a MAP for all grocery items
    map<string, int> GroceryItem; 
    map<string, int>::iterator it;
    
    streamIN.open("Grocery.txt"); // Open document
    if (!streamIN.is_open()) { // make sure input file is open
        cout << "Unable to open Grocery.txt" << endl; // error message
        return 1; // indicates error
    }
    
    // Input IN is now open
    // Creating file to write to
    streamOUT.open("frequency.dat"); // creates backup file containing frequency
    if (!streamOUT.is_open()) { // make sure output file is open
        cout << "Unable to write to frequency.dat" << endl;
    }
    
    while (!streamIN.fail()){ // iterate over all data in 'input' files
    // if our MAP has that word already, increment counter for that word
        streamIN >> groceryItem;
        
        auto search = GroceryItem.find(groceryItem);
        
        if (search != GroceryItem.end()){
            GroceryItem[groceryItem] += 1;
        }
        else {
            GroceryItem[groceryItem] = 1;
        }
    }
    
    
    // iterate over our MAP and write to output file
    for (it = GroceryItem.begin(); it != GroceryItem.end(); it++){
        streamOUT << it->first << " : " << it->second << endl;
    }
    
    // Print menu
    
    userChoice = 0;
    
    while (userChoice != 4){ // menu loop
   
        PrintMenu();

        cin >> userChoice; // select menu option
        
        if (userChoice == 1){
            // MenuOne();     // this was going to be a function, but I don't know how to pass a map
    
            cout << "Please enter the item you are looking for." << endl;
    
            cin >> item1;
    
            auto search = GroceryItem.find(item1);
        
            if (search != GroceryItem.end()){ // look for selected item in MAP
                cout << item1 << " " << GroceryItem[item1] << endl;
            }
            else {
                cout << "Sorry " << item1 << " was not found." << endl;
            }
            
        }
        else if (userChoice == 2){
            // variable for each item to lookup
            cout << "Item 1: " << endl;
            cin >> item1;
            cout << "Item 2: " << endl;
            cin >> item2;
            cout << "Item 3: " << endl;
            cin >> item3;
            
            auto search = GroceryItem.find(item1);
            
            if (search != GroceryItem.end()){ // search for item so not finding it does not return error
                cout << item1 << " " << GroceryItem[item1] << endl;
            }
            else {
                cout << "Sorry " << item1 << " was not found." << endl;
            }
            
            search = GroceryItem.find(item2);
            
            if (search != GroceryItem.end()){
                cout << item2 << " " << GroceryItem[item2] << endl;
            }
            else {
                cout << "Sorry " << item2 << " was not found." << endl;
            }
            
            search = GroceryItem.find(item3);
            
            if (search != GroceryItem.end()){
                cout << item3 << " " << GroceryItem[item3] << endl;
            }
            else {
                cout << "Sorry " << item3 << " was not found." << endl;
            }
            
        }
        else if (userChoice == 3){
            cout << "Item 1: " << endl;
            cin >> item1;
            cout << "Item 2: " << endl;
            cin >> item2;
            cout << "Item 3: " << endl;
            cin >> item3;
            
            auto search = GroceryItem.find(item1);
            
            if (search != GroceryItem.end()){      // search for item so not finding it does not return error
                cout << item1 << " " << PrintHistogram(GroceryItem[item1]) << endl;
            }
            else {
                cout << "Sorry " << item1 << " was not found." << endl;
            }
            
            search = GroceryItem.find(item2);
            
            if (search != GroceryItem.end()){
                cout << item2 << " " << PrintHistogram(GroceryItem[item2]) << endl;
            }
            else {
                cout << "Sorry " << item2 << " was not found." << endl;
            }
            
            search = GroceryItem.find(item3);
            
            if (search != GroceryItem.end()){
                cout << item3 << " " << PrintHistogram(GroceryItem[item3]) << endl;
            }
            else {
                cout << "Sorry " << item3 << " was not found." << endl;
            }
        }
        else if (userChoice == 4){
            cout << "EXIT PROGRAM" << endl;
            cout << "Thank you" << endl;
            break;    // exits loop and program
        }
        else {
            cout << "Sorry, I didn't catch that." << endl;     // should catch some errant inputs
            cin.clear();
        }
    }

    // Close both files
    streamIN.close();
    streamOUT.close();
    
    return 0; // 0 indicates no error
}