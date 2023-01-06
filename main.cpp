// sam106
//
// Using Pointers to access arrays.
// Pointer Arithmetic - incrementing pointers and using them to access arrays.

// NB:  "The name of an array is a constant pointer to the first element of an array."
// Note that we cannot change the address value in the name x as it is constant

#include <iostream>
using namespace std;
const int SIZE = 5; // array size

int main()
{
    int x[SIZE] = { 10,20,30,40,50 };  // allocate array elements on stack memory

    // In C++, the name an array is a constant pointer to the beginning of the array.
    // To verify this, we will output x (which should be an address value),
    // and we will output the address of the first element in teh array (i.e. &x[0]

    cout << "Value in array name \"x\"  is the address : " << x << endl;
    cout << "Address of first array element &x[0] is : " << &x[0] << endl;
    cout << "The addresses are the same, so this demonstrates that the name "
            "of the array is the address of the start of the array elements." << endl;

    // Let us declare a pointer p that we will use to access the elements in the array x[]
    // by manipulating the pointer.

    int* p;    // declare p as a 'pointer to an int'

    p = x;   // assign address of array to the pointer p.
    // The address of the first element in the array ( i.e. x) is
    // assigned into the pointer 'p' .  So, p now also points at the first
    // element of the array x.

    // We can now use the pointer p to access the elements of the array
    cout << "Value at *p = " << *p << endl; // dereference the pointer p giving
    // the first element in the array.

    p++;  // Increment the pointer p.
    // This means increment the value of the pointer
    // so that it points at the next element in the array x[].
    // When we increment a pointer it is incremented by the length of
    // the type of the object it points to.  Here, p is a pointer to int,
    // so, the pointer is incremented by one integer length.
    // (If the size of an int is 4 bytes on a machine, then the address in the pointer is incremented
    // by 4 (i.e. 4 bytes), which is the length of one int array element).
    //
    // Incrementing a pointer moves the pointer forward to the start of
    // the next element in an array.

    cout << "Address value stored in pointer p should be greater (by 4) than it was, p = " << p << endl;

    cout << "p should now point to second array element, so *p = " << *p << endl; // should print second element from array x[]

    // We can perform Pointer Arithmetic on a pointer to change where it points to.

    p = p + 2;  // this will move the pointer on by two elements, leaving it pointing
                // at the fourth element in the array. (adds 2 x sizeof(int) to p )

    // We can dereference ouu pointer to allow us to change the values at the location
    // where the pointer points to.

    *p = 99;   // Assigns the value 99 to where p is pointing, i.e. in the fourth
               // element of the array.

    p++;             // moves pointer to point at last element in array
    *p = *p + 100;   // gets current value from where p points, adds 100 to it, assigns new value back to where p points.

    // At this point, the pointer p is pointing to the last element in the array.
    // If we want to print out the array elements using the pointer we must (re)set the
    // pointer to point to the beginning of the array, as follows:

    p = x;  // p is reset to point at the start of array
    // remember - the name of the array x, is the address of the start of the array

    // Below, we will use out pointer to iterate over the elements in the array, by
    // incrementing the pointer on each loop cycle.

    for (int i = 0; i < SIZE; i++)
    {
        cout << *p << ", ";  // de-reference the pointer to access what the pointer is pointing at.
        p++;                 // (increment) move the pointer on to the next element.
    }

    cout << "Above, we see the changes made to array x[] using pointer p" << endl;


    // The "danger" with pointers :
    // The pointer p has been incremented in the for loop above, to a position
    // just beyond the last element in the array.
    // This memory space does not belong to the array, so we are pointing beyond the bounds of the array.
    // The pointer can be used to access an element beyond te end of the array boundary - which is a logic error!
    // (In Java, an Exception will be thrown to prevent accessing array elements out of bounds,
    // but there is no such mechanism in C++).

    cout << "\nDanger ! Source of Programmer error ! " << endl;
    cout << "- pointer is accessing element beyond the end of the array. *p = ";
    cout << *p << endl;

    // Even worse danger !!! -
    // Explain happens when you execute this (assuming the for loop above was executed)
    // and the pointer p points beyond the end of the array.
    *p = 666;
    cout << *p << endl;
    // Above, we have written a value to a memory location that is outside the array bounds.
    // So, we have written a value to some arbitrary location that our program has not allocated,
    // possibly overwriting and corrupting the contents of some other variable.
    // This is a nasty type of programming bug!

    p=nullptr;  // set pointer to null. If de-referenced by accident now, it will cause a runtime error.

    //cout << *p;       // if p in null, then dereferencing it causes a runtime error.
    //  Causes Program terminated due to an access violation with error code 0xC0000005.
    //  This error can occur if  de-referencing a NULL pointer or referencing an invalid address.


    //TODO Q.1
    // Declare and initialize an array d[] of 5 double values.
    //    Declare a pointer "pd" and assign it to point at the beginning of the array.
    //    Write a for loop that will use the pointer to triple (multiply by 3) the value of
    //    each array element.  Write a second for loop that uses a pointer to iterate
    //    over the elements and de-reference the pointer to display each element.
    //    add solution here...


//TODO Q.2
//    Continuing from above....
//    Reset the pointer "pd" to point at the start of the array.
//    Next, manipulate the pointer "pd" to point at the last element in the array d[]
//    Display the address of the last element.
//    Be careful that it is set to point at the last element, and not beyond
//    the last element.
//    Use a for loop, and the pointer, to print the array elements in reverse order.
//    Hint, decrement the pointer.


    return 0;
}



