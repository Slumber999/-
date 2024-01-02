#include"functions.c"

int main() 
{
	puthead();
	printf("请问您是否已有账号？(yes/no)\n");
	scanf("%s", LOGINCHECK);
	if (strcmp(LOGINCHECK,"no")==0)
	{
		fileaccount(fm);
		register_();
	}
	if (login_())
	{
		int sfzr=0;
		printf("是否载入历史数据？(按1载入，按2新建)\n");
		scanf("%d", &sfzr);
		if(sfzr==1)
			duru();
		file(fp);
		system("cls");
		while (1)
		{
			puthead_();
			printf("您的指令:");
			scanf("%d", &item);
			if (item == 0)
			{
				system("cls");
				puts("程序结束，谢谢您的使用！");
				baocun(fp);
				return 0;
			}
			else
			{
				switch (item)
				{
				case 1:system("cls"); input(); break;
				case 2:system("cls"); _delete(); break;
				case 3:system("cls"); reset(); break;
				case 4:system("cls"); insert(); break;
				case 5:system("cls"); display(); break;
				case 6:system("cls"); sort(); break;
				case 7:system("cls"); searchid(); break;
				case 8:system("cls"); displaybjg(); break;
				case 9:system("cls"); displaymax(); break;
				case 10:system("cls"); grouping(); break;
				case 11:system("cls"); access(); break;
				case 12:system("cls"); analysis(); break;
				case 13:system("cls"); uneven(); break;
				case 14:system("cls"); tongguolv(); break;
				default:break;
				}
			}
		}
	}
	return 0;
}
