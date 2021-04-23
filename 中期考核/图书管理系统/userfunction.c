#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"

Status readbook()//����ͼ��
{
	//printf("%d",booktype);
	Book temp[10];
	int n=0,i=0;
	FILE*fp;
	fp=fopen("librarybook.txt","r");
	if(!fp)
	{
		printf("�����޿���ļ���");
		return ERROR;
	}
	printf("���\t����\t����\t�����\n");
	//fread(&temp[i],sizeof(Book),n,fp);
	while(!feof(fp))
	{
		fread(&temp[i],sizeof(Book),1,fp);
		n++;
		//printf("%d\n",count);
	}
	//����fp��ָ���ַ
	fclose(fp);
	fp=fopen("librarybook.txt","r");
	//******************************
	for(i=0;i<n-1;i++)
	{
		fread(&temp[i],sizeof(Book),1,fp);
		printf("%d\t%s\t%s\t%d\t\n",temp[i].num,temp[i].bookname,temp[i].author,temp[i].booknum);
	}
	fclose(fp);

	printf("һ����%d����\n",(n-1));
	return SUCCESS;
}


void searchbook()//����ͼ��
{
	FILE*fp;
	int n,i,FLAG=0;
	searchbookmenu();

	int opotion;
	printf("\t\t\t\t���������ѡ�");
	while(scanf("%d",&opotion)==0||getchar()!='\n')
	{
		printf("\t\t\t\t�����˷Ƿ��ַ������������룺");
		while (getchar() != '\n');
	}
	switch(opotion)
	{
	case 1:
		{
			Book temp;
			int num;
			printf("\t\t\t\t�������ѯ��ͼ���ţ�");
			while(scanf("%d",&num)==0||getchar()!='\n')
			{
				printf("\t\t\t\t�����˷Ƿ��ַ������������룺");
				while (getchar() != '\n');
			}
			fp=fopen("librarybook.txt","r");
			if(!fp)
			{
				printf("\t\t\t\t�����޿���ļ���");
				system("pause");
				break;
			}
			n=0,i=0;
			while(!feof(fp))
			{
				fread(&temp,sizeof(Book),1,fp);
				n++;
			}
			fclose(fp);
			fp=fopen("librarybook.txt","r");
			for(i=0;i<n-1;i++)
			{
				fread(&temp,sizeof(Book),1,fp);
				if(temp.num==num)
				{
					printf("\t\t\t\t%d\t%s\t%s\t%d\t\n",temp.num,temp.bookname,temp.author,temp.booknum);
					FLAG++;
				}
			}
			if(FLAG==0)
			{
				printf("\t\t\t\tû���ҵ��Ȿ��\n");
				break;
			}
			else
			{
				printf("\t\t\t\t��%d��ͼ��",i);
			}
			fclose(fp);
			break;
		}
	case 2:
		{
			Book temp;
			char bookname[10];
			printf("\t\t\t\t�������ѯ��ͼ������");
			gets(bookname);
			fp=fopen("librarybook.txt","r");
			if(!fp)
			{
				printf("\t\t\t\t�����޿���ļ���");
				system("pause");
				break;
			}
			n=0,i=0;
			while(!feof(fp))
			{
				fread(&temp,sizeof(Book),1,fp);
				n++;
			}
			fclose(fp);
			fp=fopen("librarybook.txt","r");
			for(i=0;i<n-1;i++)
			{
				fread(&temp,sizeof(Book),1,fp);
				if(!strcmp(temp.bookname,bookname))
				{
					printf("\t\t\t\t%d\t%s\t%s\t%d\t\n",temp.num,temp.bookname,temp.author,temp.booknum);
					FLAG++;
				}
			}
			if(FLAG==0)
			{
				printf("\t\t\t\tû���ҵ��Ȿ��\n");
				break;
			}
			else
			{
				printf("\t\t\t\t��%d��ͼ��",i);
			}
			fclose(fp);
			break;
		}
	case 3:
		{
			Book temp;
			char auth[10];
			printf("\t\t\t\t�������ѯ�����ߣ�");
			gets(auth);
			fp=fopen("librarybook.txt","r");
			if(!fp)
			{
				printf("\t\t\t\t�����޿���ļ���");
				system("pause");
				break;
			}
			n=0;

			while(!feof(fp))
			{
				fread(&temp,sizeof(Book),1,fp);
				n++;
			}
			fclose(fp);
			fp=fopen("librarybook.txt","r");
			for(i=0;i<n-1;i++)
			{
				fread(&temp,sizeof(Book),1,fp);
				if(!strcmp(temp.author,auth))
				{
					printf("\t\t\t\t%d\t%s\t%s\t%d\t\n",temp.num,temp.bookname,temp.author,temp.booknum);
					FLAG++;
				}
			}
			if(FLAG==0)
			{
				printf("\t\t\t\tû���ҵ��Ȿ��\n");
				break;
			}
			else
			{
				printf("\t\t\t\t��%d��ͼ��",i);
			}
			fclose(fp);
			break;
		}
	case 4:
		{
			Book temp;
			int booknum;
			printf("\t\t\t\t�������ѯ��ͼ��������");
			while(scanf("%d",&booknum)==0||getchar()!='\n')
			{
				printf("\t\t\t\t�����˷Ƿ��ַ������������룺");
				while (getchar() != '\n');
			}
			fp=fopen("librarybook.txt","r");
			if(!fp)
			{
				printf("\t\t\t\t�����޿���ļ���");
				system("pause");
				break;
			}
			n=0,i=0;
			while(!feof(fp))
			{
				fread(&temp,sizeof(Book),1,fp);
				n++;
			}
			fclose(fp);
			fp=fopen("librarybook.txt","r");
			for(i=0;i<n-1;i++)
			{
				fread(&temp,sizeof(Book),1,fp);
				if(temp.booknum==booknum)
				{
					printf("%d\t%s\t%s\t%d\t\n",temp.num,temp.bookname,temp.author,temp.booknum);
					FLAG++;
				}
			}
			if(FLAG==0)
			{
				printf("\t\t\t\tû���ҵ��Ȿ��\n");
				break;
			}
			else
			{
				printf("\t\t\t\t��%d��ͼ��",i);
			}
			fclose(fp);
			break;
		}
	case 0:
		system("cls");
		Usermenu();
		Userselect();
		break;
	}
}

//************************************************************************
//���鹦�ܺ���
Status lendbook(DLink head)
{

	readbook();

	FILE *fp;
	FILE *fp1;

	pStudent head1=Initi();
	//�ݴ�����
	Book temp[10];
	//��¼�����ͬѧ
	yonhu a;
	yonhu temp1;
	//���ļ�
	fp=fopen("librarybook.txt","rb+");
	if(!fp)
	{
		printf("�����޿���ļ���");
		return ERROR;
	}


	//����ͼ�����н������
	DLink p2;
	//printf("test2\n");
	p2=head;
	//printf("test3\n");
	int i=0,n=0;
	while(!feof(fp))
	{
		fread(&temp[i],sizeof(Book),1,fp);
		n++;
	}
	fclose(fp);
	fp=fopen("librarybook.txt","rb+");
	for(i=0;i<n-1;i++)
	{
		fread(&temp[i],sizeof(Book),1,fp);
		DLink newbook=(DLink)malloc(sizeof(LNode));
		if(newbook)
		{
			newbook->date.num=temp[i].num;
			strcpy(newbook->date.bookname,temp[i].bookname);
			strcpy(newbook->date.author,temp[i].author);
			newbook->date.booknum=temp[i].booknum;

			p2->next=newbook;
			p2=newbook;
			newbook->next=NULL;
		}
	}
	//printf("test");
	//traval(head);

	//���û�����ͼ����Ϣ�ҵ��Ǹ��ļ�
	printf("������Ҫ����ͼ��ı��");
	while(scanf("%d",&temp[9].num)==0||getchar()!='\n')
	{
		printf("�����˷Ƿ��ַ������������룺");
		while (getchar() != '\n');
	}

	p2=head->next;
	while(p2!=NULL)
	{
		if((p2->date.num)==temp[9].num)
		{
			if(p2->date.booknum==0)
			{
				printf("ͼ����и����ѱ����꣬��Ҫ����ԤԼ��");
				yuyuemenu();
				yuyue(temp[9].num);
				return ERROR;
			}
			else
			{
				p2->date.booknum=p2->date.booknum-1;
			}
		}
		p2=p2->next;
	}
	//traval(head);
	fclose(fp);

	fp=fopen("librarybook.txt","w");//���ô򿪹ر��������֮���ٰ��޸�֮����������ݴ���
		fclose(fp);
		fp=fopen("librarybook.txt","a");
		if(!fp)
		{
			printf("�����޿���ļ���");
		}
		p2=head->next;
		while(p2!=NULL)
		{
			fwrite(&(p2->date),sizeof(Book),1,fp);
			p2=p2->next;
		}
	fclose(fp);
	//���ϰ�����ȥ�Ĳ����������


	//���������������������Ϣ�Ĳ���
	fp1=fopen("reader.txt","a+");
	if(!fp1)
	{
		printf("�����޿���ļ���");
		return ERROR;
	}

	//����ʱ�����������Ϣ����¼������Ϣ�������ڱ���
	printf("���������ĸ�����Ϣ��\n");
	printf("�꼶רҵ�༶��");
	scanf("%s",a.CLASS);
	printf("ѧ�ţ�");
	scanf("%s",a.ID);
	printf("������");
	scanf("%s",a.stuname);

	fprintf(fp1,"%s\t%s\t%s\n",a.CLASS,a.ID,a.stuname);
	fclose(fp1);

	printf("����ɹ���");
	system("pause");
	return SUCCESS;




}
//**************************************************************************
//���鹦�ܺ���
Status returnbook(DLink head)
{
	FILE *fp;//������reader.txt�ļ�
	FILE *fp1;//������librarybook.txt

        //��������˵���Ϣ,���������¼
	pStudent head1=Initi();//��ʼ��һ����ȡ����ѧ����Ϣ������
	yonhu return_data;//����һ�������洢����ͬѧ��Ϣ�ı���
	yonhu temp;//������ȡtxt��ʱ���𵽸����������

	printf("���������ĸ�����Ϣ��\n");
	printf("�꼶רҵ�༶��");
	scanf("%s",return_data.CLASS);
	printf("ѧ�ţ�");
	scanf("%s",return_data.ID);
	printf("������");
	scanf("%s",return_data.stuname);
//printf("test1\n");
	fp=fopen("reader.txt","r");
	if(!fp1)
	{
		printf("�����޿���ļ���");
		return ERROR;
	}
//printf("test2\n");
	pStudent p=head1;
	while(!feof(fp))
	{
		fscanf(fp,"%s\t%s\t%s\n",temp.CLASS,temp.ID,temp.stuname);

		pStudent message=(pStudent)malloc(sizeof(Student));
		if(message!=NULL)
		{
			strcpy(message->shuju.CLASS,temp.CLASS);
			strcpy(message->shuju.ID,temp.ID);
			strcpy(message->shuju.stuname,temp.stuname);

			p->next=message;
			message->prev=p;
			message->next=head1;
			p=message;
		}
	}
//printf("test3\n");
	int flag=0;
	p=head1->next;
	while(p!=head1)
	{
		if(strcmp(return_data.CLASS,p->shuju.CLASS)==0&&strcmp(return_data.ID,p->shuju.ID)==0&&strcmp(return_data.stuname,p->shuju.stuname)==0)
		{
			p->prev->next=p->next;
			p->next->prev=p->prev;//�Ѻͻ�������Ϣһ���Ľ��ɾȥ
			free(p);
			flag++;
			break;
		}
		else
		{
			p=p->next;
		}
	}
	if(flag==0)
	{
		printf("���û�δ���Ĺ�ͼ�飬����ʧ��!\n");
		printf("���������ⰴ�����ز˵���\n");
		system("pause");
		return ERROR;
	}
//printf("test4\n");
	fclose(fp);




	//����ͼ����Ϣ��ͼ��黹
	Book return_book;
	Book temp1;
	DLink p2=head;

	printf("����������黹��ͼ��ı�š�����������\n");
	printf("���:");
	while(scanf("%d",&return_book.num)==0||getchar()!='\n')
	{
		printf("�����˷Ƿ��ַ������������룺");
		while (getchar() != '\n');
	}
	printf("������");
	scanf("%s",return_book.bookname);
	printf("���ߣ�");
	scanf("%s",return_book.author);

	fp1=fopen("librarybook.txt","rb+");
	if(!fp1)
	{
		printf("�����޿���ļ���");
		system("pause");
		return ERROR;
	}
//printf("test1");
	int n=0;//��ȡ�ļ������ݴ洢������ͽ���һ���ĵ���
	while(!feof(fp1))
	{
		fread(&temp1,sizeof(Book),1,fp1);
		n++;
	}
	fclose(fp1);
//printf("test1");
	fp1=fopen("librarybook.txt","rb+");
	for(int i=0;i<n-1;i++)
	{
		fread(&temp1,sizeof(Book),1,fp1);
		DLink newbook=(DLink)malloc(sizeof(LNode));
		if(newbook)
		{
			newbook->date.num=temp1.num;
			strcpy(newbook->date.bookname,temp1.bookname);
			strcpy(newbook->date.author,temp1.author);
			newbook->date.booknum=temp1.booknum;

			p2->next=newbook;
			p2=newbook;
			newbook->next=NULL;
		}
	}
	fclose(fp1);
//printf("tset1\n");
	//��ԤԼ��.txt���д���
	FILE*fp3;
	fp3=fopen("jieyue.txt","r");
	if(!fp3)
	{
		printf("�����޿���ļ���");
		system("pasue");
		return ERROR;
	}
	//printf("test1\n");
        yonhu temp3;//��ȡԤԼ�û���Ϣ
        //printf("test1\n");
        pStudent head3=Initi();
        //printf("test1\n");
        pStudent p3=head3;
        //printf("test1\n");
        while(!feof(fp3))
	{
		//printf("test1\n");
		fscanf(fp3,"%s\t%s\t%s\t%d\n",&temp3.CLASS,&temp3.ID,&temp3.stuname,&temp3.yuyuenum);
		//printf("test1\n");
		pStudent message=(pStudent)malloc(sizeof(Student));
		if(message!=NULL)
		{
			//printf("test1\n");
			strcpy(message->shuju.CLASS,temp3.CLASS);
			strcpy(message->shuju.ID,temp3.ID);
			strcpy(message->shuju.stuname,temp3.stuname);
			message->shuju.yuyuenum=temp3.yuyuenum;
//printf("test1\n");
			p3->next=message;
			message->prev=p3;
			message->next=head3;
			p3=message;
		}
	}
//printf("tset1\n");
	//��Ѱ�ȶԣ�������ͬ���޳�
	pStudent T2=head1;
	int FLAG=0;
	p3=head3->next;
	while(p3!=head3)
	{
		if(p3->shuju.yuyuenum==return_book.num)
		{
			p3->prev->next=p3->next;
			p3->next->prev=p3->prev;//�Ѻ�ԤԼ��Ϣһ���Ľ��ɾȥ

			//printf("tset1\n");
			p3->next=head1->next;
			//printf("tset1\n");
			p3->next->prev=p3;
			head1->next=p3;
			//printf("tset1\n");
			p3->prev=p;
			//printf("tset1\n");
			//printf("tset1\n");
			FLAG++;
			break;

		}
		else
		{
			p3=p3->next;
		}
	}
	fclose(fp3);

	fp3=fopen("jieyue.txt","w");
	fclose(fp3);
	fp3=fopen("jieyue.txt","a");
	if(!fp3)
	{
		printf("�����޿���ļ���");
		system("pause");
		return ERROR;
	}
	pStudent T=head3->next;
	while(T!=head3)
	{
		//printf("test1");
		fprintf(fp3,"%s\t%s\t%s\t%d\n",T->shuju.CLASS,T->shuju.ID,T->shuju.stuname);
		T=T->next;
	}
	fclose(fp3);


	if(FLAG==0)
	{
		p2=head->next;//���������ݴ�����ݽ����޸�
		int flag1=0;
		while(p2!=NULL)
		{
			if(strcmp(return_book.bookname,p2->date.bookname)==0&&strcmp(return_book.author,p2->date.author)==0)
			{
				p2->date.booknum=p2->date.booknum+1;
				flag1++;
			}
			p2=p2->next;
		}
	//printf("test1");
		//����Ҳ���Ҫ������
		if(flag1==0)
		{
			printf("ͼ�����û�и�ͼ�飬����ʧ�ܣ�\n");
			system("pause");
			return ERROR;
		}
	//printf("test1");
		fp1=fopen("librarybook.txt","w");//���ô򿪹ر��������֮���ٰ��޸�֮����������ݴ���
		fclose(fp1);
		fp1=fopen("librarybook.txt","a");
		if(!fp1)
		{
			printf("�����޿���ļ���");
		}
		p2=head->next;
		while(p2!=NULL)
		{
			fwrite(&(p2->date),sizeof(Book),1,fp1);
			p2=p2->next;
		}
		fclose(fp1);
	}
//printf("test1");

	//�޸ı��ؼ�¼���������¼����Ϣ
	fp=fopen("reader.txt","w");
	fclose(fp);
	fp=fopen("reader.txt","a");
	if(!fp)
	{
		printf("�����޿���ļ���");
		system("pause");
		return ERROR;
	}
	pStudent p1=head1->next;
	while(p1!=head1)
	{
		//printf("test1");
		fprintf(fp,"%s\t%s\t%s\n",p1->shuju.CLASS,p1->shuju.ID,p1->shuju.stuname);
		p1=p1->next;
	}
	fclose(fp);

	printf("����ɹ�!\n");
	system("pause");
	return SUCCESS;

}


//*********************************
//ԤԼͼ�麯��
Status yuyue(int x)
{
	char choose;
	scanf("%c",&choose);
	switch(choose)
	{
	case 'a':
		{
			yonhu a;
			printf("���������ĸ�����Ϣ��\n");
			printf("�꼶רҵ�༶��");
			scanf("%s",a.CLASS);
			printf("ѧ�ţ�");
			scanf("%s",a.ID);
			printf("������");
			scanf("%s",a.stuname);

			FILE *fp;
			fp=fopen("jieyue.txt","a");
			if(!fp)
			{
				printf("�����޿���ļ���");
				return ERROR;
			}
			fprintf(fp,"%s\t%s\t%s\t%d\n",a.CLASS,a.ID,a.stuname,x);
			fclose(fp);
			printf("ԤԼ�ɹ�!");
			system("pause");
			return SUCCESS;
			break;
		}
	case 'b':
		{
			return ERROR;
			break;
		}
	default:
		printf("�Ƿ����룬����������!\n");
		system("pause");
		system("cls");
		yuyuemenu();
		yuyue(x);
		break;
	}
}
