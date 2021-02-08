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

/* �沨��ʽ���м��������� */

char RPN[MAXEXP]; /*�沨��ʽ���ʽ���У��Իس�����*/
int pRPN = -1;/*�沨��ʽ���ʽ���е�ǰλ�ã���ʼΪ-1*/
void AppendRPN(char ch);/*���һ���ַ����沨��ʽ���ʽ����*/
char FetchRPN(void); /*ȡ�沨��ʽ���ʽ���е�ǰ�ַ�*/
char CurRPN(void); /*�沨��ʽ���е�ǰ�ַ�*/
void RewindRPN(void);/*��ʼ���沨��ʽ����ָ����ʼλ��*/ 

void Prompt(void);/*��ʾ��Ϣ*/
void ChangetoRPN(void);/*ת��Ϊ�沨��ʽ*/
void CompRPN(void);/*�����沨��ʽ��ֵ*/


/* ת��Ϊ�沨��ʽʱ�Ĳ�������ջ���������� */

char StackOp[MAXOP];/*��������ջ*/ 
int OpTop = -1;/*��������ջջ��ָ��*/
void PushOp(char op);/*��������ջ*/
char PopOp(void); /*��������ջ*/
char TopOp(void);/*������ջ��Ԫ��*/


/* �����沨��ʽʱ�Ĳ�������ջ�Ͳ������� */

double StackOpn[MAXOPN]; /*�����沨�����ʽʱ�Ĳ�������ջ*/
int OpnTop = -1;/*�����沨�����ʽʱ�Ĳ�������ջջ��ָ��*/
void PushOpn(double Opn);/*��������ջ*/
double PopOpn(void); /*��������ջ*/
double TopOpn(void);/*������ջ��Ԫ��*/

#define NUMBER '0'  /*������������Ϊ������*/

char GetOp(char num[]);/*��ȡ�沨��ʽ���еĵ�ǰλ�ò�������*/

#endif

