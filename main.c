#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *reverse(struct Node *head)
{
    struct Node *prevNode = NULL;
    struct Node *currNode = head;
    while (currNode)
    {
        struct Node *nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}
struct Node *reverseBetween(struct Node *head, int m, int n)
{
    if (m == n)
        return head;
    struct Node *revs = NULL, *revs_prev = NULL;
    struct Node *revend = NULL, *revend_next = NULL;
    int i = 1;
    struct Node *currNode = head;
    while (currNode && i <= n)
    {
        if (i < m)
        {
            revs_prev = currNode;
        }
        if (i == m)
        {
            revs = currNode;
        }
        if (i == n)
        {
            revend = currNode;
            revend_next = currNode->next;
        }
        currNode = currNode->next;
        i++;
    }
    revend->next = NULL;
    revend = reverse(revs);
    if (revs_prev)
    {
        revs_prev->next = revend;
    }
    else
    {
        head = revend;
    }
    revs->next = revend_next;

    return head;
}
void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
struct Node *createNode(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
int main()
{
    int n, m, count, value, choice;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &count);
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < count; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node *new_node = createNode(value);
        if (!head)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }
    printf("Original list: ");
    print(head);
    do
    {
        printf("\nChoose an option:\n");
        printf("1. Reverse the entire list\n");
        printf("2. Reverse a sublist\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            head = reverse(head);
            printf("Modified list: ");
            print(head);
        }
        else if (choice == 2)
        {
            printf("Enter the start position (m): ");
            scanf("%d", &m);
            printf("Enter the end position (n): ");
            scanf("%d", &n);
            if (m < 1 || n < 1 || m > n)
            {
                printf("Invalid positions. Please try again.\n");
                continue;
            }
            head = reverseBetween(head, m, n);
            printf("Modified list: ");
            print(head);
        }
        else if (choice == 3)
        {
            printf("Exiting the program.\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}
