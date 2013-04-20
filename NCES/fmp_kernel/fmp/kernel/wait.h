/*
 *  TOPPERS/FMP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Flexible MultiProcessor Kernel
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2010 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: wait.h 661 2010-07-29 10:10:12Z ertl-honda $
 */

/*
 *		�Ԥ����ִ����⥸�塼��
 */

#ifndef TOPPERS_WAIT_H
#define TOPPERS_WAIT_H

#include "task.h"
#include "time_event.h"

/*
 *  ��������ͥ���ٽ���Ԥ����塼�ؤ�����
 *
 *  p_tcb�ǻ��ꤵ��륿�����򡤥�����ͥ���ٽ�Υ��塼p_queue���������롥
 *  ���塼�����Ʊ��ͥ���٤Υ�������������ˤϡ����κǸ���������롥
 */
Inline void
queue_insert_tpri(QUEUE *p_queue, TCB *p_tcb)
{
	QUEUE	*p_entry;
	uint_t	priority = p_tcb->priority;

	for (p_entry = p_queue->p_next; p_entry != p_queue;
										p_entry = p_entry->p_next) {
		if (priority < ((TCB *) p_entry)->priority) {
			break;
		}
	}
	queue_insert_prev(p_entry, &(p_tcb->task_queue));
}

/*
 *  �Ԥ����֤ؤ�����
 *
 *  �¹���Υ��������Ԥ����֤����ܤ����롥����Ū�ˤϡ��¹���Υ�������
 *  ��ǥ����塼����������TCB��tmevtb��callback�ե�����ɤ�NULL��
 *  ���ꤹ��ʱʵ��Ԥ��ˡ�
 */
Inline void
make_wait(TCB *p_runtsk)
{
	(void) make_non_runnable(p_runtsk);
	(p_runtsk->tmevtb).callback = NULL;
}

/*
 *  �Ԥ����֤ؤ����ܡʥ����ॢ���Ȼ����
 *
 *  �¹���Υ������򡤥����ॢ���Ȼ����դ����Ԥ����֤����ܤ����롥����
 *  Ū�ˤϡ��¹���Υ��������ǥ����塼���������������।�٥�ȥ�
 *  ���å�����Ͽ���롥
 */
extern void	make_wait_tmout(TMO tmout, PCB *p_pcb);

/*
 *  �Ԥ�����Τ���Υ��������֤ι���
 *
 *  p_tcb�ǻ��ꤵ��륿�������Ԥ��������褦���������֤򹹿����롥
 *  �Ԥ�������륿�������¹ԤǤ�����֤ˤʤ���ϡ���ǥ����塼�ˤĤ�
 *  �����ޤ����ǥ����ѥå���ɬ�פʾ��ˤ�true���֤���
 *    
 *  �Ԥ����֤���������ϡ�ɬ�����δؿ���ƤӽФ����ᡤ�ǥåɥ��å�
 *  ����Τ���Υڥ�ǥ��󥰥ե饰�Υ����å���ޤȤ�ƹԤ���
 */
Inline bool_t
make_non_wait(TCB *p_tcb)
{
	assert(TSTAT_WAITING(p_tcb->tstat));

#if TTYPE_KLOCK != G_KLOCK
	/* ͥ�����ѹ��ե饰�����å� */
	if (p_tcb->pend_chgpri) {
		p_tcb->priority = p_tcb->pend_newpri;
		/* ͥ�����ѹ��ե饰�Υ��ꥢ */
		p_tcb->pend_chgpri = false;
	}

	/* �����������Ԥ������α���ꥢ */
	p_tcb->pend_relwai = false;
#endif /* TTYPE_KLOCK != G_KLOCK */

	if (!TSTAT_SUSPENDED(p_tcb->tstat)) {
		/*
		 *  �Ԥ����֤���¹ԤǤ�����֤ؤ�����
		 */
		p_tcb->tstat = TS_RUNNABLE;
		LOG_TSKSTAT(p_tcb);
		return(make_runnable(p_tcb));
	}
	else {
		/*
		 *  ����Ԥ����֤��鶯���Ԥ����֤ؤ�����
		 */
		p_tcb->tstat = TS_SUSPENDED;
		LOG_TSKSTAT(p_tcb);
		return(false);
	}
}

/*
 *  ���֥��������Ԥ����塼����κ��
 *
 *  p_tcb�ǻ��ꤵ��륿��������Ʊ�����̿����֥������Ȥ��Ԥ����塼�ˤ�
 *  �ʤ���Ƥ���С��Ԥ����塼���������롥
 */
Inline void
wait_dequeue_wobj(TCB *p_tcb)
{
	if (TSTAT_WAIT_WOBJ(p_tcb->tstat)) {
		queue_delete(&(p_tcb->task_queue));
	}
}

/*
 *  �����Ԥ��Τ���Υ����।�٥�ȥ֥��å�����Ͽ���
 *
 *  p_tcb�ǻ��ꤵ��륿�������Ф��ơ������Ԥ��Τ���Υ����।�٥�ȥ�
 *  ���å�����Ͽ����Ƥ���С��������Ͽ������롥
 */
Inline void
wait_dequeue_tmevtb(TCB *p_tcb)
{
	if ((p_tcb->tmevtb).callback != NULL) {
		tmevtb_dequeue(p_tcb->p_pcb->p_tevtcb, &(p_tcb->tmevtb));
	}
}

/*
 *  �Ԥ����
 *
 *  p_tcb�ǻ��ꤵ��륿�������Ԥ����֤������롥����Ū�ˤϡ������।
 *  �٥�ȥ֥��å�����Ͽ����Ƥ���С��������Ͽ������롥�ޤ���������
 *  ���֤򹹿������Ԥ����������������������ͤ�E_OK�Ȥ��롥�Ԥ����塼
 *  ����κ���ϹԤ�ʤ����Ԥ���������������ؤΥǥ����ѥå���ɬ�פʾ�
 *  ��ˤ�true���֤���
 */
extern bool_t	wait_complete(TCB *p_tcb);

/*
 *  �����ॢ���Ȥ�ȼ���Ԥ����
 *
 *  p_tcb�ǻ��ꤵ��륿���������Ԥ����塼�ˤĤʤ���Ƥ�����Ԥ����塼
 *  �������������������֤򹹿����롥�ޤ����Ԥ���������������������
 *  �ͤ�wait_tmout�Ǥ�E_TMOUT��wait_tmout_ok�Ǥ�E_OK�Ȥ��롥�Ԥ����
 *  �����������ؤΥǥ����ѥå���ɬ�פʻ��ϡ�reqflg��true�ˤ��롥
 *
 *  wait_tmout_ok�ϡ�dly_tsk�ǻȤ�����Τ�Τǡ��Ԥ����塼����������
 *  ������Ԥ�ʤ���
 *
 *  ������δؿ��⡤�����।�٥�ȤΥ�����Хå��ؿ��Ȥ����Ѥ��뤿���
 *  ��Τǡ�����ߥϥ�ɥ餫��ƤӽФ���뤳�Ȥ����ꤷ�Ƥ��롥
 */
extern void	wait_tmout(TCB *p_tcb);
extern void	wait_tmout_ok(TCB *p_tcb);

/*
 *  �Ԥ����֤ζ������
 *
 *  p_tcb�ǻ��ꤵ��륿�������Ԥ����֤���Ū�˲�����롥����Ū�ˤϡ�
 *  ���������Ԥ����塼�ˤĤʤ���Ƥ�����Ԥ����塼���������������।
 *  �٥�ȥ֥��å�����Ͽ����Ƥ���Ф������Ͽ������롥�ޤ�����������
 *  ���֤򹹿������Ԥ����������������������ͤ�E_RLWAI�Ȥ��롥�ޤ���
 *  �Ԥ���������������ؤΥǥ����ѥå���ɬ�פʾ��ˤ�true���֤���
 */
extern bool_t	wait_release(TCB *p_tcb);

/*
 *  �Ԥ����塼����Ƭ�Υ�����ID
 *
 *  p_wait_queue�ǻ��ꤷ���Ԥ����塼����Ƭ�Υ�����ID���֤����Ԥ����塼
 *  �����ξ��ˤϡ�TSK_NONE���֤���
 */
Inline ID
wait_tskid(QUEUE *p_wait_queue)
{
	if (!queue_empty(p_wait_queue)) {
		return(TSKID(((TCB *)p_wait_queue->p_next)));
	}
	else {
		return(TSK_NONE);
	}
}

/*
 *  Ʊ�����̿����֥������Ȥ��Ф����Ԥ����֤ؤ�����
 *  
 *  �¹���Υ��������Ԥ����֤����ܤ�����Ʊ�����̿����֥������Ȥ��Ԥ����塼
 *  �ˤĤʤ����ޤ����Ԥ�����֥��å���WINFO�ˤ�p_wobjcb�����ꤹ�롥
 *  wobj_make_wait_tmout�ϡ������।�٥�ȥ֥��å�����Ͽ��Ԥ���
 */
extern void	wobj_make_wait(WOBJCB *p_wobjcb, TCB *p_runtsk);
extern void	wobj_make_wait_tmout(WOBJCB *p_wobjcb, TMO tmout, TCB *p_runtsk);

/*
 *  ������ͥ�����ѹ����ν���
 *
 *  Ʊ�����̿����֥������Ȥ��Ф����Ԥ����֤ˤ��륿������ͥ���٤��ѹ���
 *  �줿���ˡ��Ԥ����塼����ǤΥ������ΰ��֤������롥
 */
Inline void
wobj_change_priority(WOBJCB *p_wobjcb, TCB *p_tcb)
{
	if ((p_wobjcb->p_wobjinib->wobjatr & TA_TPRI) != 0U) {
		queue_delete(&(p_tcb->task_queue));
		queue_insert_tpri(&(p_wobjcb->wait_queue), p_tcb);
	}
}

/*
 *  �Ԥ����塼�ν����
 *
 *  �Ԥ����塼�ˤĤʤ���Ƥ��륿�����򤹤٤��Ԥ�������롥�Ԥ��������
 *  ��������������ͤϡ�E_DLT�Ȥ��롥�Ԥ���������������ؤΥǥ����ѥå�
 *  ��ɬ�פʾ���true�������Ǥʤ�����false���֤���
 */
extern bool_t	init_wait_queue(QUEUE *p_wait_queue);

#endif /* TOPPERS_WAIT_H */