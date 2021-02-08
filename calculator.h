#ifndef _calculator_h
#define _calculator_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "resorces/genlib.h"
#include "resorces/simpio.h"

#define MAXEXP  200
#define MAXOP   30
#define MAXOPN  100  

#define EMPTY 0

/* 逆波兰式队列及操作函数 */

char RPN[MAXEXP]; /*逆波兰式表达式队列，以回车结束*/
int pRPN = -1;/*逆波兰式表达式队列当前位置，初始为-1*/
void AppendRPN(char ch);/*添加一个字符到逆波兰式表达式队列*/
char FetchRPN(void); /*取逆波兰式表达式队列当前字符*/
char CurRPN(void); /*逆波兰式队列当前字符*/
void RewindRPN(void);/*初始化逆波兰式队列指针起始位置*/ 

void Prompt(void);/*提示信息*/
void ChangetoRPN(void);/*转换为逆波兰式*/
void CompRPN(void);/*计算逆波兰式的值*/


/* 转换为逆波兰式时的操作符堆栈及操作函数 */

char StackOp[MAXOP];/*操作符堆栈*/ 
int OpTop = -1;/*操作符堆栈栈顶指针*/
void PushOp(char op);/*操作符进栈*/
char PopOp(void); /*操作符出栈*/
char TopOp(void);/*操作符栈顶元素*/


/* 计算逆波兰式时的操作数堆栈和操作函数 */

double StackOpn[MAXOPN]; /*计算逆波兰表达式时的操作数堆栈*/
int OpnTop = -1;/*计算逆波兰表达式时的操作数堆栈栈顶指针*/
void PushOpn(double Opn);/*操作数进栈*/
double PopOpn(void); /*操作数出栈*/
double TopOpn(void);/*操作数栈顶元素*/

#define NUMBER '0'  /*操作对象类型为操作数*/

char GetOp(char num[]);/*获取逆波兰式队列的当前位置操作对象*/

#endif

