#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  										//**��01 ����**//

/* ���Ͷ��� */
typedef int LElemType_DC;
typedef struct DuLNode					//˫������ṹ��
{
	LElemType_DC data;
	struct DuLNode *prior;
	struct DuLNode *
	next;
	int freq;							//����Ƶ���� 
}DuLNode;
typedef DuLNode* DuLinkList;		 	//ָ��˫ѭ������ṹ��ָ�� 

/* ����ԭ�� */
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
	printf("��ʼ��������ΪL = ");
	Output_DuL_2_38(L);
	printf("\n\n");
	
	for(i=1; i<=10; i++)
		Algo_2_38(L, tmp[i-1]);
	printf("����֮��L = ");
	Output_DuL_2_38(L);
	printf("\n");
	printf("��Ӧ���ʴ�����");
	for(p=L->next; p!=L; p=p->next)
		printf("%2d ", p->freq);
	printf("\n\n");

	return 0;
}

/*����������������������������������������������������������������������
����2.38����λL��Ԫ��e��λ�򣬲�������Ƶ�������������������Ԫ�ز��ظ���
����������������������������������������������������������������������*/
int Algo_2_38(DuLinkList L, LElemType_DC e)
{	
	DuLinkList p, pre;
	int i;
	
	if(!L || L->next==L)				//�������ڻ�����Ϊ�� 
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
	
	if(p!=L)							//�ҵ�����e��ȵĽ�� 
	{
		p->freq++;
		
		while(pre!=L && pre->freq<p->freq)
		{
			i--;
			pre = pre->prior;
		}
		
		if(pre->next!=p)				//��preλ�÷����ı䣬pλ��Ҳ��Ҫ�ı� 
		{
			p->next->prior= p->prior;	//ժ�½��p 
			p->prior->next = p->next;
			
			p->next = pre->next;		//��p���뵽����λ�� 
			p->prior = pre;
			pre->next->prior= p;
			pre->next = p;
		}
				
		return i;
	}
	
	return 0;
}

Status CreatList_DuL_2_38(DuLinkList *L, int n, LElemType_DC Data[])	//���޵��д��� 
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
