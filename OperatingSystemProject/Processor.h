#pragma once
class Processor
{
public:
	Processor();
	~Processor();
	void interrupt();
	void interrupt(int* instructions);
	
private:
	//registers[0] is the accumulator
	//registers[1] is the zero register and cannot be changed
	//registers[2] --> registers[15] are general purpose registers
	int* registers; //holds 16 integers, initialized in the constructor
	unsigned short pc; //program counter

	void fetch(); //fetch the next instruction
	void decode(int instruction); //decode the instruction given
	void execute(); //execute the instruction

	void RD(); //not sure how to implement yet
	void WR(); //not sure how to implement yet
	void ST(unsigned char reg1, unsigned short addr); //store contents of register into address
	void LW(unsigned char reg1, unsigned short addr); //load contents of address into register
	void MOV(unsigned char reg1, unsigned char reg2); //move contents from reg1 to reg2
	void ADD(unsigned char sreg1, unsigned char sreg2, unsigned char dreg); //add content of both sregs to dreg
	void SUB(unsigned char sreg1, unsigned char sreg2, unsigned char dreg); //sub sreg2 from sreg1 and store in dreg
	void MUL(unsigned char sreg1, unsigned char sreg2, unsigned char dreg); //multiplies sregs and store in dreg
	void DIV(unsigned char sreg1, unsigned char sreg2, unsigned char dreg); //sreg1/sreg2 --> dreg
	void AND(unsigned char sreg1, unsigned char sreg2, unsigned char dreg); //logical AND of sreg1 and sreg2, store in dreg
	void OR(unsigned char sreg1, unsigned char sreg2, unsigned char dreg); //logical OR of sreg1 and sreg2, store in dreg
	void MOVI(short data, unsigned char dreg); //transfer data/addr into dreg
	void ADDI(short imm, unsigned char dreg); //add imm to dreg
	void MULI(short imm, unsigned char dreg); //multiply imm data by dreg data
	void DIVI(short imm, unsigned char dreg); //divide dreg data by imm data
	void LDI(short data, unsigned char dreg); //load data/address into dreg
	void SLT(unsigned char sreg, unsigned char breg, unsigned char dreg); //set dreg to 1 if sreg < breg, 0 if otherwise
	void SLTI(unsigned char sreg, short imm, unsigned char dreg); //set dreg to 1 if sreg < imm, 0 if otherwise
	void HLT(); //logical end of the program
	void NOP(); //no-op
	void JMP(unsigned short addr); //jump to the set address (set the pc to the address of the instruction to jump to)
	void BEQ(unsigned char breg, unsigned char dreg, unsigned short addr); //set pc to addr if breg == dreg
	void BNE(unsigned char breg, unsigned char dreg, unsigned short addr); //set pc to addr if breg != dreg
	void BEZ(unsigned char breg, unsigned short addr); //set pc to addr if breg == 0
	void BNZ(unsigned char breg, unsigned short addr); //set pc to addr if breg != 0
	void BGZ(unsigned char breg, unsigned short addr); //set pc to addr if breg > 0
	void BLZ(unsigned char breg, unsigned short addr); //set pc to addr if breg < 0
};

