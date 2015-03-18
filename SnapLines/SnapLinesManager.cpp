#include "SnapLinesManger.h"

using namespace std;

SnapLinesManger::SnapLinesManger()
{
}

SnapLinesManger::~SnapLinesManger()
{
}

bool SnapLinesManger::addNodeInfo(CoordNodeInfo& nodeInfo)
{
  //��ӽڵ���Ϣ
  if(nodeInfo.pNode == NULL)
	return false;

  int coords[4] = { nodeInfo.min_x, nodeInfo.max_x,
                    nodeInfo.min_y, nodeInfo.max_y};
  IVxCGNode* pTmpNode = nodeInfo.pNode; 		

  //���Ӧset�в���ڵ�ָ�롣
  m_CoordAndNodes[Min_x][coord[Min_x]].insert(pTmpNode);
  m_CoordAndNodes[Max_x][coord[Max_x]].insert(pTmpNode);
  m_CoordAndNodes[Min_y][coord[Min_y]].insert(pTmpNode);
  m_CoordAndNodes[Max_y][coord[Max_y]].insert(pTmpNode);
  
  return true;
}

bool SnapLinesManger::isDisplaySnapLine(const IVxCGNode* pNode, const int axis_var, const unsigned int coordFlag)
{
	//����֯�ṹ���ҳ��Ƿ������������ֵ��ƥ����
	if(coordFlag > 3) //������ʶ��Χ
		return false;

	//return m_CoordAndNodes[coordFlag].find(axis_var) != m_CoordAndNodes[coordFlag].end(); ���Ҫ����԰�������ԭ����λ�á�
	
	if(m_CoordAndNodes[coordFlag].find(axis_var) != m_CoordAndNodes[coorFlag].end())
	{
	  if(m_CoordAndNodes[coorFlag][axis_var].size > 1)
		return true;
	  else if( m_CoordAndNodes[coorFlag][axis_var].size == 1)
	  {
	    //�ж�����ǲ���ԭ���ڵ�ָ��
		return m_CoordAndNodes[coorFlag][axis_var].find(pNode) == m_CoordAndNodes[coorFlag][axis_var].end();
	  }
	}
	
   return false;   
}

bool SnapLinesManger::deleteNodeInfo(const IVxCGNode* pNode)
{
	//ɾ���ṹ�а����Ľڵ���Ϣ��
	if(pNode == NULL)
		return false;

	//�����ṹ���в���
	map< int, set<IVxCGNode*> >::iterator iter;
	set<IVxCGNode*>::iterator setItera;
	for(int index = 0; index < 4; index++)
	{
	  iter = m_CoordAndNodes[index].begin();
	  while(iter != m_CoordAndNodes[index].end())
	  {
		setItera = iter->value().find(pNode);
		if(setItera != iter->value().end())
		{
			iter->value().erase(setItera);
			if(iter->value().size() == 0)
			{  
			  //�Ƴ�map�е���һ��
			  m_CoordAndNodes[index].erase(itera++);
			  continue;
			}
		}
		iter++;
	  } // end while
	} // end for
	return true;
}

















