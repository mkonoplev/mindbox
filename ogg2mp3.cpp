// ogg2mp3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define var_B0 -0B0h
#define var_AC -0ACh
#define var_A8 -0A8h
#define var_A4 -0A4h
#define var_9C -9Ch
#define var_98 -98h
#define var_8 -8
#define arg_0 4


int rand32()
{
	return MAKELONG(MAKEWORD(rand(), rand()), MAKEWORD(rand(), rand()));
}

int _cdecl sub_42F8A0(unsigned int* key)
{
	__asm
	{
	loc_0042F8A0:
		sub     esp, 0B0h
		//
		mov		eax, key
		mov		[esp+0B0h+arg_0 + 00h], eax
		//
		mov     eax, [esp+0B0h+arg_0]
		push    ebx
		push    ebp
		push    esi
		mov     ecx, [eax+4]
		mov     esi, [eax+1Ch]
		mov     [esp+0BCh+var_AC], ecx
		xor     ecx, esi
		and     ecx, 548E5215h
		push    edi
		mov     edi, [eax+18h]
		mov     edx, ecx
		xor     edx, esi
		mov     esi, [eax+0Ch]
		mov     [esp+0C0h+var_98], edx
		mov     ebp, [eax+8]
		mov     edx, esi
		mov     [esp+0C0h+var_A8], edi
		xor     edx, edi
		mov     edi, [eax+10h]
		and     edx, 1088A800h
		mov     [esp+0C0h+var_A4], edi
		mov     ebx, edx
		xor     ebx, esi
		mov     esi, ebp
		xor     esi, edi
		xor     ebx, 51258A68h
		and     esi, 58D9A58h
		mov     edi, esi
		xor     edi, ebp
		mov     ebp, [eax+14h]
		mov     eax, [eax]
		mov     [esp+0C0h+var_9C], edi
		mov     edi, eax
		mov     [esp+0C0h+var_B0], ebp
		xor     edi, ebp
		and     edi, 218A8E92h
		mov     ebp, edi
		xor     ebp, eax
		mov     eax, [esp+0C0h+var_AC]
		xor     ecx, eax
		mov     eax, [esp+0C0h+var_A4]
		xor     esi, eax
		mov     eax, [esp+0C0h+var_A8]
		mov     [esp+0C0h+var_8], esi
		mov     esi, [esp+0C0h+var_B0]
		xor     edx, eax
		mov     eax, ebx
		xor     eax, [esp+0C0h+var_98]
		xor     edi, esi
		mov     esi, [esp+0C0h+var_9C]
		xor     ebp, 188F0482h
		xor     esi, 3200548Ah
		cmp     eax, 24A8C50h
		jnz     short loc_0042F9C6

	loc_0042F958:
		xor     edi, esi
		cmp     edi, 0F4873201h
		jnz     short loc_0042F9C6

	loc_0042F962:
		xor     edx, ebx
		cmp     edx, 3F5D89CAh
		jnz     short loc_0042F9C6

	loc_0042F96C:
		mov     eax, 0F0F0F0F1h
		mul     ebp
		shr     edx, 4
		mov     eax, 4EC4EC4Fh
		mov     edi, edx
		mul     ebp
		imul    edi, esi
		shr     edx, 2
		imul    edx, ebx
		add     edi, edx
		mov     edx, esi
		imul    edx, ebx
		add     edi, edx
		not     edi
		cmp     edi, ecx
		jnz     short loc_0042F9C6

	loc_0042F997:
		mov     ecx, ebp
		mov     eax, 0AAAAAAABh
		imul    ecx, ebx
		mul     ecx
		mov     eax, [esp+0C0h+var_8]
		shr     edx, 1
		sub     ebp, edx
		add     ebp, esi
		not     ebp
		cmp     ebp, eax
		jnz     short loc_0042F9C6

	loc_0042F9B6:
		pop     edi
		pop     esi
		pop     ebp
		mov     eax, 1
		pop     ebx
		add     esp, 0B0h
		// retn
		jmp		x;

	loc_0042F9C6:
		pop     edi
		pop     esi
		pop     ebp
		xor     eax, eax
		pop     ebx
		add     esp, 0B0h
		// retn
		jmp		x;
x:
		// add		esp, 4h
	}
}

void k()
{
	unsigned int key0 = 0, key1 = 0, key2 = 0, key3 = 0, key4 = 0, key5 = 0, key6 = 0, key7 = 0;
	{
		unsigned int z = 0xa0a0a0a0;
		unsigned int y = 0x3F5D89CA ^ (z ^ 0x51258A68);
		unsigned int x = 0x1088A800;

		unsigned int y2 = 0x24A8C50 ^ (z ^ 0x51258A68);
		// TODO:
		unsigned int z2 = 0x5bbfabd2;
		unsigned int x2 = 0x548E5215;

		unsigned int rebx = z ^ 0x51258A68;
		unsigned int recx = z2;

		key6 = (~x & y) | (x & z);
		key3 = (x & y) | (~x & z);
		key7 = (~x2 & y2) | (x2 & z2);
		key1 = (x2 & y2) | (~x2 & z2);
	}
	{
		unsigned int z = 0xc0c0c0c0;
		unsigned int y = 0xb0b0b0b0;
		unsigned int x = 0x218A8E92;

		unsigned int y2 = (0x0F4873201 ^ y) ^ 0x3200548A;
		// TODO:
		unsigned int z2 = 0xf2681b91;
		unsigned int x2 = 0x58D9A58;

		unsigned int rebp = z ^ 0x188F0482;
		unsigned int var8 = z2;

		key5 = (~x & y) | (x & z);
		key0 = (x & y) | (~x & z);
		key2 = (~x2 & y2) | (x2 & z2);
		key4 = (x2 & y2) | (~x2 & z2);
	}
	unsigned int key[] = 
	{ 
		key0, key1, key2, key3, key4, key5, key6, key7,
	};
	if (sub_42F8A0(key))
	{
		std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
		std::cout << key0 << key1 << key2 << key3  << key4 << key5 << key6 << key7 << std::endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	// srand((unsigned)time(NULL));
	k();

	//bool in[][3] = 
	//{
	//	{0, 0, 0},
	//	{0, 1, 0},
	//	{1, 0, 0},
	//	{1, 1, 0},
	//	{0, 0, 1},
	//	{0, 1, 1},
	//	{1, 0, 1},
	//	{1, 1, 1},
	//};

	//for (int i = 0; i < 8; i++)
	//{
	//	bool a = in[i][0];
	//	bool b = in[i][1];
	//	bool x = in[i][2];

	//	//bool y1 = ((a ^ b) & x) ^ a;
	//	// bool y2 = (a & b) | (~x) | ((~a) & (~b | (b & x)));
	//	//bool y2 = (b & x) | (a & ~x);

	//	bool y1 = (a ^ b) & x;
	//	bool y2 = (a & x) ^ (b & x);
	//	std::cout << "y1 = " << y1 << " y2 = " << y2 << std::endl;
	//}
	return 0;
}

