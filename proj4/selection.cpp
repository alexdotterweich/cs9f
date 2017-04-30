#include <iostream>
#include "dll.h"

int main () {
    const int N = 8;
    const int K = 2;
    // DLLnode *list = 0;
    DLLnode *list = new DLLnode(N);
    for (int j=N-1; j>0; j--) {
	   DLLnode *newGuy = new DLLnode (j);
	   // you fill this in
       list = list->Insert(newGuy);
    }
    list->Print ();
    while (!list->LengthIs1 ()) {
	   for (int j=0; j<K; j++) {
	       list = list->Next ();
	    }
	    // you fill this in
        list = list->Delete();
    }
    std::cout << "Only one person remains: ";
    list->Print ();
    return 0;
}
