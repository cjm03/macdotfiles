
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node ListNode;
typedef int ListData;
typedef struct _Node { ListNode* pNext; ListData* pData; } ListNode;
typedef struct { ListNode* pFirstNode; int nodeCount; } LinkedList;
typedef enum { eLook, eInsert, eDelete } eAction;
typedef enum { eFront, eBack } eWhere;

LinkedList* CreateLinkedList();
bool        IsEmpty(LinkedList* pList);
int         Size(LinkedList* pList);
void        InsertNodeToFront(LinkedList* pList, ListNode* pNode);
void        InsertNodeToBack(LinkedList* pList, ListNode* pNode);
ListNode*   RemoveNodeFromFront(LinkedList* pList);
ListNode*   RemoveNodeFromBack(LinkedList* pList);
ListNode*   GetNode(LinkedList* pList, int pos);
ListNode*   CreateNode(ListData* pData);
void        DeleteNode(ListNode* pNode);
void        PrintList(LinkedList* pList, void(*printDdata)(ListData* pData));
void        PrintNode(ListNode* pNode, void(*printDdata)(ListData* pData));
void        (*printData) (ListData* pData);
void        PrintInt(ListData* pData);
ListNode*   InsertNodeAt(LinkedList* pList, ListNode* pNode);
ListNode*   RemoveNodeAt(LinkedList* pList, ListNode* pNode);
//void        SortList(LinkedList* pList, eSortOrder order);
void        ConcatenateList(LinkedList* pList1, LinkedList* pList2);
void        TestPrintOperation(LinkedList* pLL, eAction action, ListData data, eWhere where);
void        TestCreateNodeAndInsert(LinkedList* pLL, ListData data, eWhere where);
ListData    TestExamineNode(LinkedList* pLL, eWhere where);
ListData    TestRemoveNodeAndFree(LinkedList* pLL, eWhere where);
void        OutOfStorage(void);
