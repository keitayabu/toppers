/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 * 
 *  �嵭����Ԥϡ�Free Software Foundation �ˤ�äƸ�ɽ����Ƥ��� 
 *  GNU General Public License �� Version 2 �˵��Ҥ���Ƥ����狼����
 *  ����(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ���
 *  ������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ�����������Ѳ�ǽ�ʥХ��ʥꥳ���ɡʥ���������֥륪��
 *      �������ȥե������饤�֥��ʤɡˤη������Ѥ�����ˤϡ�����
 *      ��ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ����
 *      �������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ�������������Բ�ǽ�ʥХ��ʥꥳ���ɤη��ޤ��ϵ������
 *      �߹�����������Ѥ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) ���Ѥ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) ���Ѥη��֤��̤�������ˡ�ˤ�äơ��嵭����Ԥ���𤹤�
 *        ���ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥϡ�
 *  �ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����ޤ�ơ������ʤ��ݾڤ�Ԥ�
 *  �ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū����������
 *  ���ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: sys_config.c,v 1.3 2005/11/24 12:41:23 honda Exp $
 */

/*
 *	�������åȥ����ƥ��¸�⥸�塼���OAKS32�ѡ�
 */

#include "jsp_kernel.h"
#include <sil.h>
#include "oaks32.h"

/*
 *  �������åȥ����ƥ��¸ ������롼����
 */

void
sys_initialize(void)
{
	VB * p;
	volatile char ps0, pd6;

	/*
	 * �ݡ��Ȥ�����
	 */

	/* �ݡ���P63�� TxD0, �ݡ���P62�� RxD0 �� */
	ps0 = sil_reb_mem((VP)TADR_SFR_PS0);
	ps0 |= 0x08;
	ps0 &= ~0x04;
	sil_wrb_mem((VP)TADR_SFR_PS0, ps0);
	pd6 = sil_reb_mem((VP)TADR_SFR_PD6);
	pd6 &= ~0x04;
	pd6 |= 0x08;
	sil_wrb_mem((VP)TADR_SFR_PD6, pd6);

	p = (VB*)TADR_SFR_UART0_BASE;

	/*
	 * UART��Ϣ�쥸����������
	 */
	/* �������ػ� */
	sil_wrb_mem((VP)(p+TADR_SFR_UC1_OFFSET), 0x00);

	/* �������⡼�ɥ쥸�����ν���� */
	sil_wrb_mem((VP)(p+TADR_SFR_UMR_OFFSET), 0x05);	/* ��������ݥɥ쥸���� ���������å�,*/
				/* ��Ʊ����8�ӥåȡ��ѥ�ƥ��ʤ���*/
				/* ���꡼�פʤ�	*/
			/* ��������쥸�����ν���� */
	sil_wrb_mem((VP)(p+TADR_SFR_UC0_OFFSET), 0x10);	/* ����������쥸����0 �����å�f8���� */
			/* ž��®�٥쥸�����ν���� */
	sil_wrb_mem((VP)(p+TADR_SFR_UBRG_OFFSET), 48);	/* ž��®�٥쥸����(38400bps)		*/
			/* ����������쥸�����ν���� */
	sil_wrb_mem((VP)(p+TADR_SFR_UC1_OFFSET), (TBIT_UiC1_TE | TBIT_UiC1_RE));
							/* ����������쥸������ ���������� */

	/*
	 * LED �ν����
	 */
	sil_wrb_mem((VP)TADR_SFR_P0, 0xff);	/* �ݡ���0�ǡ��������	*/
	sil_wrb_mem((VP)TADR_SFR_PD0, 0xff);	/* �ݡ���0��������	*/
}

/*
 *  �������åȥ����ƥ�ν�λ�롼����
 */

void
sys_exit(void)
{
  while (1);
}

void
sys_putc(char c)
{
	if(c == '\n'){
	    oaks32_putc( '\r' );
	}
    oaks32_putc( c );
}