#include "Processor.h"


Processor::Processor()
{
	this->registers = new int[16];
}

Processor::~Processor()
{
	delete this->registers;
}

void Processor::RD() {}; //not sure how to implement yet

void Processor::WR() {}; //not sure how to implement yet

void Processor::ST(unsigned char reg1, unsigned short addr)
{
	//not ready to implement
};

void Processor::LW(unsigned char reg1, unsigned short addr)
{
	//not ready to implement
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

void Processor::MOVI(short data, unsigned char dreg)
{
	//not ready to implement
};

void Processor::ADDI(short imm, unsigned char dreg)
{
	//not ready to implement
};

void Processor::MULI(short imm, unsigned char dreg)
{
	//not ready to implement
};

void Processor::DIVI(short data, unsigned char dreg)
{
	//not ready to implement
};

void Processor::LDI(short data, unsigned char dreg)
{
	//not ready to implement
};

void Processor::SLT(unsigned char sreg, unsigned char breg, unsigned char dreg)
{
	if (this->registers[sreg] < this->registers[breg])
		this->registers[dreg] = 1;
	else
		this->registers[dreg] = 0;
};

void Processor::SLTI(unsigned char sreg, short imm, unsigned char dreg)
{
	//not ready to implement
};

void Processor::HLT()
{
	//not ready to implement
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