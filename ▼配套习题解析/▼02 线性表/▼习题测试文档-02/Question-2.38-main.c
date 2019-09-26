#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  										//**▲01 绪论**//

/* 类型定义 */
typedef int LElemType_DC;
typedef struct DuLNode					//双向链表结构体
{
	LElemType_DC data;
	struct DuLNode *prior;
	struct DuLNode *
	next;
	int freq;							//访问频度域 
}DuLNode;
typedef DuLNode* DuLinkList;		 	//指向双循环链表结构的指针 

/* 函数原型 */
int Algo_2_38(DuLinkList L, LElemType_DC e);
Status CreatList_DuL_2_38(DuLinkList *L, int n, LElemType_DC Data[]);
Status Output_DuL_2_38(DuLinkList L);

int main(int argc, char *argv[])
{
	DuLinkList L, p;
	int i;
	LElemType_DC data[10] = {1,2,3,4,5,6,7,8,9,10};
	LElemType_DC tmp[10] = {1,2,2,2,3,4,4,5,5,9}; 
	
	CreatList_DuL_2_38(&L, 10, data);
	printf("初始化的链表为L = ");
	Output_DuL_2_38(L);
	printf("\n\n");
	
	for(i=1; i<=10; i++)
		Algo_2_38(L, tmp[i-1]);
	printf("访问之后：L = ");
	Output_DuL_2_38(L);
	printf("\n");
	printf("对应访问次数：");
	for(p=L->next; p!=L; p=p->next)
		printf("%2d ", p->freq);
	printf("\n\n");

	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题2.38：定位L中元素e的位序，并按访问频度重排链表假设链表中元素不重复┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
int Algo_2_38(DuLinkList L, LElemType_DC e)
{	
	DuLinkList p, pre;
	int i;
	
	if(!L || L->next==L)				//链表不存在或链表为空 
		return 0;
	
	i = 1;
	pre = L;
	p = L->next;
	while(p!=L && p->data!=e)
	{
		i++;
		pre = p;
		p = p->next;
	}
	
	if(p!=L)							//找到了与e相等的结点 
	{
		p->freq++;
		
		while(pre!=L && pre->freq<p->freq)
		{
			i--;
			pre = pre->prior;
		}
		
		if(pre->next!=p)				//若pre位置发生改变，p位置也需要改变 
		{
			p->next->prior= p->prior;	//摘下结点p 
			p->prior->next = p->next;
			
			p->next = pre->next;		//将p插入到合适位置 
			p->prior = pre;
			pre->next->prior= p;
			pre->next = p;
		}
				
		return i;
	}
	
	return 0;
}

Status CreatList_DuL_2_38(DuLinkList *L, int n, LElemType_DC Data[])	//从无到有创建 
{
	DuLinkList s, h;
	int i;
	
	*L = (DuLinkList)malloc(sizeof(DuLNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = (*L)->prior = *L;
	
	for(i=1,h=*L; i<=n; i++)
	{
		s = (DuLinkList)malloc(sizeof(DuLNode));
		if(!s)
			exit(OVERFLOW);
		s->data = Data[i-1];
		s->freq = 0;
		
		s->next = *L;
		s->prior = h;
		h->next = s;
		
		if(h==*L)
			h->prior = s;
		
		h = h->next;
	}
	
}

Status Output_DuL_2_38(DuLinkList L)
{
	DuLinkList p;
	
	if(!L)
		return ERROR;
	else
	{
		p = L->next;
		while(p!=L)
		{
			printf("%2d ", p->data);
			p = p->next;
		}
	}
	
	return OK;
}
