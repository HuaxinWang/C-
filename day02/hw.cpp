#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct StuNode
{
	int iId;
	char caName[32];
	float fScore;
	struct StuNode *pNext;
};

struct StuList
{
	StuNode *pFirstNode;
	int iLen;
};

StuNode *makeStuNode()
{
	StuNode *node = (StuNode *)malloc(sizeof(StuNode));
	memset(node, 0, sizeof(StuNode));
	return node;
}

StuList *makeStuList()
{
	StuList *list = (StuList *)malloc(sizeof(StuList));
	memset(list, 0, sizeof(StuList));
	return list;
}

void insertStuList(StuList *list, StuNode *node)
{
	if (NULL == list || NULL == node)
	{
		return;
	}
	node->pNext = list->pFirstNode;
	list->pFirstNode = node;
	list->iLen++;
}

void showStuList(const StuList *list)
{
	if (NULL == list)
	{
		return;
	}
	StuNode *node = list->pFirstNode;
	while (NULL != node)
	{
		cout << "id:" << node->iId 
			 << " name:" << node->caName
			 << " score:" << node->fScore << endl;
		node = node->pNext;
	}
}

void sortStuList(StuList *list)
{
	if (NULL == list)
	{
		return;
	}

	StuNode *cur = NULL;
	StuNode *curNext = NULL;
	StuNode *pre = NULL;
	int i = 0;
	for (; i < list->iLen-1; i++)
	{
		cur = list->pFirstNode;
		curNext = cur->pNext;
		pre = cur;	
		for (; NULL != cur && NULL != curNext;)
		{
			if (cur->fScore < curNext->fScore)
			{
				if (cur == list->pFirstNode)
				{
					cur->pNext = curNext->pNext;
					curNext->pNext = cur;
					list->pFirstNode = curNext;
				}		
				else
				{
					cur->pNext = curNext->pNext;
					curNext->pNext = cur;
					pre->pNext = curNext;
				}
				pre = curNext;
				curNext = cur->pNext;
			}
			else
			{
				pre = cur;
				cur = cur->pNext;
				curNext = cur->pNext;
			}
		}
	}
}


void mergeStuList(StuList *list1, StuList *list2)
{
	if (NULL == list1 || NULL == list2)
	{
		return;
	}

	StuNode *pre1 = list1->pFirstNode;
	StuNode *cur1 = pre1;
	
	StuNode *cur2 = list2->pFirstNode;
	StuNode *tmp = NULL;
	for (; NULL != cur1 && NULL != cur2;)
	{
		if (cur1->fScore <= cur2->fScore)
		{
			tmp = cur2->pNext;
			if (cur1 == list1->pFirstNode)
			{
				cur2->pNext = cur1;
				list1->pFirstNode = cur2;
			}
			else
			{
				cur2->pNext = cur1;
				pre1->pNext = cur2;
			}	
			pre1 = cur2;
			cur2 = tmp;
		}
		else
		{
			pre1 = cur1;
			cur1 = cur1->pNext;
		}
	}
}


int main(void)
{
	StuList *list = makeStuList();
	StuNode *node = makeStuNode();
	node->iId = 1000;
	strcpy(node->caName, "aa");
	node->fScore = 89;
	insertStuList(list, node);
	
	node = makeStuNode();
	node->iId = 1001;
	strcpy(node->caName, "bb");
	node->fScore = 69;
	insertStuList(list, node);
	
	node = makeStuNode();
	node->iId = 1002;
	strcpy(node->caName, "cc");
	node->fScore = 79;
	insertStuList(list, node);
	
	node = makeStuNode();
	node->iId = 1003;
	strcpy(node->caName, "dd");
	node->fScore = 99;
	insertStuList(list, node);

	showStuList(list);
	cout << "---------------------------\n";
	sortStuList(list);
	showStuList(list);
	cout << "-----------list2----------------\n";

	StuList *list2 = makeStuList();
	StuNode *node2 = makeStuNode();
	node2->iId = 1004;
	strcpy(node2->caName, "ee");
	node2->fScore = 78;
	insertStuList(list2, node2);
	
	node2 = makeStuNode();
	node2->iId = 1005;
	strcpy(node2->caName, "ff");
	node2->fScore = 89;
	insertStuList(list2, node2);
	
	node2 = makeStuNode();
	node2->iId = 1006;
	strcpy(node2->caName, "gg");
	node2->fScore = 69;
	insertStuList(list2, node2);
	
	showStuList(list2);
	cout << "---------------------------\n";
	sortStuList(list2);
	showStuList(list2);

	cout << "------------merge--------------\n";
	mergeStuList(list, list2);
	sortStuList(list);



	return 0;
}
