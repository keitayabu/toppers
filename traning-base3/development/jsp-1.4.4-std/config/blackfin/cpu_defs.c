/*
 *  TOPPERS/JSP for Blackfin
 *
 *  Copyright (C) 2004,2006,2006 by Takemasa Nakamura
 *
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ�狼��Free Software Foundation 
 *  �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
 *  �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
 *  ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ��������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  
 */
// DESTRUCTIVE_READ��sys_defs.h��������롣 

// �˲����ɤ߽Ф��쥸�����˥��������������
// �����ߥ��å��򤫤���

#include <s_services.h>

#define __SIL_LOCK_INTERRUPT( x ) \
	if (DESTRUCTIVE_READ(iop)){\
		SIL_PRE_LOC;\
		SIL_LOC_INT();\
		x;\
		SIL_UNL_INT();\
	}\
	else\
		x;

 VB sil_reb_iop(VP iop)
{
	VH temp;
//	PROLOGUE
	
    __SIL_LOCK_INTERRUPT( temp = sil_reh_mem((VP)iop) );

//	EPILOGUE;
    return temp;
}

 VH sil_reh_iop(VP iop)
{
	VH temp;

    __SIL_LOCK_INTERRUPT( temp = sil_reh_mem((VP)iop) );

    return temp;
}

 VW sil_rew_iop(VP iop)
{
	VW temp;

    __SIL_LOCK_INTERRUPT( temp = sil_rew_mem((VP)iop) );

    return temp;
}


 VH sil_reh_lep(VP iop)
{
	VH temp;
	
    __SIL_LOCK_INTERRUPT( temp = sil_reh_lem((VP)iop) );

    return temp;
}


 VW sil_rew_lep(VP iop)
{
	VW temp;
	
    __SIL_LOCK_INTERRUPT( temp = sil_rew_lem((VP)iop) );

    return temp;
}

 VH sil_reh_bep(VP iop)
{
	VH temp;
	
    __SIL_LOCK_INTERRUPT( temp = sil_reh_bem((VP)iop) );

    return temp;
}

 VW sil_rew_bep(VP iop)
{
	VW temp;
	
    __SIL_LOCK_INTERRUPT( temp = sil_rew_bem((VP)iop) );

    return temp;
}
