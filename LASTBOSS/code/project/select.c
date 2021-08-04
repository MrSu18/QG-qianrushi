#include <reg52.h>
#include "塔防游戏.h"
#include "tuxiangku.h"

void xuanguang_meun(uchar x)//选关时候的动态函数
{
	dprintf(&choose[0],18,31+guangqiachoose*17);
	while(1)
	{
		switch(receive_data)
		{
		case 'u':
			receive_data=0;
			if(guangqiachoose==0)
			{
				dprintf(clear,18,31+guangqiachoose*17);
				guangqiachoose=4;
			}
			else
			{
				guangqiachoose--;
			}
			dprintf(&choose[0],18,31+guangqiachoose*17);
			dprintf(clear,18,31+(guangqiachoose+1)*17);
			break;
		case 'd':
			receive_data=0;
			if(guangqiachoose==4)
			{
				dprintf(clear,18,31+guangqiachoose*17);
				guangqiachoose=0;
			}
			else
			{
				guangqiachoose++;
			}
			dprintf(&choose[0],18,31+guangqiachoose*17);
			dprintf(clear,18,31+(guangqiachoose-1)*17);
			break;
		case 'y':
			receive_data=0;
			selectguangqia(guangqiachoose);
			break;
		case 'n':
			receive_data=0;
			mainmeun();
			meun(x);
			break;
		default:break;
		}
	}
}

void selectguangqia(uchar flagchoose)//把关卡选择封装成一个函数
{
	buzzer_d();
	switch(guangqiachoose)
	{
	case 0:
		diyiguang(flagchoose);
		break;
	case 1:
		dierguang();
		break;
	case 2:
		disanguan();
		break;

	break;
	default:break;
	}
}
