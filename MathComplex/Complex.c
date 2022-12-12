#include "stdio.h"
#include "stdlib.h"
#include "Complex.h"
#include "math.h"

// ���ٸ���
LPComplex CreateComplex()
{
	// Ϊ���������ڴ�ռ�
	return (LPComplex)malloc(sizeof(Complex));
}

// ���ٸ���
void DestroyComplex(LPComplex *psCpx)
{
	free(*psCpx);
	*psCpx = NULL;
}

// ���츴������ʵ�����鲿�ֱ𱻸��Բ��� fReal �� fImage ��ֵ
int AssignComplex( Complex *psCpx, float fReal, float fImage )
{
	if (psCpx == NULL)
		return 1;

	psCpx->fReal = fReal;
	psCpx->fImage = fImage;
	
	return 0;
}

// ��ȡ������ʵ��ֵ
float GetReal( Complex sCpx )
{
	return sCpx.fReal;
}

// ��ȡ�������鲿ֵ
int GetImage(Complex sCpx, float* fImage)
{
	if (fImage == NULL)
		return 1;

	*fImage = sCpx.fImage;

	return 0;
}

// �������������ĺ�
int AddComplex(Complex sCpx1, Complex sCpx2, Complex* psSum)
{
	if (psSum == NULL)
		return 1;

	psSum->fReal = sCpx1.fReal + sCpx2.fReal;
	psSum->fImage = sCpx1.fImage + sCpx2.fImage;

	return 0;
}

// �������������Ĳ�
int MinusComplex(Complex sCpx1, Complex sCpx2, Complex *psSum)
{
	if(psSum == NULL)
		return 1;

	psSum->fReal = sCpx1.fReal - sCpx2.fReal;
	psSum->fImage = sCpx1.fImage - sCpx2.fImage;

	return 0;

}

// �������������ĳ˻�
int MultiComplex(Complex sCpx1, Complex sCpx2, Complex *psSum)
{
	if(psSum == NULL)
		return 1;

	psSum->fReal = sCpx1.fReal * sCpx2.fReal - sCpx1.fImage * sCpx2.fImage;
	psSum->fImage = sCpx1.fReal * sCpx2.fImage + sCpx1.fImage * sCpx2.fReal;

	return 0;

}

// ����������������
int DivComplex(Complex sCpx1, Complex sCpx2, Complex *psSum)
{
	if(psSum == NULL)
		return 1;

	psSum->fReal = (sCpx1.fReal * sCpx2.fReal + sCpx1.fImage * sCpx2.fImage)
								/(pow(sCpx2.fImage,2)+pow(sCpx2.fReal,2));
	
	psSum->fImage = (sCpx1.fImage * sCpx2.fReal - sCpx1.fReal * sCpx2.fImage)
								/(pow(sCpx2.fImage,2)+pow(sCpx2.fReal,2));

	return 0;

}

// ��ӡ����
void PrintComplex(Complex sCpx)
{
    float fReal = GetReal(sCpx);
    float fImage = 0.0f;
    GetImage(sCpx, &fImage);
    
	if (fReal == 0 && fImage == 0)
		// ������ʵ�����鲿ͬʱΪ0��0 + 0i
		printf("%.2f", 0.0f);
	else if (fImage == 0)
	{
		// ���������鲿Ϊ0, x + 0i
		printf("%.2f", fReal);
	}
	else if (fReal == 0)
	{
		// ��������ʵ��Ϊ0��0 + xi
		printf("%.2fi", fImage);
	}
	else
	{
		// ������ʵ�����鲿����Ϊ0��x + yi
		printf("%.2f", fReal);

		if (fImage > 0)
		{
			printf(" + %.2fi", fImage);
		}
		else
		{
			printf(" - %.2fi", fabs(fImage));
		}
	}
	
}