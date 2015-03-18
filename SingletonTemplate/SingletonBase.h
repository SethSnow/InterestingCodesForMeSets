/**
 *	����ʹ��һ�ֵ���ģ����Ϊʹ�á�����ģʽ�������ṩ����Ĵ����̳�
 * �̳����ֵ���ģ�壬��Ҫʵ����һ�μ̳е����ࡣ
 *	֮��Ϳ���ʹ���෽���������Դ����ĵ�����--by bshx
 */
#ifndef   SINGLETON_BASE_H_
#define  SINGLETON_BASE_H_
#include <assert.h>

/**
 *	SingletonBase
 */
template<class T>
class SingletonBase
{
public:
	SingletonBase(){
		assert(!m_pSingleClass);
		long offset = (long)(T*)(long)1 - (long)(SingletonBase<T>*)(T*)(long)1; //����̳�ָ��ƫ��
		m_pSingleClass = (T*)((long)this + offset);
	}
	~SingletonBase(){
		assert(m_pSingleClass);
		m_pSingleClass = NULL;
	}

	/**
	 *	��ȡ������ָ��
	 */
	static T*  GetInstancePointer() 
	{
		return m_pSingleClass;
	}

	/**
	 *	��ȡ����������
	 */
	static T& GetInstanceRefer()
	{
		assert(m_pSingleClass);
		return *m_pSingleClass;
	}
private:
	static T* m_pSingleClass; //!< ������
};

template<class T> 
T* SingletonBase<T>::m_pSingleClass = NULL;

#endif






