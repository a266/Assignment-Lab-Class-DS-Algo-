
#include<iostream>
#include <fstream>
#include<string>
using namespace std;


struct node{
		double data;
		struct node *next;
	};
class linkedlist{
	node *head;
	int size;
	public:
		linkedlist(){
			head=NULL;
			size=0;
		}
		~linkedlist(){

		node *temp=head;
		while(head!=NULL){
                  head=head->next;
                  delete temp;
                  temp=head;
		}
		}

		void insert(int);
		bool isempty();
		void display();
		int len();
};
bool linkedlist::isempty(){
      return head==NULL;
}

int linkedlist::len()
{
      return size;
}

void linkedlist::insert(int item){
	node *p=head;
	++size;
	node *temp=new node;
	if(head==NULL){
		temp->data=item;
		temp->next=NULL;
		head=temp;
		return;
	}
	while(p->next!=NULL){
		p=p->next;
	}

	temp->data=item;
	temp->next=NULL;
	p->next=temp;
}

void linkedlist::display(){
	node *temp=head;
	while(temp->next!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;

	}
	cout<<temp->data;
	cout<<endl;

}

linkedlist mat[100];


void write()
{
      ofstream out("file.txt");
      out<< "0 1 1 0\n";
      out<< "1 0 1 1\n";
      out<< "1 1 0 1\n";
      out<< "0 1 1 0";

}

void read(int &n)
{
      
      ifstream in("file.txt");
      string line;
      int i=0 , j=0;
      n=0;
      while(getline(in , line))
      {


            for(int k=0 ; k<line.size() ; ++k)
            {
                  if(line[k]==' ' or line[k]=='\n') continue;
                  if(line[k]=='1')
                  {
                        mat[i].insert(j);

                  }
                  ++j;

            }
            n=j;
            ++i;
            j=0;
      }
}
int main()
{
      write();
      int n;
      read(n);

      int e=0;
     for(int i =0 ; i<n ; ++i)
     {
           e+=mat[i].len();
     }
     cout<< "Tolal no. of edges "<<e/2<<endl;
     cout<< "Tolal no. of degree "<<e<<endl;
     int v;
     cout<<" Enter the vertex" <<endl;
     cin>>v;
      cout<<v<<"-->";

           mat[v].display();

     cout<<endl;
     cout<< "The graph is"<<endl;
     for(int i =0 ; i<n ; ++i)
     {
           cout<<i<<"-->";
           mat[i].display();

     }
}
