#pragma once

#ifndef OPCODE_H
#define OPCODE_H

#include <string>
#include <format>

std::string toUpper(const std::string& input) {
	std::string result = input;
	for (char& c : result) {
		c = std::toupper(c);
	}
	return result;
}


//Base Classes
class opcode_base
{
public:
	std::string m_opcode_name;
	int m_opcode_size;
public:
	opcode_base() {};
	virtual std::string get_instruction_string(uint8_t* buffer, int position) { return ""; };
};

class opcode_standalone : public opcode_base
{
public:
	opcode_standalone() { m_opcode_size = 1; }
	virtual std::string get_instruction_string(uint8_t* buffer, int position) override
	{
		return m_opcode_name;
	}
};

class opcode_one_register : public opcode_base
{
private:
	std::string m_reg1;
public:
	opcode_one_register(std::string reg1)
	{
		m_reg1 = reg1;
		m_opcode_size = 1;
	}

	virtual std::string get_instruction_string(uint8_t* buffer, int position) override
	{
		return m_opcode_name + " " + m_reg1;
	}
};

class opcode_two_register : public opcode_base
{
private:
	std::string m_reg1;
	std::string m_reg2;
public:
	opcode_two_register(std::string reg1, std::string reg2)
	{
		m_reg1 = reg1;
		m_reg2 = reg2;
		m_opcode_size = 1;
	}

	virtual std::string get_instruction_string(uint8_t* buffer, int position) override
	{
		return m_opcode_name + " " + m_reg1 + ", " + m_reg2;
	}
};

class opcode_one_register_8_bit : public opcode_base
{
private:
	std::string m_reg1;
public:
	opcode_one_register_8_bit(std::string reg1)
	{
		m_reg1 = reg1;
		m_opcode_size = 2;
	}

	virtual std::string get_instruction_string(uint8_t* buffer, int position) override
	{
		return m_opcode_name + " " + m_reg1 + ", " + toUpper(std::format("{:x}", buffer[position + 1]));
		
	}
};
class opcode_one_register_16_bit : public opcode_base
{
private:
	std::string m_reg1;
public:
	opcode_one_register_16_bit(std::string reg1)
	{
		m_reg1 = reg1;
		m_opcode_size = 3;
	}

	virtual std::string get_instruction_string(uint8_t* buffer, int position) override
	{
#ifndef VERBOSE
		int formatted_num = (buffer[position + 2] << 8) + buffer[position + 1];
		return m_opcode_name + " " + toUpper(std::format("{:x}", formatted_num));
#else
		return m_opcode_name + " " + m_reg1 + ", " + toUpper(std::format("{:x}", buffer[position + 1])) + " " + toUpper(std::format("{:x}", buffer[position + 2]));
#endif
	}
};

class opcode_8_bit : public opcode_base
{
public:
	opcode_8_bit()
	{
		m_opcode_size = 2;
	}

	virtual std::string get_instruction_string(uint8_t* buffer, int position) override
	{
		return m_opcode_name + " " + toUpper(std::format("{:x}", buffer[position + 1]));
	}
};

class opcode_16_bit : public opcode_base
{
public:
	opcode_16_bit()
	{
		m_opcode_size = 3;
	}

	virtual std::string get_instruction_string(uint8_t* buffer, int position) override
	{
#ifndef VERBOSE
		int formatted_num = (buffer[position + 2] << 8) + buffer[position + 1];
		return m_opcode_name + " " + toUpper(std::format("{:x}", formatted_num));
#else
		return m_opcode_name + " " + toUpper(std::format("{:x}", buffer[position + 1])) + " " + toUpper(std::format("{:x}", buffer[position + 2]));
#endif
	}
};

class opcode_8_bit_input : public opcode_base
{
private:
	uint8_t m_num;

public:
	opcode_8_bit_input(uint8_t num)
	{
		m_num = num;
		m_opcode_size = 1;
	}
	virtual std::string get_instruction_string(uint8_t* buffer, int position) override
	{
		return m_opcode_name + " " + toUpper(std::format("{:x}", m_num));
	}

};



//Opcode classes
class op_NOP : public opcode_standalone
{
public:
	op_NOP() { m_opcode_name = "NOP"; }
};


class op_LXI : public opcode_one_register_16_bit
{
public:
	op_LXI(std::string reg1) : opcode_one_register_16_bit{ reg1 } { m_opcode_name = "LXI"; }
};


class op_MOV : public opcode_two_register
{
public:
	op_MOV(std::string reg1, std::string reg2) : opcode_two_register{reg1, reg2}
	{
		m_opcode_name = "MOV";
	}
};

class op_STAX : public opcode_one_register
{
public:
	op_STAX(std::string reg1) : opcode_one_register{reg1}
	{
		m_opcode_name = "STAX";
	}
};

class op_SHLD : public opcode_16_bit
{
public:
	op_SHLD() { m_opcode_name = "SHLD"; }
};

class op_STA : public opcode_16_bit
{
public:
	op_STA() { m_opcode_name = "STA"; }
};

class op_INX : public opcode_one_register
{
public:
	op_INX(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "INX";
	}
};

class op_INR : public opcode_one_register
{
public:
	op_INR(std::string reg1) : opcode_one_register{reg1}
	{
		m_opcode_name = "INR";
	}
};

class op_DCR : public opcode_one_register
{
public:
	op_DCR(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "DCR";
	}
};

class op_MVI : public opcode_one_register_8_bit
{
public:
	op_MVI(std::string reg1) : opcode_one_register_8_bit{reg1}
	{
		m_opcode_name = "MVI";
	}
};

class op_RLC : public opcode_standalone
{
public:
	op_RLC() { m_opcode_name = "RLC"; }
};

class op_RAL : public opcode_standalone
{
public:
	op_RAL() { m_opcode_name = "RAL"; }
};

class op_DAA : public opcode_standalone
{
public:
	op_DAA() { m_opcode_name = "DAA"; }
};

class op_STC : public opcode_standalone
{
public:
	op_STC() { m_opcode_name = "STC"; }
};

class op_DAD : public opcode_one_register
{
public:
	op_DAD(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "DAD";
	}
};

class op_LDAX : public opcode_one_register
{
public:
	op_LDAX(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "LDAX";
	}
};

class op_LHLD : public opcode_16_bit
{
public:
	op_LHLD() { m_opcode_name = "LHLD"; }
};

class op_LDA : public opcode_16_bit
{
public:
	op_LDA() { m_opcode_name = "LDA"; }
};

class op_DCX : public opcode_one_register
{
public:
	op_DCX(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "DCX";
	}
};

class op_RRC : public opcode_standalone
{
public:
	op_RRC() { m_opcode_name = "RRC"; }
};

class op_RAR : public opcode_standalone
{
public:
	op_RAR() { m_opcode_name = "RAR"; }
};

class op_CMA : public opcode_standalone
{
public:
	op_CMA() { m_opcode_name = "CMA"; }
};

class op_CMC : public opcode_standalone
{
public:
	op_CMC() { m_opcode_name = "CMC"; }
};

class op_ADD : public opcode_one_register
{
public:
	op_ADD(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "ADD";
	}
};

class op_ADC : public opcode_one_register
{
public:
	op_ADC(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "ADC";
	}
};

class op_SUB : public opcode_one_register
{
public:
	op_SUB(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "SUB";
	}
};

class op_SBB : public opcode_one_register
{
public:
	op_SBB(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "SBB";
	}
};

class op_ANA : public opcode_one_register
{
public:
	op_ANA(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "ANA";
	}
};

class op_XRA : public opcode_one_register
{
public:
	op_XRA(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "XRA";
	}
};

class op_ORA : public opcode_one_register
{
public:
	op_ORA(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "ORA";
	}
};

class op_CMP : public opcode_one_register
{
public:
	op_CMP(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "CMP";
	}
};

class op_RNZ : public opcode_standalone
{
public:
	op_RNZ() { m_opcode_name = "RNZ"; }
};

class op_RNC : public opcode_standalone
{
public:
	op_RNC() { m_opcode_name = "RNC"; }
};

class op_RPO : public opcode_standalone
{
public:
	op_RPO() { m_opcode_name = "RPO"; }
};

class op_RP : public opcode_standalone
{
public:
	op_RP() { m_opcode_name = "RP"; }
};

class op_POP : public opcode_one_register
{
public:
	op_POP(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "POP";
	}
};

class op_JNZ : public opcode_16_bit
{
public:
	op_JNZ() { m_opcode_name = "JNZ"; }
};

class op_JNC : public opcode_16_bit
{
public:
	op_JNC() { m_opcode_name = "JNC"; }
};

class op_JPO : public opcode_16_bit
{
public:
	op_JPO() { m_opcode_name = "JPO"; }
};

class op_JP : public opcode_16_bit
{
public:
	op_JP() { m_opcode_name = "JP"; }
};

class op_JMP : public opcode_16_bit
{
public:
	op_JMP() { m_opcode_name = "JMP"; }
};

class op_OUT : public opcode_8_bit
{
public:
	op_OUT() { m_opcode_name = "OUT"; }
};

class op_XTHL : public opcode_standalone
{
public:
	op_XTHL() { m_opcode_name = "XTHL"; }
};

class op_DI : public opcode_standalone
{
public:
	op_DI() { m_opcode_name = "DI"; }
};

class op_CNZ : public opcode_16_bit
{
public:
	op_CNZ() { m_opcode_name = "CNZ"; }
};

class op_CNC : public opcode_16_bit
{
public:
	op_CNC() { m_opcode_name = "CNC"; }
};

class op_CPO : public opcode_16_bit
{
public:
	op_CPO() { m_opcode_name = "CPO"; }
};

class op_CP : public opcode_16_bit
{
public:
	op_CP() { m_opcode_name = "CP"; }
};

class op_PUSH : public opcode_one_register
{
public:
	op_PUSH(std::string reg1) : opcode_one_register{ reg1 }
	{
		m_opcode_name = "PUSH";
	}
};

class op_ADI : public opcode_8_bit
{
public:
	op_ADI() { m_opcode_name = "ADI"; }
};

class op_SUI : public opcode_8_bit
{
public:
	op_SUI() { m_opcode_name = "SUI"; }
};

class op_ANI : public opcode_8_bit
{
public:
	op_ANI() { m_opcode_name = "ANI"; }
};

class op_ORI : public opcode_8_bit
{
public:
	op_ORI() { m_opcode_name = "ORI"; }
};

class op_RST : public opcode_8_bit_input
{
public:
	op_RST(uint8_t num) : opcode_8_bit_input{num}
	{
		m_opcode_name = "RST";
	}
};

class op_RZ : public opcode_standalone
{
public:
	op_RZ() { m_opcode_name = "RZ"; }
};

class op_RC : public opcode_standalone
{
public:
	op_RC() { m_opcode_name = "RC"; }
};

class op_RPE : public opcode_standalone
{
public:
	op_RPE() { m_opcode_name = "RPE"; }
};

class op_RM : public opcode_standalone
{
public:
	op_RM() { m_opcode_name = "RM"; }
};

class op_RET : public opcode_standalone
{
public:
	op_RET() { m_opcode_name = "RET"; }
};

class op_PCHL : public opcode_standalone
{
public:
	op_PCHL() { m_opcode_name = "PCHL"; }
};

class op_SPHL : public opcode_standalone
{
public:
	op_SPHL() { m_opcode_name = "SPHL"; }
};

class op_JZ : public opcode_16_bit
{
public:
	op_JZ() { m_opcode_name = "JZ"; }
};

class op_JC : public opcode_16_bit
{
public:
	op_JC() { m_opcode_name = "JC"; }
};

class op_JPE : public opcode_16_bit
{
public:
	op_JPE() { m_opcode_name = "JPE"; }
};

class op_JM : public opcode_16_bit
{
public:
	op_JM() { m_opcode_name = "JM"; }
};

class op_IN : public opcode_8_bit
{
public:
	op_IN() { m_opcode_name = "IN"; }
};

class op_XCHG : public opcode_standalone
{
public:
	op_XCHG() { m_opcode_name = "XCHG"; }
};

class op_EI : public opcode_standalone
{
public:
	op_EI() { m_opcode_name = "EI"; }
};

class op_CZ : public opcode_16_bit
{
public:
	op_CZ() { m_opcode_name = "CZ"; }
};

class op_CC : public opcode_16_bit
{
public:
	op_CC() { m_opcode_name = "CC"; }
};

class op_CPE : public opcode_16_bit
{
public:
	op_CPE() { m_opcode_name = "CPE"; }
};

class op_CM : public opcode_16_bit
{
public:
	op_CM() { m_opcode_name = "CM"; }
};

class op_CALL : public opcode_16_bit
{
public:
	op_CALL() { m_opcode_name = "CALL"; }
};

class op_ACI : public opcode_8_bit
{
public:
	op_ACI() { m_opcode_name = "ACI"; }
};

class op_SBI : public opcode_8_bit
{
public:
	op_SBI() { m_opcode_name = "SBI"; }
};

class op_XRI : public opcode_8_bit
{
public:
	op_XRI() { m_opcode_name = "XRI"; }
};

class op_CPI : public opcode_8_bit
{
public:
	op_CPI() { m_opcode_name = "CPI"; }
};

class op_HLT : public opcode_standalone
{
public:
	op_HLT() { m_opcode_name = "HLT"; }
};

#endif