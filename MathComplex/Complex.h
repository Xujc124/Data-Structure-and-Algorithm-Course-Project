// ���帴�����ݽṹ
typedef struct tagComplex
{
	float fReal;
	float fImage;
} Complex, *LPComplex;

// ��������
LPComplex CreateComplex();

// ���ٸ���
void DestroyComplex(LPComplex *psCpx);

// ��������ֵ
int AssignComplex(Complex *psCpx, float fReal, float fImage);

// ��ȡ������ʵ��ֵ
float GetReal(Complex sCpx);

// ��ȡ�������鲿ֵ
int GetImage(Complex sCpx, float *pImage);

// �������������ĺ�
int AddComplex(Complex sCpx1, Complex sCpx2, Complex *psSum);

// �������������Ĳ�
int MinusComplex(Complex sCpx1, Complex sCpx2, Complex *psSum);

// �������������ĳ˻�
int MultiComplex(Complex sCpx1, Complex sCpx2, Complex *psSum);

// ����������������
int DivComplex(Complex sCpx1, Complex sCpx2, Complex *psSum);

// ��ӡ����
void PrintComplex(Complex sCpx1);

// ��������˵��ļӷ����ƺ���
int AddTwoComplex();

// ��������˵��ļ������ƺ���
int MinusTwoComplex();

// ��������˵��ĳ˷����ƺ���
int MultiTwoComplex();

// ��������˵��ĳ������ƺ���
int DivTwoComplex();