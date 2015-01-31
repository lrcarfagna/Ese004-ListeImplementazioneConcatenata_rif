#include <stdlib.h>
#include "linkedListRef.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtBeginning(LLElement **first, int key) {
    
    LLElement * temp;
    int returnValue=-1;
    
    temp=(LLElement*)malloc(sizeof(LLElement));
    if(temp!=NULL){
        
        temp->key=key;
        temp->next= *first;
        *first=temp;
        
        returnValue=0;
    }
    return returnValue ;
}

/*
 * Inserts the new key at the end of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtEnd(LLElement **first, int key) {
    
    int returnValue=-1;
    LLElement * temp;
    
    temp=(LLElement*)malloc(sizeof(LLElement));
    
    if(temp!=NULL){
        while(*first!=NULL){
            first=&(*first)->next;
        }
        temp->key=key;
        temp->next=NULL;
        *first=temp;
        returnValue=0;
        
    } return returnValue;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtPosition(LLElement **first, int key, int position) {
    int returnValue=-1;
    int i=0;
    LLElement * temp;
    
    
    temp=(LLElement*)malloc(sizeof(LLElement));
    
    if(temp!=NULL){
        if(position<=(LLSize(*first)) && position>=0){
            temp->key=key;
            while(i<position){
                first= &((*first)->next);
                i++;
            }
            temp->next=*first;
            *first=temp;
        }returnValue=0;
    }return returnValue;
}

/*
 * Returns the size of the list.
 */
int LLSize(LLElement *first) {
    int dimensione=0;
    
    while(first!=NULL){
        first=first->next;
        dimensione++;
    }
        
    return dimensione;
}

/*
 * Gives the key at the specified position. * 
 * 
 * Returns 0 on success.
 * Returns -1 if there is no key at the specified position
 */ 
int LLGetKey(LLElement *first, int position, int *key) {
    
    int returnValue=-1;
    
    int pos=0;
    
    if(first!=NULL){
        
        while(pos<position){
        first=first->next;
        pos++; 
        } 
        
        *key=first->key;
        returnValue=0;
    
    }
    return returnValue;
}

/*
 * Gives the position of the first element, starting from startPosition, that
 * has the specified key.
 * 
 * Returns 0 on success.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement *first, int key, int startPosition, int *position) {
    
    int returnValue= -1;
    int i=0;
    
    if(first!=NULL){
        
        while((i<startPosition) && (first!=NULL)){

            first=first->next;
            i++;

        }   
        if(first!=NULL){
            while((first->key!=key)  && (first!=NULL)){

                first=first->next;
                i++;

            }
        }
    }
    
    if(first!=NULL){
        
        returnValue=0;
        *position=i;
        
    }
    
    return returnValue;
}

/*
 * Remove the first element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveFirst(LLElement **first) {
    
    int returnValue=-1;
    LLElement * temp;
    
    if(*first!=NULL){
        temp = (*first)->next;
        free(*first);
        *first=temp;
        returnValue=0;
    }
    return returnValue;
}

/*
 * Remove the last element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveLast(LLElement **first) {
    
    int returnValue=-1;
    
    if(*first!=NULL){
        
        while((*first)->next!=NULL){
            first=&(*first)->next;
        }
        
        free(*first);
        *first=NULL;
        returnValue=0;
    }
    return returnValue;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Returns -1 in case it does not exist any element at the specified position
 */
int LLRemoveAtPosition(LLElement **first, int position) {
    
    int returnValue=-1;
    int i=0;
    LLElement * riallaccia;
    
    if(*first!=NULL){
        
        if((LLSize(*first) > position) && (position>=0)){
            
            while(i<position){
                first=&((*first)->next);
                i++;
            }   
            riallaccia=(*first)->next;
            free(*first);
            *first=riallaccia;
            returnValue=0;
        }
    }return returnValue;
}

/*
 * Empties the list.
 * Returns 0 on success.
 * Return -1 in case of emtpy list. 
 */
int LLEmptyList(LLElement **first) {
    
    int returnValue=-1;
    LLElement * cancella;
  
    if(*first!=NULL){
        while(*first!=NULL){

            cancella=*first;
            *first=(*first)->next;
            free(cancella);
        }
        returnValue=0;
    }
    return returnValue;
}