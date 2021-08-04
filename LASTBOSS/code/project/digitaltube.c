#include <reg52.h>
#include "塔防游戏.h"

unsigned char code duanxuan[] ={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

void tubedisplay(uint qian,uint bai,uint shi,uint ge)//数码管段选函数
{
	qianwei=1;
	digitaltube=duanxuan[qian];
	digitaltube=0xff;
	qianwei=0;

	baiwei=1;
	digitaltube=duanxuan[bai];
	digitaltube=0xff;
	baiwei=0;

	shiwei=1;
	digitaltube=duanxuan[shi];
	digitaltube=0xff;
	shiwei=0;

	gewei=1;
	digitaltube=duanxuan[ge];
	digitaltube=0xff;
	gewei=0;
}
