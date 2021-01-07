#pragma once
#include "GlobalDefine.h"
#include "UIObject.h"

namespace JEngine
{
	/**
	* @brief Text�� ���� ����ϴ� Ŭ����
	* @details Text�� ���� ����ϴ� Ŭ����
	* @author JBC classicaa@naver.com
	* @date 2016-10-20
	* @version 0.0.1
	*/

	class Label : public JEngine::UIObject
	{
	private:
		
		DWORD					m_dwDrawOption;
		string					m_strPrint;
	public:
		Label();

		void					Init(string str, int x, int y, DWORD drawOption);
		virtual void			Draw();
		virtual bool			Update() { return false; }

		virtual ~Label();
	};

}


