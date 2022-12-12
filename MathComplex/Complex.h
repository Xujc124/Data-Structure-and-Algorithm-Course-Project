// 定义复数数据结构
typedef struct tagComplex
{
	float fReal;
	float fImage;
} Complex, *LPComplex;

// 创建复数
LPComplex CreateComplex();

// 销毁复数
void DestroyComplex(LPComplex *psCpx);

// 给复数赋值
int AssignComplex(Complex *psCpx, float fReal, float fImage);

// 获取复数的实部值
float GetReal(Complex sCpx);

// 获取复数的虚部值
int GetImage(Complex sCpx, float *pImage);

// 计算两个复数的和
int AddComplex(Complex sCpx1, Complex sCpx2, Complex *psSum);

// 计算两个复数的差
int MinusComplex(Complex sCpx1, Complex sCpx2, Complex *psSum);

// 计算两个复数的乘积
int MultiComplex(Complex sCpx1, Complex sCpx2, Complex *psSum);

// 计算两个复数的商
int DivComplex(Complex sCpx1, Complex sCpx2, Complex *psSum);

// 打印复数
void PrintComplex(Complex sCpx1);

// 复数计算菜单的加法控制函数
int AddTwoComplex();

// 复数计算菜单的减法控制函数
int MinusTwoComplex();

// 复数计算菜单的乘法控制函数
int MultiTwoComplex();

// 复数计算菜单的除法控制函数
int DivTwoComplex();