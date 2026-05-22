// COMSC-210 | Final 2 | Gillian Rhett

#include <string>
#include <array>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>

using namespace std;

struct Node {
// each node contains name and drink of customer and a pointer to the next node
    string name;
    string drink;
    Node* next;
};

struct LL {
// a singly-linked list of customers
    Node* head;
    
    //constructor
    LL() { head = nullptr; }

    void push_back(string name, string drink) {
    // add a new customer to the end of the line
        Node* current = head;
        Node* newNode = new Node;
        newNode->name = name;
        newNode->drink = drink;
        newNode->next = nullptr;
        if (head != nullptr) {
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        else {
            head = newNode;
        }
    }

    void display_one_name(int position) {
    // display the name and drink for one customer by position in line
        int i = 0;
        if (head != nullptr) {
            Node* current = head;
            while ( i < position && current->next != nullptr) {
                current = current->next;
                ++i;
            }
            cout << current->name;
        }
        else
            cout << "The line is empty." << endl;
    }

    void pop_front() {
        if (head == nullptr)
        // the line is empty
            return;
        if (head->next != nullptr) {
        // there are at least 2 nodes
            Node* second = head->next;
            delete head;
            head = second;
            return;
        }
        if (head->next == nullptr) {
        // there is exactly one node
            delete head;
            head = nullptr;
            return;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << "\t" << current->name << "'s order is " << current->drink << endl;
            current = current->next;
        }
    }

    void deleteLL() {
        Node* current = head;
        while (current != nullptr) {
            head = current->next;
        delete current;
        current = head;
        }
        head = nullptr;
    }
};

int main() {

// Milestone 1: Using a struct, code a coffee booth queue simulation that uses a linked list as its core data structure. 
//    The linked list's struct should be a node that contains the customer's name and drink order. 
//    Create data arrays with names and drink orders from which to randomly create customer data. 
//    You may use an LLM for creating these data sets. 
    
    // store possible names in one array and possible drinks in another array
    // I used names.txt from Lab 28
    array <string, 200> names; // there are 200 names in the file
    ifstream in_file;
    in_file.open("names.txt");
    if (!in_file) {
        cout << "Error: file not found" << endl;
        return 1;
    }
    string temp_string;
    int i = 0;
    while (getline(in_file, temp_string) && i < names.size()) {
        names.at(i) = temp_string;
        ++i;
    }
    in_file.close();

    array <string, 20> drinks; // there are 20 drinks in the file
    // I used ChatGPT to generate the list of drinks
    in_file.open("drinks.txt");
    if (!in_file) {
        cout << "Error: file not found" << endl;
        return 1;
    }
    i = 0;
    while (getline(in_file, temp_string) && i < drinks.size()) {
        drinks.at(i) = temp_string;
        ++i;
    }
    in_file.close();

// Milestone 2: Run the simulation for 10 rounds. Initialize the queue with 3 customers. 
//    For any given round, there's a 50% probability that someone will join the queue. 
//    The customer at the head of the queue is always served in each round. 
//    If the queue is currently empty, no customer is served, but there is still a 
//    50% probability that someone will join the queue.
    LL coffee_queue; // for Milestone 2
    deque<string> muffin_queue; // for Milestone 3
    srand(time(0));
    int rand_n, rand_d;
    for (int i = 0; i < 3; ++i) { // each queue starts with 3 customers
        // coffee stand initial queue
        rand_n = rand() % (names.size());
        rand_d = rand() % (drinks.size());
        coffee_queue.push_back(names.at(rand_n), drinks.at(rand_d));
        // muffin stand initial queue
        rand_n = rand() % (names.size());
        muffin_queue.push_back(names.at(rand_n));
    }
    cout << "Starting coffee queue:" << endl;
    coffee_queue.display();
    cout << "Starting muffin queue:" << endl;
    for ( string customer : muffin_queue )
        cout << "\t" << customer << endl;
    int rand_c; // for 50% chance of new customer
    for (int i = 0; i < 10; ++i) {
        cout << "== Round " << i + 1 << " ==" << endl;
        cout << "Coffee Stand:" << endl;
        rand_c = rand() % 2; // 50% chance of new coffee customer
        if (rand_c == 1) {
            rand_n = rand() % (names.size());
            rand_d = rand() % (drinks.size());
            coffee_queue.push_back(names.at(rand_n), drinks.at(rand_d));
            cout << "\tnew customer " << names.at(rand_n) << " wants " << drinks.at(rand_d) << endl;
        }
        cout << "\tcoffee customer was served and left: ";
        coffee_queue.display_one_name(0);
        coffee_queue.pop_front();
        cout << "\n\tCoffee queue:" << endl;
        coffee_queue.display();
        cout << endl;

// Milestone 3: Now there's another vendor selling muffins in the next booth over. 
//    Add code to simulate that booth's queue. This time, use an std::deque. 
//    Incorporate this new booth into the 10-round simulation. The probabilities are the same.
        cout << "Muffin Stand:" << endl;
        rand_c = rand() % 2; // 50% chance of new muffin customer
        if (rand_c == 1) {
            rand_n = rand() % (names.size());
            cout << "\tnew muffin customer " << names.at(rand_n) << endl;
            muffin_queue.push_back(names.at(rand_n));
        }
        if (!muffin_queue.empty()) {
            cout << "\tmuffin customer was served and left: " << muffin_queue.at(0);
            muffin_queue.pop_front();
        }
        cout << "\n\tMuffin queue:" << endl;
        for ( string customer : muffin_queue )
            cout << "\t" << customer << endl;

    } // end of 10 round simulation

    coffee_queue.deleteLL();

// Milestone 4: Now there's a third vendor selling friendship bracelets in the next booth over. 
//    Add this simulation as well using an std::vector.

// Milestone 5: Now, there's a fourth vendor selling something of your choice; 
//    add this using a data structure of your choice that hasn't yet been used 
//    in this project but has been studied in this course.

// Milestone 6: Final touches. Each round should show queue activity for all four booths.
    

    return 0;
}