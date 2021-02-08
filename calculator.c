/*
 *�ü��׼��������ö�ջ���ɼ��㺬'+','-','*','/','()','^'(pow����),'s'(sin������,'c'(cos����)
 *���������ʽ���ҿ�����������ȼ�������sin��cos�����еĽǶȾ�ȡ�����Ʋ���������ס���Ʒ�Χ��
 *�������õ�PIֵ�����û��ֶ�����3.14�������ȷ�Ĺ���ֵ�����档������������ʽ�����'='��
 *�Իس�����ʾ������ 
 *�û�������׺���ʽ���ü��׼�����ת�������ת�����õ��沨��ʽ�������沨��ʽ��ֵ���ó�������
 *��ʽ�����𰸲������ 
 */ 
 
#include "calculator.h"

void main()
{
    Prompt();/*��ʾ������׺�������ʽ*/
    ChangetoRPN();/*��׺���ʽת��Ϊ�沨��ʽ*/
    CompRPN();/*�����沨��ʽ��ֵ*/
}

/*��ʾ��Ϣ*/
void Prompt(void)
{
	 printf("\tSIMPLE CALCULATOR\n");
	 printf("\n");
	 
	 printf("The formula can contain '+','-','*','/','()','^','s' and 'c'.\n");
	 printf("Here please write 'sin' or 'cos' in terms of 's' or 'c'.\n");
	 printf("Angles are in radians,enclosed in brackets.\n");
	 printf("Enter PI as 3.14 or a more accurate estimate.\n");
	 printf("\n");
	 	 
     printf("Give a formula��");
}

/*ת��Ϊ�沨��ʽ*/
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
                 PopOp();/*'('ֱ�ӳ�ջ������ӵ��沨��ʽ���ʽ������*/
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
            case '\t':/*��׺���ʽ�еĿո��Ʊ������ӵ��沨��ʽ������*/
                 break;
            default:      /*0,1,2,3,4,5,6,7,8,9 �� .*/
                AppendRPN(ch);
                break;
        }
    } 
     AppendRPN('\0');
}

/*����Ϊ�沨��ʽ���в�������*/
void AppendRPN(char ch)/*���һ���ַ����沨��ʽ���ж�β*/
{
     RPN[++pRPN] = ch;
}

char FetchRPN(void) /*ȡ�沨��ʽ���ʽ���е�ǰ�ַ�*/
{
     return  RPN[pRPN++];
}

char CurRPN(void) /*�沨��ʽ���е�ǰ�ַ�*/
{
     return RPN[pRPN];
}

void RewindRPN(void)/*��ʼ���沨��ʽ���г�ʼλ��ָ��*/ 
{
     pRPN = 0;
}

/*����Ϊ��������ջ��������*/     
void PushOp(char Op)/*��������ջ*/
{
     StackOp[++OpTop] = Op;
}

char PopOp(void) /*��������ջ*/
{
     if (OpTop < 0) return EMPTY;
     return StackOp[OpTop--];
}

char TopOp(void) /*������ջ��Ԫ��*/
{
     if (OpTop < 0) return EMPTY;
     return StackOp[OpTop];
}


/*
 *��ȡ�沨��ʽ���еĵ�ǰλ�ò�������
 *NUMBER��������
 *'+','-','*','/','^','s','c':������
 *'\n': ������
 *��������Ч����
 */
 char GetOp(char num[])
{
    char opType = 0;
    int i = 0;
 
    while (CurRPN() == ' ') FetchRPN();/*Skip the SPACE*/    

    switch(CurRPN()) {
    case '0':case '1':case '2':case '3':case '4':
    case '5':case '6':case '7':case '8':case '9': /*�����ַ�*/
         opType = NUMBER;
         while (isdigit(CurRPN())) num[i++] = FetchRPN();/*��������*/
         if (CurRPN() == '.') {/*С����*/
             num[i++] = FetchRPN();
             while (isdigit(CurRPN())) num[i++] = FetchRPN();/*С������*/
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

/*�����沨��ʽ��ֵ*/
void CompRPN(void)
{
     double opn1, opn2, result=0;
     bool isEnd = FALSE;
     int op;
     char tmp[20];/*�����������ַ�����*/     
     
     RewindRPN();/*��ʼ���沨��ʽ����λ��ָ��*/
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

/*����Ϊ��������ջ����*/
void PushOpn(double Opn)/*��������ջ*/
{
     StackOpn[++OpnTop] = Opn;
}

double PopOpn(void)/*��������ջ*/
{
    if (OpnTop < 0) return EMPTY;
    return StackOpn[OpnTop--];
}

double TopOpn(void)/*������ջ��Ԫ��*/
{
    if (OpnTop < 0) return EMPTY;
    return StackOpn[OpnTop];
} 
