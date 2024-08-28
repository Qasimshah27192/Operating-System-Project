#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
   vector<int> g1;

struct node
{
  int process_id, AT, BT, priority;
  string state;
  struct node *next;
};
struct Running
{
  int process_id, AT, BT, priority;
  string state;
  struct Running *nextR;
};

struct Waiting
{
  int process_id, AT, BT, priority;
  string state;
  struct Waiting *nextV;
};

struct Suspend
{
  int process_id, AT, BT, priority;
  string state;
  struct Suspend *nextU;
};
class linked_list
{
private:
  node * head, *curr;
    Running * headR, *currR;
    Waiting * headV, *currV;
    Suspend * headU, *currU;
public:
  linked_list ()
  {
    head = NULL;
    curr = NULL;
    headR = NULL;
    currR = NULL;
    headV = NULL;
    currV = NULL;
    headU = NULL;
    currU = NULL;
  }

  void create_process (int process_id, int AT, int BT, int priority,string state)
  {
    node *tmp = new node;
    tmp->process_id = process_id;
    tmp->AT = AT;
    tmp->BT = BT;
    tmp->priority = priority;
    if (head != NULL)
      {
curr = head;
while (curr->next != NULL)
 {
   curr = curr->next;

 }
curr->next = tmp;
      }
    else
      {
head = tmp;
      }
  }
 
 
 
  //code for READY
int Ready(int n)
    {
       node *temp = head;


            while(temp!=NULL)
            {
                if(temp->process_id==n)
                {
                 temp->state="Ready";
                  return 0;
                }
                else{
                   temp = temp->next;
                }

            }    
          cout<<"element not found "<<endl;
          return 0;
       }
       
       
       //code for RUNNING
       
    int Running2(int n)
    {
       node *temp = head;


            while(temp!=NULL)
            {
                if(temp->process_id==n)
                {
                   temp->state="Running";
                  return 0;
                }
                else{
                   temp = temp->next;
                }

            }    
          cout<<"element not found "<<endl;
          return 0;
       }
       
       
       
   int Display_Process(int n)
    {
       node *temp = head;


            while(temp!=NULL)
            {
                if(temp->process_id==n)
                {
cout << "Process ID" << "   " << "Arrival Time" << "  " << "Burst Time" <<
      "  " << "Priority" << "  " << "State" <<endl;
        cout << temp->process_id << "             " << temp->
     AT << "            " << temp->BT << "            " << temp->
     priority << "            " << temp->
     state<<  "            " << endl;
                  return 0;
                }
                else{
                   temp = temp->next;
                }

            }    
          return 0;
       }
       
     
       //code for display Process
       
  void display ()
  {
    node *temp = head;
    cout << endl;
    cout << "Process ID" << "   " << "Arrival Time" << "  " << "Burst Time" <<
      "  " << "Priority" << "  " << "  " << "State" << endl;
    while (temp != NULL)
      {
if (head == NULL)
 {
   cout << "No Process" << endl;
 }
else
 {
   cout << temp->process_id << "             " << temp->
     AT << "            " << temp->BT << "            " << temp->
     priority << "            " <<  temp->
     state<<  "            " << endl;

   temp = temp->next;

 }
      }

  }
 
 
  //code for Destroy
 
 void Destroy(int pos)
    {
        node *temp = head;
        node *next_node=NULL;
        int i=1;
        if(pos==1)
        {
            head=head->next;
            free(temp);
        }
        else{
        while(i<pos-1)
        {
          if(temp->next==NULL)
          {
          cout<<"not found";
          }
          else
          {
             
              temp = temp->next;
              i++;
          }
        }
        next_node = temp->next;
         temp->next= next_node->next;
        free(next_node);
}
    }
   
   
   
    //code for WAKEUP
   
      void Wakeup_q ()
  {
    int n;
    //int x1;
    Waiting *temp = headV;
    Waiting *next_node = NULL;
    Waiting *temp2 = headV;
    Waiting *running;
    n=temp->priority;

    while (temp != NULL)
      {
if (temp->process_id >= n); //&& temp->state=="Waiting")
 {
    n=1;
  running=temp;
    // temp = Waiting;
  n=temp->priority;
}
     
    temp = temp->nextV;
      }
   
    int i = 1;
    temp = running;
    node* x = new node;
          x->process_id = temp->process_id;
    x->AT = temp->AT;
    x->BT = temp->BT;
    x->state = "Wakeup";
    x->priority = temp->priority;
     
        // x->next = head;

        // head = x;
     
    int count = 1;
    Waiting *x1 = headV;
    while (x1 != temp)
      {
        x1 = x1->nextV;
        count++;
      }
        int pos = count;
        if (pos == 1)
            {
                headV = headV->nextV;
                free (temp);
      }
    else
      {
                while (i < pos - 1)
  {
                temp2 = temp2->nextV;
                i++;
                    }
                next_node = temp2->nextV;
                temp2->nextV = next_node->nextV;
                 free (next_node);
            }
                cout<<x->priority;
                x->next = head;
       
                 head = x;

    //  if(k==0)
    //  {
    //     cout<<"The process must be in the BLOCKED QUEUE to get Wakeup "<<endl;
    //  }

  }
   
//          int Display_Process_q()
//     {
//       node *temp = head;


//             while(temp!=NULL)
//             {
// cout << "Process ID" << "   " << "Arrival Time" << "  " << "Burst Time" <<
//       "  " << "Priority" << "  " << "State" <<endl;
//         cout << temp->process_id << "             " << temp->
//      AT << "            " << temp->BT << "            " << temp->
//      priority << "            " << temp->
//      state<< endl;
//                   temp = temp->next;

//             }
//               return 0;
//       }





//code for Resumed
      void Resume_k ()
  {
    int n;
    //int x1;
    Suspend *temp = headU;
    Suspend *next_node = NULL;
    Suspend *temp2 = headU;
    Suspend *running;
    n=temp->priority;

    while (temp != NULL)
      {
if (temp->process_id >= n); //&& temp->state=="Waiting")
 {
    n=1;
  running=temp;
    // temp = Waiting;
  n=temp->priority;
}
     
    temp = temp->nextU;
      }
   
    int i = 1;
    temp = running;
    node* x = new node;
          x->process_id = temp->process_id;
    x->AT = temp->AT;
    x->BT = temp->BT;
    x->state = "Resumed";
    x->priority = temp->priority;
     
    int count = 1;
    Suspend *x1 = headU;
    while (x1 != temp)
      {
        x1 = x1->nextU;
        count++;
      }
        int pos = count;
        if (pos == 1)
            {
                headU = headU->nextU;
                free (temp);
      }
    else
      {
                while (i < pos - 1)
  {
                temp2 = temp2->nextU;
                i++;
                    }
                next_node = temp2->nextU;
                temp2->nextU = next_node->nextU;
                 free (next_node);
            }
                cout<<x->priority;
                x->next = head;
       
                 head = x;

  }
   
   
    //code for BLOCKED
   
            void Waiting_v (int n)
  {
    int k;
    Running *temp = headR;
    Running *next_node = NULL;
    Running *temp2 = headR;
    Running *running;

    int i = 1;

    while (temp != NULL)
      {
if (temp->process_id == n && temp->state=="Running")
 {
    k=1;
  running = temp;
      temp = running;

   

 
    Waiting* x = new Waiting;
          x->process_id = temp->process_id;
    x->AT = temp->AT;
    x->BT = temp->BT;
    x->state = "Waiting";
    x->priority = temp->priority;
     
        x->nextV = headV;

        headV = x;
     
    int count = 1;
    Running *x1 = headR;
    while (x1 != temp)
      {
        x1 = x1->nextR;
        count++;
      }
        int pos = count;
        if (pos == 1)
            {
                headR = headR->nextR;
                free (temp);
      }
    else
      {
                while (i < pos - 1)
  {
                temp2 = temp2->nextR;
                i++;
                    }
                next_node = temp2->nextR;
                temp2->nextR = next_node->nextR;
                 free (next_node);
            }
     
            break;
                    }
            else
                {
                    k=0;
                     temp = temp->nextR;
                }
 

      }

     if(k==0)
     {
        cout<<"The process must be in the RUNNING QUEUE to get BLOCKED "<<endl;
     }

  }
   
         int Display_Process_v()
    {
      Waiting *temp = headV;


            while(temp!=NULL)
            {
cout << "Process ID" << "   " << "Arrival Time" << "  " << "Burst Time" <<
      "  " << "Priority" << "  " << "State" <<endl;
        cout << temp->process_id << "             " << temp->
     AT << "            " << temp->BT << "            " << temp->
     priority << "            " << temp->
     state<< endl;
                   temp = temp->nextV;

            }
              return 0;
       }
   
   
    //code for DISPATCHED
   
        void Running_s (int n)
  {
    int k;
    node *temp = head;
    node *next_node = NULL;
    node *temp2 = head;
    node *running;

    int i = 1;

    while (temp != NULL)
      {
if (temp->process_id == n && temp->state=="Ready")
 {
    k=1;
   running = temp;
       temp = running;

   

 
    Running* x = new Running;
           x->process_id = temp->process_id;
    x->AT = temp->AT;
    x->BT = temp->BT;
    x->state = "Running";
    x->priority = temp->priority;
     
        x->nextR = headR;

        headR = x;
     
    int count = 1;
    node *x1 = head;
    while (x1 != temp)
      {
        x1 = x1->next;
        count++;
      }
        int pos = count;
        if (pos == 1)
            {
                head = head->next;
                free (temp);
      }
    else
      {
                while (i < pos - 1)
  {
                temp2 = temp2->next;
                i++;
                    }
                next_node = temp2->next;
                temp2->next = next_node->next;
                 free (next_node);
            }
     
            break;
                    }
            else
                {
                    k=0;
                     temp = temp->next;
                }
 

       }

     if(k==0)
     {
        cout<<"The process must be in the READY QUEUE to get DISPATCHED "<<endl;
     }

   }
   
   
   
    int Display_Process_s(int n)
    {
       Running *temp = headR;


            while(temp!=NULL)
            {
cout << "Process ID" << "   " << "Arrival Time" << "  " << "Burst Time" <<
      "  " << "Priority" << "  " << "State" <<endl;
        cout << temp->process_id << "             " << temp->
     AT << "            " << temp->BT << "            " << temp->
     priority << "            " << temp->
     state<< endl;
                   temp = temp->nextR;
                }

          return 0;
       }
       
       
       
      //code for Suspend
   
            void Suspend_u (int n)
  {
    int k;
    Running *temp = headR;
    Running *next_node = NULL;
    Running *temp2 = headR;
    Running *running;

    int i = 1;

    while (temp != NULL)
      {
if (temp->process_id == n && temp->state=="Running")
 {
    k=1;
  running = temp;
      temp = running;

   

 
    Suspend* x = new Suspend;
          x->process_id = temp->process_id;
    x->AT = temp->AT;
    x->BT = temp->BT;
    x->state = "Suspend";
    x->priority = temp->priority;
     
        x->nextU = headU;

        headU = x;
     
    int count = 1;
    Running *x1 = headR;
    while (x1 != temp)
      {
        x1 = x1->nextR;
        count++;
      }
        int pos = count;
        if (pos == 1)
            {
                headR = headR->nextR;
                free (temp);
      }
    else
      {
                while (i < pos - 1)
  {
                temp2 = temp2->nextR;
                i++;
                    }
                next_node = temp2->nextR;
                temp2->nextR = next_node->nextR;
                 free (next_node);
            }
     
            break;
                    }
            else
                {
                    k=0;
                     temp = temp->nextR;
                }
 

      }

     if(k==0)
     {
        cout<<"The process must be in the RUNNING QUEUE to get BLOCKED "<<endl;
     }

  }
   
         int Display_Process_u()
    {
      Suspend *temp = headU;


            while(temp!=NULL)
            {
cout << "Process ID" << "   " << "Arrival Time" << "  " << "Burst Time" <<
      "  " << "Priority" << "  " << "State" <<endl;
        cout << temp->process_id << "             " << temp->
     AT << "            " << temp->BT << "            " << temp->
     priority << "            " << temp->
     state<< endl;
                   temp = temp->nextU;

            }
              return 0;
       }
   

//code for FCFS

  int x;
  void fcfs ()
  {
    int i = 1;
    int min;
    node *temp = head;
    node *running;
    node *trav = head;
    node *temp2 = head;
    node *next_node;
    min = temp->AT;
    while (temp != NULL)
      {
if (temp->AT < min)
 {
   running = temp;
   min = temp->AT;
   if (temp->AT != trav->AT)
     {
trav = trav->next;
     }
 }
else if (temp->AT == min)
 {
   min = temp->AT;

   if (trav->BT < temp->BT)
     {
running = trav;
     }
   else if (trav->BT > temp->BT)
     {
running = temp;
     }
   else if (trav->BT == temp->BT)
     {
if (trav->process_id < temp->process_id)
 {
   running = trav;
 }
else if (trav->process_id > temp->process_id)
 {
   running = temp;
 }

else if (trav->process_id == temp->process_id)
 {
   running = temp;
 }


     }


 }

temp = temp->next;
     
         
      }
   

    temp = running;
     g1.push_back(temp->process_id);
  int count=1;
      node *x1=head;
      while(x1!=temp)
      {
         x1=x1->next;
         count++;
      }
   
    int pos = count;
   if(temp==head)
          {
             
             if(temp->next==NULL)
             {
                 cout<<endl;
                   for (auto i = g1.begin(); i != g1.end(); ++i)
        cout <<"P"<< *i << " ";
             }
            head=temp->next;
            x=1;
            free(temp);

          }
       
 

    else
      {
  while (i < pos - 1)
      {

temp2 = temp2->next;
i++;

      }
   

next_node = temp2->next;

temp2->next = next_node->next;
free(next_node);
      }
   
   
   
   
       
   }
   
   
   //code for Priority Scheduling
   
  //  int x;
//   void priority ()
//   {
//     int i = 1;
//     int n;
//     node *temp = head;
//     node *running;
//     node *trav = head;
//     node *temp2 = head;
//     node *next_node;

//     n = temp->priority;
//     while (temp != NULL)
//       {
// if (temp->priority > n)
//  {
//    running = temp;
//    n = temp->priority;
//    if (temp->priority != trav->priority)
//      {
// trav = trav->next;
//      }
//  }
// else if (temp->priority == n)
//  {
//    n = temp->priority;

//    if (trav->BT < temp->BT)
//      {
// running = trav;
//      }
//    else if (trav->BT > temp->BT)
//      {
// running = temp;
//      }
//    else if (trav->BT == temp->BT)
//      {
// if (trav->process_id < temp->process_id)
//  {
//    running = trav;
//  }
// else if (trav->process_id > temp->process_id)
//  {
//    running = temp;
//  }

// else if (trav->process_id == temp->process_id)
//  {
//    running = temp;
//  }


//      }


//  }

// temp = temp->next;
     
         
//       }
   

//     Running* = new Running;
//           x->process_id = temp->process_id;
//     x->AT = temp->AT;
//     x->BT = temp->BT;
//     x->state = "Running";
//     x->priority = temp->priority;
     
//         x->nextR = headR;

//         headR = x;
   
   
//      g1.push_back(temp->process_id);
//   int count=1;
//       node *x1=head;
//       while(x1!=temp)
//       {
//          x1=x1->next;
//          count++;
//       }
   
//     int pos = count;
//   if(temp==head)
//           {
             
//              if(temp->next==NULL)
//              {
//                  cout<<endl;
//                   for (auto i = g1.begin(); i != g1.end(); ++i)
//         cout <<"P"<< *i << " ";
//              }
//             head=temp->next;
//             x=1;
//             free(temp);

//           }
       
 

//     else
//       {
//   while (i < pos - 1)
//       {

// temp2 = temp2->next;
// i++;

//       }
   

// next_node = temp2->next;

// temp2->next = next_node->next;
// free(next_node);
//       }
   
   
   
//   }
   
   
};

int main ()
    {
linked_list a;
      int AT, BT, priority;
           cout<<endl<<endl;
  int choice,choicey;
      cout<<"\t          ******        "<<endl;
      cout<<"\t       Welcome to Our Project   "<<endl;
      cout<<"\t          ******        "<<endl<<endl<<endl;
      cout<<"Press 1 for Process Management"<<endl;
      cout<<"Press 2 for Memory Management"<<endl;
      cout<<"Press 3 for I/O Management"<<endl;
      cout<<"Press 4 for Other Operations"<<endl;
  cout<<"Press 5 for Exit"<<endl<<endl<<endl<<endl;
      cout<<"Enter Your Choice: ";
      cin>>choice;
      cout<<endl<<endl;
      while (!choice)
            {
              cin.clear();
              cin.ignore();
              cout<<"Enter Correct Type/Format: "<<endl;
              cin >> choice;
            }
            switch(choice)
       {
      case 1:
  {
 
  while(1){
   cout<<" You Selected 1"<<endl;
   cout<<"               So,   "<<endl;
 cout<<"                Now We Are In Process Management  "<<endl<<endl;

 while(1){
 
  cout << "Press 1 to Create a process" << endl;
  cout << "Press 2 to Destroy a process" << endl;
  cout << "Press 3 to Dispath a process" << endl;
  cout << "Press 4 to Suspend a process" << endl;
  cout << "Press 5 to Resume a process" << endl;
  cout << "Press 6 to Block a process" << endl;
  cout << "Press 7 to Wakeup a process" << endl;
  cout << "Presss 8 to Change process priority a process" << endl;
  cout << "Press 9 to Process communication with other processes a process" << endl;
  cout << "Press 10 to Perform First Come First Serve" << endl;
  cout << "Press 11 to Perform priority Scheduling" << endl;
  cout << "Press 12 to Exit" <<endl;
  int process;
  int choice;
 
  cout<<endl;
  cout<<"Enter choice :";
  cin>>choice;
  cout<<endl;



  if(choice==1)
  {
  cout << "Enter amount of processes you want to enter :" << endl;
  cin >> process;
  cout<<endl;
  string state="created";
 int process_id;
  for (int i = 0; i < process; i++)
    {
      cout << "Enter process_id ";
      cin >> process_id;
      cout << " Arrival Time :";
      cin >> AT;
      cout << " Burst Time :";
      cin >> BT;
      cout << " Priority :";
      cin >> priority;
      cout << endl;
      a.create_process (process_id, AT, BT, priority,state);
    }
}
else if(choice==2)
{
   int pid;
   cout<<"Enter Process ID :";
   cin>>pid;
   a.Destroy(pid);
   cout<<endl;
   cout<<"Process "<<pid<<" is destroyed"<<endl;
   cout<< "For Now There Is :"<<endl;
   a.display();
   cout<<endl;
   
}
else if(choice==3)
{
   int pid;
   cout<<"Enter Process ID :";
   cin>>pid;
   cout <<"Processes in ready Qeue are :"<<endl;
   a.display();
   a.Ready(pid);
   cout<<"Process "<<pid<<" Before DISPATCHED"<<endl;
   a.Display_Process(pid);
   a.Running_s(pid);
   cout<<endl;
   cout<<"Process "<<pid<<" After DISPATCHED "<<endl;
   cout<< "It Is Now :"<<endl;
   a.Display_Process_s(pid);
   cout<<endl;
}
else if(choice==4)
{
  int pid;
  cout<<"Enter Process ID :";
  cin>>pid;
  a.Running_s(pid);
  cout<<"Process "<<pid<<" Before SUSPEND"<<endl;
  a.Display_Process_s(pid);
  a.Suspend_u(pid);
  cout<<endl;
  cout<<"Process "<<pid<<" After SUSPEND "<<endl;
  cout<< "It Is Now :"<<endl;
  a.Display_Process_u();
  cout<<endl;
   
}
else if(choice==5)
{
  a.Resume_k();
  cout<<endl;
  cout<<"Process Before WAKEUP"<<endl;
  a.display();
  cout<<endl;
   
}
else if(choice==6)
{
  int pid;
  cout<<"Enter Process ID :";
  cin>>pid;
  a.Running_s(pid);
  cout<<"Process "<<pid<<" Before BLOCKED"<<endl;
  a.Display_Process_s(pid);
  a.Waiting_v(pid);
  cout<<endl;
  cout<<"Process "<<pid<<" After BLOCKED "<<endl;
  cout<< "It Is Now :"<<endl;
  a.Display_Process_v();
  cout<<endl;
}
else if(choice==7)
{
  a.Wakeup_q();
  cout<<endl;
  cout<<"Process Before WAKEUP"<<endl;
  a.display();
  cout<<endl;
}
else if(choice==8)
{
    cout << " To Change process priority a process " ;
    cout << endl;
}
else if(choice==9)
{
    cout << " To Process communication with other processes a process " ;
    cout << endl;
}
else if(choice==10)
{
  a.display ();
  for (int i = 0; i <= process  ; i++)
    {
      cout << endl;
      a.fcfs ();
      cout << endl;
    //   a.display ();

    }
}    

else if(choice==11)
{
{
  a.display ();
  for (int i = 0; i <= process  ; i++)
    {
      cout << endl;
  //    a.priority ();
      cout << endl;
    //  a.display ();

    }
}
}
else if(choice==12)
{
  return 0;
}

 }
}
  }
    break;
   
    case 2:
    {
    cout<<" You Selected 2"<<endl;
          cout<<"               So,   "<<endl;
    cout<<"                 Now We Are In Memory Management    "<<endl<<endl<<endl;
}
 break;
 
 case 3:
  {
  cout<<" You Selected 3"<<endl;
              cout<<"               So,   "<<endl;
  cout<<"                 Now We Are In I/O Management      "<<endl<<endl<<endl;

 }
 break;
 
 case 4:
  {
  cout<<" You Selected 4"<<endl;
                  cout<<"               So,   "<<endl;
  cout<<"                 Now We Are In Other Operations      "<<endl<<endl<<endl;

 }
 break;
 
 case 5:
  {
  cout<<"We are going to Exit From System"<<endl;
cout<<"       Allah Hafiz "<<endl;
cout<<"           TC      "<<endl<<endl<<endl;
  return 0;
 }
                default:
                       cout<<"Invalid Choice, Please Enter Right Chocie"<<endl;
                      break;
   
            }
   
                                cout<<"If you want to perform any other function: Press 0"<<endl;
                           cout<<"\tOtherwise Press Any Integer to exit "<<endl ;
                           cin>>choice;
                           if(choice==0)
                            {
                            system("pause");
                                main();
}
    return 0;
}