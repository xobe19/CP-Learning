class Dequeue {
int* data = 0;
int capacity = 0;
int front = 0;
int last = 0;
int size = 0;
Dequeue(int size) {
this -> data = new int[size];
this -> capacity = size;
}
int insertFront(int elem) {
if(size > capacity)  return -1;
else {
    data[front] = elem;
    front = (front - 1) % capacity;
    size++;
    return 1;
}
}
int insertRear(int elem) {
    if(size > capacity) return -1;
    else {
        data[last] = elem;
        last = (last + 1) % capacity;
        size++;
        return 1;
    }
}
int deleteFront() {
    if(size == 0) return -1;
    else {
        front = (front + 1) % capacity;
        return 1;
    }
}
int deleteRear() {
    if(size == 0) return -1;
    else{
        last = (last - 1) % capacity;
        return 1;
    }
}
int getFront() {
    if(size == 0) return -1;
    else return data[front];
}
int getRear() {
    if(size == 0) return -1;
    else return data[last];
}
};