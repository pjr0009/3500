/* This file is part of GDB.

   Copyright 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   --

   This file was generated by the program igen */

#ifndef ITABLE_H
#define ITABLE_H

typedef enum {
#line 88 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_RSVD_SPECIAL,
#line 406 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_ADD_SPECIAL,
#line 432 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_ADDI_NORMAL,
#line 467 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_ADDIU_NORMAL,
#line 494 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_ADDU_SPECIAL,
#line 519 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_AND_SPECIAL,
#line 537 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_ANDI_NORMAL,
#line 557 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BEQ_NORMAL,
#line 579 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BEQL_NORMAL,
#line 602 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BGEZ_REGIMM,
#line 624 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BGEZAL_REGIMM,
#line 649 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BGEZALL_REGIMM,
#line 677 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BGEZL_REGIMM,
#line 700 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BGTZ_NORMAL,
#line 722 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BGTZL_NORMAL,
#line 747 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BLEZ_NORMAL,
#line 771 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BLEZL_NORMAL,
#line 794 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BLTZ_REGIMM,
#line 816 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BLTZAL_REGIMM,
#line 843 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BLTZALL_REGIMM,
#line 869 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BLTZL_REGIMM,
#line 894 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BNE_NORMAL,
#line 916 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BNEL_NORMAL,
#line 939 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BREAK_SPECIAL,
#line 1275 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_DIV_SPECIAL,
#line 1314 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_DIVU_SPECIAL,
#line 1668 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_J_NORMAL,
#line 1688 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_JAL_NORMAL,
#line 1708 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_JALR_SPECIAL,
#line 1728 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_JR_SPECIAL,
#line 1855 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LB_NORMAL,
#line 1872 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LBU_NORMAL,
#line 1949 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LH_NORMAL,
#line 1966 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LHU_NORMAL,
#line 1983 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LL_NORMAL,
#line 2061 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LUI_NORMAL,
#line 2080 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LW_NORMAL,
#line 2097 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LWCz_NORMAL,
#line 2114 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LWL_NORMAL,
#line 2131 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LWR_NORMAL,
#line 2210 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MFHI_SPECIAL,
#line 2236 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MFLO_SPECIAL,
#line 2254 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MOVN_SPECIAL,
#line 2271 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MOVZ_SPECIAL,
#line 2328 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MTHI_SPECIAL,
#line 2347 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MTLO_SPECIAL,
#line 2400 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MULT_SPECIAL,
#line 2441 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MULTU_SPECIAL,
#line 2472 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_NOR_SPECIAL,
#line 2496 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_OR_SPECIAL,
#line 2521 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_ORI_NORMAL,
#line 2538 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_PREF_NORMAL,
#line 2650 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SB_NORMAL,
#line 2667 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SC_NORMAL,
#line 2806 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SH_NORMAL,
#line 2831 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SLLa_SPECIAL,
#line 2872 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SLLV_SPECIAL,
#line 2896 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SLT_SPECIAL,
#line 2920 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SLTI_NORMAL,
#line 2944 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SLTIU_NORMAL,
#line 2969 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SLTU_SPECIAL,
#line 2996 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SRA_SPECIAL,
#line 3025 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SRAV_SPECIAL,
#line 3053 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SRL_SPECIAL,
#line 3081 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SRLV_SPECIAL,
#line 3098 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SUB_SPECIAL,
#line 3132 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SUBU_SPECIAL,
#line 3149 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SW_NORMAL,
#line 3166 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SWCz_NORMAL,
#line 3183 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SWL_NORMAL,
#line 3200 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SWR_NORMAL,
#line 3217 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SYNC_SPECIAL,
#line 3234 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SYSCALL_SPECIAL,
#line 3251 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TEQ_SPECIAL,
#line 3267 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TEQI_REGIMM,
#line 3283 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TGE_SPECIAL,
#line 3299 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TGEI_REGIMM,
#line 3315 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TGEIU_REGIMM,
#line 3331 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TGEU_SPECIAL,
#line 3347 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TLT_SPECIAL,
#line 3363 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TLTI_REGIMM,
#line 3379 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TLTIU_REGIMM,
#line 3395 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TLTU_SPECIAL,
#line 3411 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TNE_SPECIAL,
#line 3427 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TNEI_REGIMM,
#line 3450 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_XOR_SPECIAL,
#line 3474 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_XORI_NORMAL,
#line 3695 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_ABS_fmt_COP1,
#line 3716 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_ADD_fmt_COP1,
#line 3793 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BC1b_COP1S,
#line 3830 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_C_cond_fmtb_COP1,
#line 3867 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_CEIL_W_COP1,
#line 3901 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_CFC1b_COP1,
#line 3948 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_CTC1b_COP1,
#line 3979 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_CVT_D_fmt_COP1,
#line 4035 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_CVT_S_fmt_COP1,
#line 4079 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_CVT_W_fmt_COP1,
#line 4101 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_DIV_fmt_COP1,
#line 4216 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_FLOOR_W_fmt_COP1,
#line 4246 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LDC1b_COP1,
#line 4291 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_LWC1_COP1,
#line 4352 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MFC1b_COP1,
#line 4368 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MOV_fmt_COP1,
#line 4390 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MOVtf_SPECIAL,
#line 4406 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MOVtf_fmt_COP1,
#line 4435 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MOVN_fmt_COP1,
#line 4458 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MOVZ_fmt_COP1,
#line 4504 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MTC1b_COP1,
#line 4519 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MUL_fmt_COP1,
#line 4539 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_NEG_fmt_COP1,
#line 4658 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_RECIP_fmt_COP1,
#line 4690 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_ROUND_W_fmt_COP1,
#line 4710 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_RSQRT_fmt_COP1,
#line 4734 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SDC1b_COP1,
#line 4780 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SQRT_fmt_COP1,
#line 4799 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SUB_fmt_COP1,
#line 4820 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SWC1_COP1,
#line 4864 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_SWXC1_COP1X,
#line 4922 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TRUNC_W_COP1,
#line 4949 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BC0F_COP0,
#line 4970 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BC0FL_COP0,
#line 4983 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BC0T_COP0,
#line 4995 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_BC0TL_COP0,
#line 5008 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_CACHE_NORMAL,
#line 5055 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_ERET_COP0,
#line 5080 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MFC0_COP0,
#line 5098 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_MTC0_COP0,
#line 5115 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_RFE_COP0,
#line 5130 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_COPz_NORMAL,
#line 5147 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TLBP_COP0,
#line 5160 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TLBR_COP0,
#line 5173 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TLBWI_COP0,
#line 5186 "/root/cs161/cs161-gdb-1.4/./gdb-6.0+cs161/sim/mips/mips.igen"
  itable_TLBWR_COP0,
  nr_itable_entries,
} itable_index;

typedef enum {
  itable_flag_32,
  itable_flag_f,
  nr_itable_flags,
} itable_flags;
extern const char *itable_flag_names[];

typedef enum {
  nr_itable_options,
} itable_options;
extern const char *itable_option_names[];

typedef enum {
  itable_processor_mdmx,
  itable_processor_mips16,
  itable_processor_mips32,
  itable_processor_mips3d,
  itable_processor_mips64,
  itable_processor_mipsI,
  itable_processor_mipsII,
  itable_processor_mipsIII,
  itable_processor_mipsIV,
  itable_processor_mipsV,
  itable_processor_r3900,
  itable_processor_sb1,
  itable_processor_vr4100,
  itable_processor_vr4120,
  itable_processor_vr5000,
  itable_processor_vr5400,
  itable_processor_vr5500,
  nr_itable_processors,
} itable_processors;
extern const char *itable_processor_names[];

typedef struct _itable_instruction_info {
  itable_index nr;
  char *format;
  char *form;
  char *flags;
  char flag[nr_itable_flags + 1];
  char *options;
  char option[nr_itable_options + 1];
  char *processors;
  char processor[nr_itable_processors + 1];
  char *name;
  char *file;
  int line_nr;
} itable_info;

extern itable_info itable[nr_itable_entries];

enum {
  sizeof_itable_form = 8,
  sizeof_itable_name = 12,
  sizeof_itable_file = 10,
};

#endif /* _ITABLE_H_*/
