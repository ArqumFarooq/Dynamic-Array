#ifndef ARRAYASSIGNMENT_ARRAY_H
#define ARRAYASSIGNMENT_ARRAY_H

#endif //ARRAYASSIGNMENT_ARRAY_H

#include <iostream>
using namespace std;
class Array{
private:
    int *data;
    int *data1;
    int size;
    int maxSize;
public:
    Array();
    Array(int);
    ~Array();
    bool IsEmpty();
    bool IsFull();
    bool IsValid();
    int length();
    int getmaxSize();
    void print();
    bool grow();
    bool shrink();
    void growAndShrink();
    bool insert(int);
    bool insertAt(int,int);
    bool insertAtOrder(int);
    bool insertStart(int);
    bool deleteAtIndex(int);
    bool deleteAt(int);
    bool deleteLast();
    bool searchAndDelete(int);
    bool search(int);
    void sorting();
};
Array::Array(){
    data=NULL;
    data1=NULL;
    size=0;
    maxSize=0;
}
Array::Array(int size){
    maxSize=size;
    this->size=0;
    data=new int[maxSize];
    data1=NULL;
}
Array::~Array(){
    delete[] data;
}
bool Array::IsValid() {
    return (data!=NULL);
}
bool Array::IsEmpty() {
    return (size==0);
}
bool Array::IsFull(){
    return (size==maxSize);
}
int Array::length(){
    return size;
}
int Array::getmaxSize() {
    return maxSize;
}
void Array::print(){
    for(int i=0;i<size;i++){
        cout<<data[i]<<" ";
    }
}
bool Array::grow() {
    data1=new int[maxSize];
    for(int j=0;j<size;j++){
        data1[j]=data[j];
    }
    delete[] data;
    data=new int[maxSize*2];
    for(int j=0;j<size;j++){
        data[j]=data1[j];
    }
    delete[] data1;
    maxSize*=2;
    return true;
}
bool Array::shrink() {
    int newsize=maxSize/2;
    data1=new int[newsize];
        for(int j=0;j<size;j++){
            data1[j]=data[j];
        }
        delete[] data;
        data=new int[newsize];
        for(int j=0;j<size;j++){
            data[j]=data1[j];
        }
        delete[] data1;
        maxSize=newsize;
        return true;
}
void Array::growAndShrink() {
    int min=0.45*maxSize;
    int max=0.95*maxSize;
    if(size>=max){
        this->grow();
    }
    if(size<=min){
        this->shrink();
    }
}
bool Array::insert(int x){
    if(IsValid()){
        this->growAndShrink();
        data[size++]=x;
        return true;
    }
    return false;
}

bool Array::insertAt(int index,int x){
    if(IsValid()&&index>=0&&index<=size){
        this->growAndShrink();
        for(int i=size;i>index;i--){
            data[i]=data[i-1];
        }
        data[index]=x;
        size++;
        return true;
    }return false;
}
bool Array::insertAtOrder(int x){
    this->sorting();
    if(IsValid()) {
        int a = 0;
        for (int i = 0; i < size; i++) {
            if (data[i] > x) {
                a = i;
                break;
            }
        }
        for (int i = size; i > a; i--) {
            data[i] = data[i - 1];
        }
        data[a] = x;
        size++;
        return true;
    }return false;
}
void Array::sorting(){
    for(int i=1;i<size;i++){
        int key=data[i];
        int j=i-1;
        while(j>=0&&data[j]>key){
            data[j+1]=data[j];
            j--;
        }
        data[j+1]=key;
    }
}
bool Array::insertStart(int x) {
    if(IsValid()){
        for(int i=size;i>0;i--){
            data[i]=data[i-1];
        }
        data[0]=x;
        size++;
        return true;
    }return false;
}
bool Array::search(int x){
    if(IsValid()){
        for(int i=0;i<size;i++){
            if(data[i]==x){
                return true;
            }
        }
        return false;
    }
    return false;
}
bool Array::deleteAt(int x){
    if(IsValid()&&search(x)){
        int num=0;
        for(int i=0;i<size;i++){
            if(data[i]==x){
                num=i;
                break;
            }
        }
        deleteAtIndex(num);
        return true;
    }
    return false;
}
bool Array::deleteLast(){
    if(IsValid()){
        size--;
        return true;
    }return false;
} 
bool Array::deleteAtIndex(int index){
    if(IsValid()&&index>=0&&index<size){
        for(int i=index;i<size;i++){
            data[i]=data[i+1];
        }
        size--;
        return true;
    }return false;
}

bool Array::searchAndDelete(int x) {
    if(IsValid()&&search(x)){
        deleteAt(x);
        return true;
    }return false;
} 
