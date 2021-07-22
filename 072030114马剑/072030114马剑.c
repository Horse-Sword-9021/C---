/*
最初的时候，这个程序我是在visual studio 2019中编写的，由于vs2010不支持c99的写法，所以最后在vs2010中
运行的时候，可能会出现未声明的标识符等错误，我已尽可能将有关c99写法改为vs2010支持的c89写法，但不排除
有些地方有遗漏，如果老师还发现有错误，还请老师高抬贵手，那真的不是我的问题，要怪得怪10年前的微软，那
时它还没造出来c99的写法，如今，已经过去了10年，微软升级了，我们也该跟着升级了，不是嘛！。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<math.h>
#include<conio.h>
/*#define FORMAT " %s %s %d %d %d %d %.2f\n"
#define DATA p->data.num,p->data.name,p->data.mgrade,p->data.egrade,p->data.cgrade,p->data.total,p->data.ave*/
typedef struct//每个学生数组元素为一个结构体变量
{
	char xh[50];	//学号
	char xm[50];	//姓名，10个汉字以内
	char xb[10];		//性别，一个汉字
	int nl;			//年龄
}Student;
typedef struct//每门课程信息为一个结构体变量
{
	char kh[10];	//课号，10字符以内
	char km[25];	//课名，12汉字以内
	float xf;		//课程学分，1个浮点数
}Course;
typedef struct//学生选课信息为一个结构体变量
{
	char xh[10];	//课号，10字符以内                          
	char kh[10];	//课名，12汉字以内
	float cj;		//成绩，一个浮点数
}Select;
typedef struct
{
	char xh[10];	//学号
	char xm[25];	//姓名
	//float cj;	//各科目成绩
	float zpj;		//加权平均分
	float zxf;		//总学分
}Score;
typedef struct stucode
{
	Student slist;
	struct stucode* next;
}stucode;
typedef struct node
{
	Student data;
	struct node* next;
}Node, * Link;
/*void printdata(Node* pp)
{
	Node* p;
	p = pp;
	printf(FORMAT, DATA);
}*/
/*void init(Student slist[], int scount) //Course clist[], int* ccount, Select sclist[], int* sccount)//通过指定文件夹装入必要信息
{
	FILE* fps, * fpc, * fpsc;
	fps=fopen("学生信息.txt","r");
	while(fscanf(fps,"%d %s %s %d",&slist[scount].xh,&slist[scount].xm,&slist[scount].xb,&slist[scount].nl)!=EOF)
	{
		scount++;
	}

	/*for(scount=0;fgetc(fps)==EOF;scount++)
	{
		fscanf(fps,"%d %s %s %d",&slist[scount].xh,&slist[scount].xm,&slist[scount].xb,&slist[scount].nl);

	}
	fclose(fps);
}*/
//以下6个菜单
void main_menu()//主菜单
{
	system("cls");
	printf_s("***************学生成绩管理系统****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: 导入初始数据                    *\n");
	printf_s("*          2: 显示数据                        *\n");
	printf_s("*          3: 输入记录                        *\n");
	printf_s("*          4: 删除记录                        *\n");
	printf_s("*          5: 查询信息                        *\n");
	printf_s("*          6: 批量导出数据                    *\n");
	printf_s("*          0: 退出学生成绩管理系统            *\n");
	printf_s("*                                             *\n");
	printf_s("***********************************************\n");
	printf_s("请给出你的选择：\n");
	fflush(stdin);
}
void back()//返回函数
{
	int x;
	do {
		printf_s(" * 按 0返回菜单界面\n");
		scanf_s("%d", &x);
		system("cls");
	} while (x != 0);
}
void menu2()//2号子菜单
{
	system("cls");
	printf_s("***************学生成绩管理系统****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: 显示学生信息                    *\n");
	printf_s("*          2: 显示课程信息                    *\n");
	printf_s("*          3: 显示成绩单信息                  *\n");
	printf_s("*          0: 返回                            *\n");
	printf_s("***********************************************\n");
	printf_s("请给出你的选择：\n");
}
void menu3()//3号子菜单
{
	system("cls");
	printf_s("***************学生成绩管理系统****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: 输入学生信息                    *\n");
	printf_s("*          2: 输入课程信息                    *\n");
	printf_s("*          3: 输入成绩信息                    *\n");
	printf_s("*          0: 返回                            *\n");
	printf_s("***********************************************\n");
	printf_s("请给出你的选择：\n");
}
void menu4()//4号子菜单
{
	system("cls");
	printf_s("***************学生成绩管理系统****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: 删除学生信息                    *\n");
	printf_s("*          2: 删除课程信息                    *\n");
	printf_s("*          3: 删除成绩信息                    *\n");
	printf_s("*          0: 返回                            *\n");
	printf_s("***********************************************\n");
	printf_s("请给出你的选择：\n");
}
void menu5()//5号子菜单
{
	system("cls");
	printf_s("***************学生成绩管理系统****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: 查询学生信息                    *\n");
	printf_s("*          2: 查询课程信息                    *\n");
	printf_s("*          3: 查询成绩信息                    *\n");
	printf_s("*          0: 返回                            *\n");
	printf_s("***********************************************\n");
	printf_s("请给出你的选择：\n");
}
void menu6()//6号子菜单
{
	system("cls");
	printf_s("***************学生成绩管理系统****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: 批量导出学生、课程、选课信息    *\n");
	printf_s("*          2: 批量导出成绩单                  *\n");
	printf_s("*          0: 返回                            *\n");
	printf_s("***********************************************\n");
	printf_s("请给出你的选择：\n");
}

//1、初始化,void类型
void init(Student slist[], int* scount, Course	clist[], int* ccount, Select sclist[], int* sccount)
{
	FILE* fs, * fc, * fsc;
	int n;
	fs = fopen("学生信息.txt", "r");
	if (fs == NULL)
	{
		printf("文件无法打开\n");
		exit(1);
	}
	for (n = 0; !feof(fs); n++)
	{
		fscanf(fs, "%s%s%s%d", slist[n].xh, slist[n].xm, slist[n].xb, &slist[n].nl);
	}
	fclose(fs);
	*scount = n;
	printf("已成功读入%d条学生数据\n", n);
	fc = fopen("课程信息.txt", "r");
	if (fc == NULL)
	{
		printf("文件无法打开\n");
		exit(1);
	}
	for (n = 0; !feof(fc); n++)
	{
		fscanf(fc, "%s%s%f", clist[n].kh, clist[n].km, &clist[n].xf);
	}
	fclose(fc);
	*ccount = n;
	printf("已成功读入%d条课程数据\n", n);
	fsc = fopen("成绩信息.txt", "r");
	if (fsc == NULL)
	{
		printf("文件无法打开\n");
		exit(1);
	}
	for (n = 0; !feof(fsc); n++)
	{
		fscanf(fsc, "%s%s%f", sclist[n].xh, sclist[n].kh, &sclist[n].cj);
	}
	fclose(fsc);
	*sccount = n;
	printf("已成功读入%d条成绩数据\n", n);
}

/*void init(Student slist[], int* scount, Course clist[], int* ccount, Select sclist[], int* sccount)//初始化数据
{
	int count;
	FILE* file = NULL;
	char str[255];

	//init_slist begin
	printf_s("请输入要读取的学生列表文件。若要选择默认文件，则输入“.”：\n");
	scanf("%s", str);
	fflush(stdin);
	if (strcmp(str, ".") == 0)
	{
		strcpy(str, "slist.txt");
	}
	file = fopen(str, "r");
	while (!file)
	{
		printf_s("找不到该文件，请重新输入。若要选择默认文件，则输入“.”：\n");
		scanf("%s", str);
		fflush(stdin);
		if (strcmp(str, ".") == 0)
		{
			strcpy(str, "slist.txt");
		}
		file = fopen(str, "r");
	}
	count = 0;
	while (fscanf(file, "%s %s %s %d", slist[count].xh, slist[count].xm, slist[count].xb, &slist[count].nl) != EOF)
	{
		++count;
	}
	*scount = count;
	fclose(file);
	//init_slist end

	//init_clist begin
	printf_s("请输入要读取的课程列表文件。若要选择默认文件，则输入“.”：\n");
	scanf("%s", str);
	fflush(stdin);
	if (strcmp(str, ".") == 0)
	{
		strcpy(str, "clist.txt");
	}
	file = fopen(str, "r");
	while (!file)
	{
		printf_s("找不到该文件，请重新输入。若要选择默认文件，则输入“.”：\n");
		scanf_s("%s", str);
		fflush(stdin);
		if (strcmp(str, ".") == 0)
		{
			strcpy(str, "clist.txt");
		}
		file = fopen(str, "r");
	}
	count = 0;
	while (fscanf(file, "%s %s %f", clist[count].kh, clist[count].km, &clist[count].xf) != EOF)
	{
		++count;
	}
	*ccount = count;
	fclose(file);
	//init_clist end

	//init_sclist begin
	printf_s("请输入要读取的选课列表文件。若要选择默认文件，则输入“.”：\n");
	scanf("%s", str);
	fflush(stdin);
	if (strcmp(str, ".") == 0)
	{
		strcpy(str, "sclist.txt");
	}
	file = fopen(str, "r");
	while (!file)
	{
		printf_s("找不到该文件，请重新输入。若要选择默认文件，则输入“.”：\n");
		scanf("%s", str);
		fflush(stdin);
		if (strcmp(str, ".") == 0)
		{
			strcpy(str, "sclist.txt");
		}
		file = fopen(str, "r");
	}
	count = 0;
	while (fscanf(file, "%s %s %f", sclist[count].xh, sclist[count].kh, &sclist[count].cj) != EOF)
	{
		++count;
	}
	*sccount = count;
	fclose(file);
	//init_sclist end
}*/

//2、建立成绩单
/*void create_cjlist(Student slist[], int* scount, Select sclist[], int* sccount, Course clist[], int* ccount, Score cjlist[])
{
	int i, j, k;
	float zcj, zxf;
	printf("%d\n", *scount);
	for (i = 0; i < *scount; i++)
	{
		strcpy(cjlist[i].xh, slist[i].xh);
		strcpy(cjlist[i].xm, slist[i].xm);
	}
	for (i = 0; i < *scount; i++)//学生人数
	{
		for (j = 0, zxf = 0, zcj = 0, cjlist[i].zxf = 0; j < *sccount; j++)//是否有该学生的成绩
		{
			if (strcmp(slist[i].xh, sclist[j].xh) == 0)
			{
				for (k = 0; k < *ccount; k++)//去课程信息里找学分
				{
					if (strcmp(sclist[j].kh, clist[k].kh) == 0)
					{
						cjlist[i].zxf += clist[k].xf;
						zcj += (sclist[j].cj) * (clist[k].xf);
					}
				}
			}
		}
		cjlist[i].zpj = zcj / cjlist[i].zxf;
	}
}*/
void create_cjlist(Student slist[], int scount, Select sclist[], int sccount, Course clist[], int ccount, Score cjlist[])
{
	int i, j, k; float zcj, zxf;
	for (i = 0; i < scount; i++)
	{
		strcpy(cjlist[i].xm, slist[i].xm);
		strcpy(cjlist[i].xh, slist[i].xh);
	}
	for (i = 0; i < scount; i++)
	{
		for (j = 0, cjlist[i].zxf = 0, zcj = 0; j < ccount; j++)
		{

			if (strcmp(slist[i].xh, sclist[j].xh) == 0)//选了该门课程
			{
				for (k = 0; k < ccount; k++)
				{
					if (strcmp(sclist[j].kh, clist[k].kh) == 0)
					{
						cjlist[i].zxf = cjlist[i].zxf + clist[k].xf;
						zcj = zcj + sclist[j].cj * clist[k].xf;
					}
				}
			}
		}
		cjlist[i].zpj = zcj / cjlist[i].zxf; 
	}
}
//3、以下显示数据
	//以下3个排序
void sort_slist(Student slist[], int scount)//学号升序
{
	int i, j; Student temp;
	//FILE* fp;													//定义一个文件指针fp
	system("cls");												//清屏
	//count();													//实时检测总数n
	for (i = 0; i < scount - 1; i++)
		for (j = 0; j < scount - 1 - i; j++)					//按学号对学生信息进行排序
		{
			if (strcmp(slist[j].xh, slist[j + 1].xh) > 0)				//整型数字的比较
			{
				temp = slist[j];
				slist[j] = slist[j + 1];
				slist[j + 1] = temp;
			}
		}

	/*fp = fopen("slist.txt", "w+");  //以 “读写”方式打开students文本文件//
	for (i = 0; i < scount; i++)
		fwrite(&slist[i], sizeof(Student), 1, fp);  //以结构体students的方式从文件fp中读取，将其写入students文本文件，每次写入一个学生的信息//
	fclose(fp);      关闭文件*/

}
void sort_clist(Course clist[], int ccount)//课程号升序
{
	int i, j; Course temp;
	//FILE* fp;											//定义一个文件指针fp//
	system("cls");										//清屏
	//count();											//实时检测总数n 
	for (i = 0; i < ccount - 1; i++)
		for (j = 0; j < ccount - 1 - i; j++)			//按学号对学生信息进行排序//
		{
			if (strcmp(clist[j].kh, clist[j + 1].kh) > 0)		//整型数字的比较//
			{
				temp = clist[j];
				clist[j] = clist[j + 1];
				clist[j + 1] = temp;
			}
		}
}
void sort_cjlist(Score cjlist[], int scount)//平均成绩降序
{
	int i, j; Score temp;
	system("cls");															//清屏
	//count();																//实时检测总数n
	for (i = 0; i < scount - 1; i++)
		for (j = 0; j < scount - 1 - i; j++)								//按学号对学生信息进行排序
		{
			if (cjlist[j].zpj < cjlist[j + 1].zpj)								//整型数字的比较
			{
				temp = cjlist[j];
				cjlist[j] = cjlist[j + 1];
				cjlist[j + 1] = temp;
			}
		}
}
//以下3个显示
void disp_stud(Student slist[], int scount)//显示学生
{
	int i;
	sort_slist(slist, scount);
	printf("学号\t\t姓名\t\t性别\t年龄\n");
	for (i = 0; i < scount; i++)
	{
		printf("%s\t%s\t\t%s\t%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}
}
void disp_course(Course clist[], int ccount)//显示课程
{
	int i = 0;
	sort_clist(clist, ccount);
	printf("课号\t课名\t学分\n");
	for (i; i < ccount; i++)
	{
		printf("%s\t%s\t%.1f\n", clist[i].kh, clist[i].km, clist[i].xf);
	}
}
void disp_cjlist(Score cjlist[], int cjcount, Course clist[], int ccount, Student slist[], int scount, Select sclist[], int sccount)//显示成绩
{
	int i = 0;
	create_cjlist(slist, scount, sclist, sccount, clist, ccount, cjlist);
	sort_cjlist(cjlist, scount);
	printf("学号\t\t姓名\t\t平均分\t总修习学分\n");
	for (i = 0; i < scount; i++)
	{
		printf_s("%s\t%s\t\t%.1f\t%.1f\n", cjlist[i].xh, cjlist[i].xm, cjlist[i].zpj, cjlist[i].zxf);
	}
}

//4、以下3个数据输入
void input_stud(Student slist[], int* scount)//输入学生信息存放至学生结构体数组slist，scount为数组原有学生记录；返回学生记录数
{
	//int i = 0;     //学生人数初始化//
	char c;
	//FILE* fp;     //定义一个文件指针fp//
	//count();     //实时检测总数n//
	//fp = fopen("slist.txt", "at+");    //以“追加”方式打开students文本文件//
	do
	{
		printf_s("请输入学生的个人信息:\n");
		printf_s("请输入学生的学号:"); scanf("%s", &slist[*scount].xh);
		printf_s("请输入学生的姓名:"); scanf("%s", slist[*scount].xm);
		printf_s("请输入学生性别:"); scanf("%s", slist[*scount].xb);
		printf_s("请输入学生年龄:"); scanf_s("%d", &slist[*scount].nl); getchar();
		//fwrite(&slist[*scount], sizeof(Student), 1, fp);  //以方式将其写入students文本文件//
		*scount += 1;
		printf_s("\n\n\t\t\t\t是否继续输入(Y/N):"); c = getchar();     //提示是否继续，从键盘获得一个字符//  
	} while (c == 'y' || c == 'Y');
	//fclose(fp);
}
void input_course(Course clist[], int* ccount)//输入课程信息存放至课程信息结构体数组clist，ccount为原有课程记录；返回课程记录数
{
	//int i = 0;     //学生人数初始化//
	char c;
	//FILE* fp;     //定义一个文件指针fp//
	//count();     //实时检测总数n//
	//fp = fopen("clist.txt", "at+");    //以“追加”方式打开
	do
	{
		printf_s("请输入课程信息:\n");
		printf_s("请输入课号:"); scanf("%s", clist[*ccount].kh);
		printf_s("请输入课名:"); scanf("%s", clist[*ccount].km); //getchar();
		printf_s("请输入课程学分："); scanf_s("%lf", &clist[*ccount].xf);//getchar();
		*ccount += 1;
		printf_s("\n\n\t\t\t\t是否继续输入(Y/N):"); getchar();     //提示是否继续，从键盘获得一个字符//  
		c = getchar();
	} while (c == 'y' || c == 'Y');
	//fclose(fp);
}
void input_select(Select sclist[], int* sccount)//输入选课存放至学生选课信息结构体数组sclist，sccount为原有选课记录；无成绩用-1表示；返回选课记录总数
{
	//int i = 0;     //学生人数初始化//
	char c;
	//FILE* fp;    //定义一个文件指针fp//
	//count();    //实时检测总数n//
	//fp = fopen("sclist.txt", "at+");    //以“追加”方式打开students文本文件//
	do
	{
		printf_s("请输入学生选课信息:\n");
		printf_s("请输入学生的学号:"); scanf("%s", sclist[*sccount].xh);
		printf_s("请输入课号:"); scanf("%s", sclist[*sccount].kh);				//getchar();
		printf_s("请输入学生成绩"); scanf_s("%lf", &sclist[*sccount].cj);		//getchar();
		//fwrite(&sclist[*sccount], sizeof(Select), 1, fp);//以方式将其写入students文本文件	
		*sccount++;
		printf_s("\n\n\t\t\t\t是否继续输入(Y/N):"); getchar();			//提示是否继续，从键盘获得一个字符  
		c = getchar();
	} while (c == 'y' || c == 'Y');
	//fclose(fp);
}
//5、以下3个删除记录
void delete_stud(Student slist[], int* scount)//根据姓名或学号删除若干学生，返回剩余学生
{
	int i; char xz, name[20], k[20];
	printf_s("是否根据学号删除y/n？\n"); scanf(" %c", &xz);
	if (xz == 'y' || xz == 'Y')
	{
		printf("输入要删除学生学号:");
		fflush(stdin);
		scanf("%s", k);
		for (i = 0; i < *scount; i++)
		{
			if (strcmp(slist[i].xh, k) == 0)
			{
				if (i == *scount)*scount -= 1;
				else
				{
					slist[i] = slist[*scount - 1];
					*scount -= 1;
				}
				break;
			}
		}
		system("cls");
	}
	else
	{
		printf("输入要删除学生姓名:");
		fflush(stdin);
		gets(name);
		for (i = 0; i < *scount; i++)
		{
			if (strcmp(slist[i].xm, name))
			{
				if (i == *scount)*scount -= 1;
				else
				{
					slist[i] = slist[*scount - 1];
					*scount -= 1;
				}
				break;
			}
		}
		system("cls");
	}
}
void delete_course(Course clist[], int* ccount)//根据课程名或课程号删除课程，返回剩余课程
{

	char k[50]; int i;
	printf_s("输入要删除课程课号:");
	fflush(stdin);
	scanf("%s", k);
	for (i = 0; i < *ccount; i++)
	{
		if (strcmp(clist[i].kh, k) == 0)
		{
			if (i == *ccount)*ccount -= 1;
			else
			{
				clist[i] = clist[*ccount - 1];
				*ccount -= 1;
			}
			break;
		}
	}
	system("cls");
}
void delete_select(Select sclist[], int* sccount)//根据学号删除若干选课，返回剩余选课
{
	int i; char k[20];
	printf_s("输入要删除选课学生的学号:");
	fflush(stdin);
	scanf("%d", k);
	for (i = 0; i < *sccount; i++)
	{
		if (strcmp(sclist[i].xh ,k)==0)
		{
			if (i == *sccount)*sccount -= 1;
			else
			{
				sclist[i] = sclist[*sccount - 1];
				*sccount -= 1;
			}
			break;
		}
	}
	system("cls");
}
//6、以下查询信息
int search_xsxh(Student slist[], int n, char x[])
{
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(x, slist[i].xh) == 0)
		{
			return i;
		}
	return -1;
}
int search_xsxm(Student slist[], int n, char x[])
{
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(x, slist[i].xm) == 0)
		{
			return i; break;
		}
	return -1;
}
void query_stud(Student slist[], int scount)//根据学号或姓名查询学生并显示
{
	int xz, i; char xh[50], c, xm[50];
	printf_s("学号查询请选1，姓名查询请选2："); scanf_s("%d", &xz);
	if (xz == 1)
	{
		do
		{
			printf_s("请输入学号:"); scanf("%s", xh);
			if ((i = (search_xsxh(slist, scount, xh))) >= 0)
			{
				printf_s(" * 该生基本信息如下\n");
				printf_s(" * 学号:%s\t", slist[i].xh);
				printf_s(" * 姓名:%s\t", slist[i].xm);
				printf_s(" * 性别:%s\t", slist[i].xb);
				printf_s(" * 年龄:%d\t", slist[i].nl);
			}
			else
			{
				printf_s(" * 学号输入有误，系统中暂无该生信息!\n");
			}
			printf_s("\n\n\t\t\t\t是否继续输入(Y/N):");
			scanf(" %c", &c);     //提示是否继续，从键盘获得一个字符//  
		} while (c == 'y' || c == 'Y');
	}
	else
	{
		do
		{
			fflush(stdin);
			printf_s("请输入姓名:"); scanf("%s", xm);
			if ((i = search_xsxm(slist, scount, xm)) >= 0)
			{
				printf_s(" * 该生基本信息如下\n");
				printf_s(" * 学号:%s\t", slist[i].xh);
				printf_s(" * 姓名:%s\t", slist[i].xm);
				printf_s(" * 性别:%s\t", slist[i].xb);
				printf_s(" * 年龄:%d\t", slist[i].nl);
			}
			else
			{
				printf_s(" * 姓名输入有误，系统中暂无该生信息!\n");
			}
			printf_s("\n\n\t\t\t\t是否继续输入(Y/N):");
			scanf(" %c", &c);     //提示是否继续，从键盘获得一个字符//  
		} while (c == 'y' || c == 'Y');
	}
}
//查询课程
int search_kckh(Course clist[], int n, char x[])
{
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(x, clist[i].kh) == 0)
		{
			return i;
		}
	return -1;
}
int search_kckm(Course clist[], int n, char x[])
{
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(x, clist[i].km) == 0)
		{
			return i;
		}
	return -1;
}
void query_course(Course clist[], int ccount)//根据课程号或课程名查询课程记录并显示
{
	int xz, i; char c, kh[20], km[20];
	printf_s("课号查询请选1，课名查询请选2："); scanf_s("%d", &xz);
	if (xz == 1)
	{
		do
		{
			printf_s("请输入课号:"); scanf("%s", kh);
			if ((i =( search_kckh(clist, ccount, kh))) >= 0)
			{
				printf_s(" * 该课程基本信息如下\n");
				printf_s(" * 课号:%s\t", clist[i].kh);
				printf_s(" * 课名:%s\t", clist[i].km);
				printf_s(" * 学分:%.2f\t", clist[i].xf);
			}
			else
			{
				printf_s(" * 课号输入有误，系统中暂无该课程信息!\n");
			}
			printf_s("\n\n\t\t\t\t是否继续输入(Y/N):");
			scanf(" %c", &c);     //提示是否继续，从键盘获得一个字符//  
		} while (c == 'y' || c == 'Y');
	}
	else
	{
		do
		{
			printf_s("请输入姓名:"); scanf("%s", km);
			if ((i = (search_kckm(clist, ccount, km))) >= 0)
			{
				printf_s(" * 该课程基本信息如下\n");
				printf_s(" * 课号:%s\t", clist[i].kh);
				printf_s(" * 课名:%s\t", clist[i].km);
				printf_s(" * 学分:%.2f\t", clist[i].xf);
			}
			else
			{
				printf_s(" * 姓名输入有误，系统中暂无该生信息!\n");
			}
			printf_s("\n\n\t\t\t\t是否继续输入(Y/N):");
			scanf(" %c", &c);     //提示是否继续，从键盘获得一个字符//  
		} while (c == 'y' || c == 'Y');
	}
}
//查成绩
int search_cj(Score cjlist[], int n, char x[])
{
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(x,cjlist[i].xh)==0)return i;
	return -1;
}
void query_cjlist(Score cjlist[], int cjcount, Course clist[], int ccount, Student slist[], int scount, Select sclist[], int sccount)//查询成绩单，显示成绩，平均分，学分，排名
{
	int  i; char c, xh[10];
	do
	{
		printf_s("请输入学号:"); scanf("%s", xh);
		if ((i = (search_cj(cjlist, scount, xh))) >= 0)
		{
			printf_s(" * 该生基本成绩如下\n");
			printf_s(" * 学号:%s\t", cjlist[i].xh);
			printf_s(" * 姓名:%s\t", cjlist[i].xm);
			//printf_s(" * 成绩:%.2\t", cjlist[i].cj);
			printf_s(" * 加权平均分:%.2f\t", cjlist[i].zpj);
			printf_s(" * 总学分:%.2f\t", cjlist[i].zxf);
		}
		else
		{
			printf_s(" * 学号输入有误，系统中暂无该生信息!\n");
		}
		printf_s("\n\n\t\t\t\t是否继续输入(Y/N):");
		scanf(" %c", &c);     //提示是否继续，从键盘获得一个字符//  
	} while (c == 'y' || c == 'Y');
}
//7、批量导出数据
void write_to_file1(Student slist[], int scount, Course clist[], int ccount, Select sclist[], int sccount)//以时间序列字符串为文件名，把学生信息表，课程信息表，选课信息表分别保存至对应磁盘文件
{
	FILE* fp1, * fp2, * fp3; int i;
	time_t timep;
	struct tm* p;
	char namexs[256], namekc[256], namexk[256];
	time(&timep);							//获取从1970至今过了多少秒，存入time_t类型的timep
	p = localtime(&timep);					//用localtime将秒数转化为struct tm结构体
	sprintf(namexs, "%d.%d.%d %d：%02d导出学生信息.txt", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min);//把格式化的时间写入字符数组中
	perror("");	//输出错误信息，但是，我的程序，又怎么可能又问题呢，哼哼！！！
	sprintf(namekc, "%d.%d.%d %d：%02d导出课程信息.txt", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min);//把格式化的时间写入字符数组中
	perror("");
	sprintf(namexk, "%d.%d.%d %d：%02d导出选课信息.txt", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min);//把格式化的时间写入字符数组中
	perror("");
	fp1 = fopen(namexs, "w"); fp2 = fopen(namekc, "w"); fp3 = fopen(namexk, "w");//直接覆盖式写入，无需判断是否打开成功
	fprintf(fp1, "序号\t学号\t\t姓名\t性别\t年龄\n");
	for (i = 0; i < scount; i++)
	{
		fprintf(fp1, "%d\t%s\t%s\t%s\t%.0d\n", (i + 1), slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}
	fprintf(fp2, "序号\t课号\t课名\t课程学分\n");
	for (i = 0; i < ccount; i++)
	{
		fprintf(fp2, "%d\t%s\t%s\t%.2f\n", (i + 1), clist[i].kh, clist[i].km, clist[i].xf);
	}
	fprintf(fp3, "序号\t学号\t\t课号\t分数\n");
	for (i = 0; i < sccount; i++)
	{
		fprintf(fp3, "%d\t%s\t%s\t%.2f\n", (i + 1), sclist[i].xh, sclist[i].kh, sclist[i].cj);
	}
	fclose(fp1); fclose(fp2); fclose(fp3);
	printf_s("导出成功!!!");
}
void write_to_file2(Student slist[], int scount, Score cjlist[], Course clist[], int ccount, Select sclist[], int sccount)//以时间序列字符串为文件名，把成绩单保存在磁盘文件中
{
	int i; char namecj[256]; time_t timep; struct tm* p;FILE *fp;
	time(&timep);
	p = localtime(&timep);
	sprintf(namecj, "%d.%d.%d %d：%02d导出成绩信息.txt", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min);//把格式化的时间写入字符数组中
	perror("");
	fp = fopen(namecj, "w");
	create_cjlist(slist, scount, sclist, sccount, clist, ccount, cjlist);
	sort_cjlist(cjlist, scount);
	fprintf(fp, "序号\t学号\t\t姓名\t\t总平均分\t\t总学分\n");
	for (i = 0; i < scount; i++)
	{
		fprintf(fp, "%d\t%s\t%s\t\t%.2f\t\t%.2f\n", (i + 1), cjlist[i].xh, cjlist[i].xm, cjlist[i].zpj, cjlist[i].zxf);
	}
	fclose(fp);
	printf_s("导出成功!!!");
}
int main()
{
	Student slist[400];																		//学生信息结构体数组
	Course clist[400];																		//课程信息结构体数组
	Select sclist[400];																		//选课信息结构体数组
	Score cjlist[400];																		//成绩信息结构体数组
	int scount = 0, sccount = 0, ccount = 0, cjcount = 0,flag = 1, choose, choosez;			//初始化
	while (flag)
	{
		main_menu();
		printf_s("* 请选择您的操作:");
		scanf_s("%d", &choose);
		printf_s("\n");
		switch (choose)
		{
		case 1:
			init(slist, &scount, clist, &ccount, sclist, &sccount);
			create_cjlist(slist, scount, sclist, sccount, clist, ccount, cjlist);
			back(); break;
		case 2:
			menu2();
			printf_s("* 请选择您的操作:"); scanf_s("%d", &choosez);
			switch (choosez)
			{
			case 1:
				disp_stud(slist, scount);
				back(); break;
			case 2:
				disp_course(clist, ccount);
				back(); break;
			case 3:
				disp_cjlist(cjlist, cjcount, clist, ccount, slist, scount, sclist, sccount);
				back(); break;
			case 0:
				back(); break;
			default:
				printf_s(" ------------ 选择错误,请重新选择! ------------ ");
				break;
			}break;
		case 3:
			menu3();
			printf_s("* 请选择您的操作:"); scanf_s("%d", &choosez);
			switch (choosez)
			{
			case 1:
				input_stud(slist, &scount); 
				back(); break;
			case 2:
				input_course(clist, &ccount);
				back(); break;
			case 3:
				input_select(sclist, &sccount);
				back(); break;
			case 0:
				back(); break;
			default:
				printf_s(" ------------ 选择错误,请重新选择! ------------ ");
				break;
			}break;
		case 4:
			menu4();
			printf_s("* 请选择您的操作:"); scanf_s("%d", &choosez);
			switch (choosez)
			{
			case 1:
				delete_stud(slist, &scount); 
				back(); break;
			case 2:
				delete_course(clist, &ccount); 
				back(); break;
			case 3:
				delete_select(sclist, &sccount);
				back(); break;
			case 0:
				 back(); break;
			default:
				printf_s(" ------------ 选择错误,请重新选择! ------------ ");
				break;
			}break;
		case 5:
			menu5();
			printf_s("* 请选择您的操作:"); scanf_s("%d", &choosez);
			switch (choosez)
			{
			case 1:
				query_stud(slist, scount);
				back(); break;
			case 2:
				query_course(clist, ccount);
				back(); break;
			case 3:
				query_cjlist(cjlist, cjcount, clist, ccount, slist, scount, sclist, sccount);
				back(); break;
			case 0:
				back(); break;
			default:
				printf_s(" ------------ 选择错误,请重新选择! ------------ ");
				break;
			}break;
		case 6:
			menu6();
			printf_s("* 请选择您的操作:"); scanf_s("%d", &choosez);
			switch (choosez)
			{
			case 1:
				write_to_file1(slist, scount, clist, ccount, sclist, sccount);
				back(); break;
			case 2:
				write_to_file2(slist, scount, cjlist, clist, ccount, sclist,sccount);
				back(); break;
			default:
				printf_s(" ------------ 选择错误,请重新选择! ------------ ");
				break;
			}break;
		case 0:
			flag = 0;
			printf_s("-----------------  The End ! -----------------\n");
			printf_s("------- 感谢您的使用,欢迎再次登录,拜拜！------\n");
			break;
		default:
			printf_s(" ------------ 选择错误,请重新选择! ------------ ");
			system("pause"); break;
		}
	}
}