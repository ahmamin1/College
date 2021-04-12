#include <iostream>
#include <string>
using namespace std;
const int sz = 10;
class Q{
    int rear = -1;
    int front = -1;
    int arr[sz];
public:
    bool isFull();
    bool isEmpty();
    void enQ(int val);
    void dQ();
    int qfront();
    void display();
};


////////////////////////////////////////
int main(){
Q que;
int sz = 0;
int operation;
int insertElm;
char ans;
cout << "enter size of que." << endl;
cin >> sz; 

do{
cout << "select an operation:" << "\n 1) display" << "\n 2) enQ" << "\n 3)dQ" << "\n 4)qfront" << endl;
cin >> operation;
switch (operation)
{
case 1:
    que.display();
    break;
case 2:
    cout << "type element to insert:";
    cin >> insertElm;
    que.enQ(insertElm);
    break;
case 3:
    que.dQ();
    break;
case 4:
    cout <<"front of que.: " << que.qfront(); 
    break;
default:
cout << "\nenter a valid choice"<< endl;
    break;
}

cout << "another operation? [y] for yes:";
cin >> ans;

}
while(ans == 'y' || ans == 'Y');

return 0;
}
////////////////////////////////////////

bool Q::isEmpty(){
    if (rear == -1 && front == -1) return true;
    else return false ;
}

bool Q::isFull(){
    if (rear == sz-1) return true; 
    else return false;
}

void Q::enQ(int val){
    if(isFull()) return;
    else if (isEmpty()){
    front  = rear = 0;
    }
    else {
        rear++;
    }
    arr[rear] = val;
}
void Q::dQ(){
    if (isEmpty()) return;
    else front++;
}
int  Q::qfront(){
if (isEmpty()) return 0;
else return arr[front];
}
void Q::display() {
        if (isEmpty()) cout << "Queue is Empty" << endl;
        else{
        cout << "\n## Queue Size : " << ((rear - front) + 1) << endl;
        for (int i = front; i <= rear; i++)
            cout << "\n## Position : " << i << " , Value  : " << arr[i];
        }
}