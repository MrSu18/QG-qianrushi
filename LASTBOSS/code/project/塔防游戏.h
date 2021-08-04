#ifndef LM4229_H_INCLUDED
#define LM4229_H_INCLUDED

#define uchar unsigned char
#define uint unsigned int

#define y_1 16
#define x_1 2

typedef struct zuobiao
{
	uchar x;
	uchar y;
}XY;

typedef struct enemyxingxi
{
	struct zuobiao n;
	uchar	hp;
}Enemyxingxi;


extern uchar receive_data;

extern uchar flag;//������T0��ʱ���Ƿ��ж���һ����ǣ��ﵽ��ʱ2S������
extern uchar idata flagchoose;//�������˵���ѡ�񰴼�

extern uchar idata guangqiachoose;

extern uchar idata direnx;
extern uchar idata direny;//���˵�λ��xy�ö�ʱ���жϿ��Ƶ����ƶ�
extern uchar idata direnhp;

extern uchar idata direnshuliang;//������ǵ��˵��������Ӷ��ﵽ���γ��ֵ�Ч��

extern uchar idata Dn;//����Ŀǰ���ֵ�����
extern uchar idata HP;//����Ѫ��
extern uint idata jingbi;//�������
extern uint idata defen;//��ҵ÷�
extern uchar idata jieshuflag;//���������Ϸ�Ƿ����

extern uchar guangbiaox;
extern uchar guangbiaoy;//�������

extern uint idata score[];

//*************************************
//ͨ�ú���
void delay_ms(uint i);//��ʱms����
void init_T0();//�Զ�ʱ��0���г�ʼ��
//*************************************
//LCD
#define LCD_data P2//LCD�����ݶ˿�
#define LcmLengthDots    240
#define LcmWidthDots     128//��LCD����Ļ���ݽ��ж��巽���޸�

sbit C_D=P1^4;	//��LCD�Ĺ��ܶ˿ڽ�������
sbit R_D=P1^5;
sbit W_R=P1^6;
sbit C_E=P1^7;
sbit REST=P3^7;
//***************************************
//�����
#define digitaltube P0

sbit qianwei 	=P1^0;//������ܹ��ܶ˿ڽ�������
sbit baiwei	=P1^1;
sbit shiwei	=P1^2;
sbit gewei	=P1^3;
//***************************************
//EEPROM�ϵ�洢��
sbit SDA=P3^6;
sbit SCL=P3^5;
//***************************************
//������
sbit beep=P3^4;
//***************************************
//LCD���ܺ���
void write_LCD_commond(uchar com);//��LCDдһ��ָ��
void write_LCD_data(uchar dat);//��LCDдһ������

void write_LCD_dc(uchar com,uchar dat);//дһ�����ݺ�һ��ָ��
void write_LCD_ddc(uchar com,uchar dat1,uchar dat2);//д�������ݺ�һ��ָ��

void LM4229_init(void);//LCD��ʼ������
void LM4229_clear(void);//LCD��������
void dprintf(uchar *bmp_16,uint X_pos,uint Y_pos);//lcd��ʾ����(x,y)240*128,0<x<28,0<y<122
void charprintf(unsigned char *bmp_16,uint X_pos,uint Y_pos);

//***************************************
//���溯��
void mainmeun();//��Ϸ��ʼǰ�����˵�����
void choosemenu(uchar x);//ͨ�����ݲ������ı��ͷ��λ��
void cachu(uchar x);//����ǰ���ͷ�ĺ���

void gameinterface();//��������Ϸ�������
void first();//����Ϸ���棬Ĭ�ϵ�һ�ؿ�ʼ

void youxixinxi(uchar a,uchar b,uchar bai,uchar shi,uchar ge);//��ʾ����ʣ����������Ѫ�������н�������ĺ�������Ҫ���ݱ���ȥ������ʾ
void youxixinxi2_0(HP,n,jingbi);//��������֮��Ĺؿ���Ϣ
void shibaijiemian();//��Ϸʧ�ܽ���
void chengongjiemian();//��Ϸ�ɹ�����

void jixuyouxi();//������Ϸ�����ѡ�ض����˵�
void paihanbang();//��ʾ���а���Ϣ
void paihanbangfenshu(uchar i,uchar j,uint p);//�ֱ�����а��ϵķ������д�ӡ����paihanbang������

//�˵�ѡ����
void xuanguang_meun(uchar x);//ѡ��ʱ��Ķ�̬����
void selectguangqia(uchar flagchoose);//�ѹؿ�ѡ���װ��һ������

//**************************************
//����ܹ��ܺ���
void tubedisplay(uint ge,uint shi,uint bai,uint qian);//��ѡ����
//**************************************
//˫��ͨ�Ź��ܺ���
void init_R();//�Խ��շ����г�ʼ��
void ser();//��ʱ���ж�
//**************************************
//��Ϸ�����߼�����
void meun(uchar flagchoose);

XY zuobiaochuli(uchar guangbiaox,uchar guangbiaoy);//���괦���������ڻ���������ͷ���������
XY zuobiaochuli2_0(uchar guangbiaox,uchar guangbiaoy);//2*16��Ӧ�����괦����

void gongjidir();//���ڷ�������������

void yaokon();//��Ϸ��ʼ��������ĺ���

//ÿ�ص���ƺ���
//��һ��
void initfirstmove();//����һ�ص��˵��ƶ� �趨��ʼ����ʼֵ
void firstmove();//��һ�ص����˶��켣������T0��ʱ���ж�
void diyiguang(uchar flagchoose);//��һ���ܵĽӿں���
//�ڶ���
void second();//�ڶ��صĽ��溯��
void youxifenqu();//��Ϸ�����غϽ��溯�������ٴ��븴����
void secondmove();//�ڶ��ص����˶����켣
void dierguang();//�ڶ����ܵĽӿں���
void judgeresult();//�жϳɹ�����ʧ�ܵĺ���
void gonjidir2_0();//�Ľ�֮��Ĺ�������
uchar towerjiance2();//���������Ƿ��ڵ���·���ϣ��ڷ���0���ڷ���1
//������
void third();//�����صĽ��溯��
void disanguan();//�����ص��ܽӿں���
void thirdmove();//�����صĵ����ƶ�
//**************************************
//EEPROM���ܺ���
void delay();
void init_EEPROM();
void respons();
void stop();
void writebyte(uchar date);
uchar readbyte();
void write_add(uchar address,uchar date);
uchar read_add(uchar address);
//�洢��ȡ��Ϣ
void scorepaixu(uint *p);//�Դ洢���ݵ������������ʹ֮������ٴ���EEPROM
void Weeprom();//�洢���ݵ�EEPROM��
void Reeprom();//��EEPROM�ж�ȡ����
//**************************************
//������
void Beep();//�������ߵ�Ƶ�仯
void buzzer_d();//������������ʾ��
#endif // LM4229_H_INCLUDED
