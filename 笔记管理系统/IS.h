#ifndef IS_H_INCLUDED
#define IS_H_INCLUDED
typedef enum Status
{
	SUCCESS=1,
	ERROR=0
}Status;
//*****************************
//��ʾָ���
Status IS(char *p);//��ʾ��ǰ����Ŀ¼�ļ�
Status IS_(char *p);//IS<·��>����
Status IStrees(char *p);//IS-a����
Status ISgrep(char *p);//����������Ѱ���ݵ��ļ�
//*******************************
//ɾ���ļ�����
Status deldir(char *p);



#endif // IS_H_INCLUDED
