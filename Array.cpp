// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <conio.h>
#include "Array.h"

using namespace std;
static Array a(5);

//declaration of the function used in switch
void printAction();
void insertAtlast();
void insertAtstart();
void insertAtindex();
void insertAtorder();
void deleteAtindex();
void deletelast();
void deleteat();
void search();
void searchAnddelete();

//main function
int main() {
    int choice = 0;
    printAction();
    bool quit = false;
    while (!quit) {
        cout << "enter the choice\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "The  number of elements in the Array is: " << a.length() << "\n";
            break;
        }
        case 2: {
            cout << "The Max size of the Array is: " << a.getmaxSize() << "\n";
            break;
        }
        case 3: {
            cout << "The elements on the Array are\n";
            a.print();
            cout << "\n";
            break;
        }
        case 4: {
            insertAtlast();
            break;
        }
        case 5: {
            insertAtstart();
            break;
        }
        case 6: {
            insertAtindex();
            break;
        }
        case 7: {
            insertAtorder();
            break;
        }
        case 8: {
            a.sorting();
            cout << "Array sorted SuccessFully......\n";
            break;
        }
        case 9: {
            deleteAtindex();
            break;
        }
        case 10: {
            deletelast();
            break;
        }
        case 11: {
            deleteat();
            break;
        }
        case 12: {
            search();
            break;
        }
        case 13: {
            searchAnddelete();
            break;
        }
        case 14: {
            printAction();
            break;
        }
        case 15: {
            cout << "SuccessFully Eixted the program....\n";
            quit = true;
            break;
        }
        default: {
            cout << "please enter the choice with in range \n";
            break;
        }
        }
    }
    getch();
    return 0;
}
void printAction() {
    cout << "Enter the choice\n";
    cout << "1.  To display number of elements\n";
    cout << "2.  To display max size \n";
    cout << "3.  To print \n";
    cout << "4.  To insert at Last\n";
    cout << "5.  To insert at Start\n";
    cout << "6.  To insert at index\n";
    cout << "7.  To insert in Order\n";
    cout << "8.  To sort\n";
    cout << "9.  To delete at index\n";
    cout << "10. To delete last\n";
    cout << "11. To delete at\n";
    cout << "12. To search\n";
    cout << "13. To search And delete\n";
    cout << "14. To printAction\n";
    cout << "15. To quit\n";
}

void insertAtlast() {
    int x = 0;
    cout << "Please enter the Elements to insert: ";
    cin >> x;
    if (a.insert(x)) {
        cout << "Elements added successFully\n";
    }
    else {
        cout << "There might be some error please Reenter....\n";
    }
}

void insertAtstart() {
    int x = 0;
    cout << "Please enter the Elements to insert at start: ";
    cin >> x;
    if (a.insert(x)) {
        cout << "Elements added successFully at start of the Array\n";
    }
    else {
        cout << "There might be some error please Reenter....\n";
    }
}

void insertAtindex() {
    int x = 0, index = 0;
    cout << "please Enter the index of the Element: ";
    cin >> index;
    cout << "\n please enter the element: \n";
    cin >> x;
    if (a.insertAt(index, x)) {
        cout << "Element added Successfully at index " << index << "in the array\n";
    }
    else {
        cout << "There might be something wrong so please Renter the index and element\n";
        insertAtindex();
    }
}

void insertAtorder() {
    int x = 0;
    cout << "Please enter the Element to insert in order: \n";
    cin >> x;
    if (a.insertAtOrder(x)) {
        cout << "Element added successfully...\n";
    }
    else {
        cout << "There is some error so please reenter the choice\n";
    }
}

void deleteAtindex() {
    int index = 0;
    cout << "Please enter the Index of the element to delete: \n";
    cin >> index;
    if (a.deleteAtIndex(index)) {
        cout << "Element deleted SuccessFully at " << index << "\n";
    }
    else {
        cout << "Error in deleting the element so please reneter the index\n";
        deleteAtindex();
    }
}

void deletelast() {
    if (a.deleteLast()) {
        cout << "Last element deleted successfully....\n";
    }
    else {
        cout << "Error in deleting the last element so reenter the choice\n";
    }
}

void deleteat() {
    int x = 0;
    cout << "Please enter the element to delete: \n";
    cin >> x;
    if (a.deleteAt(x)) {
        cout << "Element deleted SuccessFully.....\n";
    }
    else {
        cout << "element not Found so please reenter the choice\n";
    }
}

void search() {
    int x = 0;
    cout << "Please enter the element to search: \n";
    cin >> x;
    if (a.search(x)) {
        cout << "Element SuccessFully found in the array...\n";
    }
    else {
        cout << "Elements not found in the Array\n";
    }
}

void searchAnddelete() {
    int x = 0;
    cout << "Please enter the element to search and delete: \n";
    cin >> x;
    if (a.searchAndDelete(x)) {
        cout << "Element search Found and deleted Sussessfulyy....\n";
    }
    else {
        cout << "Either element not Found or error in deleting so please reenter the choice\n";
    }
}
