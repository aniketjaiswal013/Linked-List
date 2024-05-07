#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* convert2ll( vector<int>&a){
  Node* head=new Node(a[0]);
  Node* mover=head;
  for(int i=1;i<a.size();i++){
    Node* temp=new Node(a[i]);
    mover->next=temp;
    mover=temp;
  }
  return head;
}
                  //  TRAVERSEL OPERATION
void TraverseInLL(Node* head){
      Node* p=head;
     while(p){
       cout<<p->data<<endl;
       p=p->next;
     }
}

                      // ALL DELETION OPREATION
Node* DeleteAtFirst(Node* head){
    Node* temp=head;
    head=head->next;
    delete temp; 
    return head;
}
 Node* DeleteAtLast(Node* head){
    Node* temp=head;
    if(head==nullptr||temp->next==nullptr)return nullptr;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    
    delete temp->next;
      temp->next=nullptr;
    return head;
 }
  Node* DeleteKthElement(Node* head,int k){
    if(head==nullptr)return head;
     Node* temp=head;
    if(k==1){
    head=head->next;
    delete temp; 
    return head;
    }
    else{
           int cnt=1;
           while(cnt!=k-1&&temp->next!=nullptr){
               temp=temp->next;
               cnt++;
           }
           if(temp->next!=nullptr){
           Node* p=temp->next;
           temp->next=temp->next->next;
           delete p;      
           }
    }
    return head;
   
 }
 Node* DeleteThisElement(Node* head,int ele){
    if(head==nullptr)return head;
     Node* temp=head;
    if(head->data==ele){
    head=head->next;
    delete temp; 
    return head;
    }
    else{
            Node* prev=head;
           while(temp!= NULL){
            if(temp->data==ele){
              prev->next=prev->next->next;
              delete temp;
              break;
            }
            prev=temp;
            temp=temp->next;
           }
  
    }
    return head;
   
 }

                      // ALL INSERTION OPERATION

Node* InsertAtFirst(Node* head,int ele){
      Node* temp=new Node(ele);
      if(head==NULL){
        head=temp;
        return head;
      }
      temp->next=head;
      head=temp;
      return head;
     }    


Node* InsertAtLast(Node* head,int ele){
      Node* AddNode=new Node(ele);
       if(head==NULL){
        head=AddNode;
        return head;
      }
      Node* temp=head;
   while(temp->next!=NULL){
          temp=temp->next;
   }
   temp->next=AddNode;
      return head;
  }    

  Node* InsertAtKthPos(Node* head,int ele,int k){
      Node* AddNode=new Node(ele);
      if(head==NULL){     //this is a case when linked list is empty and we
       if(k==1){           // have to insert a element a 1st postion means k=1 if k>1the return as you want 
        AddNode->next=head;
        head=AddNode;
        return head;
      }
      else{
        return NULL;
      }
      }

       if(k==1){ // linked have a multiple element and task is to insert a element at 1st
        AddNode->next=head;
        head=AddNode;
        return head;
      }


      int cnt=1;
      Node* temp=head;
   while(cnt!=k-1 && temp!=NULL){
    temp=temp->next;
    cnt++;
   }
   if(temp!=NULL){
   AddNode->next=temp->next;
   temp->next=AddNode;
   }
      return head;
  }  


  Node* InsertBeforeThisElement(Node* head,int ele,int val){
  //it is insure that element is present in the linked list
   Node* AddNode=new Node(val);
     Node* temp=head;
    if(head->data==ele){
    AddNode->next=head;
    head=AddNode;
    return head;
    }
    else{
            Node* prev=head;
           while(temp!= NULL){
            if(temp->data==ele){
              AddNode->next=prev->next;
              prev->next=AddNode;
              break;
            }
            prev=temp;
            temp=temp->next;
           }
  
    }
    return head;
   
 }               
             

main(){
    vector<int>a={2,5,7,8,9,10,11};
     Node* start=convert2ll(a);
 start=InsertBeforeThisElement(start,11,12);
     TraverseInLL(start);
   
}

