// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 10/11/2019

// ⚠️ updates: 菜单的add选项里加了是否为相同item name的判断，如果相同则不能插入该item，提示要改名字。


#include "linkedlist.h"
#include "Item.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Function Prototypes:
void Menu(ifstream&, List&, ofstream&, itemType&); // Main menu
void itemInfoMenu(List&);                          // Item Info's update Menu
void getFilePath(ifstream&, ofstream&, string&);   // Function to Read in the file path input
void testFilePathInput(ifstream&, string&);        // Function to verify valid file path input


// ------ Project 1 driver ------ //
int main()
{
    ifstream fin;   // input file stream
    ofstream fout;  // output file stream
    
    itemType aItem;
    List aList;
    string fPath;
    
    // Read in the file path
    getFilePath(fin, fout, fPath);
    
    // Sort the while inventory file
    aList.sortFile(fin, aList, aItem);
    
    // Display the sorted inventory data
    aList.display(cout);
    
    // Display Main Menu
    Menu(fin, aList, fout, aItem);

    fin.close();
    fout.close();

    return 0;
}  // ------ End of Project 1 driver ------ //



// Definition of readFilePath ()
void getFilePath(ifstream& fin, ofstream& fout, string& fPath)
{
    cout << "Enter the file path of the input file: ";
    getline(cin, fPath);
    fin.open(fPath);          // Open the input file
    
    // Verify valid the file path input
    testFilePathInput(fin, fPath);
    
    fout.open("NewList.txt"); // Open the output file
}


// Definition of testInput ()
void testFilePathInput(ifstream& fin, string& fPath)
{
    while(!fin)
    {
        cout << "Invalid file path, try again: ";
        getline(cin, fPath);
        fin.open(fPath);  // open the input file
    }
}


// Definition of Main Menu ()
void Menu(ifstream& fin, List& aList, ofstream& fout, itemType& aItem)
{
    int choice; // Choice number
    
    do    // Display Menu
    {
        cout << "\nMain Menu:\n"
             << "    1: Display in alphabetical order by name\n"
             << "    2: Display in reverse alphabetical order\n"
             << "    3: Add an item to the inventory\n"
             << "    4: Delete an item from inventory\n"
             << "    5: Change any info for an item\n"
             << "    6: Exit and output data to a txt file\n";
        cout << "\nWhich main menu choice? ";
        cin >> choice; // read in a choice number
        testDataInput(cin, choice);


        switch (choice) // Link the choice numbers to related functions
        {
            case 1:
                cout << "\nInventory in Alphabetical order: \n\n";
                aList.sortExistingList(aList);
                aList.display(cout);
                cout << endl;
                break;
            case 2:
                cout << "\nInventory in REVERSE alphabetical order: \n\n";
                aList.reverse(); // reverse the order
                aList.display(cout);
                cout << endl;
                break;
            case 3:
                cout << "You chose to ADD an item, enter item information:\n";
                cin >> aItem;
                aList.sortExistingList(aList); // have the list sorted
                // check if the added item name if have same name
                if (aList.checkSameItemName(aList, aItem)) // if so, dispaly message
                   cout << "\nThe item name \""<< aItem.itemName
                        << "\" is already taken, please choose a different name.\n\n";
                else // if not, continue to add
                {
                    aList.addItem(aItem);  // add the item
                    cout << endl;
                    aList.display(cout);
                }
                break;
            case 4:
                cout << "You chose to Delete an item, enter an item name: ";
                cin >> aItem.itemName;
                testDataInput(cin, aItem.itemName); // have the list sorted
                // check if item name exists, delete the item name
                if (aList.searchName(aItem.itemName) != -1)
                {
                    cout << "\n *** The item has been deleted *** \n";
                    aList.eraseItem(aList.searchName(aItem.itemName));
                    aList.display(cout);
                }
                else // if not, display message
                    cout << "\nCould not find the item name \"" << aItem.itemName
                         << "\", please check the name."
                         << endl << endl;
                break;
            case 5:
                itemInfoMenu(aList); // goes to the menu of item change
                aList.sortExistingList(aList);
                break;
            case 6: // enter 6 then exit menu
                break;
            default:
                cout << "The input of " << choice << " is invalid, please try again(1~6): \n";
                break;
        }
    }while (choice != 6); // input 5 to exit the do-while Menu

    aList.display(fout); // output data to the output file
    cout << "You chose to EXIT, program terminated successfully!\n\n";
}


// Definition of info update Menu ()
void itemInfoMenu(List& aList)
{
    int option;            // user's option for changing item info
    string origItemName;   // original item name
    
    // Menu for changin item infos
    do
        {
            cout << "Which item info would you like to change:\n"
                 << "    1: Change Item Name\n"
                 << "    2: Change Unit Price\n"
                 << "    3: Change Minimum Inventory Level\n"
                 << "    4: Change Number in Stock\n"
                 << "    5: Back to the main menu\n"
                 << "\nWhich menu option? ";
            cin  >> option; // read in option from user
            testDataInput(cin, option);

            switch (option)
            {
                case 1:
                    cout << "Enter an existing Item Name: ";
                    cin >> origItemName; // existing item info
                    testDataInput(cin, origItemName);
                    aList.updateItemName(aList, origItemName);
                    break;
                case 2:
                    cout << "Enter an existing Item Name: ";
                    cin >> origItemName; // existing item info
                    testDataInput(cin, origItemName);
                    aList.updateItemPrice(aList, origItemName);
                    break;
                case 3:
                    cout << "Enter an existing Item Name: ";
                    cin >> origItemName; // existing item info
                    testDataInput(cin, origItemName);
                    aList.updateItemLevel(aList, origItemName);
                    break;
                case 4:
                    cout << "Enter an existing Item Name: ";
                    cin >> origItemName; // existing item info
                    testDataInput(cin, origItemName);
                    aList.updateItemStock(aList, origItemName);
                    break;
                case 5: // enter 5 then exit menu
                    break;
                default:
                    cout << "The input of " << option << " is invalid, please try again(1~5): \n";
                    break;
            }
        }while (option != 5); // input 5 to exit the do-while Menu
}
