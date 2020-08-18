#include<iostream>
#include <algorithm>
#include<cstdlib>
#include<vector>
using namespace std;

typedef long long llint;

// Node Declaration
struct node
{
    int info;
    node *next;
    node *prev;
    node(int number = 0){
        next = prev = NULL;
        info = number;
    }
};

/*class double_clist
{
    public:
        node *create_node(int);
        void insert_begin();
        void insert_last(int);
        void insert_pos();
        void delete_pos(int);
        void search();
        void update();
        void display();
        void reverse();
        void sort();
        double_clist()
        {
            start = NULL;
            last = NULL;
        }
};


int counter = 0, clock = 1;
*/

int main(){

    //double_clist cdl;
    node* p;
    int i, k, n;

    cin >> n >> k;
    p = new node(1);
    node* first = p;
    for (int i = 2; i <= n; i++){
        node* new_node = new node(i);
        p->next = new_node;
        new_node->prev = p;
        p = new_node;
    }
    p->next = first;
    first->prev = p;

    node* cur = first;

    for (i=1; i<n; i++)
    {
        if (cur->info % 2 == 1){
            for (int j = 1; j <= k; j++)
                cur = cur->next;
        } else {
            for (int j = 1; j <= k; j++)
                cur = cur->prev;
        }

        node* badi = cur->next;
        node* ghabli = cur->prev;

        badi->prev = ghabli;
        ghabli->next = badi;

        cur = badi;
    }

    cout << cur->info;
//    while(counter>1)
//    {
//        if
//    }




}

/*
 *MEMORY ALLOCATED FOR NODE DYNAMICALLY
 */
 /*
node* double_clist::create_node(int value)
{
    counter++;
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void double_clist::insert_last(int value)
{
    struct node *temp;
    temp = create_node(value);
    if (start == last && start == NULL)
    {

        start = last = temp;
        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
        start->prev = last;
        last->next = start;
    }
}


void double_clist::delete_pos(int pos)
{
    int i;
    node *ptr, *s;
    if (start == last && start == NULL)
    {
        cout<<"List is empty, nothing to delete"<<endl;
        return;
    }
//    cout<<endl<<"Enter the postion of element to be deleted: ";
//    cin>>pos;
    if (counter < pos)
    {
        cout<<"Position out of range"<<endl;
        return;
    }
    s = start;
    if(pos == 1)
    {
        counter--;
        last->next = s->next;
        s->next->prev = last;
        start = s->next;
        free(s);
        cout<<"Element Deleted"<<endl;
        return;
    }
    for (i = 0;i < pos - 1;i++ )
    {
        s = s->next;
        ptr = s->prev;
    }
    ptr->next = s->next;
    s->next->prev = ptr;
    if (pos == counter)
    {
        last = ptr;
    }
    counter--;
    free(s);
//    cout<<"Element Deleted"<<endl;
} */
