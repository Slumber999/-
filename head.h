#pragma warning(disable : 4996)


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


#define ID_LENGTH 12								//ѧ�ų���
#define NAME_LENGTH 12								//��������
#define MAX_NUMBER 1000								//���ѧ������
#define ACCOUNT_LENGTH 11							//�˺���󳤶�+1
#define PASSWORD_LENGTH 11							//������󳤶�+1


typedef struct student
{
	char id[ID_LENGTH];								//ѧ��id
	char name[NAME_LENGTH];							//����
	double computer;								//������ɼ�
	double math;									//�����ɼ�
	double english;									//Ӣ��ɼ�
	double politics;								//���γɼ�
	double sum;										//�ܷ�
}s;
s students[MAX_NUMBER];								//����ѧ������


int item;											//switchָ��
char LOGINCHECK[5];									//yesʱֱ�ӵ�¼ϵͳ��noʱע���ٵ�¼
int CHECK = 0;										//��¼���(0��¼�ɹ���1��¼ʧ��)
FILE* fm;											//�˻�
FILE* fp;											//�ɼ���
int N = 0;											//����
double SUM = 0;										//SUM/N������ѧ����ƽ���ɼ�


int search(char id[]);								//����(id)
void fileaccount(FILE* fm);							//�����˻��ļ�
void file(FILE* fp);								//�����ɼ����ļ�
bool check();										//���¼��ѧ��ѧ���Ƿ��ظ�
bool _check(char student[]);						//�������ѧ��ѧ���Ƿ�����¼��ѧ���ظ�
void check100(double x, int biao, int kemu);		//����Ƿ񳬹����뷶Χ
void check150(double x, int biao, int kemu);        //����Ƿ񳬹����뷶Χ
void puthead_();									//��ʾѡ��
void puthead();										//��ʾ��ͷ
void register_();									//ע��
bool login_();										//��¼
void input();										//¼��
void _delete();										//ɾ��
void reset();										//��д
void insert();										//����
void sort();										//����
void display();										//��ʾ
void searchid();									//��ѯ
void displaybjg();									//�������Ŀ������ѧ��
void displaymax();									//���������߷� 
void grouping();									//�������
void baocun();										//����
void assess();										//����(����ѧ����120��80���ܳɼ�ǰ��)
void duru();										//����(�ļ��е�ѧ����Ϣ)
void analysis();									//����ѧ��ѧϰ״̬
void uneven();										//����ѧ��ƫ������
void tongguolv();									//����ͨ����