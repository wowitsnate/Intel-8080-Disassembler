#pragma once


#ifndef OPCODE_MAP_H
#define OPCODE_MAP_H

#include <unordered_map>

#include "Opcode.h"

std::unordered_map<uint8_t, opcode_base*> opcode_map = {
	//NOP's
	{0x0, new op_NOP()},
	{0x8, new op_NOP()},
	{0x10, new op_NOP()},
	{0x18, new op_NOP()},
	{0x20, new op_NOP()},
	{0x28, new op_NOP()},
	{0x30, new op_NOP()},
	{0x38, new op_NOP()},

	//LXI's
	{0x1, new op_LXI("B")},
	{0x11, new op_LXI("D")},
	{0x21, new op_LXI("H")},
	{0x31, new op_LXI("SP")},

	//MOV's
	//MOV B, X
	{0x40, new op_MOV("B", "B")},
	{0x41, new op_MOV("B", "C")},
	{0x42, new op_MOV("B", "D")},
	{0x43, new op_MOV("B", "E")},
	{0x44, new op_MOV("B", "H")},
	{0x45, new op_MOV("B", "L")},
	{0x46, new op_MOV("B", "M")},
	{0x47, new op_MOV("B", "A")},
	//MOV C, X
	{0x48, new op_MOV("C", "B")},
	{0x49, new op_MOV("C", "C")},
	{0x4A, new op_MOV("C", "D")},
	{0x4B, new op_MOV("C", "E")},
	{0x4C, new op_MOV("C", "H")},
	{0x4D, new op_MOV("C", "L")},
	{0x4E, new op_MOV("C", "M")},
	{0x4F, new op_MOV("C", "A")},
	//MOV D, X
	{0x50, new op_MOV("D", "B")},
	{0x51, new op_MOV("D", "C")},
	{0x52, new op_MOV("D", "D")},
	{0x53, new op_MOV("D", "E")},
	{0x54, new op_MOV("D", "H")},
	{0x55, new op_MOV("D", "L")},
	{0x56, new op_MOV("D", "M")},
	{0x57, new op_MOV("D", "A")},
	//MOV E, X
	{0x58, new op_MOV("E", "B")},
	{0x59, new op_MOV("E", "C")},
	{0x5A, new op_MOV("E", "D")},
	{0x5B, new op_MOV("E", "E")},
	{0x5C, new op_MOV("E", "H")},
	{0x5D, new op_MOV("E", "L")},
	{0x5E, new op_MOV("E", "M")},
	{0x5F, new op_MOV("E", "A")},
	//MOV H, X
	{0x60, new op_MOV("H", "B")},
	{0x61, new op_MOV("H", "C")},
	{0x62, new op_MOV("H", "D")},
	{0x63, new op_MOV("H", "E")},
	{0x64, new op_MOV("H", "H")},
	{0x65, new op_MOV("H", "L")},
	{0x66, new op_MOV("H", "M")},
	{0x67, new op_MOV("H", "A")},
	//MOV L, X
	{0x68, new op_MOV("L", "B")},
	{0x69, new op_MOV("L", "C")},
	{0x6A, new op_MOV("L", "D")},
	{0x6B, new op_MOV("L", "E")},
	{0x6C, new op_MOV("L", "H")},
	{0x6D, new op_MOV("L", "L")},
	{0x6E, new op_MOV("L", "M")},
	{0x6F, new op_MOV("L", "A")},
	//MOV M, X
	{0x70, new op_MOV("M", "B")},
	{0x71, new op_MOV("M", "C")},
	{0x72, new op_MOV("M", "D")},
	{0x73, new op_MOV("M", "E")},
	{0x74, new op_MOV("M", "H")},
	{0x75, new op_MOV("M", "L")},
	//NO 0x76
	{0x77, new op_MOV("M", "A")},
	//MOV A, X
	{0x78, new op_MOV("A", "B")},
	{0x79, new op_MOV("A", "C")},
	{0x7A, new op_MOV("A", "D")},
	{0x7B, new op_MOV("A", "E")},
	{0x7C, new op_MOV("A", "H")},
	{0x7D, new op_MOV("A", "L")},
	{0x7E, new op_MOV("A", "M")},
	{0x7F, new op_MOV("A", "A")},

	//STAX
	{0x2, new op_STAX("B")},
	{0x12, new op_STAX("D")},

	//SHLD
	{0x22, new op_SHLD()},

	//STA
	{0x32, new op_STA()},

		//INX
	{ 0x3, new op_INX("B") },
	{ 0x13, new op_INX("D") },
	{ 0x23, new op_INX("H") },
	{ 0x33, new op_INX("SP") },

		//INR
	{ 0x4, new op_INR("B") },
	{ 0x14, new op_INR("D") },
	{ 0x24, new op_INR("H") },
	{ 0x34, new op_INR("M") },

	{ 0xC, new op_INR("C") },
	{ 0x1C, new op_INR("E") },
	{ 0x2C, new op_INR("L") },
	{ 0x3C, new op_INR("A") },

		//DCR
	{ 0x5, new op_DCR("B") },
	{ 0x15, new op_DCR("D") },
	{ 0x25, new op_DCR("H") },
	{ 0x35, new op_DCR("M") },

	{ 0xD, new op_DCR("C") },
	{ 0x1D, new op_DCR("E") },
	{ 0x2D, new op_DCR("L") },
	{ 0x3D, new op_DCR("A") },

	//MVI
	{ 0x6, new op_MVI("B") },
	{ 0x16, new op_MVI("D") },
	{ 0x26, new op_MVI("H") },
	{ 0x36, new op_MVI("M") },

	{ 0xE, new op_MVI("C") },
	{ 0x1E, new op_MVI("E") },
	{ 0x2E, new op_MVI("L") },
	{ 0x3E, new op_MVI("A") },

	//RLC, RAL, DAA, STC
	{ 0x7, new op_RLC() },
	{ 0x17, new op_RAL() },
	{ 0x27, new op_DAA() },
	{ 0x37, new op_STC() },

	//DAD
	{ 0x9, new op_DAD("B") },
	{ 0x19, new op_DAD("D") },
	{ 0x29, new op_DAD("H") },
	{ 0x39, new op_DAD("SP") },

	//LDAX, LHLD, LDA
	{ 0xA, new op_LDAX("B") },
	{ 0x1A, new op_LDAX("D") },
	{ 0x2A, new op_LHLD() },
	{ 0x3A, new op_LDA() },

	//DCX
	{ 0xB, new op_DCX("B") },
	{ 0x1B, new op_DCX("D") },
	{ 0x2B, new op_DCX("H") },
	{ 0x3B, new op_DCX("SP") },

	//RRC, RAR, CMA, CMC
	{ 0xF, new op_RRC() },
	{ 0x1F, new op_RAR() },
	{ 0x2F, new op_CMA() },
	{ 0x3F, new op_CMC() },

	//ADD
	{ 0x80, new op_ADD("B") },
	{ 0x81, new op_ADD("C") },
	{ 0x82, new op_ADD("D") },
	{ 0x83, new op_ADD("E") },
	{ 0x84, new op_ADD("H") },
	{ 0x85, new op_ADD("L") },
	{ 0x86, new op_ADD("M") },
	{ 0x87, new op_ADD("A") },

	//ADC
	{ 0x88, new op_ADC("B") },
	{ 0x89, new op_ADC("C") },
	{ 0x8A, new op_ADC("D") },
	{ 0x8B, new op_ADC("E") },
	{ 0x8C, new op_ADC("H") },
	{ 0x8D, new op_ADC("L") },
	{ 0x8E, new op_ADC("M") },
	{ 0x8F, new op_ADC("A") },

		//SUB
	{ 0x90, new op_SUB("B") },
	{ 0x91, new op_SUB("C") },
	{ 0x92, new op_SUB("D") },
	{ 0x93, new op_SUB("E") },
	{ 0x94, new op_SUB("H") },
	{ 0x95, new op_SUB("L") },
	{ 0x96, new op_SUB("M") },
	{ 0x97, new op_SUB("A") },

		//SBB
	{ 0x98, new op_SBB("B") },
	{ 0x99, new op_SBB("C") },
	{ 0x9A, new op_SBB("D") },
	{ 0x9B, new op_SBB("E") },
	{ 0x9C, new op_SBB("H") },
	{ 0x9D, new op_SBB("L") },
	{ 0x9E, new op_SBB("M") },
	{ 0x9F, new op_SBB("A") },

	//ANA
	{ 0xA0, new op_ANA("B") },
	{ 0xA1, new op_ANA("C") },
	{ 0xA2, new op_ANA("D") },
	{ 0xA3, new op_ANA("E") },
	{ 0xA4, new op_ANA("H") },
	{ 0xA5, new op_ANA("L") },
	{ 0xA6, new op_ANA("M") },
	{ 0xA7, new op_ANA("A") },

	//XRA
	{ 0xA8, new op_XRA("B") },
	{ 0xA9, new op_XRA("C") },
	{ 0xAA, new op_XRA("D") },
	{ 0xAB, new op_XRA("E") },
	{ 0xAC, new op_XRA("H") },
	{ 0xAD, new op_XRA("L") },
	{ 0xAE, new op_XRA("M") },
	{ 0xAF, new op_XRA("A") },

	//ORA
	{ 0xB0, new op_ORA("B") },
	{ 0xB1, new op_ORA("C") },
	{ 0xB2, new op_ORA("D") },
	{ 0xB3, new op_ORA("E") },
	{ 0xB4, new op_ORA("H") },
	{ 0xB5, new op_ORA("L") },
	{ 0xB6, new op_ORA("M") },
	{ 0xB7, new op_ORA("A") },

	//CMP
	{ 0xB8, new op_CMP("B") },
	{ 0xB9, new op_CMP("C") },
	{ 0xBA, new op_CMP("D") },
	{ 0xBB, new op_CMP("E") },
	{ 0xBC, new op_CMP("H") },
	{ 0xBD, new op_CMP("L") },
	{ 0xBE, new op_CMP("M") },
	{ 0xBF, new op_CMP("A") },

	//RNZ, RNC, RPO, RP
	{ 0xC0 , new op_RNZ() },
	{ 0xD0 , new op_RNC() },
	{ 0xE0 , new op_RPO() },
	{ 0xF0 , new op_RP() },

	//POP
	{ 0xC1 , new op_POP("B") },
	{ 0xD1 , new op_POP("D") },
	{ 0xE1 , new op_POP("H") },
	{ 0xF1 , new op_POP("PSW") },

	//JNZ, JNC, JPO, JP
	{ 0xC2 , new op_JNZ() },
	{ 0xD2 , new op_JNC() },
	{ 0xE2 , new op_JPO() },
	{ 0xF2 , new op_JP() },

	//JMP, OUT, XTHL, DI
	{ 0xC3 , new op_JMP() },
	{ 0xD3 , new op_OUT() },
	{ 0xE3 , new op_XTHL() },
	{ 0xF3 , new op_DI() },

	{ 0xCB , new op_JMP() },

	//CNZ, CNC, CPO, CP
	{ 0xC4 , new op_CNZ() },
	{ 0xD4 , new op_CNC() },
	{ 0xE4 , new op_CPO() },
	{ 0xF4 , new op_CP() },

	//PUSH
	{ 0xC5 , new op_PUSH("B") },
	{ 0xD5 , new op_PUSH("D") },
	{ 0xE5 , new op_PUSH("H") },
	{ 0xF5 , new op_PUSH("PSW") },

	//ADI, SUI, ANI, ORI
	{ 0xC6 , new op_ADI() },
	{ 0xD6 , new op_SUI() },
	{ 0xE6 , new op_ANI() },
	{ 0xF6 , new op_ORI() },

	//RST
	{ 0xC7 , new op_RST(0x0) },
	{ 0xD7 , new op_RST(0x2) },
	{ 0xE7 , new op_RST(0x4) },
	{ 0xF7 , new op_RST(0x6) },

	{ 0xCF , new op_RST(0x1) },
	{ 0xDF , new op_RST(0x3) },
	{ 0xEF , new op_RST(0x5) },
	{ 0xFF , new op_RST(0x7) },

	//RZ, RC, RPE, RM
	{ 0xC8 , new op_RZ() },
	{ 0xD8 , new op_RC() },
	{ 0xE8 , new op_RPE() },
	{ 0xF8 , new op_RM() },

	//RET, PCHL, SPHL
	{ 0xC9 , new op_RET() },
	{ 0xD9 , new op_RET() },
	{ 0xE9 , new op_PCHL() },
	{ 0xF9 , new op_SPHL() },

	//JZ, JC, JPE, JM
	{ 0xCA , new op_JZ() },
	{ 0xDA , new op_JC() },
	{ 0xEA , new op_JPE() },
	{ 0xFA , new op_JM() },

	// IN, XCHG, EI
	{ 0xDB , new op_IN() },
	{ 0xEB , new op_XCHG() },
	{ 0xFB , new op_EI() },

	//CZ, CC, CPE, CM
	{ 0xCC , new op_CZ() },
	{ 0xDC , new op_CC() },
	{ 0xEC , new op_CPE() },
	{ 0xFC , new op_CM() },

	//CALL
	{ 0xCD , new op_CALL() },
	{ 0xDD , new op_CALL() },
	{ 0xED , new op_CALL() },
	{ 0xFD , new op_CALL() },


		//ACI, SBI, XRI, CPI
	{ 0xCE , new op_ACI() },
	{ 0xDE , new op_SBI() },
	{ 0xEE , new op_XRI() },
	{ 0xFE , new op_CPI() },

		//HLT
	{ 0x76 , new op_HLT() },
};

#endif