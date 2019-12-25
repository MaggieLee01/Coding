//˼·��������Ķ��壬��һ�����캯������Ϊchar*���ڶ�������Ĳ���Ϊ���ÿ�����
//����=�����������str1=str2��ֵ��

#include<cstdio>
#include<cstring>
#include<iostream>
#pragma warning(disable:4996)

class CMyString
{
public:
	CMyString(char *pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator=(const CMyString& str);

	void Print();

private:
	char* m_pData;
};

CMyString::CMyString(char *pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = 0;
		char *m = pData;
		while (*m++ != '\0')
			length++;

		m = pData;
		
		m_pData = new char[length + 1];
		char *n = m_pData;//��������m_pDataָ���ſ��Ը�ֵ������ָ��
		while (*m != '\0')
			*(n++) = *(m++);//����ֱ�Ӷ�m_pData��pDataָ�����ѽ����Ȼָ��ָ��ĩβ
		*(n++) = '\0';
	}
}
CMyString::CMyString(const CMyString& str)//���𰸣��˴�����thisҲ���ԣ�Ҳ�����жϿ�ָ��
{
	char *m = str.m_pData;
	if (m == nullptr)
	{
		this->m_pData = new char[1];
		this->m_pData[0] = '\0';
	}
	else
	{
		int length = 0;
		while (*m++ != '\0')
			length++;

		m = str.m_pData;

		this->m_pData = new char[length + 1];
		char *n = this->m_pData;//��������m_pData��ָ���ſ��Ը�ֵ������ָ��

		while (*m != '\0')
			*(n++) = *(m++);//����ֱ�Ӷ�m_pData��pDataָ�����ѽ����Ȼָ��ָ��ĩβ
		*(n++) = '\0';
	}
}
CMyString& CMyString::operator=(const CMyString& str)
{
	//������Ϊ������Ĺ��츳ֵһ��
	if (this == &str)
		return *this;
	delete[] m_pData;//�����ڴ�й¶
	m_pData = nullptr;//����Ҫ������Ұָ��

	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
	return *this;	
}
void CMyString::Print() 
{
	std::cout << this->m_pData << std::endl;
}
CMyString::~CMyString()
{
	delete[] m_pData;
}

// ====================���Դ���====================


void Test1()
{
	printf("Test1 begins:\n");

	char text[] = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
}

// ��ֵ���Լ�
void Test2()
{
	printf("Test2 begins:\n");

	char text[] = "Hello world";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.Print();
	printf(".\n");
}

// ������ֵ
void Test3()
{
	printf("Test3 begins:\n");

	char text[] = "Hello world";

	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.Print();
	printf(".\n");
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	system("pause");
	return 0;
}

//����ο��𰸣�
//�ַ����ĳ��ȼ��㡢�ַ����ĸ�ֵ����ר�ŵ�string����strlen strcpy�������Լ���д��
//new������д��
//�������캯�����㳤�ȣ�����ռ䣬copy���ɣ�û���漰thisָ�룬Ҳ����Ҫ�ж�str�Ƿ�Ϊ��

//˼������Ϊʲô��һ��char* ָ����Ҫ�ж��Ƿ�Ϊ���ء�
//�����ˣ�copy�����ʱ���Ȼ�ܴ���CMyString��ĳ�Ա�����Ѿ�����˿�ָ������⣬ֱ�Ӹ��Ƽ��ɡ�

//˼����ʲôʱ����thisָ�룬�࿴�����ܾ���
//"zbc"�����ַ����������"cstrings"��char* text = "Hello world";���ֶ��屨���������鶨��

//�࿼�ǲ�������

//vs2017����strcpy�����������������֣�
//1��#pragma warning(disable:4996)
//2.c/c++Ԥ����������Ԥ�������_CRT_SECURE_NO_WARNINGS
//3.c/c++���棬SDLѡ��رա������顿
