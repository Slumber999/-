#pragma warning(disable : 4996)


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


#define ID_LENGTH 12								//学号长度
#define NAME_LENGTH 12								//姓名长度
#define MAX_NUMBER 1000								//最大学生数量
#define ACCOUNT_LENGTH 11							//账号最大长度+1
#define PASSWORD_LENGTH 11							//密码最大长度+1


typedef struct student
{
	char id[ID_LENGTH];								//学生id
	char name[NAME_LENGTH];							//姓名
	double computer;								//计算机成绩
	double math;									//高数成绩
	double english;									//英语成绩
	double politics;								//政治成绩
	double sum;										//总分
}s;
s students[MAX_NUMBER];								//创建学生数组


int item;											//switch指令
char LOGINCHECK[5];									//yes时直接登录系统，no时注册再登录
int CHECK = 0;										//登录检测(0登录成功，1登录失败)
FILE* fm;											//账户
FILE* fp;											//成绩单
int N = 0;											//计数
double SUM = 0;										//SUM/N即所有学生的平均成绩


int search(char id[]);								//查找(id)
void fileaccount(FILE* fm);							//创建账户文件
void file(FILE* fp);								//创建成绩单文件
bool check();										//检查录入学生学号是否重复
bool _check(char student[]);						//检查插入的学生学号是否与已录入学生重复
void check100(double x, int biao, int kemu);		//检查是否超过输入范围
void check150(double x, int biao, int kemu);        //检查是否超过输入范围
void puthead_();									//显示选项
void puthead();										//显示表头
void register_();									//注册
bool login_();										//登录
void input();										//录入
void _delete();										//删除
void reset();										//改写
void insert();										//插入
void sort();										//排序
void display();										//显示
void searchid();									//查询
void displaybjg();									//输出各科目不及格学生
void displaymax();									//输出各科最高分 
void grouping();									//分组输出
void baocun();										//保存
void assess();										//评优(优秀学生，120，80，总成绩前三)
void duru();										//读入(文件中的学生信息)
void analysis();									//分析学生学习状态
void uneven();										//分析学生偏科现象
void tongguolv();									//考试通过率