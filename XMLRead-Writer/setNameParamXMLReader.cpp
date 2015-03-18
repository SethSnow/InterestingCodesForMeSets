#include "stdafx.h"
#include "setNameParamXMLReader.h"
#include "XMLCommon.h"
#include <iostream>

XERCES_CPP_NAMESPACE_USE

SetNameParamXMLReader::SetNameParamXMLReader()
{
	memset(m_version, 0, sizeof(char) * 64);
}

bool SetNameParamXMLReader::readConfigFile(const char *filePath)
{
	bool res = false;

	if (!filePath)
		return res;

	try{
		XMLPlatformUtils::Initialize();
	}
	catch (const XMLException & toCatch){
		char *message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Error during initialization! : \n"
			<< message << "\n";
		XMLString::release(&message);
		return res;
	}

	XercesDOMParser *parser = new XercesDOMParser();
	parser->setValidationScheme(XercesDOMParser::Val_Always);
	parser->setDoNamespaces(true);

	ErrorHandler *errHandler = (ErrorHandler*)new HandlerBase();
	parser->setErrorHandler(errHandler);

	try{
		parser->parse(filePath);
	}
	catch (const XMLException &toCatch){
		char *message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Exception message is: \n"
			<< message << "\n";
		XMLString::release(&message);
	}
	catch (const DOMException &toCatch) {
		char * message = XMLString::transcode(toCatch.msg);
		std::cout << "Exception message is: \n"
			<< message << "\n";
		XMLString::release(&message);
	}
	catch (...) {
		std::cout << "Unexpected Exception \n";
	}

	//����xml�� ȡ����������
	xercesc::DOMDocument *doc = parser->getDocument();
	//��ȡ�����ڵ�
	DOMElement *pRoot = doc->getDocumentElement();
	if (pRoot)
	{
		//��ȡ�汾
		std::string tmpVer = XMLString::transcode(pRoot->getAttribute(XMLString::transcode("version")));
		strncpy(m_version, tmpVer.c_str(), tmpVer.length() + 1);

		//��ȡ�����ļ�
		READ_ELE_XML("formatName",g_nameSetParam.strName, MAX_PATH, doc);
		READ_ELE_XML("prefixName", g_nameSetParam.strPrefixName, MAX_PATH, doc);
		READ_ELE_XML("suffixName", g_nameSetParam.strSuffixName, MAX_PATH, doc);

		READ_ELE_BOOL_XML("prefix", doc, g_nameSetParam.isHasPrefix);
		READ_ELE_BOOL_XML("suffix", doc, g_nameSetParam.isHasSuffix);
		res = true;
	}
	//�ͷ���Դ
	DELETEPTR(parser);
	XMLPlatformUtils::Terminate();
	return res;
}





