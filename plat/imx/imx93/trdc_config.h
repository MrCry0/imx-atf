/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <trdc.h>

#define SP(X)           ((X) << 12)
#define SU(X)           ((X) << 8)
#define NP(X)           ((X) << 4)
#define NU(X)           ((X) << 0)

#define RWX             7
#define RW              6
#define RX              5
#define R               4
#define X               1

/* GLBAC7 is used for TRDC only, any setting to GLBAC7 will be ignored */

/* aonmix */
struct trdc_glbac_config trdc_a_mbc_glbac[] = {
	/* MBC0 */
	{ 0, 0, SP(RW)  | SU(RW)   | NP(RW)  | NU(RW) },

	/* MBC1 */
	{ 1, 0, SP(RW)  | SU(RW)   | NP(RW)  | NU(RW) },
	{ 1, 1, SP(RW)  | SU(R)    | NP(RW)  | NU(R)  },
	{ 1, 2, SP(RWX) | SU(RWX)  | NP(RWX) | NU(RWX)  },
};

struct trdc_mbc_config trdc_a_mbc[] = {
	{ 0, 0, 0, MBC_BLK_ALL, 0, true }, /* MBC0 AIPS1 for S401 DID0 */
	{ 0, 0, 1, MBC_BLK_ALL, 0, true }, /* MBC0 Sentinel_SOC_In for S401 DID0 */
	{ 0, 0, 2, MBC_BLK_ALL, 0, true }, /* MBC0 GPIO1 for S401 DID0 */
	{ 1, 0, 0, MBC_BLK_ALL, 0, true }, /* MBC1 CM33 code TCM for S401 DID0 */
	{ 1, 0, 1, MBC_BLK_ALL, 0, true }, /* MBC1 CM33 system TCM for S401 DID0 */

	{ 0, 1, 0, MBC_BLK_ALL, 0, true }, /* MBC0 AIPS1 for MTR DID1 */
	{ 0, 1, 1, MBC_BLK_ALL, 0, true }, /* MBC0 Sentinel_SOC_In for MTR DID1 */

	{ 0, 2, 0, MBC_BLK_ALL, 0, true }, /* MBC0 AIPS1 for M33 DID2 */
	{ 0, 2, 1, MBC_BLK_ALL, 0, true }, /* MBC0 Sentinel_SOC_In for M33 DID2 */
	{ 0, 2, 2, MBC_BLK_ALL, 0, true }, /* MBC0 GPIO1 for M33 DID2 */
	{ 1, 2, 0, MBC_BLK_ALL, 2, true  }, /* MBC1 CM33 code TCM for M33 DID2 */
	{ 1, 2, 1, MBC_BLK_ALL, 2, true  }, /* MBC1 CM33 system TCM for M33 DID2 */

	{ 0, 3, 0, MBC_BLK_ALL, 0, false }, /* MBC0 AIPS1 for A55 DID3 */
	{ 0, 3, 1, MBC_BLK_ALL, 0, false }, /* MBC0 Sentinel_SOC_In for A55 DID3 */
	{ 0, 3, 2, MBC_BLK_ALL, 0, false }, /* MBC0 GPIO1 for A55 DID3 */
	{ 1, 3, 0, MBC_BLK_ALL, 1, false }, /* MBC1 CM33 code TCM for A55 DID3 */
	{ 1, 3, 1, MBC_BLK_ALL, 1, false }, /* MBC1 CM33 system TCM for A55 DID3 */
	{ 1, 10, 1, MBC_BLK_ALL, 2, false }, /* MBC1 CM33 system TCM for SoC masters DID10 */

	{ 0, 7, 0, MBC_BLK_ALL, 0, false }, /* MBC0 AIPS1 for eDMA DID7 */
};

struct trdc_glbac_config trdc_a_mrc_glbac[] = {
	{ 0, 0, SP(RWX) | SU(RWX) | NP(RWX) | NU(RWX) },
	{ 0, 1, SP(R)   | SU(0)   | NP(R)   | NU(0)   },
};

struct trdc_mrc_config trdc_a_mrc[] = {
	{ 0, 2, 0, 0x00000000, 0x00040000, 0, true }, /* MRC0 M33 ROM for M33 DID2 */
	{ 0, 3, 0, 0x00100000, 0x00040000, 1, true }, /* MRC0 M33 ROM for A55 DID3 */
};

/* wakeupmix */
struct trdc_glbac_config trdc_w_mbc_glbac[] = {
	/* MBC0 */
	{ 0, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },

	/* MBC1 */
	{ 1, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },
};

struct trdc_mbc_config trdc_w_mbc[] = {
	{ 0, 1, 0, MBC_BLK_ALL, 0, true }, /* MBC0 AIPS2 for MTR DID1 */
	{ 1, 1, 0, MBC_BLK_ALL, 0, true }, /* MBC1 AIPS3 for MTR DID1 */

	{ 0, 2, 0, MBC_BLK_ALL, 0, true }, /* MBC0 AIPS2 for M33 DID2 */
	{ 0, 2, 1, MBC_BLK_ALL, 0, true }, /* MBC0 GPIO2_In for M33 DID2 */
	{ 0, 2, 2, MBC_BLK_ALL, 0, true }, /* MBC0 GPIO3 for M33 DID2 */
	{ 0, 2, 3, MBC_BLK_ALL, 0, true }, /* MBC0 DAP  for M33 DID2 */
	{ 1, 2, 0, MBC_BLK_ALL, 0, true }, /* MBC1 AIPS3 for M33 DID2 */
	{ 1, 2, 1, MBC_BLK_ALL, 0, true }, /* MBC1 AHB_ISPAP for M33 DID2 */
	{ 1, 2, 2, MBC_BLK_ALL, 0, true },  /* MBC1 NIC_MAIN_GPV for M33 DID2 */
	{ 1, 2, 3, MBC_BLK_ALL, 0, true }, /* MBC1 GPIO4 for M33 DID2 */

	{ 0, 3, 0, MBC_BLK_ALL, 0, false }, /* MBC0 AIPS2 for A55 DID3 */
	{ 0, 3, 1, MBC_BLK_ALL, 0, false }, /* MBC0 GPIO2_In for A55 DID3 */
	{ 0, 3, 2, MBC_BLK_ALL, 0, false }, /* MBC0 GPIO3 for A55 DID3 */
	{ 0, 3, 3, MBC_BLK_ALL, 0, false }, /* MBC0 DAP  for A55 DID3 */
	{ 1, 3, 0, MBC_BLK_ALL, 0, false }, /* MBC1 AIPS3 for A55 DID3 */
	{ 1, 3, 1, MBC_BLK_ALL, 0, false }, /* MBC1 AHB_ISPAP for A55 DID3 */
	{ 1, 3, 2, MBC_BLK_ALL, 0, true },  /* MBC1 NIC_MAIN_GPV for A55 DID3 */
	{ 1, 3, 3, MBC_BLK_ALL, 0, false }, /* MBC1 GPIO4 for A55 DID3 */

	{ 0, 7, 0, MBC_BLK_ALL, 0, false }, /* MBC0 AIPS2 for eDMA DID7 */
	{ 1, 7, 0, MBC_BLK_ALL, 0, false }, /* MBC1 AIPS3 for eDMA DID7  */
};

struct trdc_glbac_config trdc_w_mrc_glbac[] = {
	/* MRC0 */
	{ 0, 0, SP(RX)  | SU(RX)   | NP(RX)   | NU(RX)    },

	/* MRC1 */
	{ 1, 0, SP(RWX) | SU(RWX)  | NP(RWX)  | NU(RWX)   },
};

struct trdc_mrc_config trdc_w_mrc[] = {
	{ 0, 3, 0, 0x00000000, 0x00040000, 0, false }, /* MRC0 A55 ROM for A55 DID3 */

	{ 1, 2, 0, 0x28000000, 0x08000000, 0, true  }, /* MRC1 FLEXSPI1 for M33 DID2 */
	{ 1, 3, 0, 0x28000000, 0x08000000, 0, false }, /* MRC1 FLEXSPI1 for A55 DID3 */
};

/* nicmix */
struct trdc_glbac_config trdc_n_mbc_glbac[] = {
	/* MBC0 */
	{ 0, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },

	/* MBC1 */
	{ 1, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },

	/* MBC2 */
	{ 2, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },
	{ 2, 1, SP(R) | SU(R) | NP(R) | NU(R) },

	/* MBC3 */
	{ 3, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },
	{ 3, 1, SP(RWX) | SU(RWX) | NP(RWX) | NU(RWX) },
};

struct trdc_mbc_config trdc_n_mbc[] = {
	{ 0, 0, 0, MBC_BLK_ALL, 0, true }, /* MBC0 DDRCFG for S401 DID0 */
	{ 0, 0, 1, MBC_BLK_ALL, 0, true }, /* MBC0 AIPS4 for  S401 DID0 */
	{ 0, 0, 2, MBC_BLK_ALL, 0, true }, /* MBC0 MEDIAMIX for  S401 DID0 */
	{ 0, 0, 3, MBC_BLK_ALL, 0, true }, /* MBC0 HSIOMIX for  S401 DID0 */
	{ 1, 0, 0, MBC_BLK_ALL, 0, true }, /* MBC1 MTR_DCA, TCU, TROUT for  S401 DID0 */
	{ 1, 0, 1, MBC_BLK_ALL, 0, true }, /* MBC1 MTR_DCA, TCU, TROUT for  S401 DID0 */
	{ 1, 0, 2, MBC_BLK_ALL, 0, true }, /* MBC1 MLMIX for  S401 DID0 */
	{ 1, 0, 3, MBC_BLK_ALL, 0, true }, /* MBC1 MLMIX for  S401 DID0 */
	{ 2, 0, 0, MBC_BLK_ALL, 0, true }, /* MBC2 GIC for  S401 DID0 */
	{ 2, 0, 1, MBC_BLK_ALL, 0, true }, /* MBC2 GIC for  S401 DID0 */
	{ 3, 0, 0, MBC_BLK_ALL, 0, true }, /* MBC3 OCRAM for  S401 DID0 */
	{ 3, 0, 1, MBC_BLK_ALL, 0, true }, /* MBC3 OCRAM for  S401 DID0 */

	{ 0, 1, 0, MBC_BLK_ALL, 0, true }, /* MBC0 DDRCFG for MTR DID1 */
	{ 0, 1, 1, MBC_BLK_ALL, 0, true }, /* MBC0 AIPS4 for  MTR DID1 */
	{ 0, 1, 2, MBC_BLK_ALL, 0, true }, /* MBC0 MEDIAMIX for MTR DID1 */
	{ 0, 1, 3, MBC_BLK_ALL, 0, true }, /* MBC0 HSIOMIX for  MTR DID1 */
	{ 1, 1, 0, MBC_BLK_ALL, 0, true }, /* MBC1 MTR_DCA, TCU, TROUT for  MTR DID1 */
	{ 1, 1, 1, MBC_BLK_ALL, 0, true }, /* MBC1 MTR_DCA, TCU, TROUT for  MTR DID1 */
	{ 1, 1, 2, MBC_BLK_ALL, 0, true }, /* MBC1 MLMIX for  MTR DID1 */
	{ 1, 1, 3, MBC_BLK_ALL, 0, true }, /* MBC1 MLMIX for  MTR DID1 */

	{ 0, 2, 0, MBC_BLK_ALL, 0, true }, /* MBC0 DDRCFG for M33 DID2 */
	{ 0, 2, 1, MBC_BLK_ALL, 0, true }, /* MBC0 AIPS4 for M33 DID2 */
	{ 0, 2, 2, MBC_BLK_ALL, 0, true }, /* MBC0 MEDIAMIX for M33 DID2 */
	{ 0, 2, 3, MBC_BLK_ALL, 0, true }, /* MBC0 HSIOMIX for M33 DID2 */
	{ 1, 2, 0, MBC_BLK_ALL, 0, true }, /* MBC1 MTR_DCA, TCU, TROUT for M33 DID2 */
	{ 1, 2, 1, MBC_BLK_ALL, 0, true }, /* MBC1 MTR_DCA, TCU, TROUT for M33 DID2 */
	{ 1, 2, 2, MBC_BLK_ALL, 0, true }, /* MBC1 MLMIX for M33 DID2 */
	{ 1, 2, 3, MBC_BLK_ALL, 0, true }, /* MBC1 MLMIX for M33 DID2 */
	{ 2, 2, 0, MBC_BLK_ALL, 1, true }, /* MBC2 GIC for M33 DID2 */
	{ 2, 2, 1, MBC_BLK_ALL, 1, true }, /* MBC2 GIC for M33 DID2 */
	{ 3, 2, 0, MBC_BLK_ALL, 0, true  }, /* MBC3 OCRAM for M33 DID2 */
	{ 3, 2, 1, MBC_BLK_ALL, 0, true  }, /* MBC3 OCRAM for M33 DID2 */

	{ 0, 3, 0, MBC_BLK_ALL, 0, false }, /* MBC0 DDRCFG for A55 DID3 */
	{ 0, 3, 1, MBC_BLK_ALL, 0, false }, /* MBC0 AIPS4 for A55 DID3 */
	{ 0, 3, 2, MBC_BLK_ALL, 0, false }, /* MBC0 MEDIAMIX for A55 DID3 */
	{ 0, 3, 3, MBC_BLK_ALL, 0, false }, /* MBC0 HSIOMIX for A55 DID3 */
	{ 1, 3, 0, MBC_BLK_ALL, 0, false }, /* MBC1 MTR_DCA, TCU, TROUT for A55 DID3 */
	{ 1, 3, 1, MBC_BLK_ALL, 0, false }, /* MBC1 MTR_DCA, TCU, TROUT for A55 DID3 */
	{ 1, 3, 2, MBC_BLK_ALL, 0, false }, /* MBC1 MLMIX for A55 DID3 */
	{ 1, 3, 3, MBC_BLK_ALL, 0, false }, /* MBC1 MLMIX for A55 DID3 */
	{ 2, 3, 0, MBC_BLK_ALL, 0, false }, /* MBC2 GIC for A55 DID3 */
	{ 2, 3, 1, MBC_BLK_ALL, 0, false }, /* MBC2 GIC for A55 DID3 */
	{ 3, 3, 0, MBC_BLK_ALL, 1, true  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 1, MBC_BLK_ALL, 1, true  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 0, 0, 0, false  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 0, 1, 0, false  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 0, 2, 0, false  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 0, 3, 0, false  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 0, 4, 0, false  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 0, 5, 0, false  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 1, 0, 0, false  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 1, 1, 0, false  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 1, 2, 0, false  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 1, 3, 0, false  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 1, 4, 0, false  }, /* MBC3 OCRAM for A55 DID3 */
	{ 3, 3, 1, 5, 0, false  }, /* MBC3 OCRAM for A55 DID3 */

	{ 0, 7, 1, MBC_BLK_ALL, 0, false }, /* MBC0 AIPS4 for eDMA DID7 */
	{ 0, 7, 2, MBC_BLK_ALL, 0, false }, /* MBC0 MEDIAMIX for eDMA DID7 */
	{ 0, 7, 3, MBC_BLK_ALL, 0, false }, /* MBC0 HSIOMIX for eDMA DID7 */

	{ 3, 10, 0, MBC_BLK_ALL, 0, false }, /* MBC3 OCRAM for DID10 */
	{ 3, 10, 1, MBC_BLK_ALL, 0, false }, /* MBC3 OCRAM for DID10 */
};

struct trdc_glbac_config trdc_n_mrc_glbac[] = {
	{ 0, 0, SP(RW)  | SU(RW)  | NP(RW)  | NU(RW)  },
	{ 0, 1, SP(RWX) | SU(RWX) | NP(RWX) | NU(RWX) },
};

struct trdc_mrc_config trdc_n_mrc[] = {
	{ 0, 0, 0, 0x80000000, 0x80000000, 0, false }, /* MRC0 DRAM for S400 DID0 */
	{ 0, 1, 0, 0x80000000, 0x80000000, 0, false }, /* MRC0 DRAM for MTR DID1 */
	{ 0, 2, 0, 0x80000000, 0x80000000, 0, true }, /* MRC0 DRAM for M33 DID2 */
	{ 0, 3, 0, 0x80000000, 0x80000000, 1, false }, /* MRC0 DRAM for A55 DID3 */
	{ 0, 5, 0, 0x80000000, 0x80000000, 0, false }, /* MRC0 DRAM for USDHC1 DID5 */
	{ 0, 6, 0, 0x80000000, 0x80000000, 0, false }, /* MRC0 DRAM for USDHC2 DID6 */
	{ 0, 7, 0, 0x80000000, 0x80000000, 0, false }, /* MRC0 DRAM for eDMA DID7 */
	{ 0, 8, 0, 0x80000000, 0x80000000, 1, false }, /* MRC0 DRAM for Coresight, Testport DID8 */
	{ 0, 9, 0, 0x80000000, 0x80000000, 1, false }, /* MRC0 DRAM for DAP DID9 */
	{ 0, 10, 0, 0x80000000, 0x80000000, 0, false }, /* MRC0 DRAM for SoC masters DID10 */
	{ 0, 11, 0, 0x80000000, 0x80000000, 0, false }, /* MRC0 DRAM for USB DID11 */
};
