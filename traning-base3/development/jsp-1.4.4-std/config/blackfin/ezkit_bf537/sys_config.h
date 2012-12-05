/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  TOPPERS/JSP for Blackfin
 *
 *  Copyright (C) 2004,2006,2006 by Takemasa Nakamura
 *  Copyright (C) 2004 by Ujinosuke
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


#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_


/*
 *  �����ͥ����������̾�Υ�͡���
 */
#include <sys_rename.h>

#include <chip_config.h>

/*
 *	�������åȥ����ƥ��¸�⥸�塼���EZKIT-BF537�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�t_config.h �Τߤ��饤�󥯥롼�ɤ���롥
 *  ¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
*/

/*
 * ADSP-BF537�˰�¸�������ܡ��ɤؤμ����ˤ�äƷ�ޤ�ѥ�᡼����
 * ������������롣
 */


/*
 * �ɤΤ褦�ʥ����å����Ϥˤ��б��Ǥ���褦���ʲ���CSEL, SSEL, MSEL����
 * �ȥ����å����ϼ��ȿ�(Hz)����ꤹ�롣PLL�Υץ�������sys_config.c��
 * sys_initialize()�ؿ��ǹԤ��롣
 *
 * CSELVAL��1,2,4,8���椫�����֡�CLKIN��ñ�̤�Hz
 */

#define CSELVAL 1
#define SSELVAL 5
#define MSELVAL 24
#define CLKIN 25000000



/*
 * �ϡ��ɥ����������顼�����ߤε���
 * QUICK_HW_ERROR��define����ȡ��ϡ��ɥ����������顼�����٥��
 * ��¨�¤˼�������롣define���ʤ����ˤϡ��������Ԥ����֤�
 * �ϡ��ɥ����������顼�������ߤ�ȯ��������硢���γ����ߤޤ�
 * �Ԥ�����뤳�Ȥˤʤ롣
 *
 */
//#define QUICK_HW_ERROR


/*
 * �¹Ի�������ؿ��λ���
 *
 * �ޥ��� USE_RUNTIME_INIT ���������ȡ�start.asm�Τʤ��� _mi_initialize
 * ��ƤӽФ������δؿ��ϥΡ��֡��ȥ⡼�ɤǵ�ư����Ȥ��ˤΤ�ɬ�פˤʤ�Τ�
 * �̾�� USE_RUNTIME_INIT��Ȥ�ɬ�פϤʤ���
 * �ܺ٤�ADI��EE239�˾ܤ�����http://tinyurl.com/2hpbk (tinyURL)
 *
*/
//#define USE_RUNTIME_INIT

/*
 * �����ͥ�����������ߤ����
 *
 * �ޥ���UNMANAGED_INT�ϥ����ͥ�����������ߤ�������롣����
 * �ޥ�����16�ӥåȤΥӥåȥޥåפˤʤäƤ��ꡢ�ʲ��ˤ���ѥ�����
 * �Τ����ҤȤĤ�Ȥ����ʤ����ɤΤ褦�ʥѥ����������Ǥ�NMI�ϴ�����
 * ����ߤȤ��ư����롣
 * UNMANAGED_INT��������ʤ���硢NMI����������������ߤȤ��ư����롣
 *
*/
//#define UNMANAGED_INT 0x0020			// IVHW�������ͥ������.
//#define UNMANAGED_INT 0x0060			// IVTMR��IVHW�������ͥ������.
//#define UNMANAGED_INT 0x00E0			// IVG7, IVTMR��IVHW�������ͥ������.
//#define UNMANAGED_INT 0x01E0			// IVG8 ... IVG7, IVTMR��IVHW�������ͥ������.
//#define UNMANAGED_INT 0x03E0			// IVG9 ... IVG7, IVTMR��IVHW�������ͥ������.
//#define UNMANAGED_INT 0x07E0			// IVG10 ... IVG7, IVTMR��IVHW�������ͥ������.
//#define UNMANAGED_INT 0x0FE0			// IVG11 ... IVG7, IVTMR��IVHW�������ͥ������.
//#define UNMANAGED_INT 0x1FE0			// IVG12 ... IVG7, IVTMR��IVHW�������ͥ������.
//#define UNMANAGED_INT 0x3FE0			// IVG13 ... IVG7, IVTMR��IVHW�������ͥ������.

/*
 * C++��Ϣ�񸻤��Ѱդ���
 *
 * �ޥ���INIT_C_PLUS_PLUS���������ȡ�C++�����ѤΥơ��֥��
 * ����������ɤ�¹Ԥ��롣�ޤ���C++�����ѤΥơ��֥���������
 *
*/
//#define INIT_C_PLUS_PLUS

/*
 *  ��ư��å������Υ������åȥ����ƥ�̾
 */
#define	TARGET_NAME	"EZ-KIT Lite BF537"


/*
 *  ���ꥢ��ݡ��ȿ������
 *  TNUM_SIOP_XXX�ϡ�UART�μ��̤��Ȥ�������롣
 *  TNUM_SIOP_UART��BF537��¢UART�Τ�����PDIC�����Ѥ����Ρ�
 *  BF537��UART��դ��Ĥ�äƤ���Τǡ�2,1��0��������롣
 *  TNUM_PORT�ϡ�TNUM_SIOP_XXX�Τ�����GDIC�����Ѥ����Τ����¡�
 *  uart.c�ǻȤ���
 */
#define TNUM_PORT	1		/* GDIC�����ݡ��Ȥ��륷�ꥢ��ݡ��Ȥο� */
#define TNUM_SIOP_UART	1	/* PIDC�����ݡ��Ȥ��륷�ꥢ��ݡ��Ȥο� */

/*
 *  ���ꥢ��ݡ����ֹ�˴ؤ������
 *  ���������������ꥢ��ݡ��Ȥ�Ȥ�ʤ�����̵�뤷�Ƥ�����
 */
#define	LOGTASK_PORTID	1	/* �����ƥ�������Ѥ��륷�ꥢ��ݡ����ֹ� */

/*  UART0�Υܡ��졼�ȡ� */
#define UART0_BAUD_RATE 57600		/* 57600 bps*/
#define UART1_BAUD_RATE 57600		/* 57600 bps*/

/*
 * PLL�ν�����ζ���
 * PLL�ϡ�PLL_CTL�쥸�������ǥե�����ͤǡ����ġ�SDRAM����ȥ����餬
 * �ǥ������֥�ΤȤ��˸¤�������Ԥ��褦�ˤʤäƤ��롣����ϡ��֡���
 * ���������ʤɤν�������եȤ�SDRAM�����������Ȥ��ˤ�����ݸ�뤿��
 * �Ǥ��롣������VisualDSP++�ΥǥХå���SDRAM��ʬ�ǽ�������뤿�ᡢ
 * ���ε�ǽ�Ȥ��ޤ��ޤ�礤���Ĥ��ʤ���礬���롣
 * ����˴ؤ�餺��˽�������������ˤ� FORCE_PLL_INITIALIZE �ޥ�����
 * ������롣
 */
// #deinfe FORCE_PLL_INITIALIZE

#endif /* _SYS_CONFIG_H_ */