#include <iostream>
#include <fstream>
#include <cstring> 

using namespace std; 

struct Item{
  Item(int v, Item* n){
    val = v; 
    next = n;
  }
  int val;
  Item* next;
};

Item* concantenate(Item* head1, Item* head2);
void removeEvens(Item*& head);
double findAverage(Item* head);
void readLists(Item*& head1, Item*& head2);
void printList(std::ostream& ofile, Item* head);
int getsize(Item* head);

int getsize(Item* head){

  int counter = 0;
  Item* pointer = head;
  while(pointer->next != NULL){
    counter++;
    pointer = pointer->next;
  }
  return counter;
}

Item* concantenate(Item* head1, Item* head2)
{
  Item* ptr; //local pointer
  ptr = head1;
  //123678
  //456009
  if (ptr->next == NULL){
    ptr->next = head2;
  }
  else{
    ptr = ptr->next;
    concantenate(ptr, head2);
  }
  return head1;
}

void removeEvens(Item*& head){
  Item* ptr;
  Item* prev;
  ptr = head;
//123456789-> 13579
  if (head == NULL){
    cout << "ERROR: empty list" << endl;
  }
  else{
    if(ptr->val % 2 != 0){ //odd
      prev = ptr;
      ptr = ptr->next;
      removeEvens(ptr);
    }
    else{//even
      if(head == ptr)  {//case when the first of the element is even
	head = ptr->next;
	delete ptr;
	ptr = head;
	removeEvens(ptr);
      }
      else if(ptr->next != NULL){//case when element between the first
   	                         // and the last one is even.
	prev->next = ptr->next;
	prev = ptr->next;
	delete ptr;
	ptr = prev;
	removeEvens(ptr);
      }
      else{//when the last element is even
	prev->next = NULL;
	delete ptr;	
      }
    }
  }
}

double findAverage(Item* head){
  Item* temp;
  temp = head;
  double avg = 0;
  double sum = 0.0;
  int count = 0;
  //123456
  if(head == NULL){
    cout << "Nothing in the list" << endl;
  }
  else{
    if(temp->next != NULL){
      sum = sum + temp->val;
      temp = temp->next;
      count++;
      findAverage(temp);
    }
    else{//reached the last one
      sum = sum + temp->val;
      avg = sum / (count + 1);
    }
  }
  return avg;
}

void readLists(Item*& head1, Item*& head2){
  string text;
  string text2;
  int count = 0;//size of the array
  ifstream my_file ("input.txt");
  int integer = 0;
  Item* line1ptr, line2ptr;

  if(my_file.fail()){
    cout << "Couldn't open file" << endl;
    return 1;
  }
  else{
    line1ptr = new Item();
    line2ptr = new Item();
    getline(my_file,text1);
    getline(my_file,text2);
      
       
        
      
      my_file.close();
  }
}
return 0;  
}

void printList(std::ostream& ofile, Item* head){
  if(head == NULL)
    ofile << std::endl;
  else{
    ofile << head->val << " ";
    printList(ofile, head-> next);
  }
}
