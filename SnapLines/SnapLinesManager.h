/**
 * \author bshx
 * \date 2014-03-19
 * \detail ʵ��һ����ͼԪ�Ķ��������⣬���������
 */
 
 #ifndef _SnapLinesManager_h_
 #define _SnapLinesManager_h_
 
 #include <stdlib.h>
 #include <pthread.h>
 #include <vector>
 #include <map>
 #include <set>
 
 using namespace std;
 
 
 /**
  * \struct CoordNodeInfo ����ͼԪ������飩�ڵ��������Ϣ
  */
  struct CoordNodeInfo
  {
	int min_x, max_x; //!< �����Сx����
	int min_y, max_y; //!< �����Сy����
	IVxCGNode* pNode;
	
	/*
	  ���幹�������
	 */
	CoordNodeInfo(): min_x(0), max_x(0),
	                 min_y(0), max_y(0),
					 pNode(NULL)
					 {}
    ~CoordNodeInfo() {}	
  }
 
 
 
 /**
  * \class SnapLineManager ������Զ����ߵ���ʾ�ͼ���
  * \detail 
  *	 �ⶨʹ��map��set�������ֱ���ж������У���ͼԪ��Χ�������С�����������ͼԪ������飩������
  *  �����ƶ�ͼԪ�İ�Χ����ֵ������ȷ���Ƿ��ڳ�������ͼԪ�������ֵ����
  */
   class SnapLineManager
   {
	public:
		SnapLineManager();
		~SnapLineManager();
		
		
		/**
		 * \enum ��Χ�������С�����ʶ
		 */
		enum CoordMinMax
		{
			Min_x = 0,
			Max_x,
			Min_y,
			Max_y
		};
		
		/**
		 * \param nodeInfo ͼԪ����Χ��������Ϣ
		 * \return �����ӳɹ�����true�� ���򷵻�false
		 * \detail 
		 *   �Ե�ǰ������һ��ͼԪ������飩����Ϣ������ӣ���Ӻ����Ϣ����map��������
		 */
		 bool addNodeInfo(CoordNodeInfo& nodeInfo);
		 
		 /**
		  * \param  pNode �ڵ����ָ��
		  * \param axis_var ��������ֵ
		  * \param coordFlag ֻ��������Ǹ����꣬ȡֵ�ο� \enum CoordMinMax
		  * \return ���������ʾ��Ӧ�������򷵻�true�����򷵻�false
		  * \detail
		  *    ���жԸ�������Ķ����߲��ԣ�ͨ���볡���и���ͼԪ������飩���бȽϡ�
		  * \sa CoordMinMax
		  */
		 bool isDisplaySnapLine(const IVxCGNode* pNode, const int axis_var, const unsigned int coordFlag);
		 
		
		/**
		 * 
		 * \param pNode ��Ҫ�ڽṹ��ɾ���Ľڵ�ָ������
		 * \return ���ɾ���ɹ�����true�����򷵻�false
		 * \detail 
		 *    ɾ���ṹ���������һ��Ĵ洢��Ϣ�����ҵ�map��setû�м�¼ʱɾ������ڵ�������ݡ�Ҳ�൱�ڸ��´洢�Ľṹ��
		 */
		 bool deleteNodeInfo(const IVxCGNode* pNode);
		
	protected:
		
	private:
	  
		map< unsigned int, set<IVxCGNode*> > m_CoordAndNodes[4]; //!< ����ֱ���min_x��max_x��min_y��max_y�����������ļ��ϡ�
   }
   
 
 
 #endif
 
 
 