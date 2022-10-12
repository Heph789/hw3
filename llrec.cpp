#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot_(Node *head, Node *&smaller, Node *&larger, int pivot)
{
    if (head == NULL) {
        if (larger == NULL) smaller = NULL;
        else larger = NULL;
        return;
    }
    if (head->val > pivot) {
        larger = head;
        llpivot_(head->next, smaller, larger->next, pivot);
    }
    else {
        smaller = head;
        llpivot_(head->next, smaller->next, larger, pivot);
    }
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    llpivot_(head, smaller, larger, pivot);
    head = NULL;
}
