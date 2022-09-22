#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE {
    char szData[64];
    struct NODE* next;
} NODE;

NODE g_head = { 0 };


void PrintList(void)
{
    NODE* pHead = g_head.next;
    while (pHead != NULL)
    {
        printf("[%p] %s, next[%p]\n",
               pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }

    putchar('\n');
}

int IsEmpty()
{
    if (g_head.next == NULL)
        return 1;

    return 0;
}

int InsertAtHead(char* pszData)
{
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));

    strcpy(pNode->szData, pszData);

    if (IsEmpty())
        g_head.next = pNode;
    else {
        pNode->next = g_head.next;
        g_head.next = pNode;
    }

    return 1;
}

int InsertAtTail(char* pszData)
{
    NODE* pTmp = &g_head;
    while (pTmp->next != 0)
        pTmp = pTmp->next;

    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strcpy(pNode->szData, pszData);

    pTmp->next = pNode;
}


void ReleaseList(void)
{
    printf("\nReleaseList()\n");
    NODE* pTmp = g_head.next;
    while (pTmp != NULL) {
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;
        printf("Delete: [%p] %s\n", pTmp, pTmp->szData);
        printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
        free(pDelete);
    }
    g_head.next = NULL;
}

NODE* FindData(char* pszData)
{
    NODE* pCur = g_head.next;
    NODE* pPrev = &g_head;
    while (pCur != NULL)
    {
        if (strcmp(pCur->szData, pszData) == 0)
            return pPrev;
        pCur = pCur->next;
        pPrev = pPrev->next;
    }

    return 0;
}


int DeleteData(char* pszData)
{
    NODE* pPrev = FindData(pszData);
    if (pPrev != NULL) {
        NODE *pDelete = pPrev->next;
        pPrev->next = pDelete->next;

        printf("DeleteData(): %s\n", pDelete->szData);
        free(pDelete);
        return 1;
    }
    return 0;
}


int main()
{
    puts("*** InsertAtHead() ***");
    InsertAtHead("TEST01");
    InsertAtHead("TEST02");
    InsertAtHead("TEST03");
    PrintList();

    putchar('\n');

    DeleteData("TEST01");
    PrintList();
    DeleteData("TEST02");
    PrintList();
    DeleteData("TEST03");
    PrintList();

    puts("*** InsertAtTail() ***");
    InsertAtTail("TEST01");
    InsertAtTail("TEST02");
    InsertAtTail("TEST03");
    PrintList();

    putchar('\n');

    DeleteData("TEST01");
    PrintList();
    DeleteData("TEST02");
    PrintList();
    DeleteData("TEST03");
    PrintList();

    ReleaseList();
    return 0;
}