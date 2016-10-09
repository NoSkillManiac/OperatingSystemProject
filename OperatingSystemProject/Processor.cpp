#include "Processor.h"


Processor::Processor(Memory* ram)
{
	this->registers = new int[16];
	this->physical_ram = ram;
}

Processor::~Processor()
{
	delete this->registers;
}

void Processor::run()
{
	halted = false;
	while (!halted)
	{
		unsigned int instruction = fetch();
		decode_and_execute(instruction);
	}
};

int Processor::fetch()
{
	unsigned int addr = this->pc + this->base_addr;
	return this->physical_ram->get(addr);
};

void Processor::decode_and_execute(unsigned int instruction)
{
	unsigned int type = (instruction & 0xC0000000); //isolate the two leftmost bits
	unsigned int opcode = (instruction & 0x3F000000) >> 24; //isolate the 6 opcode bits and shift them to the far right

	//type does not get shifted. The two type bits simply get isolated and then compared to save time from bitshifting
	//opcode has the 6 opcode bits isolated and then shifted because easier

	if (type == INSTRUCTION_ARITHMETIC)
	{
		char s1 = (char)((instruction & 0x00F00000) >> 20);
		char s2 = (char)((instruction & 0x000F0000) >> 16);
		char dr = (char)((instruction & 0x0000F000) >> 12);
		switch (opcode)
		{
		case: OP_
		}
	}
	else if (type == INSTRUCTION_CONDITIONAL)
	{
		
	}
	else if (type == INSTRUCTION_IO)
	{

	}
	else /*if(type == INSTRUCTION_JUMP*/
	{

	}
};

void Processor::interrupt()
{

};

void Processor::interrupt(int* instructions, size_t length)
{

};

void Processor::RD()
{

}; //not sure how to implement yet

void Processor::WR()
{

}; //not sure how to implement yet

void Processor::ST(unsigned char reg1, unsigned short addr)
{
	this->physical_ram->set(addr, this->registers[reg1]);
};

void Processor::LW(unsigned char reg1, unsigned short addr)
{
	this->registers[reg1] = this->physical_ram->get(addr);
};

void Processor::MOV(unsigned char reg1, unsigned char reg2)
{
	this->registers[reg2] = this->registers[reg1];
};

void Processor::ADD(unsigned char sreg1, unsigned char sreg2, unsigned char dreg)
{
	this->registers[dreg] = this->registers[sreg1] + this->registers[sreg2];
};

void Processor::SUB(unsigned char sreg1, unsigned char sreg2, unsigned char dreg)
{
	this->registers[dreg] = this->registers[sreg1] - this->registers[sreg2];
};

void Processor::MUL(unsigned char sreg1, unsigned char sreg2, unsigned char dreg)
{
	this->registers[dreg] = this->registers[sreg1] * this->registers[sreg2];
};

void Processor::DIV(unsigned char sreg1, unsigned char sreg2, unsigned char dreg)
{
	this->registers[dreg] = this->registers[sreg1] / this->registers[sreg2];
};

void Processor::AND(unsigned char sreg1, unsigned char sreg2, unsigned char dreg)
{
	this->registers[dreg] = this->registers[sreg1] && this->registers[sreg2];
};

void Processor::OR(unsigned char sreg1, unsigned char sreg2, unsigned char dreg)
{
	this->registers[dreg] = this->registers[sreg1] || this->registers[sreg2];
};

void Processor::MOVI(int data, unsigned char dreg)
{
	this->registers[dreg] = data;
};

void Processor::ADDI(int imm, unsigned char dreg)
{
	this->registers[dreg] += imm;
};

void Processor::MULI(int imm, unsigned char dreg)
{
	this->registers[dreg] *= imm;
};

void Processor::DIVI(int data, unsigned char dreg)
{
	this->registers[dreg] /= data;
};

void Processor::LDI(short data, unsigned char dreg)
{
	//I am assuming this sets the value of dreg to the value held at the memory location
	this->registers[dreg] = this->physical_ram->get(data + base_addr);
};

void Processor::SLT(unsigned char sreg, unsigned char breg, unsigned char dreg)
{
	if (this->registers[sreg] < this->registers[breg])
		this->registers[dreg] = 1;
	else
		this->registers[dreg] = 0;
};

void Processor::SLTI(unsigned char sreg, int imm, unsigned char dreg)
{
	//not ready to implement
	if (this->registers[sreg] > imm)
		this->registers[dreg] = 1;
	else
		this->registers[dreg] = 0;
};

void Processor::HLT()
{
	this->halted = true;
};

void Processor::NOP()
{
	//no-op, this function intentionally left blank
};

void Processor::JMP(unsigned short addr)
{
	this->pc = addr;
}

void Processor::BEQ(unsigned char breg, unsigned char dreg, unsigned short addr)
{
	if (this->registers[breg] == this->registers[dreg])
		this->pc = addr;
};

void Processor::BNE(unsigned char breg, unsigned char dreg, unsigned short addr)
{
	if (this->registers[breg] != this->registers[dreg])
		this->pc = addr;
};

void Processor::BEZ(unsigned char breg, unsigned short addr)
{
	if (this->registers[breg] == 0)
		this->pc = addr;
};

void Processor::BNZ(unsigned char breg, unsigned short addr)
{
	if (this->registers[breg] != 0)
		this->pc = addr;
};

void Processor::BGZ(unsigned char breg, unsigned short addr)
{
	if (this->registers[breg] > 0)
		this->pc = addr;
};

void Processor::BLZ(unsigned char breg, unsigned short addr)
{
	if (this->registers[breg] < 0)
		this->pc = addr;
};