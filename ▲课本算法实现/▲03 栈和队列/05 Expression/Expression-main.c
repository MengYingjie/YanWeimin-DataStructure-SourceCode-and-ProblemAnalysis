/***************************************
 *						               *
 * �ļ���: ��03 ջ�Ͷ���\05 Expression *
 * 						               *
 * ��  ��: ���ʽ��ֵ��غ�������      *
 *                                     *
 ***************************************/

#include "Expression.c"			//**��03 ջ�Ͷ���**//					

int main(int argc, char **argv)
{
	char opnd;
	char *exp = "1+2*(5-3)-6/2+4#";
	
	opnd = EvaluateExpression(exp);
	
	printf("��Ϊʾ����%s �ļ�����Ϊ��%c\n", exp, opnd);
	
	printf("\n");
	
	return 0;
}
