#ifndef __STACK_H__
#define __STACK_H__

#pragma once

typedef struct BSTtreeNode* DataTypeBS;

typedef struct Stack
{
	DataTypeBS* _array;
	int _top;//表示有效元素个数  表示栈顶位置
	int _capacity;//底层空间的大小
}Stack;

//初始化
void StackInit(Stack* s);

// 检测栈是否为空 
int StackEmpty(Stack* s);

// 入栈 
void StackPush(Stack* s, DataTypeBS data);

// 出栈 
void StackPop(Stack* s);

// 获取栈顶元素 
DataTypeBS StackTop(Stack* s);

// 有效元素的个数 
int StackSize(Stack* s);

//打印栈
void PrintStack(Stack* s);

//增容 
void StackCapacity(Stack* s);

//括号匹配问题
int MatchBrackets(Stack* s, const char* pstr);

//后缀表达式求值
int RPN(Stack* s, const char* pstr);
int FindSpace(const char* pstr);


#endif //__STACK_H__
