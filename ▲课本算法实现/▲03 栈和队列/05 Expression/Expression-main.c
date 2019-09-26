/***************************************
 *						               *
 * 文件夹: ▲03 栈和队列\05 Expression *
 * 						               *
 * 内  容: 表达式求值相关函数测试      *
 *                                     *
 ***************************************/

#include "Expression.c"			//**▲03 栈和队列**//					

int main(int argc, char **argv)
{
	char opnd;
	char *exp = "1+2*(5-3)-6/2+4#";
	
	opnd = EvaluateExpression(exp);
	
	printf("作为示例，%s 的计算结果为：%c\n", exp, opnd);
	
	printf("\n");
	
	return 0;
}
