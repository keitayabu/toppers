/*
 *  TOPPERS/FMP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Flexible MultiProcessor Kernel
 * 
 *  Copyright (C) 2006 by GJ Business Division RICOH COMPANY,LTD. JAPAN  
 *  Copyright (C) 2007-2009 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
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
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: target_serial.h 447 2009-10-16 08:51:47Z ertl-honda $
 */

/*
 * ���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�AT91SKYEYE�ѡ�
 */

#ifndef TOPPERS_TARGET_SERIAL_H
#define TOPPERS_TARGET_SERIAL_H

#include "at91skyeye.h"

/*
 *  SIO�γ���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define INHNO_SIO_PRC1   (0x10000|IRQ_USART0)  /* ����ߥϥ�ɥ��ֹ� */
#define INTNO_SIO_PRC1   (0x10000|IRQ_USART0)  /* ������ֹ� */
#define INTPRI_SIO_PRC1       -2               /* �����ͥ���� */
#define INTATR_SIO_PRC1       0U               /* �����°�� */

#define INHNO_SIO_PRC2   (0x20000|IRQ_USART0)  /* ����ߥϥ�ɥ��ֹ� */
#define INTNO_SIO_PRC2   (0x20000|IRQ_USART0)  /* ������ֹ� */
#define INTPRI_SIO_PRC2       -2               /* �����ͥ���� */
#define INTATR_SIO_PRC2       0U               /* �����°�� */

#define INHNO_SIO_PRC3   (0x30000|IRQ_USART0)  /* ����ߥϥ�ɥ��ֹ� */
#define INTNO_SIO_PRC3   (0x30000|IRQ_USART0)  /* ������ֹ� */
#define INTPRI_SIO_PRC3       -2               /* �����ͥ���� */
#define INTATR_SIO_PRC3       0U               /* �����°�� */

#define INHNO_SIO_PRC4   (0x40000|IRQ_USART0)  /* ����ߥϥ�ɥ��ֹ� */
#define INTNO_SIO_PRC4   (0x40000|IRQ_USART0)  /* ������ֹ� */
#define INTPRI_SIO_PRC4       -2               /* �����ͥ���� */
#define INTATR_SIO_PRC4       0U               /* �����°�� */

/*
 *  ���ꥢ��I/O�ݡ��ȿ������
 */
#define TNUM_SIOP		TNUM_PRCID		/* ���ݡ��Ȥ��륷�ꥢ��I/O�ݡ��Ȥο� */


#ifndef TOPPERS_MACRO_ONLY

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥��å������
 */
typedef struct sio_port_control_block	SIOPCB;

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_RDY_SND	1U		/* ������ǽ������Хå� */
#define SIO_RDY_RCV	2U		/* �������Υ�����Хå� */

/*
 * �����ͥ뵯ư���Υ��������Ѥν������in usart.h��
 */
extern  void at91skyeye_init_uart(uint_t siopid);

/*
 *  UART����Υݡ���󥰽���
 */
Inline void
at91skyeye_putc(char_t c)
{
	sil_wrw_mem((void *)USART0_THR, c);
}

/*
 *  SIO�ɥ饤�Фν����
 */
extern void sio_initialize(intptr_t exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB *sio_opn_por(ID siopid, intptr_t exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�������
 */
extern void sio_cls_por(SIOPCB *p_siopcb);

/*
 *  SIO�γ���ߥϥ�ɥ�
 */
extern void sio_handler(void);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern bool_t sio_snd_chr(SIOPCB *siopcb, char_t c);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
extern int_t sio_rcv_chr(SIOPCB *siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void sio_ena_cbr(SIOPCB *siopcb, uint_t cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void sio_dis_cbr(SIOPCB *siopcb, uint_t cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void sio_irdy_snd(intptr_t exinf);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void sio_irdy_rcv(intptr_t exinf);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_SERIAL_H */