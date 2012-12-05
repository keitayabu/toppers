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
 *  @(#) $Id: start.S,v 1.19 2007/01/05 02:02:38 honda Exp $
 */
                
/*
 *    �����ͥ��ѤΥ������ȥ��åץ⥸�塼��(ARMv4��)
 */
#define _MACRO_ONLY
#include <armv4.h>
#include <sys_defs.h>

#include <t_config.h>
 


        /*
         * Vector�ơ��֥�ȥ����ץơ��֥�
         * �������Ϲ��0x3c
         */
        .section .vector,"a"
        .code 32
        .align 0
        .global vector_table
#ifdef _MINDSTORMSNXT_
		.global _kernel_arm_vector_add
#endif  /* _MINDSTORMSNXT_ */
vector_table:
        ldr pc, reset_vector       /* �ꥻ�å�             */
        ldr pc, undef_vector       /* ̤���̿��           */
        ldr pc, swi_vector         /* ���եȥ����������   */
        ldr pc, prefech_vector     /* �ץ�ե��å����ܡ��� */
        ldr pc, data_abort_vector  /* �ǡ������ܡ���       */
        ldr pc, reserved_vector
#ifdef _MINDSTORMSNXT_
        ldr   pc,[pc,#-0xF20]	@ IRQ : read the AIC
        ldr   pc,[pc,#-0xF24]	@ FIQ : read the AIC
#else  /* _MINDSTORMSNXT_ */
        ldr pc, irq_vector         /* IRQ                  */
        ldr pc, fiq_vector         /* IRQ                  */
#endif  /* _MINDSTORMSNXT_ */

/*
 *  �٥������ơ��֥�
 */
_kernel_arm_vector_add:
reset_vector:
        .long   start
undef_vector:
        .long   undef_handler
swi_vector:
        .long   swi_handler
prefech_vector:
        .long   prefetch_abort_handler
data_abort_vector:
        .long   data_abort_handler
reserved_vector:
		.long   reserved_handler
#ifndef _MINDSTORMSNXT_
#ifdef VECTOR_IN_ROM
irq_vector:
        .long   IRQ_Handler
fiq_vector:
        .long   FIQ_Handler
#else /* VECTOR_IN_ROM */
irq_vector:
        .long   irq_exception
fiq_vector:
        .long   fiq_exception
#endif /* VECTOR_IN_ROM */
#endif /* _MINDSTORMSNXT_ */


        .text
        .code 32
        .align     0
        .global    start
start:
        mov  r1,  #(CPSR_SVC|CPSR_FIQ_BIT|CPSR_IRQ_BIT) /* To System mode */
		msr  cpsr, r1

#ifdef _MINDSTORMSNXT_

@
@ Do the remapping, if required, so that RAM is at address 0.
@
@  We read what is at address 0 and 2MB
@ We then invert what is at 2MB and read at 0 again
@ If address 0 has changed, then RAM is already at 0, so there is
@ no need to remap

        ldr  r0,=0x000000
        ldr  r2,=0x200000
        ldr  r3,[r0]
        ldr  r4,[r2]
        ldr  r5,=0xFFFFFFFF
        eor  r5,r4,r5
        str  r5,[r2]
        ldr  r5,[r0]
        str  r4,[r2]

        cmp  r3,r5
        bne  skip_remap_toggle

        ldr  r0,=(TADR_MC_BASE+TOFF_MC_RCR)
        ldr  r1,=1
        str  r1,[r0]

skip_remap_toggle:
        b    continue_boot

continue_boot:

@   Set up stacks etc.
@   We set up the irq and system stacks
@   We switch to system mode for further execution
@   NB Stacks should be 8-byte aligned for APCS
@   They should already be aligned, but we mask the values to make sure.
@
@ Set up Interrupt stack
        msr  CPSR_c,#0xD2 @ IRQ mode, IRQ, FIQ off
        ldr  r0, =__irq_stack__
        mov  sp,r0
        bic  sp,sp,#7    @ make sure it is 8-byte aligned

        msr  CPSR_c,#(CPSR_SVC|CPSR_FIQ_BIT|CPSR_IRQ_BIT) /* To System mode */

#endif	/* _MINDSTORMSNXT_ */

        /*
         * �����å��ݥ��󥿤ȡ��ե졼��ݥ��󥿤ν����
         * SL(�����å���¥쥸����r10)�����ꤹ��ɬ�פ����뤫?
         * gcc�ϥǥ��ե���ȤǤ�-mapcs�ʤΤ�ɬ�פʤ�
         */
        ldr  r3, =STACKTOP
        mov  sp, r3
        mov  r11, #0        /* Arm�⡼���ѥե졼��ݥ���   */         
        mov  r7, #0         /* Thubm�⡼���ѥե졼��ݥ��� */

        /*
         * hardware_init_hook�θƤӽФ� ��0�Ǥʤ�����
         *
         * �������åȥϡ��ɥ������˰�¸����ɬ�פʽ����������������
         * �ϡ�hardware_init_hook �Ȥ����ؿ����Ѱդ���
         */
        ldr  r0, =hardware_init_hook
        cmp  r0, #0x00
        blne hardware_init_hook

        /*
         *  bss���������Υ��ꥢ
         */
start_1:
        ldr  r1, =__bss_start
        ldr  r2, =__bss_end
        cmp  r1,r2
        bhs  start_3
        mov  r0,#0
start_2:
        str  r0,[r1],#4
        cmp  r1, r2
        blo  start_2

start_3:
#if defined(NXTBIOS)
        /*
         *  vector���������ν����(NXTBIOS��)
         *  __vectors_load_start__ ���� __vectors_load_end__ �ޤǤ�__vectors_ram_start__ �ʹߤ�
         *  ���ԡ�����
         */
        ldr  r1, =__vectors_load_start__
        ldr  r3, =__vectors_load_end__
        cmp  r1, r3
        bhs  start_32
        ldr  r2, =__vectors_ram_start__
start_31:
        ldr  r0, [r1],#4
        str  r0, [r2],#4
        cmp  r1, r3
        blo  start_31
start_32:
#endif /* NXTBIOS */
#if defined(VECTOR_IN_ROM) || defined(NXTBIOS)
        /*
         *  data���������ν����(ROM���б�)
         *  __idata_start ���� __idata_end �ޤǤ�__data_start �ʹߤ�
         *  ���ԡ�����
         */
        ldr  r1, =__idata_start
        ldr  r3, =__idata_end
        cmp  r1, r3
        bhs  start_5
        ldr  r2, =__data_start
start_4:        
        ldr  r0, [r1],#4
        str  r0, [r2],#4
        cmp  r1, r3
        blo  start_4
#endif /* VECTOR_IN_ROM || NXTBIOS */
        /*
         *  software_init_hook ��ƽФ���0 �Ǥʤ�����
         *
         *  ���եȥ������Ķ����ä˥饤�֥��ˤ˰�¸����ɬ�פʽ������
         *  ����������ϡ�software_init_hook �Ȥ����ؿ����Ѱդ����
         *  �褤��
         */
start_5:
        ldr   r0, =software_init_hook
        cmp   r0, #0x00
        blne  software_init_hook

start_6:
        ldr r0, =kernel_start
        mov lr, pc
        bx  r0


        /*
         *  �ǥե���ȥ������ץ����ؿ���thumb�б��ϥ�ɥ�
         */
        .global undef_handler
        .global swi_handler
        .global prefetch_abort_handler
        .global data_abort_handler
        .global reserved_handler

        .text
        .code 32
        .align 	0

undef_handler:
        msr CPSR_c,#0xDF		@ System mode , I and F bits set (interrupts disabled)
        ldr r0,=undef_exception
        mov lr,pc
        bx  r0
undef_exception_returned:
        b   undef_exception_returned

swi_handler:
        msr CPSR_c,#0xDF		@ System mode , I and F bits set (interrupts disabled)
        ldr r0,=swi_exception
        mov lr,pc
        bx  r0
swi_exception_returned:
        b   swi_exception_returned

prefetch_abort_handler:
        msr CPSR_c,#0xDF		@ System mode , I and F bits set (interrupts disabled)
        ldr r0,=prefetch_exception
        mov lr,pc
        bx  r0
prefetch_exception_returned:
        b   prefetch_exception_returned

data_abort_handler:
        msr CPSR_c,#0xDF		@ System mode , I and F bits set (interrupts disabled)
        ldr r0,=data_abort_exception
        mov lr,pc
        bx  r0
data_abort_exception_returned:
        b   data_abort_exception_returned

reserved_handler:
        b   reserved_handler

