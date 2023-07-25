
#include "opcode_map.h"

int main()
{
    uint8_t buffer[] = {
    0x78, 0xB1, 0xC8, 0x1A, 0x77, 0x13, 0x23, 0x0B,
    0x78, 0xB1, 0xC2, 0x03, 0x10, 0xC9
    };

    int pc = 0;
    int start_pos = 0x1000;

    while (pc < 14)
    {
        if (opcode_map.contains(buffer[pc]))
        {
            std::string Instruction = opcode_map[buffer[pc]]->get_instruction_string(buffer, pc);
            printf("%lX \t %s\n", start_pos + pc, Instruction.c_str());
            pc += opcode_map[buffer[pc]]->m_opcode_size;
        }
        else
        {
            printf("UNKOWN OPCODE: %02x\n", buffer[pc]);
            pc++;
        }
    }
   return 1;
}