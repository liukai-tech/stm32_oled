#ifndef OLED_BASIC_H
#define OLED_BASIC_H

typedef struct COORDINATE 
{
	int x;
	int y;
}TypeXY;
#define point TypeXY 
typedef struct ROATE
{
	TypeXY center;
	float angle;
	int direct;
}TypeRoate;

#define RADIAN(angle)  ((angle==0)?0:(3.14159*angle/180))
#define MAX(x,y)  		((x)>(y)? (x):(y))
#define MIN(x,y)  		((x)<(y)? (x):(y))
#define SWAP(x, y) \
	(y) = (x) + (y); \
	(x) = (y) - (x); \
	(y) = (y) - (x);

//���ñ���ģʽ��0Ϊ͸����1Ϊ������
void SetTextBkMode(unsigned char value);
//��ȡ��ǰ����ģʽ
unsigned char GetTextBkMode(void);
void SetPointBuffer(int x,int y,int value);
unsigned char GetPointBuffer(int x,int y);
void UpdateScreen(void);
void ClearScreen(void);
void InitGraph(void);

TypeXY GetRotateXY(int x,int y);
void SetRotateValue(int x,int y,float angle,int direct);
void SetRotateCenter(int x0,int y0);
void SetAnggleDir(int direction);
void SetAngle(float angle);
void FloodFill(unsigned char x,unsigned char y,int oldcolor,int newcolor);
void FillRect(int x,int y,int width,int height);
void FloodFill2(unsigned char x,unsigned char y,int oldcolor,int newcolor);
void FillVerticalLine(int x,int y,int height,int value);
void FillByte(int page,int x,unsigned  char byte);

unsigned char pgm_read_byte(const unsigned char * addr);
unsigned int oled_pow(unsigned char m,unsigned char n);
unsigned char FrameRateUpdateScreen(int value);
#endif
