#include"head.h"

void puthead()
{
	puts("-----------------------------------------");
	puts("|-------��ӭ����ѧ����Ϣ����ϵͳ!-------|");
	puts("|---------------------------------------|");
}


void puthead_() {
	puts("|------------���������ָ��-------------|");
	puts("|                                       |");
	puts("|          1.¼��ѧ����Ϣ               |");
	puts("|          2.ɾ��ѧ����Ϣ               |");
	puts("|          3.�޸�ѧ����Ϣ               |");
	puts("|          4.����ѧ����Ϣ               |");
	puts("|          5.��ʾ��ǰѧ����Ϣ           |");
	puts("|          6.���ɼ���������             |");
	puts("|          7.��ѧ�Ų�ѯѧ����Ϣ         |");
	puts("|          8.�������Ŀ������ѧ��       |");
	puts("|          9.���������߷�             |");
	puts("|          10.����ͳ��ѧ����Ϣ          |");
	puts("|          11.����                      |");
	puts("|          12.����ѧ��ѧϰ״̬          |");
	puts("|          13.����ѧ���Ƿ�ƫ��          |");
	puts("|          14.����ͨ����                |");
	puts("|          0.����������                 |");
	puts("|                                       |");
	puts("-----------------------------------------");
}


int search(char searchid[])											//����id����λ�ú���
{																	//���ҳɹ������±꣬���ɹ�����-1
	for (int i = 0; i < N; i++)
	{
		if (strcmp(students[i].id, searchid) == 0)
			return i;
	}
	return -1;
}


bool check()														//����Ƿ������ͬid 
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


bool _check(char student[])											//�������ѧ��ѧ���Ƿ�����¼��ѧ���ظ�
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


void check150(double x, int biao, int kemu)							//����Ƿ񳬹����뷶Χ
{
	if (x > 150 || x < 0)
	{
		printf("��������������˷�Χ�����������룺");
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


void check100(double x, int biao, int kemu)							//����Ƿ񳬹����뷶Χ
{
	if (x > 100 || x < 0)
	{
		printf("��������������˷�Χ�����������룺");
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


void display()														//չʾ��ǰѧ����Ϣ
{
	printf("��ǰѧ����ϢΪ:\n");
	puts("    ѧ��        ����         �����   ����    Ӣ��    ����   �ܷ�");
	for (int i = 0; i < N; i++)
	{
		printf("%-4d%-12s%-10s%8.2lf%8.2lf%8.2lf%8.2lf%8.2lf\n", i + 1, students[i].id, students[i].name, students[i].computer, students[i].math, students[i].english, students[i].politics, students[i].sum);
	}
	printf("��ǰƽ����Ϊ:%.2lf\n\n\n", SUM / N);
}


void input()
{
	int n;
	printf("¼��ѧ������:");
	scanf("%d", &n);
	while (n <= 0)
	{
		printf("�����������Ϊ0�����Ǹ���������������:");
		scanf("%d", &n);
	}
	
	
	for (int i = N, j = 0; i < N + n; i++, j++)
	{
		printf("��%d��ѧ��:\n", j + 1);
		printf("ѧ��:");
		scanf("%s", students[i].id);

		printf("����:");
		scanf("%s", students[i].name);

		printf("������ɼ�(0-150):");
		scanf("%lf", &students[i].computer);
		check150(students[i].computer, i, 1);										//������������Ƿ񳬳���Χ

		printf("�����ɼ�(0-150):");
		scanf("%lf", &students[i].math);
		check150(students[i].math, i, 2);

		printf("Ӣ��ɼ�(0-100):");
		scanf("%lf", &students[i].english);
		check100(students[i].english, i, 3);

		printf("���γɼ�(0-100):");
		scanf("%lf", &students[i].politics);
		check100(students[i].politics, i, 4);

		students[i].sum = students[i].computer + students[i].math + students[i].english + students[i].politics;
		SUM += students[i].sum;
	}
	N = n + N;
	if (check() == false)												//����
	{
		N = N - n;
		system("cls");
		puts("�����к����ظ�id�����鲢�������룡");
		input();
	}
	else
	{
		puts("¼��ɹ���\n");
		display();
	}
}



void _delete()														//ɾ��ѧ����Ϣ
{
	char searchid[ID_LENGTH];
	printf("������ѧ��ѧ��:");
	scanf("%s", searchid);
	int sea = search(searchid);										//�ȴ�ɾ����ѧ��λ���±�
	if (sea != -1)
	{
		SUM -= students[sea].sum;									//�޸�ƽ���ɼ�
		for (int i = sea + 1; i < N; i++)
		{
			students[i - 1] = students[i];							//sea֮�������ѧ��ǰ��һλ������sea��ѧ����Ϣ
		}
		N--;														//��������һ
		display();
	}
	else 
	{
		puts("���޴��ˣ�");
	}
}


void reset()
{
	char searchid[ID_LENGTH];
	printf("������ѧ��ѧ��:");
	scanf("%s", &searchid);
	int sea = search(searchid);
	if (sea != -1)
	{
		SUM -= students[sea].sum;									//�޸�ƽ���ɼ�
		puts("�������д�����Ϣ:");
		printf("������ɼ�(0-150):");
		scanf("%lf", &students[sea].computer);
		check150(students[sea].computer, sea, 1);					//���

		printf("�����ɼ�(0-150):");
		scanf("%lf", &students[sea].math);
		check150(students[sea].math, sea, 2);

		printf("Ӣ��ɼ�(0-100):");
		scanf("%lf", &students[sea].english);
		check100(students[sea].english, sea, 3);

		printf("���γɼ�(0-100):");
		scanf("%lf", &students[sea].politics);
		check100(students[sea].politics, sea, 4);

		students[sea].sum = students[sea].computer + students[sea].math + students[sea].english + students[sea].politics;
		SUM += students[sea].sum;
		puts("�޸����:");
		display();
	}
	else
	{
		puts("���޴��ˣ�");
	}
}


void insert()
{
	N++;
	puts("������Ҫ�����ѧ����Ϣ:");
	printf("ѧ��:");
	scanf("%s", &students[N - 1].id);

	printf("����:");
	scanf("%s", &students[N - 1].name);

	printf("������ɼ�(0-150):");
	scanf("%lf", &students[N - 1].computer);
	check150(students[N - 1].computer, N - 1, 1);

	printf("�����ɼ�(0-150):");
	scanf("%lf", &students[N - 1].math);
	check150(students[N - 1].math, N - 1, 2);

	printf("Ӣ��ɼ�(0-100):");
	scanf("%lf", &students[N - 1].english);
	check150(students[N - 1].english, N - 1, 3);

	printf("���γɼ�(0-100):");
	scanf("%lf", &students[N - 1].politics);
	check150(students[N - 1].politics, N - 1, 4);

	students[N - 1].sum = students[N - 1].computer + students[N - 1].math + students[N - 1].english + students[N - 1].politics;
	SUM += students[N - 1].sum;

	if (_check(students[N - 1].id) == false)								//����
	{
		N--;																//ɾ��������������
		system("cls");
		puts("�������ظ�id�����鲢���²��룡");
		insert();
	}
	else
	{
		puts("������ɣ�");
		display();
	}
}



void sort()
{
	puts("-------------���������ָ��--------------");
	puts("|                                       |");
	puts("|          1.���ܳɼ�����               |");
	puts("|          2.��������ɼ�����           |");
	puts("|          3.�������ɼ�����             |");
	puts("|          4.��Ӣ��ɼ�����             |");
	puts("|          5.�����γɼ�����             |");
	puts("|                                       |");
	puts("-----------------------------------------");

	int item;
	printf("����ָ��:");
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
			puts("���ܳɼ����������:\n");
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
			puts("��������ɼ����������:\n");
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
			puts("�������ɼ����������:\n");
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
			puts("��Ӣ��ɼ����������:\n");
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
			puts("�����γɼ����������:\n");
			break;
		}
		default:break;
	}
	display();
}


void searchid()
{
	char searchid[ID_LENGTH];
	printf("������ѧ��ѧ��:");
	scanf("%s", &searchid);
	int sea = search(searchid);
	if (sea != -1)
	{
		puts("��ѯ�ɹ�:\n");
		printf("\n      ѧ��:  %s",students[sea].id);
		printf("\n      ����:  %s", students[sea].name);
		printf("\n������ɼ�:  %.2lf", students[sea].computer);
		printf("\n  �����ɼ�:  %.2lf", students[sea].math);
		printf("\n  Ӣ��ɼ�:  %.2lf", students[sea].english);
		printf("\n  ���γɼ�:  %.2lf", students[sea].politics);
		printf("\n      �ܷ�:  %.2lf\n\n\n", students[sea].sum);
	}
	else
	{
		puts("���޴��ˣ�");
	}
}


void displaybjg()
{
	int chazhao = 0;
	puts("-------------���������ָ��--------------");
	puts("|                                       |");
	puts("|          1.���Ҽ�����������ѧ��     |");
	puts("|          2.���Ҹ����������ѧ��       |");
	puts("|          3.����Ӣ�ﲻ�����ѧ��       |");
	puts("|          4.�������β������ѧ��       |");
	puts("|          5.���Ҹ��Ʋ������ѧ��       |");
	puts("|                                       |");
	puts("-----------------------------------------");
	printf("����ָ��:");
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
					printf("������������ѧ����\n\n");
					puts("             ѧ��        ����        �ɼ�");
				}
				printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].computer);
			}
			
		}
		if (panduan == 0)
			printf("�����ȫ������(���ި��ޡ�)\n\n");
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
					printf("�����������ѧ����\n\n");
					puts("             ѧ��        ����        �ɼ�");
				}
				printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].math);
			}
		}
		if (panduan == 0)
			printf("����ȫ������(���ި��ޡ�)\n\n");
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
				printf("Ӣ�ﲻ�����ѧ����\n\n");
				puts("             ѧ��        ����        �ɼ�");
				}
				printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].english);
			}
		}
		if (panduan == 0)
			printf("Ӣ��ȫ������(���ި��ޡ�)\n\n");
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
				printf("���β������ѧ����\n\n");
				puts("             ѧ��        ����        �ɼ�");
				}
				printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].politics);
			}
		}
		if (panduan == 0)
			printf("����ȫ������(���ި��ޡ�)\n\n");
		else
			printf("\n");
	}
}


void grouping()
{
	puts("-------------���������ָ��--------------");
	puts("|                                       |");
	puts("|         1.���ҵ���ƽ���ֵ�ѧ��        |");
	puts("|         2.���Ҹ���ƽ���ֵ�ѧ��        |");
	puts("|                                       |");
	puts("-----------------------------------------");
	printf("����ָ�");
	int i, n;
	scanf("%d", &n);
	switch (n)
	{
	case 1:
	{
		for (i = 0; i < N; i++)
		{
			if (students[i].sum < SUM / N)
				printf("ѧ�ţ�%s ������%s �ܷ֣�%.2f\n", students[i].id, students[i].name, students[i].sum);
		}
	}break;
	case 2:
	{
		for (i = 0; i < N; i++)
		{
			if (students[i].sum > SUM / N)
				printf("ѧ�ţ�%s ������%s �ܷ֣�%.2f\n", students[i].id, students[i].name, students[i].sum);
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

	printf("�������߷֣�\n\n");
	puts("             ѧ��        ����        �ɼ�");											//����ʱһ�����
	for (int i = 0; i < N; i++)
	{
		if (students[computer].computer == students[i].computer)
		{
			printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].computer);
		}
	}

	printf("\n������߷֣�\n\n");
	puts("             ѧ��        ����        �ɼ�");
	for (int i = 0; i < N; i++)
	{
		if (students[math].math == students[i].math)
		{
			printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].math);
		}

	}

	printf("\nӢ����߷֣�\n\n");
	puts("             ѧ��        ����        �ɼ�");
	for (int i = 0; i < N; i++)
	{
		if (students[english].english == students[i].english)
		{
			printf("             %-12s%-10s%8.2lf\n", students[i].id, students[i].name, students[i].english);
		}
	}

	printf("\n������߷֣�\n\n");
	puts("             ѧ��        ����        �ɼ�");
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
	printf("����ѧ����(���Ƴɼ��÷�80%%���ϣ�������ǰ��):\n\n\n");
	puts("ѧ��        ����");
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
		printf("û������ѧ����");
	}
	printf("\n\n\n");
}


void fileaccount(FILE* fm)
{
	fm = fopen("account.txt", "w");																//�ļ�������ʱ�������ļ�
	if (fm == NULL)
	{
		printf("�ļ���ʧ��!");
		exit(0);
	}
	fclose(fm);
}


void register_()																				//ע��
{
	puts("��ע���˺�:");
	fm = fopen("account.txt", "a");
	if (fm == NULL)
	{
		printf("�ļ���ʧ��!");
		exit(0);
	}
	else
	{
		char account[ACCOUNT_LENGTH], password[PASSWORD_LENGTH];								//�˺�����
		printf("�����������˺�(������%dλ):", ACCOUNT_LENGTH - 1);
		scanf("%s", account);
		fprintf(fm, "�˺�: %s\n", account);

		printf("��������������(������%dλ):", PASSWORD_LENGTH - 1);
		scanf("%s", password);
		fprintf(fm, "����: %s", password);

		fclose(fm);
		system("cls");
	}
}


bool login_()																					//��¼
{
	if (CHECK == 0)puts("���¼:\n\n");

	fm = fopen("account.txt", "r");																//ֻ��
	if (fm == NULL)
	{
		printf("�ļ���ʧ��!");
		return false;
	}
	else
	{
		char account_[ACCOUNT_LENGTH], password_[PASSWORD_LENGTH];
		char account__[ACCOUNT_LENGTH], password__[PASSWORD_LENGTH];
		printf("�����������˺�(������%dλ):", ACCOUNT_LENGTH - 1);
		scanf("%s", account__);
		printf("��������������(������%dλ):", PASSWORD_LENGTH - 1);
		scanf("%s", password__);

		while (fscanf(fm, "%s", account_))														//��ȡ��ȷ�˺�
		{
			if (strcmp(account_, "�˺�: ") != 0)												//����ȡ�˺�ǰ�ġ��˺�:��
			{
				fscanf(fm, "%s", account_);	
				break;
			}
		}

		while (fscanf(fm, "%s", password_))														//��ȡ��ȷ����
		{
			if (strcmp(password_, "����: ") != 0)												//����ȡ����ǰ�ġ�����:��
			{
				fscanf(fm, "%s", password_);
				break;
			}
		}

		fclose(fm);

		if (strcmp(account_, account__) == 0 && strcmp(password_, password__) == 0)				//������˺���������ȷ���˺�������Ƚ�
		{																						//����ȷ���¼�ɹ�������ϵͳ
			system("cls");																		//�д��������������˺�����
			printf("��¼�ɹ�\n\n\n");
			return true;
		}
		else if (strcmp(account_, account__) != 0 || strcmp(password_, password__) != 0)
		{
			system("cls");
			printf("�˺Ż�������������µ�¼��\n");
			CHECK = 1;
			login_();																			//�ݹ飬���µ�¼
		}
	}
}


void file(FILE* fp)
{
	fp = fopen("students.txt", "w");															//�ļ�������ʱ����
	if (fp==NULL)
	{
		printf("�ļ���ʧ��!");
		exit(0);
	}
	fclose(fp);
}


void baocun(FILE* fp)
{
	fp = fopen("students.txt", "a");															//׷��
	if (fp==NULL)
	{
		printf("�ļ���ʧ��!");
		exit(0);
	}
	fprintf(fp, "�ɼ���:%d\n\n    ѧ��        ����        �����   ����    Ӣ��    ����    �ܷ�\n",N);

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
	printf("�ɼ����ѱ�����students.txt��,����ʱ�鿴��\n\n");
}

void duru()
{
	printf("������\n");
	fp = fopen("students.txt", "r");
	fscanf(fp, "�ɼ���:%d\n\n    ѧ��        ����        �����   ����    Ӣ��    ����    �ܷ�\n", &N);
	int x[1000];
	for (int i = 0; i < N; i++)
	{
		fscanf(fp, "%d%s%s %lf %lf %lf %lf %lf\n", &x[i], students[i].id, students[i].name, &students[i].computer, &students[i].math, &students[i].english, &students[i].politics, &students[i].sum);
		SUM += students[i].sum;
	}
	printf("�������\n");
	fclose(fp);
}


void analysis()
{
	int i = 0;
	int cnt[MAX_NUMBER] = { 0 };
	printf("             ѧ��        ����\n");
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
			printf("             %-12s%-10s�ĳɼ�����\n", students[i].id, students[i].name);
		else if (cnt[i] <= 2)
			printf("             %-12s%-10s�ĳɼ����д����\n", students[i].id, students[i].name);
		else if (cnt[i] == 3)
			printf("             %-12s%-10s��ѧϰ״̬���ѳɼ�������\n", students[i].id, students[i].name);
		else
			printf("             %-12s%-10s�ĳɼ��ǳ���⣬ϣ����ʦ����Լ̸\n", students[i].id, students[i].name);
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
		printf("             ѧ��        ����\n");
		if (max[i] - min[i] > 30)
		{
			printf("             %-12s%-10sƫ�����أ���Ҫ����滮ѧϰʱ��\n", students[i].id, students[i].name);
		}
		else
		{
			printf("             %-12s%-10s��������ƫ������\n", students[i].id, students[i].name);
		}
		i = i + 1;
	}
}

void tongguolv()
{
	puts("-------------���������ָ��--------------");
	puts("|                                       |");
	puts("|          1.������������ͨ����       |");
	puts("|          2.�����������ͨ����         |");
	puts("|          3.���Ӣ�￼��ͨ����         |");
	puts("|          4.������ο���ͨ����         |");
	puts("|                                       |");
	puts("-----------------------------------------");
	printf("����ָ�");
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
		printf("��������Ե�ͨ�����ǣ�%.2f%%\n", 100 * tgv);
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
		printf("�������Ե�ͨ�����ǣ�%.2f%%\n", 100 * tgv);
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
		printf("Ӣ�￼�Ե�ͨ�����ǣ�%.2f%%\n", 100 * tgv);
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
		printf("���ο��Ե�ͨ�����ǣ�%.2f%%\n", 100 * tgv);
		break;
	}
	default:break;
	}
}
