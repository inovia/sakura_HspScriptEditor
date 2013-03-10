/*!	@file
	@brief �v���Z�X���N���X�w�b�_�t�@�C��

	@author aroka
	@date	2002/01/08 �쐬
*/
/*
	Copyright (C) 2002, aroka �V�K�쐬

	This source code is designed for sakura editor.
	Please contact the copyright holder to use this code for other purpose.
*/

#ifndef _CPROCESS_H_
#define _CPROCESS_H_

#include "global.h"
#include "CShareData.h"

/*-----------------------------------------------------------------------
�N���X�̐錾
-----------------------------------------------------------------------*/
/*!
	@brief �v���Z�X���N���X
*/
class SAKURA_CORE_API CProcess {
public:
	CProcess( HINSTANCE hInstance, LPCTSTR lpCmdLine );
	bool Run();
	virtual ~CProcess(){}
protected:
	CProcess();
	virtual bool InitializeProcess();
	virtual bool MainLoop() = 0;
	virtual void OnExitProcess() = 0;

	HINSTANCE	m_hInstance;
	HWND		m_hWnd;

	//	�B���CShareDate�Ƃ���B�iCProcess���ӔC��������new/delete����j
	CShareData		m_cShareData;
	DLLSHAREDATA*	m_pShareData;

private:
};


///////////////////////////////////////////////////////////////////////
#endif /* _CPROCESS_H_ */

/*[EOF]*/