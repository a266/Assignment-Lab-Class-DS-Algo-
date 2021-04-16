#include<iostream>
#include<stdlib.h>

#define max 5

using namespace std;

class Lin_Queue{
    public:
    int arr[max];
    int front;
    int rear;

    Lin_Queue(){
    
    front = 0;
    rear = 0;
    }

    bool isFull(){
        if (rear == max - 1)
            return true;
        else
            return false;
        
    }

    bool isEmpty(){
        if (front == rear)
            return true;
        else
            return false;
        
    }

    void enqueue(int item){

        if (!isFull())
        {
            rear++;
            arr[rear] = item;
        }

        else
        {
            cout << "Queue is full" << endl;
        }
    }

    int dequeue(){
        if (!isEmpty())
        {
            front++;
            return arr[front];
        }

        else
        {
            cout << "The Queue is underflow" << endl;
            return -1;
        }
    }

    void display(){
        if (!isEmpty())
        {
            for (int i = front + 1; i <= rear; i++)
            {
                cout << arr[i] << "   ";
            }
        }

        else
        {
            cout << "The Queue is Empty" << endl;
        }   
    }
};

int main()
{

    Lin_Queue Q1;


    while (1)
    {
    	cout<<endl;
        cout << " 1. Enqueue \n 2. Dequeue \n 3. Display \n 4. Exit" << endl;
        cout << "Enter your choice" << endl;
        int n;

        cin >> n;

        switch(n){

            case 1:
            	system("CLS");
                int item;
                cout << "Enter the item" << endl;
                cin >> item;
                Q1.enqueue(item);
                break;

            case 2:
            	system("CLS");
                Q1.dequeue();
                break;

            case 3:
            	system("CLS");
                cout << "The Queue is" << endl;
                Q1.display();
                break;      

            case 4:
            	system("CLS");
                exit(1);  

            default:
            	system("CLS");
                cout << "Choose the options correctly";
                break;        
        }
    } 
    return 0;
}
