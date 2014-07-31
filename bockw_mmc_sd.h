#ifndef __BOCKW_SDHC_H__
#define	__BOCKW_SDHC_H__

#define CTL_SD_CMD 0x00
#define CTL_ARG_REG 0x04
#define CTL_STOP_INTERNAL_ACTION 0x08
#define CTL_XFER_BLK_COUNT 0xa
#define CTL_RESPONSE 0x0c
#define CTL_STATUS 0x1c
#define CTL_STATUS2 0x1e
#define CTL_IRQ_MASK 0x20
#define CTL_SD_CARD_CLK_CTL 0x24
#define CTL_SD_XFER_LEN 0x26
#define CTL_SD_MEM_CARD_OPT 0x28
#define CTL_SD_ERROR_DETAIL_STATUS 0x2c
#define CTL_SD_DATA_PORT 0x30
#define CTL_TRANSACTION_CTL 0x34
#define CTL_SDIO_STATUS 0x36
#define CTL_SDIO_IRQ_MASK 0x38
#define CTL_DMA_ENABLE 0xd8
#define CTL_RESET_SD 0xe0
#define CTL_SDIO_REGS 0x100
#define CTL_CLK_AND_WAIT_CTL 0x138
#define CTL_RESET_SDIO 0x1e0

/* Definitions for values the CTRL_STATUS register can take. */
#define TMIO_STAT_CMDRESPEND    0x00000001
#define TMIO_STAT_DATAEND       0x00000004
#define TMIO_STAT_CARD_REMOVE   0x00000008
#define TMIO_STAT_CARD_INSERT   0x00000010
#define TMIO_STAT_SIGSTATE      0x00000020
#define TMIO_STAT_WRPROTECT     0x00000080
#define TMIO_STAT_CARD_REMOVE_A 0x00000100
#define TMIO_STAT_CARD_INSERT_A 0x00000200
#define TMIO_STAT_SIGSTATE_A    0x00000400
#define TMIO_STAT_CMD_IDX_ERR   0x00010000
#define TMIO_STAT_CRCFAIL       0x00020000
#define TMIO_STAT_STOPBIT_ERR   0x00040000
#define TMIO_STAT_DATATIMEOUT   0x00080000
#define TMIO_STAT_RXOVERFLOW    0x00100000
#define TMIO_STAT_TXUNDERRUN    0x00200000
#define TMIO_STAT_CMDTIMEOUT    0x00400000
#define TMIO_STAT_RXRDY         0x01000000
#define TMIO_STAT_TXRQ          0x02000000
#define TMIO_STAT_ILL_FUNC      0x20000000
#define TMIO_STAT_CMD_BUSY      0x40000000
#define TMIO_STAT_ILL_ACCESS    0x80000000

#define TMIO_BBS		512		/* Boot block size */

struct bockw_esdhc_cfg {
	u32	esdhc_base;
	u32	no_snoop;
	u32	clk_enable;
};

#define WAIT_RESPONSE_ERROR		0xFF
#define WAIT_RESPONSE_CMD		0x01
#define WAIT_RESPONSE_DATA_RX	0x02
#define WAIT_RESPONSE_DATA_TX	0x03
#define WAIT_RESPONSE_DATA_END	0x04

/* Define some IRQ masks */
/* This is the mask used at reset by the chip */
#define TMIO_MASK_ALL           0x837f031d
#define TMIO_MASK_READOP  (TMIO_STAT_RXRDY | TMIO_STAT_DATAEND)
#define TMIO_MASK_WRITEOP (TMIO_STAT_TXRQ | TMIO_STAT_DATAEND)
#define TMIO_MASK_CMD     (TMIO_STAT_CMDRESPEND | TMIO_STAT_CMDTIMEOUT | \
		TMIO_STAT_CARD_REMOVE | TMIO_STAT_CARD_INSERT)
#define TMIO_MASK_IRQ     (TMIO_MASK_READOP | TMIO_MASK_WRITEOP | TMIO_MASK_CMD)

int bockw_mmc_init(struct bockw_esdhc_cfg *cfg);

#endif	//__BOCKW_SDHC_H__
