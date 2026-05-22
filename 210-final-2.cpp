// COMSC-210 | Final 2 | Gillian Rhett
#include <string>
#include <array>
#include <fstream>

using namespace std;

struct Node {
    string name;
    string drink;
    Node* next;
};

int main() {

// Milestone 1: Using a struct, code a coffee booth queue simulation that uses a linked list as its core data structure. 
//    The linked list's struct should be a node that contains the customer's name and drink order. 
//    Create data arrays with names and drink orders from which to randomly create customer data. 
//    You may use an LLM for creating these data sets. 
    
    // store possible names in one array and possible drinks in another array
    // I used names.txt from Lab 28


// Milestone 2: Run the simulation for 10 rounds. Initialize the queue with 3 customers. 
//    For any given round, there's a 50% probability that someone will join the queue. 
//    The customer at the head of the queue is always served in each round. 
//    If the queue is currently empty, no customer is served, but there is still a 
//    50% probability that someone will join the queue.

// Milestone 3: Now there's another vendor selling muffins in the next booth over. 
//    Add code to simulate that booth's queue. This time, use an std::deque. 
//    Incorporate this new booth into the 10-round simulation. The probabilities are the same.

// Milestone 4: Now there's a third vendor selling friendship bracelets in the next booth over. 
//    Add this simulation as well using an std::vector.

// Milestone 5: Now, there's a fourth vendor selling something of your choice; 
//    add this using a data structure of your choice that hasn't yet been used 
//    in this project but has been studied in this course.

// Milestone 6: Final touches. Each round should show queue activity for all four booths.
    

    return 0;
}