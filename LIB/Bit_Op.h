#ifndef BIT_OP_H
#define BIT_OP_H

#define Get_Bit(Reg, Bit)   ((Reg >> (Bit)) & 0x01)
#define Set_Bit(Reg, Bit)    Reg |= (1 << Bit)
#define Clear_Bit(Reg, Bit)  Reg &= ~(1 << Bit)
#define Toggle_Bit(Reg, Bit) Reg ^= (1 << Bit)

#endif
