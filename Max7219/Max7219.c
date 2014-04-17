sbit LOAD=P1^2;          //MAX7219����           12�}
sbit DIN=P1^1;           //MAX7219��C���       1�}
sbit CLK=P1^0;           //MAX7219��C����        13�}
//�H�s�������w�q
#define DECODE_MODE  0x09   //�ѽX����H�s��
#define INTENSITY    0x0A   //�G�ױ���H�s��
#define SCAN_LIMIT   0x0B   //���y�ɭ��H�s��
#define SHUT_DOWN    0x0C   //���_�Ҧ��H�s��
#define DISPLAY_TEST 0x0F   //���ձ���H�s��         
//����n��
void Write7219(unsigned char address,unsigned char dat);
void Initial(void);
//��}�B��Ƶo�e�Ƶ{��
void Write7219(unsigned char address,unsigned char dat)
{   
    unsigned char i;
    LOAD=0;    //�ԧC����u�A�襤����
    //�o�e�a�}
    for (i=0;i<8;i++)        //����j��8��              
    {   
       CLK=0;        //�M�s�����׬y��
       DIN=(bit)(address&0x80); //�C�������줸��      
       address<<=1;             //�����@��
       CLK=1;        //�����W�ɪu�A�o�e��}
    }
    //�o�e���
    for (i=0;i<8;i++)               
    {   
       CLK=0;
       DIN=(bit)(dat&0x80);     
       dat<<=1;  
       CLK=1;        //�����W�ɪu�A�o�e���
    }
    LOAD=1;    //�o�e�����A�W�ɪu��s���                       
}
//MAX7219��l�ơA�]�mMAX7219����������H�s��
void Initial(void)                 
{ 
    Write7219(SHUT_DOWN,0x01);         //�}�ҥ��`�u�@�Ҧ��]0xX1�^
    Write7219(DISPLAY_TEST,0x00);      //��ܤu�@�Ҧ��]0xX0�^
    Write7219(DECODE_MODE,0xff);       //��Υ��ѽX�Ҧ�
    Write7219(SCAN_LIMIT,0x07);        //8�uLED����
    Write7219(INTENSITY,0x04);          //�]�m��l�G��      
}
���յ{��
void main(void)
{
    unsigned char i; 
    Initial();               //MAX7219��l��
    while(1)
    {  
       for(i=1;i<9;i++)
       {
           Write7219(i,i);      //�ƽX�����1~8
       }
    } 
}
