/*
�����ʱ���������������visual studio 2019�б�д�ģ�����vs2010��֧��c99��д�������������vs2010��
���е�ʱ�򣬿��ܻ����δ�����ı�ʶ���ȴ������Ѿ����ܽ��й�c99д����Ϊvs2010֧�ֵ�c89д���������ų�
��Щ�ط�����©�������ʦ�������д��󣬻�����ʦ��̧���֣�����Ĳ����ҵ����⣬Ҫ�ֵù�10��ǰ��΢����
ʱ����û�����c99��д��������Ѿ���ȥ��10�꣬΢�������ˣ�����Ҳ�ø��������ˣ��������
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
typedef struct//ÿ��ѧ������Ԫ��Ϊһ���ṹ�����
{
	char xh[50];	//ѧ��
	char xm[50];	//������10����������
	char xb[10];		//�Ա�һ������
	int nl;			//����
}Student;
typedef struct//ÿ�ſγ���ϢΪһ���ṹ�����
{
	char kh[10];	//�κţ�10�ַ�����
	char km[25];	//������12��������
	float xf;		//�γ�ѧ�֣�1��������
}Course;
typedef struct//ѧ��ѡ����ϢΪһ���ṹ�����
{
	char xh[10];	//�κţ�10�ַ�����                          
	char kh[10];	//������12��������
	float cj;		//�ɼ���һ��������
}Select;
typedef struct
{
	char xh[10];	//ѧ��
	char xm[25];	//����
	//float cj;	//����Ŀ�ɼ�
	float zpj;		//��Ȩƽ����
	float zxf;		//��ѧ��
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
/*void init(Student slist[], int scount) //Course clist[], int* ccount, Select sclist[], int* sccount)//ͨ��ָ���ļ���װ���Ҫ��Ϣ
{
	FILE* fps, * fpc, * fpsc;
	fps=fopen("ѧ����Ϣ.txt","r");
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
//����6���˵�
void main_menu()//���˵�
{
	system("cls");
	printf_s("***************ѧ���ɼ�����ϵͳ****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: �����ʼ����                    *\n");
	printf_s("*          2: ��ʾ����                        *\n");
	printf_s("*          3: �����¼                        *\n");
	printf_s("*          4: ɾ����¼                        *\n");
	printf_s("*          5: ��ѯ��Ϣ                        *\n");
	printf_s("*          6: ������������                    *\n");
	printf_s("*          0: �˳�ѧ���ɼ�����ϵͳ            *\n");
	printf_s("*                                             *\n");
	printf_s("***********************************************\n");
	printf_s("��������ѡ��\n");
	fflush(stdin);
}
void back()//���غ���
{
	int x;
	do {
		printf_s(" * �� 0���ز˵�����\n");
		scanf_s("%d", &x);
		system("cls");
	} while (x != 0);
}
void menu2()//2���Ӳ˵�
{
	system("cls");
	printf_s("***************ѧ���ɼ�����ϵͳ****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: ��ʾѧ����Ϣ                    *\n");
	printf_s("*          2: ��ʾ�γ���Ϣ                    *\n");
	printf_s("*          3: ��ʾ�ɼ�����Ϣ                  *\n");
	printf_s("*          0: ����                            *\n");
	printf_s("***********************************************\n");
	printf_s("��������ѡ��\n");
}
void menu3()//3���Ӳ˵�
{
	system("cls");
	printf_s("***************ѧ���ɼ�����ϵͳ****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: ����ѧ����Ϣ                    *\n");
	printf_s("*          2: ����γ���Ϣ                    *\n");
	printf_s("*          3: ����ɼ���Ϣ                    *\n");
	printf_s("*          0: ����                            *\n");
	printf_s("***********************************************\n");
	printf_s("��������ѡ��\n");
}
void menu4()//4���Ӳ˵�
{
	system("cls");
	printf_s("***************ѧ���ɼ�����ϵͳ****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: ɾ��ѧ����Ϣ                    *\n");
	printf_s("*          2: ɾ���γ���Ϣ                    *\n");
	printf_s("*          3: ɾ���ɼ���Ϣ                    *\n");
	printf_s("*          0: ����                            *\n");
	printf_s("***********************************************\n");
	printf_s("��������ѡ��\n");
}
void menu5()//5���Ӳ˵�
{
	system("cls");
	printf_s("***************ѧ���ɼ�����ϵͳ****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: ��ѯѧ����Ϣ                    *\n");
	printf_s("*          2: ��ѯ�γ���Ϣ                    *\n");
	printf_s("*          3: ��ѯ�ɼ���Ϣ                    *\n");
	printf_s("*          0: ����                            *\n");
	printf_s("***********************************************\n");
	printf_s("��������ѡ��\n");
}
void menu6()//6���Ӳ˵�
{
	system("cls");
	printf_s("***************ѧ���ɼ�����ϵͳ****************\n");
	printf_s("*                                             *\n");
	printf_s("*          1: ��������ѧ�����γ̡�ѡ����Ϣ    *\n");
	printf_s("*          2: ���������ɼ���                  *\n");
	printf_s("*          0: ����                            *\n");
	printf_s("***********************************************\n");
	printf_s("��������ѡ��\n");
}

//1����ʼ��,void����
void init(Student slist[], int* scount, Course	clist[], int* ccount, Select sclist[], int* sccount)
{
	FILE* fs, * fc, * fsc;
	int n;
	fs = fopen("ѧ����Ϣ.txt", "r");
	if (fs == NULL)
	{
		printf("�ļ��޷���\n");
		exit(1);
	}
	for (n = 0; !feof(fs); n++)
	{
		fscanf(fs, "%s%s%s%d", slist[n].xh, slist[n].xm, slist[n].xb, &slist[n].nl);
	}
	fclose(fs);
	*scount = n;
	printf("�ѳɹ�����%d��ѧ������\n", n);
	fc = fopen("�γ���Ϣ.txt", "r");
	if (fc == NULL)
	{
		printf("�ļ��޷���\n");
		exit(1);
	}
	for (n = 0; !feof(fc); n++)
	{
		fscanf(fc, "%s%s%f", clist[n].kh, clist[n].km, &clist[n].xf);
	}
	fclose(fc);
	*ccount = n;
	printf("�ѳɹ�����%d���γ�����\n", n);
	fsc = fopen("�ɼ���Ϣ.txt", "r");
	if (fsc == NULL)
	{
		printf("�ļ��޷���\n");
		exit(1);
	}
	for (n = 0; !feof(fsc); n++)
	{
		fscanf(fsc, "%s%s%f", sclist[n].xh, sclist[n].kh, &sclist[n].cj);
	}
	fclose(fsc);
	*sccount = n;
	printf("�ѳɹ�����%d���ɼ�����\n", n);
}

/*void init(Student slist[], int* scount, Course clist[], int* ccount, Select sclist[], int* sccount)//��ʼ������
{
	int count;
	FILE* file = NULL;
	char str[255];

	//init_slist begin
	printf_s("������Ҫ��ȡ��ѧ���б��ļ�����Ҫѡ��Ĭ���ļ��������롰.����\n");
	scanf("%s", str);
	fflush(stdin);
	if (strcmp(str, ".") == 0)
	{
		strcpy(str, "slist.txt");
	}
	file = fopen(str, "r");
	while (!file)
	{
		printf_s("�Ҳ������ļ������������롣��Ҫѡ��Ĭ���ļ��������롰.����\n");
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
	printf_s("������Ҫ��ȡ�Ŀγ��б��ļ�����Ҫѡ��Ĭ���ļ��������롰.����\n");
	scanf("%s", str);
	fflush(stdin);
	if (strcmp(str, ".") == 0)
	{
		strcpy(str, "clist.txt");
	}
	file = fopen(str, "r");
	while (!file)
	{
		printf_s("�Ҳ������ļ������������롣��Ҫѡ��Ĭ���ļ��������롰.����\n");
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
	printf_s("������Ҫ��ȡ��ѡ���б��ļ�����Ҫѡ��Ĭ���ļ��������롰.����\n");
	scanf("%s", str);
	fflush(stdin);
	if (strcmp(str, ".") == 0)
	{
		strcpy(str, "sclist.txt");
	}
	file = fopen(str, "r");
	while (!file)
	{
		printf_s("�Ҳ������ļ������������롣��Ҫѡ��Ĭ���ļ��������롰.����\n");
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

//2�������ɼ���
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
	for (i = 0; i < *scount; i++)//ѧ������
	{
		for (j = 0, zxf = 0, zcj = 0, cjlist[i].zxf = 0; j < *sccount; j++)//�Ƿ��и�ѧ���ĳɼ�
		{
			if (strcmp(slist[i].xh, sclist[j].xh) == 0)
			{
				for (k = 0; k < *ccount; k++)//ȥ�γ���Ϣ����ѧ��
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

			if (strcmp(slist[i].xh, sclist[j].xh) == 0)//ѡ�˸��ſγ�
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
//3��������ʾ����
	//����3������
void sort_slist(Student slist[], int scount)//ѧ������
{
	int i, j; Student temp;
	//FILE* fp;													//����һ���ļ�ָ��fp
	system("cls");												//����
	//count();													//ʵʱ�������n
	for (i = 0; i < scount - 1; i++)
		for (j = 0; j < scount - 1 - i; j++)					//��ѧ�Ŷ�ѧ����Ϣ��������
		{
			if (strcmp(slist[j].xh, slist[j + 1].xh) > 0)				//�������ֵıȽ�
			{
				temp = slist[j];
				slist[j] = slist[j + 1];
				slist[j + 1] = temp;
			}
		}

	/*fp = fopen("slist.txt", "w+");  //�� ����д����ʽ��students�ı��ļ�//
	for (i = 0; i < scount; i++)
		fwrite(&slist[i], sizeof(Student), 1, fp);  //�Խṹ��students�ķ�ʽ���ļ�fp�ж�ȡ������д��students�ı��ļ���ÿ��д��һ��ѧ������Ϣ//
	fclose(fp);      �ر��ļ�*/

}
void sort_clist(Course clist[], int ccount)//�γ̺�����
{
	int i, j; Course temp;
	//FILE* fp;											//����һ���ļ�ָ��fp//
	system("cls");										//����
	//count();											//ʵʱ�������n 
	for (i = 0; i < ccount - 1; i++)
		for (j = 0; j < ccount - 1 - i; j++)			//��ѧ�Ŷ�ѧ����Ϣ��������//
		{
			if (strcmp(clist[j].kh, clist[j + 1].kh) > 0)		//�������ֵıȽ�//
			{
				temp = clist[j];
				clist[j] = clist[j + 1];
				clist[j + 1] = temp;
			}
		}
}
void sort_cjlist(Score cjlist[], int scount)//ƽ���ɼ�����
{
	int i, j; Score temp;
	system("cls");															//����
	//count();																//ʵʱ�������n
	for (i = 0; i < scount - 1; i++)
		for (j = 0; j < scount - 1 - i; j++)								//��ѧ�Ŷ�ѧ����Ϣ��������
		{
			if (cjlist[j].zpj < cjlist[j + 1].zpj)								//�������ֵıȽ�
			{
				temp = cjlist[j];
				cjlist[j] = cjlist[j + 1];
				cjlist[j + 1] = temp;
			}
		}
}
//����3����ʾ
void disp_stud(Student slist[], int scount)//��ʾѧ��
{
	int i;
	sort_slist(slist, scount);
	printf("ѧ��\t\t����\t\t�Ա�\t����\n");
	for (i = 0; i < scount; i++)
	{
		printf("%s\t%s\t\t%s\t%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}
}
void disp_course(Course clist[], int ccount)//��ʾ�γ�
{
	int i = 0;
	sort_clist(clist, ccount);
	printf("�κ�\t����\tѧ��\n");
	for (i; i < ccount; i++)
	{
		printf("%s\t%s\t%.1f\n", clist[i].kh, clist[i].km, clist[i].xf);
	}
}
void disp_cjlist(Score cjlist[], int cjcount, Course clist[], int ccount, Student slist[], int scount, Select sclist[], int sccount)//��ʾ�ɼ�
{
	int i = 0;
	create_cjlist(slist, scount, sclist, sccount, clist, ccount, cjlist);
	sort_cjlist(cjlist, scount);
	printf("ѧ��\t\t����\t\tƽ����\t����ϰѧ��\n");
	for (i = 0; i < scount; i++)
	{
		printf_s("%s\t%s\t\t%.1f\t%.1f\n", cjlist[i].xh, cjlist[i].xm, cjlist[i].zpj, cjlist[i].zxf);
	}
}

//4������3����������
void input_stud(Student slist[], int* scount)//����ѧ����Ϣ�����ѧ���ṹ������slist��scountΪ����ԭ��ѧ����¼������ѧ����¼��
{
	//int i = 0;     //ѧ��������ʼ��//
	char c;
	//FILE* fp;     //����һ���ļ�ָ��fp//
	//count();     //ʵʱ�������n//
	//fp = fopen("slist.txt", "at+");    //�ԡ�׷�ӡ���ʽ��students�ı��ļ�//
	do
	{
		printf_s("������ѧ���ĸ�����Ϣ:\n");
		printf_s("������ѧ����ѧ��:"); scanf("%s", &slist[*scount].xh);
		printf_s("������ѧ��������:"); scanf("%s", slist[*scount].xm);
		printf_s("������ѧ���Ա�:"); scanf("%s", slist[*scount].xb);
		printf_s("������ѧ������:"); scanf_s("%d", &slist[*scount].nl); getchar();
		//fwrite(&slist[*scount], sizeof(Student), 1, fp);  //�Է�ʽ����д��students�ı��ļ�//
		*scount += 1;
		printf_s("\n\n\t\t\t\t�Ƿ��������(Y/N):"); c = getchar();     //��ʾ�Ƿ�������Ӽ��̻��һ���ַ�//  
	} while (c == 'y' || c == 'Y');
	//fclose(fp);
}
void input_course(Course clist[], int* ccount)//����γ���Ϣ������γ���Ϣ�ṹ������clist��ccountΪԭ�пγ̼�¼�����ؿγ̼�¼��
{
	//int i = 0;     //ѧ��������ʼ��//
	char c;
	//FILE* fp;     //����һ���ļ�ָ��fp//
	//count();     //ʵʱ�������n//
	//fp = fopen("clist.txt", "at+");    //�ԡ�׷�ӡ���ʽ��
	do
	{
		printf_s("������γ���Ϣ:\n");
		printf_s("������κ�:"); scanf("%s", clist[*ccount].kh);
		printf_s("���������:"); scanf("%s", clist[*ccount].km); //getchar();
		printf_s("������γ�ѧ�֣�"); scanf_s("%lf", &clist[*ccount].xf);//getchar();
		*ccount += 1;
		printf_s("\n\n\t\t\t\t�Ƿ��������(Y/N):"); getchar();     //��ʾ�Ƿ�������Ӽ��̻��һ���ַ�//  
		c = getchar();
	} while (c == 'y' || c == 'Y');
	//fclose(fp);
}
void input_select(Select sclist[], int* sccount)//����ѡ�δ����ѧ��ѡ����Ϣ�ṹ������sclist��sccountΪԭ��ѡ�μ�¼���޳ɼ���-1��ʾ������ѡ�μ�¼����
{
	//int i = 0;     //ѧ��������ʼ��//
	char c;
	//FILE* fp;    //����һ���ļ�ָ��fp//
	//count();    //ʵʱ�������n//
	//fp = fopen("sclist.txt", "at+");    //�ԡ�׷�ӡ���ʽ��students�ı��ļ�//
	do
	{
		printf_s("������ѧ��ѡ����Ϣ:\n");
		printf_s("������ѧ����ѧ��:"); scanf("%s", sclist[*sccount].xh);
		printf_s("������κ�:"); scanf("%s", sclist[*sccount].kh);				//getchar();
		printf_s("������ѧ���ɼ�"); scanf_s("%lf", &sclist[*sccount].cj);		//getchar();
		//fwrite(&sclist[*sccount], sizeof(Select), 1, fp);//�Է�ʽ����д��students�ı��ļ�	
		*sccount++;
		printf_s("\n\n\t\t\t\t�Ƿ��������(Y/N):"); getchar();			//��ʾ�Ƿ�������Ӽ��̻��һ���ַ�  
		c = getchar();
	} while (c == 'y' || c == 'Y');
	//fclose(fp);
}
//5������3��ɾ����¼
void delete_stud(Student slist[], int* scount)//����������ѧ��ɾ������ѧ��������ʣ��ѧ��
{
	int i; char xz, name[20], k[20];
	printf_s("�Ƿ����ѧ��ɾ��y/n��\n"); scanf(" %c", &xz);
	if (xz == 'y' || xz == 'Y')
	{
		printf("����Ҫɾ��ѧ��ѧ��:");
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
		printf("����Ҫɾ��ѧ������:");
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
void delete_course(Course clist[], int* ccount)//���ݿγ�����γ̺�ɾ���γ̣�����ʣ��γ�
{

	char k[50]; int i;
	printf_s("����Ҫɾ���γ̿κ�:");
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
void delete_select(Select sclist[], int* sccount)//����ѧ��ɾ������ѡ�Σ�����ʣ��ѡ��
{
	int i; char k[20];
	printf_s("����Ҫɾ��ѡ��ѧ����ѧ��:");
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
//6�����²�ѯ��Ϣ
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
void query_stud(Student slist[], int scount)//����ѧ�Ż�������ѯѧ������ʾ
{
	int xz, i; char xh[50], c, xm[50];
	printf_s("ѧ�Ų�ѯ��ѡ1��������ѯ��ѡ2��"); scanf_s("%d", &xz);
	if (xz == 1)
	{
		do
		{
			printf_s("������ѧ��:"); scanf("%s", xh);
			if ((i = (search_xsxh(slist, scount, xh))) >= 0)
			{
				printf_s(" * ����������Ϣ����\n");
				printf_s(" * ѧ��:%s\t", slist[i].xh);
				printf_s(" * ����:%s\t", slist[i].xm);
				printf_s(" * �Ա�:%s\t", slist[i].xb);
				printf_s(" * ����:%d\t", slist[i].nl);
			}
			else
			{
				printf_s(" * ѧ����������ϵͳ�����޸�����Ϣ!\n");
			}
			printf_s("\n\n\t\t\t\t�Ƿ��������(Y/N):");
			scanf(" %c", &c);     //��ʾ�Ƿ�������Ӽ��̻��һ���ַ�//  
		} while (c == 'y' || c == 'Y');
	}
	else
	{
		do
		{
			fflush(stdin);
			printf_s("����������:"); scanf("%s", xm);
			if ((i = search_xsxm(slist, scount, xm)) >= 0)
			{
				printf_s(" * ����������Ϣ����\n");
				printf_s(" * ѧ��:%s\t", slist[i].xh);
				printf_s(" * ����:%s\t", slist[i].xm);
				printf_s(" * �Ա�:%s\t", slist[i].xb);
				printf_s(" * ����:%d\t", slist[i].nl);
			}
			else
			{
				printf_s(" * ������������ϵͳ�����޸�����Ϣ!\n");
			}
			printf_s("\n\n\t\t\t\t�Ƿ��������(Y/N):");
			scanf(" %c", &c);     //��ʾ�Ƿ�������Ӽ��̻��һ���ַ�//  
		} while (c == 'y' || c == 'Y');
	}
}
//��ѯ�γ�
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
void query_course(Course clist[], int ccount)//���ݿγ̺Ż�γ�����ѯ�γ̼�¼����ʾ
{
	int xz, i; char c, kh[20], km[20];
	printf_s("�κŲ�ѯ��ѡ1��������ѯ��ѡ2��"); scanf_s("%d", &xz);
	if (xz == 1)
	{
		do
		{
			printf_s("������κ�:"); scanf("%s", kh);
			if ((i =( search_kckh(clist, ccount, kh))) >= 0)
			{
				printf_s(" * �ÿγ̻�����Ϣ����\n");
				printf_s(" * �κ�:%s\t", clist[i].kh);
				printf_s(" * ����:%s\t", clist[i].km);
				printf_s(" * ѧ��:%.2f\t", clist[i].xf);
			}
			else
			{
				printf_s(" * �κ���������ϵͳ�����޸ÿγ���Ϣ!\n");
			}
			printf_s("\n\n\t\t\t\t�Ƿ��������(Y/N):");
			scanf(" %c", &c);     //��ʾ�Ƿ�������Ӽ��̻��һ���ַ�//  
		} while (c == 'y' || c == 'Y');
	}
	else
	{
		do
		{
			printf_s("����������:"); scanf("%s", km);
			if ((i = (search_kckm(clist, ccount, km))) >= 0)
			{
				printf_s(" * �ÿγ̻�����Ϣ����\n");
				printf_s(" * �κ�:%s\t", clist[i].kh);
				printf_s(" * ����:%s\t", clist[i].km);
				printf_s(" * ѧ��:%.2f\t", clist[i].xf);
			}
			else
			{
				printf_s(" * ������������ϵͳ�����޸�����Ϣ!\n");
			}
			printf_s("\n\n\t\t\t\t�Ƿ��������(Y/N):");
			scanf(" %c", &c);     //��ʾ�Ƿ�������Ӽ��̻��һ���ַ�//  
		} while (c == 'y' || c == 'Y');
	}
}
//��ɼ�
int search_cj(Score cjlist[], int n, char x[])
{
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(x,cjlist[i].xh)==0)return i;
	return -1;
}
void query_cjlist(Score cjlist[], int cjcount, Course clist[], int ccount, Student slist[], int scount, Select sclist[], int sccount)//��ѯ�ɼ�������ʾ�ɼ���ƽ���֣�ѧ�֣�����
{
	int  i; char c, xh[10];
	do
	{
		printf_s("������ѧ��:"); scanf("%s", xh);
		if ((i = (search_cj(cjlist, scount, xh))) >= 0)
		{
			printf_s(" * ���������ɼ�����\n");
			printf_s(" * ѧ��:%s\t", cjlist[i].xh);
			printf_s(" * ����:%s\t", cjlist[i].xm);
			//printf_s(" * �ɼ�:%.2\t", cjlist[i].cj);
			printf_s(" * ��Ȩƽ����:%.2f\t", cjlist[i].zpj);
			printf_s(" * ��ѧ��:%.2f\t", cjlist[i].zxf);
		}
		else
		{
			printf_s(" * ѧ����������ϵͳ�����޸�����Ϣ!\n");
		}
		printf_s("\n\n\t\t\t\t�Ƿ��������(Y/N):");
		scanf(" %c", &c);     //��ʾ�Ƿ�������Ӽ��̻��һ���ַ�//  
	} while (c == 'y' || c == 'Y');
}
//7��������������
void write_to_file1(Student slist[], int scount, Course clist[], int ccount, Select sclist[], int sccount)//��ʱ�������ַ���Ϊ�ļ�������ѧ����Ϣ���γ���Ϣ��ѡ����Ϣ��ֱ𱣴�����Ӧ�����ļ�
{
	FILE* fp1, * fp2, * fp3; int i;
	time_t timep;
	struct tm* p;
	char namexs[256], namekc[256], namexk[256];
	time(&timep);							//��ȡ��1970������˶����룬����time_t���͵�timep
	p = localtime(&timep);					//��localtime������ת��Ϊstruct tm�ṹ��
	sprintf(namexs, "%d.%d.%d %d��%02d����ѧ����Ϣ.txt", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min);//�Ѹ�ʽ����ʱ��д���ַ�������
	perror("");	//���������Ϣ�����ǣ��ҵĳ�������ô�����������أ��ߺߣ�����
	sprintf(namekc, "%d.%d.%d %d��%02d�����γ���Ϣ.txt", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min);//�Ѹ�ʽ����ʱ��д���ַ�������
	perror("");
	sprintf(namexk, "%d.%d.%d %d��%02d����ѡ����Ϣ.txt", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min);//�Ѹ�ʽ����ʱ��д���ַ�������
	perror("");
	fp1 = fopen(namexs, "w"); fp2 = fopen(namekc, "w"); fp3 = fopen(namexk, "w");//ֱ�Ӹ���ʽд�룬�����ж��Ƿ�򿪳ɹ�
	fprintf(fp1, "���\tѧ��\t\t����\t�Ա�\t����\n");
	for (i = 0; i < scount; i++)
	{
		fprintf(fp1, "%d\t%s\t%s\t%s\t%.0d\n", (i + 1), slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}
	fprintf(fp2, "���\t�κ�\t����\t�γ�ѧ��\n");
	for (i = 0; i < ccount; i++)
	{
		fprintf(fp2, "%d\t%s\t%s\t%.2f\n", (i + 1), clist[i].kh, clist[i].km, clist[i].xf);
	}
	fprintf(fp3, "���\tѧ��\t\t�κ�\t����\n");
	for (i = 0; i < sccount; i++)
	{
		fprintf(fp3, "%d\t%s\t%s\t%.2f\n", (i + 1), sclist[i].xh, sclist[i].kh, sclist[i].cj);
	}
	fclose(fp1); fclose(fp2); fclose(fp3);
	printf_s("�����ɹ�!!!");
}
void write_to_file2(Student slist[], int scount, Score cjlist[], Course clist[], int ccount, Select sclist[], int sccount)//��ʱ�������ַ���Ϊ�ļ������ѳɼ��������ڴ����ļ���
{
	int i; char namecj[256]; time_t timep; struct tm* p;FILE *fp;
	time(&timep);
	p = localtime(&timep);
	sprintf(namecj, "%d.%d.%d %d��%02d�����ɼ���Ϣ.txt", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min);//�Ѹ�ʽ����ʱ��д���ַ�������
	perror("");
	fp = fopen(namecj, "w");
	create_cjlist(slist, scount, sclist, sccount, clist, ccount, cjlist);
	sort_cjlist(cjlist, scount);
	fprintf(fp, "���\tѧ��\t\t����\t\t��ƽ����\t\t��ѧ��\n");
	for (i = 0; i < scount; i++)
	{
		fprintf(fp, "%d\t%s\t%s\t\t%.2f\t\t%.2f\n", (i + 1), cjlist[i].xh, cjlist[i].xm, cjlist[i].zpj, cjlist[i].zxf);
	}
	fclose(fp);
	printf_s("�����ɹ�!!!");
}
int main()
{
	Student slist[400];																		//ѧ����Ϣ�ṹ������
	Course clist[400];																		//�γ���Ϣ�ṹ������
	Select sclist[400];																		//ѡ����Ϣ�ṹ������
	Score cjlist[400];																		//�ɼ���Ϣ�ṹ������
	int scount = 0, sccount = 0, ccount = 0, cjcount = 0,flag = 1, choose, choosez;			//��ʼ��
	while (flag)
	{
		main_menu();
		printf_s("* ��ѡ�����Ĳ���:");
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
			printf_s("* ��ѡ�����Ĳ���:"); scanf_s("%d", &choosez);
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
				printf_s(" ------------ ѡ�����,������ѡ��! ------------ ");
				break;
			}break;
		case 3:
			menu3();
			printf_s("* ��ѡ�����Ĳ���:"); scanf_s("%d", &choosez);
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
				printf_s(" ------------ ѡ�����,������ѡ��! ------------ ");
				break;
			}break;
		case 4:
			menu4();
			printf_s("* ��ѡ�����Ĳ���:"); scanf_s("%d", &choosez);
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
				printf_s(" ------------ ѡ�����,������ѡ��! ------------ ");
				break;
			}break;
		case 5:
			menu5();
			printf_s("* ��ѡ�����Ĳ���:"); scanf_s("%d", &choosez);
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
				printf_s(" ------------ ѡ�����,������ѡ��! ------------ ");
				break;
			}break;
		case 6:
			menu6();
			printf_s("* ��ѡ�����Ĳ���:"); scanf_s("%d", &choosez);
			switch (choosez)
			{
			case 1:
				write_to_file1(slist, scount, clist, ccount, sclist, sccount);
				back(); break;
			case 2:
				write_to_file2(slist, scount, cjlist, clist, ccount, sclist,sccount);
				back(); break;
			default:
				printf_s(" ------------ ѡ�����,������ѡ��! ------------ ");
				break;
			}break;
		case 0:
			flag = 0;
			printf_s("-----------------  The End ! -----------------\n");
			printf_s("------- ��л����ʹ��,��ӭ�ٴε�¼,�ݰݣ�------\n");
			break;
		default:
			printf_s(" ------------ ѡ�����,������ѡ��! ------------ ");
			system("pause"); break;
		}
	}
}