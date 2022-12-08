#include <iostream>
#include <sys/time.h>
using namespace std;

// fuction to get time
long getTimeinMicrosecond()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
};
// Linear Queue using array
int queue[100], n = 100, front = -1, rear = -1;
int stack[100], top = -1;
// Defined for Array Priority Queue
#define N 20

int Q[N], Pr[N];
int r = -1, f = -1;

class NodeStacks
{
public:
    int data;
    NodeStacks *link;

    NodeStacks(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};

void array_display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

class Stack

{
    NodeStacks *top;

public:
    Stack() { top = NULL; }

    void push(int data)
    {

        NodeStacks *temp = new NodeStacks(data);

        if (!temp)
        {
            cout << "\nStack Overflow";
            exit(1);
        }

        temp->data = data;

        temp->link = top;

        top = temp;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    int peek()
    {
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }

    void pop()
    {
        NodeStacks *temp;

        if (top == NULL)
        {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else
        {

            temp = top;

            top = top->link;

            free(temp);
        }
    }

    void display()
    {
        NodeStacks *temp;

        if (top == NULL)
        {
            cout << "\nStack Underflow";
            exit(1);
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {

                cout << temp->data;

                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};

struct Queuenode
{
    int data;
    struct Queuenode *next;
};
struct Queuenode *Front = NULL;
struct Queuenode *Rear = NULL;
struct Queuenode *Temp;

struct DLL_node
{
    struct DLL_node *prev;
    struct DLL_node *next;
    int data;
};
struct DLL_node *head;

struct CLLnode
{
    int data;
    struct CLLnode *next;
};
struct CLLnode *CLL_head;

void Linked_Insert()
{

    long starttime, endtime;
    starttime = getTimeinMicrosecond();

    int val;
    cout << "Insert the element in queue : " << endl;
    cin >> val;
    if (Rear == NULL)
    {
        Rear = (struct Queuenode *)malloc(sizeof(struct Queuenode));
        Rear->next = NULL;
        Rear->data = val;
        Front = Rear;
    }
    else
    {
        Temp = (struct Queuenode *)malloc(sizeof(struct Queuenode));
        Rear->next = Temp;
        Temp->data = val;
        Temp->next = NULL;
        Rear = Temp;
    }

    endtime = getTimeinMicrosecond();
    cout << "\nTime Taken is " << endtime - starttime << " microsecond" << endl;
}

void Linked_Delete()
{

    long starttime, endtime;
    starttime = getTimeinMicrosecond();
    Temp = Front;
    if (Front == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else if (Temp->next != NULL)
    {
        Temp = Temp->next;
        cout << "Element deleted from queue is : " << Front->data << endl;
        free(Front);
        Front = Temp;
    }
    else
    {
        cout << "Element deleted from queue is : " << Front->data << endl;
        free(Front);
        Front = NULL;
        rear = NULL;
    }
    endtime = getTimeinMicrosecond();
    cout << "\nTime Taken is " << endtime - starttime << " microsecond" << endl;
}

void Linked_Display()
{

    long starttime, endtime;
    starttime = getTimeinMicrosecond();

    Temp = Front;
    if ((Front == NULL) && (Rear == NULL))
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    while (Temp != NULL)
    {
        cout << Temp->data << " ";
        Temp = Temp->next;
    }
    cout << endl;

    endtime = getTimeinMicrosecond();
    cout << "\nTime Taken is " << endtime - starttime << " microsecond" << endl;
}

class SLL_node
{
public:
    int data;
    SLL_node *next;

    SLL_node(int value)
    {

        data = value;

        next = NULL;
    }
};

void SLL_insertathead(SLL_node *&head, int val)
{
    SLL_node *n = new SLL_node(val);
    n->next = head;
    head = n;
}

void SLL_insertafter(SLL_node *head, int key, int val)
{
    SLL_node *n = new SLL_node(val);
    if (key == head->data)
    {
        n->next = head->next;
        head->next = n;
        return;
    }

    SLL_node *temp = head;
    while (temp->data != key)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            return;
        }
    }
    n->next = temp->next;
    temp->next = n;
}

void SLL_insertattail(SLL_node *&head, int val)
{
    SLL_node *n = new SLL_node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    SLL_node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void SLL_print(SLL_node *&head)
{
    SLL_node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int linearSearch_array(int arr[], int n, int x)
{
    // int x;
    // cout<<"Enter the element to be searched"<<endl;
    // cin>>x;

    for (int i = 0; i < n; i++)
    {
        if (x == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int minElement_array(int arr[], int n)
{

    int smallest = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    return smallest;
}

int maxElement_array(int arr[], int n)
{

    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        };
    }
    return max;
}

void Bubble_sort(int a[], int n)
{

    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "Sorted using Bubble Sort :" << endl;
    cout << "It's Worst Time Complexity is : O(n^2) " << endl;
};

int partition(int a[], int start, int end)
{
    int pivot = a[end]; // pivot element
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {
        // If current element is smaller than the pivot
        if (a[j] < pivot)
        {
            i++; // increment index of smaller element
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[end];
    a[end] = t;
    return (i + 1);
}

void quick(int a[], int start, int end ) /* a[] = array to be sorted, start = Starting index, end = Ending index */
{
    if (start < end)
    {
        int p = partition(a, start, end); // p is the partitioning index
        quick(a, start, p - 1);
        quick(a, p + 1, end);
    }
  
}

void Merge(int *a, int low, int high, int mid)
{

    int i, j, k, temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}

void MergeSort(int *a, int high, int low = 0)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);

        Merge(a, low, high, mid);
    }
    cout << "Sorted using Merge Sort :" << endl;
    cout << "It's Worst Time Complexity is : O(nlogn) " << endl;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "Sorted using Insertion Sort :" << endl;
    cout << "It's Worst Time Complexity is : O(n^2) " << endl;
}

void sorting(int a[], int n)
{

    long starttime, endtime;
    cout << "What type of sorting Algorithm you want to ise :" << endl;
    cout << "1  --> Bubble sort" << endl;
    cout << "2  --> Quick sort" << endl;
    cout << "3  --> Insertion sort" << endl;
    cout << "4  --> Merge Sort" << endl;

    int choice1;
    cout << "Enter your choice " << endl;
    cin >> choice1;

    starttime = getTimeinMicrosecond();

    switch (choice1)
    {
    case 1:
        Bubble_sort(a, n);
        break;

    case 2:
        quick(a,0, n-1);
          cout << "Sorted using Quick Sort :" << endl;
          cout << "Time Complexity : O(n^2) " << endl;

        break;

    case 3:
        insertionSort(a, n);
        break;

    case 4:
        MergeSort(a, n - 1);
        break;
    }
}

void InsertinQueue_array()
{
    int val;
    if (rear == n - 1)
        cout << "Queue Overflow" << endl;
    else
    {
        if (front == -1)
            front = 0;
        cout << "Insert the element in queue : " << endl;
        cin >> val;
        rear++;
        queue[rear] = val;
    }
}

void DeleteFromQueue_array()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow ";
        return;
    }
    else
    {
        cout << "Element deleted from queue is : " << queue[front] << endl;
        front++;
        ;
    }
}

void Displayqueue_array()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue elements are : ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int LinearQueue_array()
{
    int queue[100], n = 100, front = -1, rear = -1;
    int ch;
    cout << "1) Insert element to queue" << endl;
    cout << "2) Delete element from queue" << endl;
    cout << "3) Display all the elements of queue" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            InsertinQueue_array();
            break;
        case 2:
            DeleteFromQueue_array();
            break;
        case 3:
            Displayqueue_array();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch != 4);
    return 0;
}

void CircularQueueEnqueue_array(int element, int max = 5)
{
    if (front == -1 && rear == -1) // condition to check queue is empty
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % max == front) // condition to check queue is full
    {
        printf("Queue is overflow..");
    }
    else
    {
        rear = (rear + 1) % max; // rear is incremented
        queue[rear] = element;   // assigning a value to the queue at the rear position.
    }
}

int CircularQueueDequeue_array(int max = 5)
{
    if ((front == -1) && (rear == -1)) // condition to check queue is empty
    {
        printf("\nQueue is underflow..");
    }
    else if (front == rear)
    {
        printf("\nThe dequeued element is %d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nThe dequeued element is %d", queue[front]);
        front = (front + 1) % max;
    }
}

void CirularQueueDisplay_array(int max = 5)

{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty..");
    }
    else
    {
        printf("\nElements in a Queue are :");
        while (i <= rear)
        {

            printf("%d,", queue[i]);
            i = (i + 1) % max;
        }
    }
}

int Prioritydequeue_array()
{
    if (f == -1)
    {
        cout << "Queue is Empty";
    }
    else
    {
        cout << "deleted Element =" << Q[f] << endl;
        cout << "Its Priority = " << Pr[f] << endl;
        if (f == r)
            f = r = -1;
        else
            f++;
    }
}

void Priorityenqueue_array(int data, int p)
{
    int i;
    if ((f == 0) && (r == N - 1)) // Check if Queue is full
        cout << "Queue is full";
    else
    {
        if (f == -1) // if Queue is empty
        {
            f = r = 0;
            Q[r] = data;
            Pr[r] = p;
        }
        else if (r == N - 1) // if there there is some elemets in Queue
        {
            for (i = f; i <= r; i++)
            {
                Q[i - f] = Q[i];
                Pr[i - f] = Pr[i];
                r = r - f;
                f = 0;
                for (i = r; i > f; i--)
                {
                    if (p > Pr[i])
                    {
                        Q[i + 1] = Q[i];
                        Pr[i + 1] = Pr[i];
                    }
                    else
                        break;
                    Q[i + 1] = data;
                    Pr[i + 1] = p;
                    r++;
                }
            }
        }
        else
        {
            for (i = r; i >= f; i--)
            {
                if (p > Pr[i])
                {
                    Q[i + 1] = Q[i];
                    Pr[i + 1] = Pr[i];
                }
                else
                    break;
            }
            Q[i + 1] = data;
            Pr[i + 1] = p;
            r++;
        }
    }
}

void Priorityprint_array()
{
    int i;
    for (i = f; i <= r; i++)
    {
        cout << "Element =" << Q[i] << "Priority = " << Pr[i] << endl;
    }
}

int PriorityQueue_array()
{
    int opt, n, i, data, p;
    cout << "Enter Your Choice:-" << endl;
    do
    {
        cout << "1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit" << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "Enter the number of data" << endl;
            cin >> n;
            cout << "Enter your data and Priority of data" << endl;
            i = 0;
            while (i < n)
            {
                cin >> data;
                cin >> p;
                Priorityenqueue_array(data, p);
                i++;
            }
            break;
        case 2:
            Priorityprint_array();
            break;
        case 3:
            Prioritydequeue_array();
            break;
        case 0:
            break;
        default:
            cout << "Incorrect Choice" << endl;
        }
    } while (opt != 0);
    return 0;
}

int circularQueue_array()
{
    int max = 5;
    int queue[max]; // array declaration
    int front = -1;
    int rear = -1;

    int choice = 1, x; // variables declaration

    while (choice < 4 && choice != 0) // while loop
    {
        printf("\n Press 1: Insert an element");
        printf("\nPress 2: Delete an element");
        printf("\nPress 3: Display the element");
        printf("\nPress 4: exit");
        printf("\nEnter your choice");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Enter the element which is to be inserted");
            scanf("%d", &x);
            CircularQueueEnqueue_array(x);
            break;
        case 2:
            CircularQueueDequeue_array();
            break;
        case 3:
            CirularQueueDisplay_array();
        case 4:
            break;
        }
    }
}

void Stack_array_push(int val)
{
    if (top >= n - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        stack[top] = val;
    }
}

void Stack_array_pop()
{
    if (top <= -1)
        cout << "Stack Underflow" << endl;
    else
    {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}

void Stack_array_display()
{
    if (top >= 0)
    {
        cout << "Stack elements are:";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack is empty";
}

int ArrayQueue()
{
    int choice;
    cout << "What kind of Queue would you like to see " << endl;
    cout << "1 -->  linear Queue " << endl;
    cout << "2 -->  Circular Queue " << endl;
    cout << "3 -->  Priority Queue " << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        LinearQueue_array();
        break;
    case 2:
        circularQueue_array();
        break;
    case 3:
        PriorityQueue_array();
        break;
    }
}

int stacks_array()
{
    int ch, val;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            Stack_array_push(val);
            break;
        }
        case 2:
        {
            Stack_array_pop();
            break;
        }
        case 3:
        {
            Stack_array_display();
            break;
        }
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);
    return 0;
}

int stacks_Linked()
{
    Stack s;
    int ch, val;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Peek stack" << endl;
    cout << "5) Exit" << endl;
    do
    {
        cout << "\nEnter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            s.push(val);
            break;
        }
        case 2:
        {
            s.pop();
            break;
        }
        case 3:
        {
            s.display();
            break;
        }
        case 4:
        {
            s.peek();
            break;
        }
        case 5:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);
}

void CLL_beginsert()
{
    struct CLLnode *ptr, *temp;
    int item;
    ptr = (struct CLLnode *)malloc(sizeof(struct CLLnode));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter the node data : ");
        scanf("%d", &item);
        ptr->data = item;
        if (CLL_head == NULL)
        {
            CLL_head = ptr;
            ptr->next = CLL_head;
        }
        else
        {
            temp = CLL_head;
            while (temp->next != CLL_head)
                temp = temp->next;
            ptr->next = CLL_head;
            temp->next = ptr;
            CLL_head = ptr;
        }
        printf("\nnode inserted\n");
    }
}

void CLL_lastinsert()
{
    struct CLLnode *ptr, *temp;
    int item;
    ptr = (struct CLLnode *)malloc(sizeof(struct CLLnode));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Data : ");
        scanf("%d", &item);
        ptr->data = item;
        if (CLL_head == NULL)
        {
            CLL_head = ptr;
            ptr->next = CLL_head;
        }
        else
        {
            temp = CLL_head;
            while (temp->next != CLL_head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = CLL_head;
        }

        printf("\nnode inserted\n");
    }
}

void CLL_begin_delete()
{
    struct CLLnode *ptr;
    if (CLL_head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (CLL_head->next == CLL_head)
    {
        head = NULL;
        free(CLL_head);
        printf("\nnode deleted\n");
    }

    else
    {
        ptr = CLL_head;
        while (ptr->next != CLL_head)
            ptr = ptr->next;
        ptr->next = CLL_head->next;
        free(CLL_head);
        CLL_head = ptr->next;
        printf("\nnode deleted\n");
    }
}

void CLL_last_delete()
{
    struct CLLnode *ptr, *preptr;
    if (CLL_head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (CLL_head->next == CLL_head)
    {
        CLL_head = NULL;
        free(CLL_head);
        printf("node deleted\n");
    }
    else
    {
        ptr = CLL_head;
        while (ptr->next != CLL_head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("node deleted\n");
    }
}

void CLL_display()
{
    struct CLLnode *ptr;
    ptr = CLL_head;
    if (CLL_head == NULL)
    {
        printf("\nnothing to print ");
    }
    else
    {
        printf("Printing values \n");

        while (ptr->next != CLL_head)
        {

            printf("%d\n ->", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}

void DLL_insertion_beginning()
{
    struct DLL_node *ptr;
    int item;
    ptr = (struct DLL_node *)malloc(sizeof(struct DLL_node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Item value \n");
        scanf("%d", &item);

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = item;
            head = ptr;
        }
        else
        {
            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\nNode inserted\n");
    }
}

void DLL_insertion_last()
{
    struct DLL_node *ptr, *temp;
    int item;
    ptr = (struct DLL_node *)malloc(sizeof(struct DLL_node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
    printf("\node inserted\n");
}

void DLL_insertion_specified()
{
    struct DLL_node *ptr, *temp;
    int item, loc, i;
    ptr = (struct DLL_node *)malloc(sizeof(struct DLL_node));
    if (ptr == NULL)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        temp = head;
        printf("Enter the location");
        scanf("%d", &loc);
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\n There are less than %d elements", loc);
                return;
            }
        }
        printf("Enter value");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
        printf("\nnode inserted\n");
    }
}

void DLL_deletion_beginning()
{
    struct DLL_node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
}

void DLL_deletion_last()
{
    struct DLL_node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        printf("\n node deleted\n");
    }
}

void DLL_deletion_specified()
{
    struct DLL_node *ptr, *temp;
    int val;
    printf("\n Enter the data after which the DLL_node is to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    while (ptr->data != val)
        ptr = ptr->next;
    if (ptr->next == NULL)
    {
        printf("\nCan't delete\n");
    }
    else if (ptr->next->next == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        printf("\nnode deleted\n");
    }
}

void DLL_display()
{
    struct DLL_node *ptr;
    printf("\n printing values \n");
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int Singly_linked_list()
{
    SLL_node *head = NULL;

    int ch, val, val1, val2;
    cout << "1) Insert At head" << endl;
    cout << "2) Insert After" << endl;
    cout << "3) Print " << endl;
    cout << "4) Exit" << endl;

    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be inserted:" << endl;
            cin >> val;
            SLL_insertattail(head, val);
            break;
        }
        case 2:
        {
            cout << "Enter value to be inserted:" << endl;
            cin >> val1;
            cout << "Enter the value after which it has to be inserted:" << endl;
            cin >> val2;
            SLL_insertafter(head, val2, val1);
            break;
        }
        case 3:
        {
            SLL_print(head);
            break;
        }

        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
            cout << "Please Enter a valid Choice ";
        }
    } while (ch != 4);
};

int circular_linked_list()
{
    int choice = 0;
    printf("\nChoose one option from the following list ...\n");
    printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Display\n6.Exit\n");
    while (choice != 6)
    {
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            CLL_beginsert();
            break;
        case 2:
            CLL_lastinsert();
            break;
        case 3:
            CLL_begin_delete();
            break;
        case 4:
            CLL_last_delete();
            break;
        case 5:
            CLL_display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
};

int Doubly_linked_list()
{
    int choice = 0;
    printf("\nChoose one option from the following list \n");
    printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at specified position\n4.Delete From Beginning\n5.Delete from last\n6.Delete from Specified Position\n7.Show\n8.Exit\n");
    while (choice != 7)
    {
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            DLL_insertion_beginning();
            break;
        case 2:
            DLL_insertion_last();
            break;
        case 3:
            DLL_insertion_specified();
            break;
        case 4:
            DLL_deletion_beginning();
            break;
        case 5:
            DLL_deletion_last();
            break;
        case 6:
            DLL_deletion_specified();
            break;
        case 7:
            DLL_display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Please enter valid choice ");
        }
    }
}

int LinkedQueue()
{
    int ch = 1;
    cout << "1) Insert element to queue" << endl;
    cout << "2) Delete element from queue" << endl;
    cout << "3) Display all the elements of queue" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            Linked_Insert();
            break;
        case 2:
            Linked_Delete();
            break;
        case 3:
            Linked_Display();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Please Enter a valid Choice ";
        }
    } while (ch != 4);
    return 0;
}

int array()
{
    int n;
    int arr[100];
    int choice2, size;

    cout << "Enter the size of array" << endl;
    cin >> n;

    cout << "Enter the element" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    };
    cout << "1 --> linear Search" << endl;
    cout << "2 --> Max Element" << endl;
    cout << "3 --> Min Element" << endl;
    cout << "4 --> Sorting" << endl;

    cin >> choice2;
    switch (choice2)
    {
        cout << "Enter your choice" << endl;
    case 1:
        cout << "Enter the number to be searched " << endl;
        cin >> size;
        cout << linearSearch_array(arr, n, size);
        break;
    case 2:
        cout << "Maximum Element is : " << maxElement_array(arr, n);
        break;

    case 3:
        cout << "Minimum Element is : " << minElement_array(arr, n);
        break;
    case 4:
        sorting(arr, n);
        array_display(arr, n);
        break;
    default:
        cout << "Please Enter a valid Choice ";
    }
}

int Queue()
{
    int choice;
    cout << "What kind of Queue would you like to see " << endl;
    cout << "1 -->  Array implementation of queue " << endl;
    cout << "2 -->  Linked List implementation of queue " << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        ArrayQueue();
        break;

    case 2:
        LinkedQueue();
        break;
    default:
        cout << "Please Enter a valid Choice ";
    }
}

int stacks()
{
    int choice;
    cout << "what implementation of stack would you like to see : " << endl;
    cout << "1 --> Array " << endl;
    cout << "2 --> Linked List " << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        stacks_array();
        break;
    case 2:
        stacks_Linked();
        break;
    default:
        cout << "Please Enter a valid Choice ";
    }
}

int LinkedList()
{
    cout << "What implementation would you like to see : " << endl;
    cout << "1  --> Singly Linked list" << endl;
    cout << "2  --> Circular Linked List" << endl;
    cout << "3  --> Doubly Linked List" << endl;

    int choice1;
    cout << "Enter your choice " << endl;
    cin >> choice1;

    switch (choice1)
    {
    case 1:
        Singly_linked_list();
        break;

    case 2:
        circular_linked_list();
        break;

    case 3:
        Doubly_linked_list();
        break;
    default:
        cout << "Please Enter a valid Choice ";
    }
}

int main()
{

cout<<"Name          : NIDHI CHAUDHARY "<<endl;
cout<<"Roll Number   : 10901012021 "<<endl;
cout<<"COurse        : Btech Cse  "<<endl;

    long starttime, endtime;
    cout << "What implementation would you like to see : " << endl;
    cout << "1  --> Array" << endl;
    cout << "2  --> Queue" << endl;
    cout << "3  --> Stack" << endl;
    cout << "4  --> Linked List" << endl;

    int choice1;
    cout << "Enter your choice " << endl;
    cin >> choice1;

    starttime = getTimeinMicrosecond();

    switch (choice1)
    {
    case 1:
        array();
        break;

    case 2:
        Queue();
        break;

    case 3:
        stacks();
        break;

    case 4:
        LinkedList();
        break;
    default:
        cout << "Please Enter a valid Choice ";
    };
    endtime = getTimeinMicrosecond();
    cout << "\nTime Taken is " << endtime - starttime << " microsecond" << endl;
}
