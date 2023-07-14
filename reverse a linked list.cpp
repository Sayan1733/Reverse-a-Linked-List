#include<iostream>
using namespace std;
class node{
	public:
		int data;			//Data Part
		node* next;			//Pointer part
		node(int val){		//inserting value using constructor
			data=val;
			next=NULL;
		}
};

void insertathead(node* &head,int val){
	node* n=new node(val);			//Assigning a memory and value or 
									//Assigning a data field[data->NUll]
	n->next=head;					//shifting head element to next 
	head=n;							//assign new value in head
}

void insertattail(node* &head,int val){
	node* n = new node(val);		//Assigning a data field[data->NUll]
	
	if(head==NULL){					//Checking if head is null or not
		head=n;
		return;
	}
	
	node* temp=head;			//new node name as temp and assign head
	while(temp->next!=NULL){	//iterate till NULL
		temp=temp->next;
	}
	temp->next=n;				//last node assign value
	
}

void display(node* head){
	node* temp=head;			//assign temp to head
	while(temp!=NULL){				//iterate to display data
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
node* reverse(node* &head){
	node* prevptr=NULL;				//store null in previous
	node* currptr=head;				//store head in current
	node* nextptr;					
	while(currptr!=NULL){			//iterate till current is NULL
		nextptr=currptr->next;		//next=current->next(next of current)
		currptr->next=prevptr;		//next of current = previous(head->null)
		
		prevptr=currptr;			//previous=current
		currptr=nextptr;			//current=next
	}
	
	return prevptr;					//rturn the previous part 
}
node* recursivereverse(node* &head){		//recursive way
	if(head==NULL || head->next==NULL){			//if head is null or head has 1 element
		return head;
	}
	node* newhead=recursivereverse(head->next);			//newhead=reverse part till 2nd position
	head->next->next=head;								//2is now head
	head->next=NULL;									//linking 2 with 1
	
	return newhead;
}
int main(){
	node* head=NULL;
	int n1,n2,i;
	cout<<"Enter 1 to add data in head or 2 to add data in tail"<<endl;
	cin>>i;
	if(i==1){
			do{
			cout<<"Type 0 to terminate the print"<<endl;
			cin>>n1;
			insertathead(head,n1);
		}while(n1!=0);
	}
	else if(i==2){
		do{
			cout<<"Type 0 to terminate the print"<<endl;
			cin>>n2;
			insertattail(head,n2);
		}while(n2!=0);
	}
	else{
		cout<<"You entered wrong choice"<<endl;
	}
	display(head);
	node* newhead=recursivereverse(head);
	display(newhead);
				
	return 0;
}
