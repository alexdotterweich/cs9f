#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <string>
using namespace std;

struct Inv {
    string itemName;
    int quantity;
};

class Inventory {
public:
    Inventory ();
    void Update (string item, int amount);
    void ListByName ();
    void ListByQuantity ();
    
    
private:
    // You provide this.
    // struct Inv {
    //     string itemName;
    //     int quantity;
    // };
    vector<Inv> invent;
};

#endif