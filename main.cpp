#include <iostream>

using namespace std;

typedef struct ListNode{
  int data;
  struct ListNode *nextNode;
}*ptr;

ptr firstHead = NULL, firstCurrent, secondHead = NULL, secondCurrent, sumHead = NULL, sumCurrent;

void FirstList(int value){
     ptr newNode = new ListNode;
     newNode->data = value;
     if(firstHead == NULL){
        newNode->nextNode = NULL;
        firstHead = newNode;
        firstCurrent = newNode;
     }
     else{
        firstCurrent->nextNode = newNode;
        firstCurrent = newNode;
     }
}

void SecondList(int value){
     ptr newNode = new ListNode;
     newNode->data = value;
     if(secondHead == NULL){
        newNode->nextNode = NULL;
        secondHead = newNode;
        secondCurrent = newNode;
     }
     else{
        secondCurrent->nextNode = newNode;
        secondCurrent = newNode;
     }
}

void AddList(){
     ptr firstListData = firstHead, secondListData = secondHead;
     int d1,d2,sum, remain, temp = 0;
     while(firstListData != NULL){
        d1 = firstListData->data;
        d2 = secondListData->data;
        sum = firstListData->data + secondListData->data + temp;
        //temp = 0;
        cout << sum << endl;

        ptr sumNode = new ListNode;

        if(sum < 10){
            sumNode->data = sum;
            if(sumHead == NULL){
                sumNode->nextNode = NULL;
                sumHead = sumNode;
                sumCurrent = sumNode;
            }
            else{
                sumCurrent->nextNode = sumNode;
                sumCurrent = sumNode;
            }
        }
        else if(sum >= 10){
            remain = sum %10;
            temp = sum / 10;
            sumNode->data = remain;
              if(sumHead == NULL){
                sumNode->nextNode = NULL;
                sumHead = sumNode;
                sumCurrent = sumNode;
            }
            else{
                sumCurrent->nextNode = sumNode;
                sumCurrent = sumNode;
            }
        }
        firstListData = firstListData->nextNode;
        secondListData = secondListData->nextNode;
     }
     if(temp != 0){
        ptr sumNode = new ListNode;
        sumNode->data = temp;
        sumCurrent->nextNode = sumNode;
        sumCurrent = sumNode;
     }
     ptr displayList = sumHead;
     cout << "List after summation: ";
     while(displayList != NULL){
        cout << displayList->data << " ";
        displayList = displayList->nextNode;
     }
     cout << endl;
}


int main()
{
    int firstList, secondList;

    cout << "Enter first list data: ";
    for(int i = 0; i < 3; i++){
        cin >> firstList;
        FirstList(firstList);
    }
    cout << "Enter Second List data: ";
    for(int j = 0; j < 3; j++){
        cin >> secondList;
        SecondList(secondList);
    }
    AddList();
   // DisplaySumList();
    return 0;
}
