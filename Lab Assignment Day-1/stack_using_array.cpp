#include<iostream>
#define MAX 5

using namespace std;

class Stack{
 		int a[MAX];
 		int top;
 	public:	
 		Stack(){
			top=-1;
			}
		int isempty(){
  			if(top == -1)
   				return 1;
  			else
   				return 0;
		}

		int isfull(){
  			if(top==MAX-1)
   				return 1;
  			else
   				return 0;
		}

		void push()
		{
  			if(isfull()==1)
   				cout<<"STACK IS FULL!! CAN'T ENTER MORE DATA "<<endl;
  			else{
   				cout<<"ENTER VALUE: ";
   				int n;
   				cin>>n;
   				top++;
   				a[top]=n; 
   			}
		}

		void pop(){
  			if(isempty()==1)
   				cout<<"NOTHING TO POP"<<endl;
  			else{
  				cout<<"The Element is popped:"<<endl;
  				top--;
			}
		}

		void show(){
  			int j=0;
  			for(j=top;j>=0;j--)
   			cout<<a[j]<<" ";
  			cout<<endl;
		}

		int peek(){
  			cout<<"PEEK IS "<<a[top]<<endl;
		}

};


int main(void){
 	Stack ar;
 	int m=1;
 	while(m!=0){
  		cout<<endl<<"ENTER CHOICE "<<endl<<"1 Push Element"<<endl<<"2 Peek Element"<<endl<<"3 Pop Element"<<endl<<"4 Display"<<endl<<"0 TO CLOSE THE PROGRAM"<<endl;
  		cin>>m;
  		cout<<endl<<endl;
  	switch(m){
   	case 1:
   		system("CLS");
   		cout<<"Enter the element which you want to push: "<<endl;
    	ar.push();
    	break;
   	case 2:
   		system("CLS");
    	cout<<endl<<"The peek element is: "<<endl;
    	ar.peek();
    	break;
   	case 3:
   		system("CLS");
    	ar.pop();
    	break;
    case 4:
    	system("CLS");
    	cout<<"The stack is: ";
    	ar.show();
    	break;
   	case 0:
    	ar.show();
    	cout<<"CLOSING THE PROGRAM....";
    	break;        
}
  
}
}
