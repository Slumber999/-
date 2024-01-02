#include"head.h"

void puthead()
{
	puts("-----------------------------------------");
	puts("|-------欢迎来到学生信息管理系统!-------|");
	puts("|---------------------------------------|");
}


void puthead_() {
	puts("|------------请输入操作指令-------------|");
	puts("|                                       |");
	puts("|          1.录入学生信息               |");
	puts("|          2.删除学生信息               |");
	puts("|          3.修改学生信息               |");
	puts("|          4.插入学生信息               |");
	puts("|          5.显示当前学生信息           |");
	puts("|          6.按成绩降序排序             |");
	puts("|          7.按学号查询学生信息         |");
	puts("|          8.输出各科目不及格学生       |");
	puts("|          9.输出各科最高分             |");
	puts("|          10.分组统计学生信息          |");
	puts("|          11.评优                      |");
	puts("|          12.分析学生学习状态          |");
	puts("|          13.分析学生是否偏科          |");
	puts("|          14.考试通过率                |");
	puts("|          0.结束并保存                 |");
	puts("|                                       |");
	puts("-----------------------------------------");
}


int search(char searchid[])											//根据id查找位置函数
{																	//查找成功返回下标，不成功返回-1
	for (int i = 0; i < N; i++)
	{
		if (strcmp(students[i].id, searchid) == 0)
			return i;
	}
	return -1;
}


bool check()														//检查是否存在相同id 
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (strcmp(students[i].id, students[j].id) == 0)
			{
				return false;
			}
		}
	}
	return true;
}


bool _check(char student[])											//检查插入的学生学号是否与已录入学生重复
{
	for (int i = 0; i < N - 1; i++) 
	{
		if (strcmp(students[i].id, student) == 0)
		{
			return false;
		}
	}
	return true;
}


void check150(double x, int biao, int kemu)							//检查是否超过输入范围
{
	if (x > 150 || x < 0)
	{
		printf("您输入的数超出了范围，请重新输入：");
		if (kemu == 1)
		{
			scanf("%lf", &students[biao].computer);
			check150(students[biao].computer, biao, kemu);
		}
		if (kemu == 2)
		{
			scanf("%lf", &students[biao].math);
			check150(students[biao].math, biao, kemu);
		}
	}
}


void check100(double x, int biao, int kemu)							//检查是否超过输入范围
{
	if (x > 100 || x < 0)
	{
		printf("您输入的数超出了范围，请重新输入：");
		if (kemu == 3)
		{
			scanf("%lf", &students[biao].english);
			check100(students[biao].english, biao, kemu);
		}
		if (kemu == 4)
		{
			scanf("%lf", &students[biao].politics);
			check100(students[biao].politics, biao, kemu);
		}
	}
}


void display()														//展示当前学生信息
{
	printf("当前学生信息为:\n");
	puts("    学号        姓名         计算机   高数    英语    政治   总分");
	for (int i = 0; i < N; i++)
	{
		printf("%-4d%-12s%-10s%8.2lf%8.2lf%8.2lf%8.2lf%8.2lf\n", i + 1, students[i].id, students[i].name, students[i].computer, students[i].math, students[i].english, students[i].politics, students[i].sum);
	}
	printf("当前平均分为:%.2lf\n\n\n", SUM / N);
}


void input()
{
	int n;
	printf("录入学生人数:");
	scanf("%d", &n);
	while (n <= 0)
	{
		printf("您输入的人数为0或者是负数，请重新输入:");
		scanf("%d", &n);
	}
	
	
	for (int i = N, j = 0; i < N + n; i++, j++)
	{
		printf("第%d个学生:\n", j + 1);
		printf("学号:");
		scanf("%s", students[i].id);

		printf("姓名:");
		scanf("%s", students[i].name);

		printf("计算机成绩(0-150):");
		scanf("%lf", &students[i].computer);
		check150(students[i].computer, i, 1);										//检查输入数字是否超出范围

		printf("高数成绩(0-150):");
		scanf("%lf", &students[i].math);
		check150(students[i].math, i, 2);

		printf("英语成绩(0-100):");
		scanf("%lf", &students[i].english);
		check100(students[i].english, i, 3);

		printf("政治成绩(0-100):");
		scanf("%lf", &students[i].politics);
		check100(students[i].politics, i, 4);

		students[i].sum = students[i].computer + students[i].math + students[i].english + students[i].politics;
		SUM += students[i].sum;
	}
	N = n + N;
	if (check() == false)												//查重
	{
		N = N - n;
		system("cls");
		puts("输入中含有重复id，请检查并重新输入！");
		input();
	}
	else
	{
		puts("录入成功！\n");
		display();
	}
}



void _delete()														//删除学生信息
{
	char searchid[ID_LENGTH];
	printf("请输入学生学号:");
	scanf("%s", searchid);
	int sea = search(searchid);										//等待删除的学生位置下标
	if (sea != -1)
	{
		SUM -= students[sea].sum;									//修改平均成绩
		for (int i = sea + 1; i < N; i++)
		{
			students[i - 1] = students[i];							//sea之后的所有学生前移一位，覆盖sea处学生信息
		}
		N--;														//总人数减一
		display();
	}
	else 
	{
		puts("查无此人！");
	}
}


void reset()
{
	char searchid[ID_LENGTH];
	printf("请输入学生学号:");
	scanf("%s", &searchid);
	int sea = search(searchid);
	if (sea != -1)
	{
		SUM -= students[sea].sum;									//修改平均成绩
		puts("请输入改写后的信息:");
		printf("计算机成绩(0-150):");
		scanf("%lf", &students[sea].computer);
		check150(students[sea].computer, sea, 1);					//检查

		printf("高数成绩(0-150):");
		scanf("%lf", &students[sea].math);
		check150(students[sea].math, sea, 2);

		printf("英语成绩(0-100):");
		scanf("%lf", &students[sea].english);
		check100(students[sea].english, sea, 3);

		printf("政治成绩(0-100):");
		scanf("%lf", &students[sea].politics);
		check100(students[sea].politics, sea, 4);

		students[sea].sum = students[sea].computer + students[sea].math + students[sea].english + students[sea].politics;
		SUM += students[sea].sum;
		puts("修改完成:");
		display();
	}
	else
	{
		puts("查无此人！");
	}
}


void insert()
{
	N++;
	puts("请输入要插入的学生信息:");
	printf("学号:");
	scanf("%s", &students[N - 1].id);

	printf("姓名:");
	scanf("%s", &students[N - 1].name);

	printf("计算机成绩(0-150):");
	scanf("%lf", &students[N - 1].computer);
	check150(students[N - 1].computer, N - 1, 1);

	printf("高数成绩(0-150):");
	scanf("%lf", &students[N - 1].math);
	check150(students[N - 1].math, N - 1, 2);

	printf("英语成绩(0-100):");
	scanf("%lf", &students[N - 1].english);
	check150(students[N - 1].english, N - 1, 3);

	printf("政治成绩(0-100):");
	scanf("%lf", &students[N - 1].politics);
	check150(students[N - 1].politics, N - 1, 4);

	students[N - 1].sum = students[N - 1].computer + students[N - 1].math + students[N - 1].english + students[N - 1].politics;
	SUM += students[N - 1].sum;

	if (_check(students[N - 1].id) == false)								//查重
	{
		N--;																//删除错误插入的数据
		system("cls");
		puts("插入了重复id，请检查并重新插入！");
		insert();
	}
	else
	{
		puts("插入完成！");
		display();
	}
}



void sort()
{
	puts("-------------请输入操作指令--------------");
	puts("|                                       |");
	puts("|          1.按总成绩排序               |");
	puts("|          2.按计算机成绩排序           |");
	puts("|          3.按高数成绩排序             |");
	puts("|          4.按英语成绩排序             |");
	puts("|          5.按政治成绩排序             |");
	puts("|                                       |");
	puts("-----------------------------------------");

	int item;
	printf("您的指令:");
	scanf("%d", &item);
	switch (item) 
	{
		case 1:
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = N - 1; j > i; j--)
				{
					if (students[j].sum > students[j - 1].sum)
					{
						s change = students[j];
						students[j] = students[j - 1];
						students[j - 1] = change;
					}
				}
			}
			system("cls");
			puts("按总成绩降序排序后:\n");
			break;
		}
		case 2:
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = N - 1; j > i; j--)
				{
					if (students[j].computer > students[j - 1].computer)
					{
						s change = students[j];
						students[j] = students[j - 1];
						students[j - 1] = change;
					}
				}
			}
			system("cls");
			puts("按计算机成绩降序排序后:\n");
			break;
		}
		case 3:
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = N - 1; j > i; j--)
				{
					if (students[j].math > students[j - 1].math)
					{
						s change = students[j];
						students[j] = students[j - 1];
						students[j - 1] = change;
					}
				}
			}
			system("cls");
			puts("按高数成绩降序排序后:\n");
			break;
		}
		case 4:
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = N - 1; j > i; j--)
				{
					if (students[j].english > students[j - 1].english)
					{
						s change = students[j];
						students[j] = students[j - 1];
						students[j - 1] = change;
					}
				}
			}
			system("cls");
			puts("按英语成绩降序排序后:\n");
			break;
		}
		case 5:
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = N - 1; j > i; j--)
				{
					if (students[j].politics > students[j - 1].politics)
					{
						s change = students[j];
						students[j] = students[j - 1];
						students[j - 1] = change;
					}
				}
			}
			system("cls");
			puts("按政治成绩降序排序后:\n");
			break;
		}
		default:break;
	}
	display();
}


void searchid()
{
	char searchid[ID_LENGTH];
	printf("请输入学生学号:");
	scanf("%s", &searchid);
	int sea = search(searchid);
	if (sea != -1)
	{
		puts("查询成功:\n");
		printf("\n      学号:  %s",students[sea].id);
		printf("\n      姓名:  %s", students[sea].name);
		printf("\n计算机成绩:  %.2lf", students[sea].computer);
		printf("\n  高数成绩:  %.2lf", students[sea].math);
		printf("\n  英语成绩:  %.2lf", students[sea].english);
		printf("\n  政治成绩:  %.2lf", students[sea].politics);
		printf("\n      总分:  %.2lf\n\n\n", students[sea].sum);
	}
	else
	{
		puts("查无此人！");
	}
}


void displaybjg()
{
	int chazhao = 0;
	puts("-------------请输入操作指令--------------");
	puts("|                                       |");
	puts("|          1.查找计算机不及格的学生     |");
	puts("|          2.查找高数不及格的学生       |");
	puts("|          3.查找英语不及格的学生       |");
	puts("|          4.查找政治不及格的学生       |");
	puts("|          5.查找各科不及格的学生       |");
	puts("|                                       |");
	puts("-----------------------------------------");
	printf("您的指令:");
	scanf("%d", &chazhao);
	system("cls");

	int panduan = 0;
	if (chazhao == 1 || chazhao == 5)
	{
		for (int i = 0; i < N; i++)
		{
			if (students[i].computer < 90 )
			{
				panduan++;
				if (panduan == 1)
				{
					printf("计算机不及格的学生：\n\n");
					puts("             学号        姓名        成绩");
				}
				printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].computer);
			}
			
		}
		if (panduan == 0)
			printf("计算机全都及格(〃＾▽＾〃)\n\n");
		else
			printf("\n");
		panduan = 0;
	}

	if (chazhao == 2 || chazhao == 5)
	{
		for (int i = 0; i < N; i++)
		{
			if (students[i].math < 90)
			{
				panduan++;
				if (panduan == 1)
				{
					printf("高数不及格的学生：\n\n");
					puts("             学号        姓名        成绩");
				}
				printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].math);
			}
		}
		if (panduan == 0)
			printf("高数全都及格(〃＾▽＾〃)\n\n");
		else
			printf("\n");
		panduan = 0;
	}

	if (chazhao == 3 || chazhao == 5)
	{
		for (int i = 0; i < N; i++)
		{
			if (students[i].english < 60)
			{
				panduan++;
				if (panduan == 1)
				{
				printf("英语不及格的学生：\n\n");
				puts("             学号        姓名        成绩");
				}
				printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].english);
			}
		}
		if (panduan == 0)
			printf("英语全都及格(〃＾▽＾〃)\n\n");
		else
			printf("\n");
		panduan = 0;
	}

	if (chazhao == 4 || chazhao == 5)
	{
		for (int i = 0; i < N; i++)
		{
			if (students[i].politics < 60)
			{
				panduan++;
				if (panduan == 1)
				{
				printf("政治不及格的学生：\n\n");
				puts("             学号        姓名        成绩");
				}
				printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].politics);
			}
		}
		if (panduan == 0)
			printf("政治全都及格(〃＾▽＾〃)\n\n");
		else
			printf("\n");
	}
}


void grouping()
{
	puts("-------------请输入操作指令--------------");
	puts("|                                       |");
	puts("|         1.查找低于平均分的学生        |");
	puts("|         2.查找高于平均分的学生        |");
	puts("|                                       |");
	puts("-----------------------------------------");
	printf("您的指令：");
	int i, n;
	scanf("%d", &n);
	switch (n)
	{
	case 1:
	{
		for (i = 0; i < N; i++)
		{
			if (students[i].sum < SUM / N)
				printf("学号：%s 姓名：%s 总分：%.2f\n", students[i].id, students[i].name, students[i].sum);
		}
	}break;
	case 2:
	{
		for (i = 0; i < N; i++)
		{
			if (students[i].sum > SUM / N)
				printf("学号：%s 姓名：%s 总分：%.2f\n", students[i].id, students[i].name, students[i].sum);
		}
	}break;
	default:break;
	}
}


void displaymax()
{
	int computer = 0, math = 0, english = 0, politics = 0;
	for (int i = 0; i < N; i++)
	{
		if (students[computer].computer < students[i].computer)
		{
			computer = i;
		}
		if (students[math].math < students[i].math)
		{
			math = i;
		}
		if (students[english].english < students[i].english)
		{
			english = i;
		}
		if (students[politics].politics < students[i].politics)
		{
			politics = i;
		}
	}

	printf("计算机最高分：\n\n");
	puts("             学号        姓名        成绩");											//并列时一起输出
	for (int i = 0; i < N; i++)
	{
		if (students[computer].computer == students[i].computer)
		{
			printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].computer);
		}
	}

	printf("\n高数最高分：\n\n");
	puts("             学号        姓名        成绩");
	for (int i = 0; i < N; i++)
	{
		if (students[math].math == students[i].math)
		{
			printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].math);
		}

	}

	printf("\n英语最高分：\n\n");
	puts("             学号        姓名        成绩");
	for (int i = 0; i < N; i++)
	{
		if (students[english].english == students[i].english)
		{
			printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].english);
		}
	}

	printf("\n政治最高分：\n\n");
	puts("             学号        姓名        成绩");
	for (int i = 0; i < N; i++)
	{
		if (students[politics].politics == students[i].politics)
		{
			printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].politics);
		}
	}
}


void access()
{
	int num = 0;
	printf("优秀学生奖(单科成绩得分80%%以上，总排名前三):\n\n\n");
	puts("学号        姓名");
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (students[j].sum > students[j - 1].sum)
			{
				s temp = students[j];
				students[j] = students[j - 1];
				students[j - 1] = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (students[i].computer >= 120 && students[i].english >= 80 && students[i].math >= 120 && students[i].politics >= 80)
		{
			printf("%-12s%-10s\n", students[i].id, students[i].name);
			num++;
		}
	}
	if (num == 0)
	{
		printf("没有优秀学生！");
	}
	printf("\n\n\n");
}


void fileaccount(FILE* fm)
{
	fm = fopen("account.txt", "w");																//文件不存在时创建新文件
	if (fm == NULL)
	{
		printf("文件打开失败!");
		exit(0);
	}
	fclose(fm);
}


void register_()																				//注册
{
	puts("请注册账号:");
	fm = fopen("account.txt", "a");
	if (fm == NULL)
	{
		printf("文件打开失败!");
		exit(0);
	}
	else
	{
		char account[ACCOUNT_LENGTH], password[PASSWORD_LENGTH];								//账号密码
		printf("请输入您的账号(不超过%d位):", ACCOUNT_LENGTH - 1);
		scanf("%s", account);
		fprintf(fm, "账号: %s\n", account);

		printf("请输入您的密码(不超过%d位):", PASSWORD_LENGTH - 1);
		scanf("%s", password);
		fprintf(fm, "密码: %s", password);

		fclose(fm);
		system("cls");
	}
}


bool login_()																					//登录
{
	if (CHECK == 0)puts("请登录:\n\n");

	fm = fopen("account.txt", "r");																//只读
	if (fm == NULL)
	{
		printf("文件打开失败!");
		return false;
	}
	else
	{
		char account_[ACCOUNT_LENGTH], password_[PASSWORD_LENGTH];
		char account__[ACCOUNT_LENGTH], password__[PASSWORD_LENGTH];
		printf("请输入您的账号(不超过%d位):", ACCOUNT_LENGTH - 1);
		scanf("%s", account__);
		printf("请输入您的密码(不超过%d位):", PASSWORD_LENGTH - 1);
		scanf("%s", password__);

		while (fscanf(fm, "%s", account_))														//读取正确账号
		{
			if (strcmp(account_, "账号: ") != 0)												//不读取账号前的“账号:”
			{
				fscanf(fm, "%s", account_);	
				break;
			}
		}

		while (fscanf(fm, "%s", password_))														//读取正确密码
		{
			if (strcmp(password_, "密码: ") != 0)												//不读取密码前的“密码:”
			{
				fscanf(fm, "%s", password_);
				break;
			}
		}

		fclose(fm);

		if (strcmp(account_, account__) == 0 && strcmp(password_, password__) == 0)				//输入的账号密码与正确的账号密码相比较
		{																						//均正确则登录成功，进入系统
			system("cls");																		//有错误则重新输入账号密码
			printf("登录成功\n\n\n");
			return true;
		}
		else if (strcmp(account_, account__) != 0 || strcmp(password_, password__) != 0)
		{
			system("cls");
			printf("账号或密码错误，请重新登录！\n");
			CHECK = 1;
			login_();																			//递归，重新登录
		}
	}
}


void file(FILE* fp)
{
	fp = fopen("students.txt", "w");															//文件不存在时创建
	if (fp==NULL)
	{
		printf("文件打开失败!");
		exit(0);
	}
	fclose(fp);
}


void baocun(FILE* fp)
{
	fp = fopen("students.txt", "a");															//追加
	if (fp==NULL)
	{
		printf("文件打开失败!");
		exit(0);
	}
	fprintf(fp, "成绩单:%d\n\n    学号        姓名        计算机   高数    英语    政治    总分\n",N);

	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (students[j].sum > students[j - 1].sum)
			{
				s change = students[j];
				students[j] = students[j - 1];
				students[j - 1] = change;
			}
		}
	}

	for (int i = 0; i < N; i++) 
	{
		fprintf(fp,"%-4d%-12s%-10s%6.2lf%8.2lf%8.2lf%8.2lf%8.2lf\n",i+1, students[i].id, students[i].name, students[i].computer, students[i].math, students[i].english, students[i].politics, students[i].sum);
	}
	fclose(fp);
	printf("成绩单已保存至students.txt中,可随时查看。\n\n");
}

void duru()
{
	printf("载入中\n");
	fp = fopen("students.txt", "r");
	fscanf(fp, "成绩单:%d\n\n    学号        姓名        计算机   高数    英语    政治    总分\n", &N);
	int x[1000];
	for (int i = 0; i < N; i++)
	{
		fscanf(fp, "%d%s%s %lf %lf %lf %lf %lf\n", &x[i], students[i].id, students[i].name, &students[i].computer, &students[i].math, &students[i].english, &students[i].politics, &students[i].sum);
		SUM += students[i].sum;
	}
	printf("载入完成\n");
	fclose(fp);
}


void analysis()
{
	int i = 0;
	int cnt[MAX_NUMBER] = { 0 };
	printf("             学号        姓名\n");
	while (i != N )
	{
		if (students[i].computer < 90)
			cnt[i]++;
		if (students[i].math < 90)
			cnt[i]++;
		if (students[i].english < 60)
			cnt[i]++;
		if (students[i].politics < 60)
			cnt[i]++;
		i = i + 1;
	}
	for (i = 0; i < N; i++)
	{
		if (cnt[i] == 0)
			printf("             %-12s%-10s的成绩良好\n", students[i].id, students[i].name);
		else if (cnt[i] <= 2)
			printf("             %-12s%-10s的成绩还有待提高\n", students[i].id, students[i].name);
		else if (cnt[i] == 3)
			printf("             %-12s%-10s的学习状态不佳成绩不理想\n", students[i].id, students[i].name);
		else
			printf("             %-12s%-10s的成绩非常糟糕，希望老师当面约谈\n", students[i].id, students[i].name);
	}
}

void uneven()
{
	int max[MAX_NUMBER] = { 0 }, min[MAX_NUMBER] = { 0 };
	int i = 0;
	int j = 0;
	int num[4] = { 0 };
	while (i != N)
	{
		num[0] = students[i].computer;
		num[1] = students[i].math;
		num[2] = students[i].english;
		num[3] = students[i].politics;
		max[i] = num[0], min[i] = num[0];
		for (j = 1; j < 3; j++)
		{
			if (max[i] < num[j])
			{
				max[i] = num[j];
			}
		}
		for (j = 1; j < 3; j++)
		{
			if (min[i] > num[j])
			{
				min[i] = num[j];
			}
		}
		printf("             学号        姓名\n");
		if (max[i] - min[i] > 30)
		{
			printf("             %-12s%-10s偏科严重，需要合理规划学习时间\n", students[i].id, students[i].name);
		}
		else
		{
			printf("             %-12s%-10s并无明显偏科现象\n", students[i].id, students[i].name);
		}
		i = i + 1;
	}
}

void tongguolv()
{
	puts("-------------请输入操作指令--------------");
	puts("|                                       |");
	puts("|          1.输出计算机考试通过率       |");
	puts("|          2.输出高数考试通过率         |");
	puts("|          3.输出英语考试通过率         |");
	puts("|          4.输出政治考试通过率         |");
	puts("|                                       |");
	puts("-----------------------------------------");
	printf("您的指令：");
	int n;
	double tgv, tg = 0.0;
	scanf("%d", &n);
	switch (n)
	{
	case 1:
	{
		for (int i = 0; i < N; i++)
		{
			if (students[i].computer >= 90)
				tg++;
			tgv = tg / N;
		}
		printf("计算机考试的通过率是：%.2f%%\n", 100 * tgv);
		break;
	}
	case 2:
	{
		for (int i = 0; i < N; i++)
		{
			if (students[i].math >= 90)
				tg++;
			tgv = tg / N;
		}
		printf("高数考试的通过率是：%.2f%%\n", 100 * tgv);
		break;
	}
	case 3:
	{
		for (int i = 0; i < N; i++)
		{
			if (students[i].english >= 60)
				tg++;
			tgv = tg / N;
		}
		printf("英语考试的通过率是：%.2f%%\n", 100 * tgv);
		break;
	}
	case 4:
	{
		for (int i = 0; i < N; i++)
		{
			if (students[i].politics >= 60)
				tg++;
			tgv = tg / N;
		}
		printf("政治考试的通过率是：%.2f%%\n", 100 * tgv);
		break;
	}
	default:break;
	}
}
