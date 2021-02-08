#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

int main()
{
    int T, n1, n2, n3;
    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

int len(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

int go(Node *head1, Node *head2, int diff)
{
    Node *p1 = head1, *p2 = head2;
    while (diff--)
    {
        if (p1 == NULL)
            return -1;
        p1 = p1->next;
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (p1 == p2)
            return p1->data;
        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
}

int intersectPoint(Node *head1, Node *head2)
{
    int len1 = len(head1);
    int len2 = len(head2);
    int diff, y1, y2;
    if (len1 > len2)
    {
        diff = len1 - len2;
        y1 = go(head1, head2, diff);
        return y1;
    }
    else
    {
        diff = len2 - len1;
        y2 = go(head2, head1, diff);
        return y2;
    }
}
