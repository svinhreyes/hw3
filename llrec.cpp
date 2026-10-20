#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
  //base case: the list is empty
  if(head == NULL){
    smaller = NULL;
    larger = NULL;
    return;
  }

  //save the first node
  Node* current = head;

  //move head to the remaining list
  head = head->next;

  //recursively split the remaining nodes
  llpivot(head, smaller, larger, pivot);

  //put the saved node at the front of the correct list
  if(current->val <= pivot){
    current->next = smaller;
    smaller = current;
  }else{
    current->next = larger;
    larger = current;
  }
}

