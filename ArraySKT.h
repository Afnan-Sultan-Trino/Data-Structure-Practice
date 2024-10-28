#include <iostream>
using namespace std;

class Array
{
private:
    int size;
    int length = 0;
    int *arr;

public:
    // Constructor: Initialize array with size and default values
    Array(const int size)
    {
        this->size=size;
        arr= new int[size];
        for(int i=0;i<size;i++){
            arr[i]=0;
        }
    }

    // Constructor: Initialize array with a specific value
    Array(const int size, int v) : Array(size)
    {
        for(int i=0;i<size;i++){
            arr[i]=v;
        }
    }

    // Initialize array elements with a specific value
    void initArray(int v)
    {
        for(int i=0;i<size;i++){
            arr[i]=v;
        }
    }

    // Return the length of the array (number of elements inserted)
    int getLength()
    {
        return length;
    }

    // Get the element at a given position
    int at(int pos)
    {
        if(pos>=0 && pos<length){
            return arr[pos];
        }else{
            cout<<"Invalid index"<<pos<<endl;
            //throw std::out_of_range("Index out of bounds");
            return -1;
        }
    }

    // Check if the array is empty
    bool isEmpty()
    {
        if(length==0){
            return true;
        }else{
            return false;
        }
    }

    // Check if the array is full
    bool isFull()
    {
        if(length==size){
            return true;
        }else{
            return false;
        }
    }

    // Print the array elements
    void print()
    {
        if(isEmpty()){
            cout<<"Array is Empty"<<endl;
        }else{
            for(int i=0;i<length;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }

    // Insert an element at the end of the array
    void insert(int v)
    {
        if(isFull()){
            cout<<"Insertion failed"<<endl;
        }else{
            arr[length]=arr[v];
            length++;
        }
    }

    // Insert an element at a specific position
    void insertAt(int pos, int v)
    {
        if(pos>=0 && pos<length && !isFull()){
            for(int i=length;i>pos;i--){
                arr[i]=arr[i-1];
            }
            arr[pos]=v;
            length++;
        }else{
            cout<<"Insertion failed"<<endl;
        }
    }

    // Replace the element at a specific position
    void replaceAt(int pos, int v)
    {
        if(pos>=0 && pos<length){
            arr[pos]=v;
        } 
    }

    // Remove the last element from the array
    void remove()
    {
        if(isEmpty()){
            cout<<"The array is Empty"<<endl;
        }else{
            length--;
        }
    }

    // Remove an element from a specific position
    void removeAt(int pos)
    {
        if(pos>=0 && pos<length && !isEmpty()){
            for(int i=pos;i<length-1;i++){
                arr[i]=arr[i+1];
            }
            length--;
        }else{
            cout<<"Removal failed"<<endl;
        }
    }

    // Clear the array by resetting all elements and length
    void clear()
    {
        initArray(0);
        length=0;
    }

    // Reverse the array
    void reverseArray()
    {
        for(int i=0;i<length/2;i++){
            int temp=arr[i];
            arr[i]=arr[length-1-i];
            arr[length-1-i]=temp;
        }
    }

    // Copy elements from another array into this array
    void copyArray(int data[], int n)
    {
        if(n>size){
            cout<<"Array size is greater than current array"<<endl;
        }
        clear();
        for(int i=0;i<n;i++){
            arr[i]=data[i];
        }
        length=n;
    }

    // Destructor: Clean up memory when the object is destroyed
    ~Array()
    {
        delete[]arr;
    }
};