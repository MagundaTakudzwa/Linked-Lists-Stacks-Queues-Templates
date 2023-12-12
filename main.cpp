#include <iostream>
#include <sstream>
#include <string>

#include "Node.h"
#include "List.h"
#include "CLinkedList.h"
#include "CLinkedList.cpp"
#include "List.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"


using namespace std;


/* -------------------------------------------------------------------------- */
/*                                 PLEASE READ                                */
/* -------------------------------------------------------------------------- */
/*
    Hello 110 Student :). This main.cpp provides very very basic testing that should help prevent some errors
    in your code. However, it is not a complete test suite. You should write your own tests to ensure that your
    code is working as expected

    Please do not be surprised if this main works but your FF upload fails as the FF main is different from this one.
    This Assignment has many edge cases, please test as much as possible.
*/



void t1(){
    cout<<"Testing CLinkedList"<<endl;
    CLinkedList<int> list;
    cout<<"Testing basics"<<endl;
    list.append(1);
    list.append(2);
    list.prepend(3);
    //list.print();
    list.insert(4, 3);
    list.print();// Output should be "3 -> 1 -> 2 -> 4\n"
     list.remove(0);//remember remove works based of index
     list.remove(0);
    list.remove(100);//test for invalid
    list.remove(1);
    list.removeElements(2);
    list.print();// Output should be "Empty\n
    list.append(1);
     list.append(1);
    list.print();// Output should be "1 -> 1\n"
    list.removeElements(1);
    list.print();// Output should be "Empty\n
}

void t2(){
    cout<<"Testing CLinkedList"<<endl;
    CLinkedList<int> list;
    cout<<"Testing rotations"<<endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
   list.RRotate(2);
    list.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
    list.LRotate(7);
    list.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    cout<<"Testing Assignment operator and rotation"<<endl;
    CLinkedList<int> list2;
    list2= list;
    list2.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    list2.RRotate(2);
    list2.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
}

void t3(){
    cout<<"Testing Stack"<<endl;
    Stack<int> stack;
    cout<<"Testing basics"<<endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout<<stack.pop()<<endl;// Output should be "4\n"
    cout<<stack.peek()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "2\n"
    cout<<stack.pop()<<endl;// Output should be "1\n"
    cout<<stack.pop()<<endl;// Output should be "0\n" since we are returning the default val
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout<<"Testing copy constructor"<<endl;
    Stack<int> stack2(stack);
    cout<<stack2.pop()<<endl;// Output should be "3\n"
    cout<<stack2.pop()<<endl;// Output should be "2\n"
    cout<<stack2.pop()<<endl;// Output should be "1\n"
    cout<<stack2.pop()<<endl;// Output should be "0\n" since we are returning the default val
    cout<<stack.pop()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "2\n"
    cout<<stack.pop()<<endl;// Output should be "1\n"
    cout<<stack.pop()<<endl;// Output should be "0\n" since we are returning the default val
    //loading up items to test destructor
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
}

void t4(){
    cout<<"Testing Queue"<<endl;
    Queue<int> queue;
    cout<<"Testing basics"<<endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    cout<<queue.dequeue()<<endl;// Output should be "1\n"
    cout<<queue.peek()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "3\n"
    cout<<queue.dequeue()<<endl;// Output should be "4\n"
    cout<<queue.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout<<"Testing copy constructor"<<endl;
    Queue<int> queue2(queue);
    cout<<queue2.dequeue()<<endl;// Output should be "1\n"
    cout<<queue2.dequeue()<<endl;// Output should be "2\n"
    cout<<queue2.dequeue()<<endl;// Output should be "3\n"
    cout<<queue2.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    cout<<queue.dequeue()<<endl;// Output should be "1\n"
    cout<<queue.dequeue()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "3\n"
    cout<<queue.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    //loading up items to test destructor
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

}

int main(){
    t1();
   t2();
   t3();
     t4();
    


    CLinkedList<int> list3;
    list3.append(1);
    list3.append(2);
    list3.append(3);
    list3.append(4);
    list3.append(5);

    // Display the original list
    std::cout << "Original List: ";
    list3.print();
    
    //swap function-working 
    list3.swap(1,3);
    std::cout << "After swapping elements at indices 1 and 3: ";
    list3.print();

    //Test the slice function
    list3.slice(0,3);
    std::cout << "After slicing from index 0 to 2: ";
    list3.print();


//test for the removing duplicates function 
    CLinkedList<int> list40;
    list40.append(3);
    list40.append(2);
    list40.append(3);
     list40.append(1);
    list40.append(2);
    list40.append(3);
    list40.append(1);
    std::cout<<"list before removing duplicates: "<<std::endl;
    list40.print();
    list40.removeDuplicates();
    std::cout<<"list after removing duplicates: "<<std::endl;
    list40.print();



    CLinkedList<int> list5;
    list5.append(1);
    list5.append(2);
    list5.append(3);

    CLinkedList<int> list6;
    list6.append(4);
    list6.append(5);
    list6.append(6);

   // Test the assignment operator (=)
   list6 = list5;
   //list5.clear();
   std::cout << "List6 after assignment: ";
    list6.print();
    //Expected output: List6 after assignment: 1 2 3

    list6.prepend(9);
    //Test the equality operator (==)
    if (list6 == list5) {
        std::cout << "List5 and List6 are equal." << std::endl;
    } else {
        std::cout << "List5 and List6 are not equal." << std::endl;
    }
    

   // Test the addition operator (+=)
    list6 += list5;
    std::cout << "List6 after addition: ";
    list6.print();
    

   CLinkedList<int> listt;
    listt.append(1);
    listt.append(2);
    listt.append(3);
    listt.append(4);

    CLinkedList<int> listt2;
    listt2.append(3);
    listt2.append(4);
    listt2.append(5);
    listt2.append(6);

    std::cout << "List 1: ";
    listt.print();

    std::cout << "List 2: ";
    listt2.print();

    CLinkedList<int>* operatorMinus = listt - listt2;

    std::cout << "List 1 - List 2: ";
    operatorMinus->print();

    delete operatorMinus; // Don't forget to free the memory of the result.


    
    //Test the removeDuplicates() function
    CLinkedList<int> list4;
    list4.append(2);
    list4.append(4);
    list4.append(4);
    list4.append(5);
     list4.removeDuplicates();
     std::cout << "List4 after removing duplicates: ";
     list4.print();

  CLinkedList<int> listconsume;
    listconsume.append(1);
    listconsume.append(2);
    listconsume.append(3);
    listconsume.append(4);
    listconsume.append(5);
    // Test the consume() function
    CLinkedList<int> list7;
    list7.append(6);
    list7.append(7);
    listconsume.consume(list7);
    std::cout << "List4 after consuming List7: ";
    listconsume.print();
    std::cout << "List7 after consumption: ";
    list7.print();
    // Expected output for List4 after consuming List7: 1 2 3 4 5 6 7
    // Expected output for List7 after consumption: (empty)


   CLinkedList<int> list8;
    CLinkedList<int> list9;

    // Add elements to list1 and list2
    for (int i = 1; i <= 5; i++) {
        list8.append(i);
        list9.append(i + 5);
    }

    std::cout << "List 8: ";
    list8.print(); // Should print: 1->2->3->4->5

    std::cout << "List 9: ";
    list9.print(); // Should print: 6->7->8->9->10

    // // // Test the consume function
    list8.consume(list9);

    // std::cout << "After consume:" << std::endl;

    std::cout << "List 8: ";
    list8.print(); // Should print: 1->2->3->4->5->6->7->8->9->10
    list8.reverse();
    std::cout<<"reversed: ";
    list8.print();
    std::cout << "List 9: ";
    list9.print(); // Should print: Empty
    list9.reverse();




 CLinkedList<int> list78;
    list78.append(1);
    list78.append(2);
    list78.append(3);
    list78.append(4);
    list78.append(5);
   list78.removeElements(2);

    // Print the original list.
    std::cout << "Original list: ";
    list78.print();

    //Filter the list to keep only values greater than 2.
    list78.filter("!=", 1);

    //Print the filtered list.
    std::cout << "Filtered list (!= 1): ";
    list78.print();

    // Filter the list to keep only values less than or equal to 4.
    list78.filter("<=", 4);

    // Print the newly filtered list.
    std::cout << "Filtered list (values <= 4): ";
    list78.print();
    std::cout<<list78[0]<<std::endl;
    std::cout<<list78.get(0)<<std::endl;
     return 0;
}