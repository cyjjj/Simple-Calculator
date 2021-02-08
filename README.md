# Simple-Calculator
2018-2019春夏浙江大学程序设计小组作业-简易计算器

### 系统功能说明
本程序利用堆栈实现简单计算器功能，能对带有`+``-``*``/`和`()`以及`sin`、`cos`、`pow`简单函数的算数表达式（中缀表达式）求值，且包含优先级的判断，算术表达式中的数字可为整数也可为小数。  
要注意的是，在用该简易计算器进行计算，输入算数表达式时，应将`sin`、`cos`、`pow`分别写成`s`、`c`、`^`的形式，且sin、cos函数中的角度应以`弧度制`输入并用括号括住，其中`PI`以3.14或更精确的估计值由用户手动输入。算术表达式以`回车键`结束，不需“=”。例：`1+(3-s(3.14/6))^2+3*(20+6)`。

1.	程序运行后，先输出`SIMPLE CALCULATOR`标题，并输出提示信息，提醒该简易计算器使用的一些注意事项，包括该简易计算器可计算的运算方式及简单函数sin、cos、pow，算术表达式输入的格式要求，如sin、cos、pow、PI用s、c、^、3.14（或更精确的估计值）形式输入，提示输入算术表达式。  
2.	用户在屏幕上输入一符合要求的算术表达式（中缀表达式），并以回车结束。  
3.	该简易计算器读取用户输入的中缀表达式，并利用操作符堆栈将其转化为逆波兰式，准备进行下一步的计算。  
4.	计算器利用操作数堆栈对转换后得到的逆波兰式进行计算，若逆波兰式中出现计算器不允许的非法字符，如t，输出`Invalid expression!`并不再继续计算。  
5.	计算完成后将最后结果输出：`The value of the expression is:`。  

该简易计算器虽然界面比较简陋，未能实现模拟计算器界面，即仿照真实计算器通过“按键”输入算术表达式。且其中PI的值由用户手动用3.14（或更精确的估计值）代替输入，对用户使用sin、cos函数不够方便，且造成最后结果存在一定误差。但总体来说该计算器的基础计算功能比较完善，对于简单算数表达式均可求值，且具有三角函数和幂函数的拓展功能，计算数范围较广，能满足日常计算要求。

### 使用说明
1.	用户可通过键盘输入包含加减乘除四则运算、括号以及sin、cos三角函数和pow幂函数的算数表达式。  
2.	算术表达式以`回车键`结束（不用打=）。  
3.	sin、cos三角函数、pow幂函数在算术表达式中以`s`、`c`、`^`形式输入。  
4.	对于sin、cos函数内部的值应用括号限制，且所有角度均使用`弧度制`，若需用到`PI`值则手动代替输入3.14。  
5.	计算器计算后自动输出最后结果。  
6.	结束后按任意键退出。  
