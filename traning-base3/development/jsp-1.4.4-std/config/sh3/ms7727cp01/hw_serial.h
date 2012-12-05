/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: hw_serial.h,v 1.9 2005/07/28 06:56:29 honda Exp $
 */

/*
 *  ���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�MS7717CP01�ѡ�
 *  
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>

#include <sh3.h>
#include <ms7727cp01.h>
#include <st16c2550.h>

/*
 *  ���ꥢ��γ���ߥϥ�ɥ�Υ٥����ֹ�(�����ͥ����)
 */
#define INHNO_SIO   ST16C2550_INT

/*
 * �����ߥ�٥�
 */
#define SIO_INTLVL   8

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
#define sio_initialize  st16c2550_initialize

#ifndef _MACRO_ONLY
/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
Inline SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB  *siopcb;
    BOOL    openflag;

    /*
     *  �����ץ󤷤��ݡ��Ȥ����뤫�� openflg ���ɤ�Ǥ�����
     */
    openflag = st16c2550_openflag();
    
    /*
     *  �ǥХ�����¸�Υ����ץ������
     */
    siopcb = st16c2550_opn_por(siopid, exinf);

    /*
     * �����ߴ�Ϣ������
     * ���顼�ϥ�ɥ����Ͽ���٤�
     */
    if(!openflag){
        define_int_plevel(INHNO_SIO,SIO_INTLVL);     /* SWͥ���� */
        sil_wrh_mem((VP)IPRD,                        /* HWͥ���� */  
                    (sil_reh_mem((VP)IPRD) | (SIO_INTLVL << 12))); 
        /* PINT���͡��֥� */
        sil_wrh_mem((VP)PINTER,
                    (sil_reh_mem((VP)PINTER) | siopcb->siopinib->pinter_val));
    }

    return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�������
 */
Inline void
sio_cls_por(SIOPCB *siopcb)
{
    /*
     *  �ǥХ�����¸�Υ�������������
     */
    st16c2550_cls_por(siopcb);
}


/*
 *  SIO�γ���ߥϥ�ɥ�
 */
#define sio_handler st16c2550_isr

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
#define sio_snd_chr st16c2550_snd_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
#define sio_rcv_chr st16c2550_rcv_chr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
#define sio_ena_cbr st16c2550_ena_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
#define sio_dis_cbr st16c2550_dis_cbr

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
#define sio_ierdy_snd   st16c2550_ierdy_snd

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
#define sio_ierdy_rcv   st16c2550_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */