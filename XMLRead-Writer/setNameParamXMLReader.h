/**
 *	��ȡ�������õ�xml�ļ�
 */
#ifndef SET_NAME_PARAM_XML_READER_H_
#define SET_NAME_PARAM_XML_READER_H_


/**
 *	��ȡxml�����ļ�
 */
class SetNameParamXMLReader
{
public:
	SetNameParamXMLReader();

    /**
	 *	��ȡxml�ļ��е�������Ϣ
	 * \param filePath �ļ�·��
	 * \return bool	�����ȡ�ɹ�����true�� ���򷵻�false
	 */
	bool readConfigFile(const char *filePath);

private:
	char m_version[64];
};

#endif

