/*
 *该简易计算器利用堆栈，可计算含'+','-','*','/','()','^'(pow函数),'s'(sin函数）,'c'(cos函数)
 *的算术表达式，且考虑运算的优先级。其中sin、cos函数中的角度均取弧度制并用括号括住限制范围，
 *且若需用到PI值，由用户手动输入3.14（或更精确的估计值）代替。输入的算术表达式不需打'='，
 *以回车键表示结束。 
 *用户输入中缀表达式，该简易计算器转化并输出转化所得的逆波兰式，计算逆波兰式的值，得出算术表
 *达式的最后答案并输出。 
 */ 
 
#include "calculator.h"

void main()
{
    Prompt();/*提示输入中缀算术表达式*/
    ChangetoRPN();/*中缀表达式转换为逆波兰式*/
    CompRPN();/*计算逆波兰式的值*/
}

/*提示信息*/
void Prompt(void)
{
	 printf("\tSIMPLE CALCULATOR\n");
	 printf("\n");
	 
	 printf("The formula can contain '+','-','*','/','()','^','s' and 'c'.\n");
	 printf("Here please write 'sin' or 'cos' in terms of 's' or 'c'.\n");
	 printf("Angles are in radians,enclosed in brackets.\n");
	 printf("Enter PI as 3.14 or a more accurate estimate.\n");
	 printf("\n");
	 	 
     printf("Give a formula：");
}

/*转换为逆波兰式*/
void ChangetoRPN(void)
{
    bool isEnd = FALSE;
    char ch;
    
    while (!isEnd) {
        ch = getchar();
        switch (ch) {
            case '(':
                 PushOp(ch);
                 break;
            case ')':
                 if (CurRPN()!=' ') AppendRPN(' ');                 
                 while (TopOp() != '(') {
                     AppendRPN(PopOp());
                     AppendRPN(' ');
                 }
                 PopOp();/*'('直接出栈，不添加到逆波兰式表达式队列中*/
                 break;
            case '+':
            case '-':
                 if (CurRPN()!=' ') AppendRPN(' ');
                 while (TopOp() != EMPTY && TopOp() != '(') {
                     AppendRPN(PopOp());
                     AppendRPN(' ');
                 }
                 PushOp(ch); 
                 break;
            case '*':
            case '/':
                 if (CurRPN()!=' ') AppendRPN(' ');
                 while (TopOp() == '^'||TopOp() == 's'||TopOp() == 'c') {
                     AppendRPN(PopOp());
                     AppendRPN(' ');
                 } 
                 PushOp(ch);
                 break;
             case 's':
             case 'c':
            	 if (CurRPN()!=' ') AppendRPN(' ');
                 while (TopOp() == '^'){
                     AppendRPN(PopOp());
                     AppendRPN(' ');
                 } 
                 PushOp(ch);
                 break;
             case '^':
            	 if (CurRPN()!=' ') AppendRPN(' ');
            	 while (TopOp() == '^'){
            	 	AppendRPN(PopOp());
            	 	AppendRPN(' ');
            	 }
            	 PushOp(ch);
            	 break;
             case '\n':
                 if (CurRPN()!=' ') AppendRPN(' ');
                 while (TopOp()!= EMPTY) {
                       AppendRPN(PopOp());
                       AppendRPN(' ');
                 }
                 AppendRPN(ch);
                 isEnd = TRUE;
                 break;
            case ' ':
            case '\t':/*中缀表达式中的空格及制表符不添加到逆波兰式队列中*/
                 break;
            default:      /*0,1,2,3,4,5,6,7,8,9 和 .*/
                AppendRPN(ch);
                break;
        }
    } 
     AppendRPN('\0');
}

/*以下为逆波兰式队列操作函数*/
void AppendRPN(char ch)/*添加一个字符到逆波兰式队列队尾*/
{
     RPN[++pRPN] = ch;
}

char FetchRPN(void) /*取逆波兰式表达式队列当前字符*/
{
     return  RPN[pRPN++];
}

char CurRPN(void) /*逆波兰式队列当前字符*/
{
     return RPN[pRPN];
}

void RewindRPN(void)/*初始化逆波兰式队列初始位置指针*/ 
{
     pRPN = 0;
}

/*以下为操作符堆栈操作函数*/     
void PushOp(char Op)/*操作符进栈*/
{
     StackOp[++OpTop] = Op;
}

char PopOp(void) /*操作符出栈*/
{
     if (OpTop < 0) return EMPTY;
     return StackOp[OpTop--];
}

char TopOp(void) /*操作符栈顶元素*/
{
     if (OpTop < 0) return EMPTY;
     return StackOp[OpTop];
}


/*
 *获取逆波兰式队列的当前位置操作对象
 *NUMBER：操作数
 *'+','-','*','/','^','s','c':操作符
 *'\n': 结束符
 *其它：无效对象
 */
 char GetOp(char num[])
{
    char opType = 0;
    int i = 0;
 
    while (CurRPN() == ' ') FetchRPN();/*Skip the SPACE*/    

    switch(CurRPN()) {
    case '0':case '1':case '2':case '3':case '4':
    case '5':case '6':case '7':case '8':case '9': /*数字字符*/
         opType = NUMBER;
         while (isdigit(CurRPN())) num[i++] = FetchRPN();/*整数部分*/
         if (CurRPN() == '.') {/*小数点*/
             num[i++] = FetchRPN();
             while (isdigit(CurRPN())) num[i++] = FetchRPN();/*小数部分*/
         }
         num[i] = '\0';
         break;
    case '^':
	case '+':
    case '-':
    case '*':
    case '/':
    case 's':
    case 'c':
    case '\n':
         opType = FetchRPN();
         break;
    default:
         opType = '#';
    }
    return opType;    
} 

/*计算逆波兰式的值*/
void CompRPN(void)
{
     double opn1, opn2, result=0;
     bool isEnd = FALSE;
     int op;
     char tmp[20];/*操作数数字字符序列*/     
     
     RewindRPN();/*初始化逆波兰式队列位置指针*/
     while (!isEnd) {
         op = GetOp(tmp);
         switch(op) {
         case NUMBER:
              PushOpn(atof(tmp));
              break;
         case '+':
              PushOpn(PopOpn() + PopOpn());
              break;
         case '-':
              opn2 = PopOpn();
              PushOpn(PopOpn() - opn2);
              break;
         case '*':
              PushOpn(PopOpn() * PopOpn());
              break;
         case '/':
              opn2 = PopOpn();
              PushOpn(PopOpn() / opn2);
              break;
         case '^':
         	  opn2 = PopOpn();
              PushOpn(pow(PopOpn(),opn2));
              break;
         case 's':
         	  opn2 = PopOpn();
         	  PushOpn(sin(opn2));
         	  break;
         case 'c':
         	  opn2 = PopOpn();
         	  PushOpn(cos(opn2));
              break;
         case '\n':
              printf("The value of the expression is: %g\n", PopOpn());
              isEnd = TRUE;
              break; 
         default:
              printf("Invalid expression!\n");
              return;
         }    
     }
}

/*以下为操作数堆栈函数*/
void PushOpn(double Opn)/*操作数进栈*/
{
     StackOpn[++OpnTop] = Opn;
}

double PopOpn(void)/*操作数出栈*/
{
    if (OpnTop < 0) return EMPTY;
    return StackOpn[OpnTop--];
}

double TopOpn(void)/*操作数栈顶元素*/
{
    if (OpnTop < 0) return EMPTY;
    return StackOpn[OpnTop];
} 
