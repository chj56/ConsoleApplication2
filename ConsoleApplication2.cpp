#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

enum token_kind
{
	ERROR_TOKEN,//异常
	IDENT,//标识符
	INT_CONST,//整型常数
	FLOAT_CONST,//浮点型常数
	CHAR_CONST,//字符型常数
	INT,//整型
	SHORT,//短整型
	LONG,//长整型
	FLOAT,//浮点型
	DOUBLE,//双精度型
	CHAR,//字符型
	EQ,//等号
	NE,//不等号
	LT,//小于
	LE,//小于等于
	GT,//大于
	GE,//大于等于
	PLUS,//加号
	PLUSPLUS,//自增运算符
	MINUS,//减号
	MINUSMINUS,//自减运算符
	MULTIPLICATION,//乘号
	DIVISION,//除号
	ANL,//逻辑与
	ORL,//逻辑或
	ASSIGN,//赋值号
	LP,//左小括号
	RP,//右小括号
	LS,//左中括号
	RS,//右中括号
	LB,//左大括号
	RB,//右大括号
	SEMI,//分号
	COMMA,//逗号
	IF,
	ELSE,
};

FILE* fp;
char token_text[999][20];
int line = 1,num=0;
int  gettoken();
int main(void)
{
	int i1,i2,i3=0,count=0;
	char filename[20];
	for (i1 = 1; i1 != 0;) {
		system("cls");
		printf("请输入文件名：\n");
		scanf("%s\n",filename);
		system("cls");
		if ((fp = fopen(filename, "r+")) == NULL)//打开以finame为名的文件
		{
			printf("加载失败！\n");

		}
		else {
			system("cls");
			printf("单词类别     单词值");
			while (i2=(gettoken()!=EOF))
			{
				switch (i2)
				{
				case 0:printf("错误        %s\n", token_text[i3]); break;
				case 1:printf("标识符      %s\n", token_text[i3]); break;
				case 2:printf("整型常数    %s\n", token_text[i3]); break;
				case 3:printf("浮点型常数  %s\n", token_text[i3]); break;
				case 4:printf("字符型常数  %s\n", token_text[i3]); break;
				case 5:printf("整型        %s\n", token_text[i3]); break;
				case 6:printf("短整型      %s\n", token_text[i3]); break;
				case 7:printf("长整型      %s\n", token_text[i3]); break;
				case 8:printf("浮点型      %s\n", token_text[i3]); break;
				case 9:printf("双精度型    %s\n", token_text[i3]); break;
				case 10:printf("字符型      %s\n", token_text[i3]); break;
				case 11:printf("等号        %s\n", token_text[i3]); break;
				case 12:printf("不等号      %s\n", token_text[i3]); break;
				case 13:printf("小于        %s\n", token_text[i3]); break;
				case 14:printf("小于等于    %s\n", token_text[i3]); break;
				case 15:printf("大于        %s\n", token_text[i3]); break;
				case 16:printf("大于等于    %s\n", token_text[i3]); break;
				case 17:printf("加号        %s\n", token_text[i3]); break;
				case 18:printf("自增运算符  %s\n", token_text[i3]); break;
				case 19:printf("减号        %s\n", token_text[i3]); break;
				case 20:printf("自减运算符  %s\n", token_text[i3]); break;
				case 21:printf("乘号        %s\n", token_text[i3]); break;
				case 22:printf("除号        %s\n", token_text[i3]); break;
				case 23:printf("逻辑与      %s\n", token_text[i3]); break;
				case 24:printf("逻辑或      %s\n", token_text[i3]); break;
				case 25:printf("赋值号      %s\n", token_text[i3]); break;
				case 26:printf("左小括号    %s\n", token_text[i3]); break;
				case 27:printf("右小括号    %s\n", token_text[i3]); break;
				case 28:printf("左中括号    %s\n", token_text[i3]); break;
				case 29:printf("右中括号    %s\n", token_text[i3]); break;
				case 30:printf("左大括号    %s\n", token_text[i3]); break;
				case 31:printf("右大括号    %s\n", token_text[i3]); break;
				case 32:printf("分号        %s\n", token_text[i3]); break;
				case 33:printf("逗号        %s\n", token_text[i3]); break;
				case 34:printf("错误        %s\n", token_text[i3]); break;
				case 35:printf("标识符      %s\n", token_text[i3]); break;
				}
				if (i3 < 998)
					i3++;
				else {
					printf("单词过多，程序溢出！");
					return 0;
				}
			}
		}
		
		if(fp!=NULL) fclose(fp);

	}
}

int  gettoken()
{  // fp也可以作为全局变量，该函数不使用参数
   //初始化单词自身值token_text为空;
	char c;
	char key[6][9] = { "int","short","long","float","double","char" };
	int n=num;
	int k1 = 0,k2=0;

	while ((c = fgetc(fp))&&((c==10 )|| (c==13) ||(c== 32)))   //过滤掉空白符号，如果考虑报错位置，对回车需要单独
		if (c == 13)                              //处理，每次回车，设置一个行数计数器加1
			line++;
								 
	if ((c>='A'&&c<='Z')|| (c >= 'a' && c <= 'z')) 
	{
		do 
		{ 
			token_text[num][k1++] = c;
		}while ((c = fgetc(fp)) && ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')));   //拼标识符串
			ungetc(c, fp);   //退回多读的字符到文件输入缓冲区
			token_text[num][k1++] = '\0';

                             	//标识符可能是关键字，需要判定并返回对应种类码，符号串在token_text中
                             //可以将所有关键字做成一个查找表，当标识符和某个关键字相等时，返回
			                             //关键字的种类编码，否则返回IDENT


			for (; k2 <= 5; k2++)
			{
				if (strcmp(key[k2], token_text[num]))
					return 5 + k2;
		    }
			return IDENT;
	}

	if (c>='0'&&c<='9') 
	{
		do 
		{ 
			token_text[num][k1++] = c;
		} while ((c = fgetc(fp)) && (c >= '0' && c <= '9'));  //拼数字串
			ungetc(c, fp);   //退回多读的字符
			return 	INT_CONST;//数字串在token_text中，返回INT_CONST。
	}

	switch(c){
	 case'=':  c = fgetc(fp);
		 if (c == ' = ')  //返回相等运算符编码EQ；
			 return EQ;
		 else {
			 ungetc(c, fp);
			 return ASSIGN;
			 //返回赋值运算符编码ASSIGN；
		 }
	 
	 case'<':  c = fgetc(fp);
		 if (c == ' = ')  //返回小于等于运算符编码LE；
			 return LE;
		 else {
			 ungetc(c, fp);
			 return LT;
			 //返回小于运算符编码LT；
		 }

	 case'>':  c = fgetc(fp);
		 if (c == ' = ')  //返回大于等于运算符编码GE；
			 return GE;
		 else {
			 ungetc(c, fp);
			 return GT;
			 //返回大于运算符编码GT；
		 }

	 case'+':  c = fgetc(fp);
		 if (c == ' + ')  //返回自增运算符编码PLUSPLUS；
			 return PLUSPLUS;
		 else {
			 ungetc(c, fp);
			 return PLUS;
			 //返回加法运算符编码PLUS；
		 }

	 case'-':  c = fgetc(fp);
		 if (c == ' - ')  //返回自减运算符编码MINUSMINUS；
			 return MINUSMINUS;
		 else {
			 ungetc(c, fp);
			 return MINUS;
			 //返回减法运算符编码MINUS；
		 }

	 case'*': return MULTIPLICATION;//返回乘法运算符MULTIPLICATION

	 case'/': return DIVISION;//返回除法运算符DIVISION

	 case'&':  c = fgetc(fp);
		 if (c == ' & ')  //返回逻辑与编码ANL；
			 return ANL;
		 else {
			 ungetc(c, fp);
			 return ERROR_TOKEN;
			 //报错；错误符号
		 }

	 case'|':  c = fgetc(fp);
		 if (c == ' | ')  //返回逻辑或编码ORL；
			 return ORL;
		 else {
			 ungetc(c, fp);
			 return ERROR_TOKEN;
			 //报错；错误符号
		 }

	 case'(': return LP;//返回左小括号LP

	 case')': return RP;//返回除法运算符DIVISION

	 case'[': return LS;//返回除法运算符DIVISION

	 case']': return RS;//返回除法运算符DIVISION

	 case'{': return LB;//返回除法运算符DIVISION

	 case'}': return RB;//返回除法运算符DIVISION

	 case';': return SEMI;//返回分号SEMI

	 case',': return COMMA;//返回逗号COMMA

	default:  if (feof(fp))   return EOF;
			else return ERROR_TOKEN; //报错；错误符号
	}


}