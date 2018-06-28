#include"Stack.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

void StackInit(Stack* s)
{
	assert(s);

	s->_top = 0;
	s->_capacity = 10;
	s->_array = (DataTypeBS *)malloc(sizeof(DataTypeBS)*s->_capacity);
	if (NULL == s->_array)
	{
		assert(s->_array);
		return;
	}
}

int StackEmpty(Stack* s)
{
	assert(s);

	if (s->_top)
		return 0;
	
	return 1;
}

void StackPush(Stack* s, DataTypeBS data)
{
	assert(s);

	//判断栈是否满了
	if (s->_top >= s->_capacity)
		StackCapacity(s);

	s->_array[s->_top++] = data;
}

void StackPop(Stack* s)
{
	assert(s);

	//动态栈为空
	if (StackEmpty(s))
		return;

	--s->_top;
}

DataTypeBS StackTop(Stack* s)
{
	assert(!StackEmpty(s));

	return s->_array[s->_top - 1];
}

int StackSize(Stack* s)
{
	assert(s);

	return s->_top;
}

void PrintStack(Stack* s)
{
	int i = 0;
	assert(s);

	//动态栈为空
	if (StackEmpty(s))
		return;

	if (0 == s->_top)
		return;

	for (i = 0; i < s->_top; ++i)
	{
		printf("%d ",s->_array[i]);
	}
	printf("\n");
}

void StackCapacity(Stack* s)
{
	assert(s);

	DataTypeBS * temp = s->_array;
	//动态栈为空
	if (StackEmpty(s))
		return;

	s->_array = (DataTypeBS *)realloc(s->_array, sizeof(DataTypeBS)*s->_capacity * 2);
	if (NULL == s->_array)
	{
		printf("增容失败");
		s->_array = temp;
	}

}

//int MatchBrackets(Stack* s, const char* pstr)
//{
//	assert(s);
//
//	int i = 0;
//	int len = 0;
//	len = strlen(pstr);
//	if (NULL == pstr)
//		return 0;
//	for (i = 0; i < len; ++i)
//	{
//		if (pstr[i] == '(' || pstr[i] == ')' ||
//			pstr[i] == '[' || pstr[i] == ']' ||
//			pstr[i] == '{' || pstr[i] == '}')
//		{
//			if (pstr[i] == '(' || pstr[i] == '[' || pstr[i] == '{')
//			{
//				StackPush(s, pstr[i]);
//			
//			}
//
//			if (pstr[i] == ')' || pstr[i] == ']' || pstr[i] == '}')
//			{
//				char str = 0;
//				if (StackEmpty(s))
//				{
//					printf("右括号多余左括号\n");
//					return 0;
//				}
//
//				str = StackTop(s);
//				if (pstr[i] == ')' && str == '(' ||
//					pstr[i] == ']' && str == '[' ||
//					pstr[i] == '}' && str == '{')
//				{
//					StackPop(s);
//				}
//				else
//				{
//					printf("括号不匹配\n");
//					return 0;
//				}
//			}
//		}
//		else
//			continue;
//		
//	}
//
//	if (!StackEmpty(s))
//	{
//		printf("左括号多余右括号\n");
//		return 0;
//	}
//
//	printf("匹配正确\n");
//	return 1;
//}
//
//int RPN(Stack* s, const char* pstr)
//{
//	int i = 0;
//	int len = 0;
//	int num = 0;
//	len = strlen(pstr);
//	assert(s);
//	assert(pstr);
//
//	for (i = 0; i < len; ++i)
//	{
//		int right = 0;
//		int left = 0;
//		if (pstr[i] >= '0' && pstr[i] <= '9')
//		{
//			StackPush(s, atoi(&pstr[i]));
//
//			i = i + FindSpace(&pstr[i]);
//			
//		}
//		else
//		{
//			if (' ' != pstr[i])
//			{
//				right = StackTop(s);
//				StackPop(s);
//				left = StackTop(s);
//				StackPop(s);
//			}
//
//			switch (pstr[i])
//			{
//			case '+':
//				StackPush(s, left + right);
//				break;
//			case '-':
//				StackPush(s, left - right);
//				break;
//			case '*':
//				StackPush(s, left * right);
//				break;
//			case '/':
//			{	
//				if (0 == right)
//				{
//					printf("分母不能为0\n");
//					break;
//	            }
//				StackPush(s, left / right);
//				break;
//			}
//			default:
//				break;
//			}
//		}
//	}
//	return StackTop(s);
//}

int FindSpace(const char* pstr)
{
	int i = 0;
	assert(pstr);

	while (' ' != pstr[i])
	{
		++i;
	}

	return i;
}
