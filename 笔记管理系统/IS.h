#ifndef IS_H_INCLUDED
#define IS_H_INCLUDED
#include"function.h"

//*****************************
//��ʾָ���
Status IS(char *p);//��ʾ��ǰ����Ŀ¼�ļ�
Status IS_(char *p);//IS<·��>����
Status IStrees(char *p);//IS-a����
Status ISgrep(char *p);//����������Ѱ���ݵ��ļ�
//*******************************
//ɾ���ļ�����
Status deldir(char *p);//ɾ��ָ���ļ����Լ��ļ����µ���������
//*******************************
//�ƶ��ļ�
Status SplitCommand(char *str,char *order,char *title0,char *title1);//�и��
Status mvfile(char *p);//��ָ���ļ��ƶ���ָ���ļ�����
//*******************************
Status sortfile(char *p);//��Ŀ���ļ��н�������




#endif // IS_H_INCLUDED
