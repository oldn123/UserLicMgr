#include "stdafx.h"
#include "CBase64Code.h"

BYTE * GetAddrData(DWORD)
{
	return 0;
}


int __stdcall sub_1001EBF0(int a1, int a2)
{
	BYTE *v2; // eax
	DWORD *v3; // ecx
	signed int v4; // edi

	v2 = (BYTE *)(a2 + 1);
	v3 = (DWORD*)GetAddrData(0x100F629C);
	v4 = 8;
	do
	{
		*(v2 - 1) = *(BYTE *)(a1 + *(v3 - 1));
		*v2 = *(BYTE *)(a1 + *v3);
		v2[1] = *(BYTE *)(a1 + v3[1]);
		v2[2] = *(BYTE *)(a1 + v3[2]);
		v2[3] = *(BYTE *)(a1 + v3[3]);
		v2[4] = *(BYTE *)(a1 + v3[4]);
		v2 += 6;
		v3 += 6;
		--v4;
	}
	while ( v4 );
	return 0;
}

int __stdcall sub_1001EC60(void *a1, size_t a2)
{
	size_t v2; // esi
	char v4[56]; // [esp+18h] [ebp-3Ch]

	v2 = a2;
	memcpy(v4, a1, a2);
	memcpy(&v4[v2], (char *)a1 + 28, v2);
	memcpy(a1, (char *)a1 + v2, 28 - v2);
	memcpy((char *)a1 - a2 + 28, v4, a2);
	memcpy((char *)a1 + 28, (char *)a1 + a2 + 28, 28 - a2);
	memcpy((char *)a1 - a2 + 56, &v4[a2], a2);
	return 0;
}

int __stdcall sub_1001EBA0(int a1, int a2)
{
	BYTE *v2; // eax
	DWORD *v3; // ecx
	signed int v4; // edi

	v2 = (BYTE *)(a2 + 1);
	v3 = (DWORD*)GetAddrData(0x100F61BC);
	v4 = 14;
	do
	{
		*(v2 - 1) = *(BYTE *)(a1 + *(v3 - 1));
		*v2 = *(BYTE *)(a1 + *v3);
		v2[1] = *(BYTE *)(a1 + v3[1]);
		v2[2] = *(BYTE *)(a1 + v3[2]);
		v2 += 4;
		v3 += 4;
		--v4;
	}
	while ( v4 );
	return 0;
}

// 数据转换，需要详细分析
int __stdcall convBitData_1001F5A0(int a1, int a2)
{
	int v2; // ebx
	size_t *v3; // esi
	char v5; // [esp+Ch] [ebp-3Ch]

	v2 = a2;
	sub_1001EBA0(a1, (int)&v5);
	v3 = (size_t *)GetAddrData(0x100F6358);
	do
	{
		sub_1001EC60(&v5, *v3);
		sub_1001EBF0((int)&v5, v2);
		++v3;
		v2 += 48;
	}
	while ( (signed int)v3 < (signed int)GetAddrData(0x100F6398));
	return 0;
}

int __stdcall base64Decode_1000F080(char *a1, char *encodeString, int encodeDataLen)
{
	return Base64_Decode(a1, encodeString, encodeDataLen);
}

// 字符串转数据，如"8a9d4c...."-->0x8a,0x9d,0x4c....
signed int __stdcall stringDataToByteData_1000EF90(int a1, BYTE *a2, int a3)
{
	BYTE *v3; // edi
	char *v4; // esi
	char v5; // al
	char v6; // cl
	char v7; // al
	char v8; // cl

	if ( a3 <= 0 )
		return 0;
	v3 = a2;
	v4 = (char *)(a1 + 1);
	while ( 1 )
	{
		v5 = *(v4 - 1);
		v6 = *v4;
		if ( (unsigned __int8)(*(v4 - 1) - 48) > 9u )
		{
			if ( (unsigned __int8)(v5 - 65) > 5u )
			{
				if ( (unsigned __int8)(v5 - 97) > 5u )
					return -1;
				v7 = v5 - 87;
			}
			else
			{
				v7 = v5 - 55;
			}
		}
		else
		{
			v7 = *(v4 - 1) - 48;
		}
		if ( (unsigned __int8)(v6 - 48) > 9u )
			break;
		v8 = v6 - 48;
LABEL_15:
		v4 += 2;
		*v3++ = v8 | 16 * v7;
		if ( (signed int)&v4[-1 - a1] >= a3 )
			return 0;
	}
	if ( (unsigned __int8)(v6 - 65) <= 5u )
	{
		v8 = v6 - 55;
		goto LABEL_15;
	}
	if ( (unsigned __int8)(v6 - 97) <= 5u )
	{
		v8 = v6 - 87;
		goto LABEL_15;
	}
	return -1;
}

// 将字符串转成bit数据存储，如：'a'的ascII是0x61,0x61的二进制是0110 0001,则转换结果为：01 00 00 00  00 01 01 00，即转为2进制形式，反向存储，每一位用一个字节存储
int __stdcall stringToBitData_1001EAE0(int a1, int a2)
{
	int v2; // esi
	signed int v3; // edi
	char v4; // dl
	signed int v5; // eax
	char v6; // bl

	v2 = a2;
	v3 = 0;
	do
	{
		v4 = *(BYTE *)(v3 + a1);
		v5 = 0;
		do
		{
			v6 = v4 >> v5++;
			*(BYTE *)(v2 + v5 - 1) = v6 & 1;
		}
		while ( v5 < 8 );
		++v3;
		v2 += 8;
	}
	while ( v3 < 8 );
	return 0;
}


int __stdcall sub_1001ED00(BYTE *a1)
{
	signed int v1; // eax
	int v2; // ecx
	char v3; // dl
	int v4; // ecx
	char v5; // dl
	int v6; // ecx
	char v8; // [esp+8h] [ebp-44h]
	char v9; // [esp+9h] [ebp-43h]
	char v10; // [esp+Ah] [ebp-42h]
	char v11[61]; // [esp+Bh] [ebp-41h]

	v1 = 0;
	do
	{
		v2 = GetAddrData(0x100F567C)[v1];
		*(&v8 + v1) = a1[GetAddrData(0x100F5678)[v1]];
		v3 = a1[v2];
		v4 = GetAddrData(0x100F5680)[v1];
		*(&v9 + v1) = v3;
		v5 = a1[v4];
		v6 = GetAddrData(0x100F5684)[v1];
		*(&v10 + v1) = v5;
		v11[v1] = a1[v6];
		v1 += 4;
	}
	while ( v1 < 64 );
	memcpy(a1, &v8, 0x40u);
	return 0;
}

int __stdcall sub_1001EE20(BYTE *a1)
{
	signed int v1; // eax
	int v2; // ecx
	char v3; // dl
	int v4; // ecx
	char v5; // dl
	int v6; // ecx
	char v7; // dl
	int v8; // ecx
	char v9; // dl
	int v10; // ecx
	char v12; // [esp+8h] [ebp-34h]
	char v13; // [esp+9h] [ebp-33h]
	char v14; // [esp+Ah] [ebp-32h]
	char v15; // [esp+Bh] [ebp-31h]
	char v16; // [esp+Ch] [ebp-30h]
	char v17[43]; // [esp+Dh] [ebp-2Fh]

	v1 = 0;
	do
	{
		
		v2 = GetAddrData(0x100F587C)[v1];
		*(&v12 + v1) = a1[GetAddrData(0x100F5878)[v1]];
		v3 = a1[v2];
		v4 = GetAddrData(0x100F5880)[v1];
		*(&v13 + v1) = v3;
		v5 = a1[v4];
		v6 = GetAddrData(0x100F5884)[v1];
		*(&v14 + v1) = v5;
		v7 = a1[v6];
		v8 = GetAddrData(0x100F5888)[v1];
		*(&v15 + v1) = v7;
		v9 = a1[v8];
		v10 = GetAddrData(0x100F588C)[v1];
		*(&v16 + v1) = v9;
		v17[v1] = a1[v10];
		v1 += 6;
	}
	while ( v1 < 48 );
	memcpy(a1, &v12, 0x30u);
	return 0;
}

int __stdcall sub_1001EF60(char *a1)
{
	char *v1; // edx
	char *v2; // edi
	char *v3; // ecx
	char *v4; // eax
	signed int v5; // esi
	int v6; // edx
	int v7; // edx
	int v8; // ST14_4
	int v9; // ebp
	char *v10; // ebx
	char *v12; // [esp+18h] [ebp-44h]
	char *v13; // [esp+1Ch] [ebp-40h]
	char *v14; // [esp+20h] [ebp-3Ch]
	char *v15; // [esp+34h] [ebp-28h]

	v1 = a1 + 3;
	v13 = a1 + 15;
	v2 = a1 + 5;
	v14 = a1 + 10;
	v3 = a1 + 13;
	v12 = a1 + 20;
	v4 = a1 + 11;
	v5 = 0;
	v15 = a1 + 3;
	do
	{
		v6 = GetAddrData(0x100F59B8)[v1[1]
		+ 2 * (*v1 + 2 * (*(v12 - 18) + 2 * (*(v3 - 12) + 2 * (*(v4 - 6) + 2 * (2 * v5 + *(v1 - 3))))))];
		a1[4 * v5] = (v6 >> 3) & 1;
		a1[4 * v5 + 1] = (v6 >> 2) & 1;
		a1[4 * v5 + 2] = (v6 >> 1) & 1;
		a1[4 * v5 + 3] = v6 & 1;
		v7 = GetAddrData(0x100F5AB8)[*(v4 - 1)
			+ 2 * (*(v4 - 2) + 2 * (*(v4 - 3) + 2 * (*(v4 - 4) + 2 * (*v4 + 2 * (2 * v5 + *(v4 - 5))))))];
		*(v2 - 1) = (GetAddrData(0x100F5AB8)[*(v4 - 1)
			+ 2
			* (*(v4 - 2) + 2 * (*(v4 - 3) + 2 * (*(v4 - 4) + 2 * (*v4 + 2 * (2 * v5 + *(v4 - 5))))))] >> 3) & 1;
		*v2 = (v7 >> 2) & 1;
		v2[1] = (v7 >> 1) & 1;
		v2[2] = v7 & 1;
		v8 = GetAddrData(0x100F5BB8)[v3[3] + 2 * (v3[2] + 2 * (v3[1] + 2 * (*v3 + 2 * (v4[6] + 2 * (2 * v5 + *(v3 - 1))))))];
		*(v14 - 2) = (GetAddrData(0x100F5BB8)[v3[3] + 2 * (v3[2] + 2 * (v3[1] + 2 * (*v3 + 2 * (v4[6] + 2 * (2 * v5 + *(v3 - 1))))))] >> 3) & 1;
		v2[4] = (v8 >> 2) & 1;
		*v14 = (v8 >> 1) & 1;
		v14[1] = v8 & 1;
		v9 = GetAddrData(0x100F5CB8)[v12[2] + 2 * (v12[1] + 2 * (*v12 + 2 * (v3[6] + 2 * (v4[12] + 2 * (2 * v5 + *(v12 - 2))))))];
		v12 += 24;
		*(v13 - 3) = (v9 >> 3) & 1;
		v2[8] = (v9 >> 2) & 1;
		v14[4] = (v9 >> 1) & 1;
		v10 = v13;
		v13 += 16;
		*v10 = v9 & 1;
		v5 += 4;
		v1 = v15 + 24;
		v4 += 24;
		v3 += 24;
		v2 += 16;
		v15 += 24;
		v14 += 16;
	}
	while ( v5 < 8 );
	return 0;
}

int __stdcall DesEncode_1001EED0(BYTE *a1)
{
	signed int v1; // eax
	int v2; // ecx
	char v3; // dl
	int v4; // ecx
	char v5; // dl
	int v6; // ecx
	char v8; // [esp+8h] [ebp-24h]
	char v9; // [esp+9h] [ebp-23h]
	char v10; // [esp+Ah] [ebp-22h]
	char v11[29]; // [esp+Bh] [ebp-21h]

	v1 = 0;
	do
	{
		v2 = GetAddrData(0x100F593C)[v1];
		*(&v8 + v1) = a1[GetAddrData(0x100F5938)[v1]];
		v3 = a1[v2];
		v4 = GetAddrData(0x100F5940)[v1];
		*(&v9 + v1) = v3;
		v5 = a1[v4];
		v6 = GetAddrData(0x100F5944)[v1];
		*(&v10 + v1) = v5;
		v11[v1] = a1[v6];
		v1 += 4;
	}
	while ( v1 < 32 );
	memcpy(a1, &v8, 0x20u);
	return 0;
}

int __stdcall sub_1001ED90(BYTE *a1)
{
	signed int v1; // eax
	int v2; // ecx
	char v3; // dl
	int v4; // ecx
	char v5; // dl
	int v6; // ecx
	char v8; // [esp+8h] [ebp-44h]
	char v9; // [esp+9h] [ebp-43h]
	char v10; // [esp+Ah] [ebp-42h]
	char v11[61]; // [esp+Bh] [ebp-41h]

	v1 = 0;
	do
	{
		v2 = GetAddrData(0x100F577C)[v1];
		*(&v8 + v1) = a1[GetAddrData(0x100F5778)[v1]];
		v3 = a1[v2];
		v4 = GetAddrData(0x100F5780)[v1];
		*(&v9 + v1) = v3;
		v5 = a1[v4];
		v6 = GetAddrData(0x100F5784)[v1];
		*(&v10 + v1) = v5;
		v11[v1] = a1[v6];
		v1 += 4;
	}
	while ( v1 < 64 );
	memcpy(a1, &v8, 0x40u);
	return 0;
}

int __stdcall sub_1001EB20(int a1, DWORD *a2)
{
	signed int v2; // eax
	BYTE *v3; // edi
	char v4; // cl
	char v5; // dl
	char v6; // cl
	char v7; // dl
	char v8; // cl
	char v9; // dl

	v2 = 0;
	*a2 = 0;
	a2[1] = 0;
	v3 = (BYTE *)(a1 + 2);
	do
	{
		*((BYTE *)a2 + v2) |= *(v3 - 2);
		v4 = *((BYTE *)a2 + v2) | 2 * *(v3 - 1);
		*((BYTE *)a2 + v2) = v4;
		v5 = v4 | 4 * *v3;
		*((BYTE *)a2 + v2) = v5;
		v6 = v5 | 8 * v3[1];
		*((BYTE *)a2 + v2) = v6;
		v7 = v6 | 16 * v3[2];
		*((BYTE *)a2 + v2) = v7;
		v8 = v7 | 32 * v3[3];
		*((BYTE *)a2 + v2) = v8;
		v9 = v8 | (v3[4] << 6);
		*((BYTE *)a2 + v2) = v9;
		*((BYTE *)a2 + v2++) = v9 | (v3[5] << 7);
		v3 += 8;
	}
	while ( v2 < 8 );
	return 0;
}

int __stdcall sub_1001F400(int a1, int a2, int a3)
{
	int v3; // ebx
	signed int v4; // eax
	char v5; // cl
	char v6; // cl
	char v7; // cl
	signed int v8; // eax
	char v9; // dl
	char v10; // dl
	signed int v11; // eax
	signed int v13; // [esp+10h] [ebp-9Ch]
	char v14[48]; // [esp+18h] [ebp-94h]
// 	char v15; // [esp+19h] [ebp-93h]
// 	char v16; // [esp+1Ah] [ebp-92h]
// 	char v17; // [esp+1Bh] [ebp-91h]
// 	char v18; // [esp+1Ch] [ebp-90h]
// 	char v19[43]; // [esp+1Dh] [ebp-8Fh]
	char v20[32]; // [esp+48h] [ebp-64h]
// 	char v21; // [esp+49h] [ebp-63h]
// 	char v22; // [esp+4Ah] [ebp-62h]
// 	char v23[29]; // [esp+4Bh] [ebp-61h]
	char v24[32]; // [esp+68h] [ebp-44h]
	char v25[32]; // [esp+88h] [ebp-24h]

	stringToBitData_1001EAE0(a1, (int)&v20[0]);
	sub_1001ED00((BYTE*)v20);
	v13 = 15;
	v3 = a2 + 721;
	do
	{
		memcpy(v14, v24, 0x20u);
		sub_1001EE20((BYTE*)v14);
		v4 = 0;
		do
		{
			v5 = *(BYTE *)(v3 + v4);
			v14[v4] ^= *(BYTE *)(v3 + v4 - 1);
			v14[1 + v4] ^= v5;
			v6 = *(BYTE *)(v3 + v4 + 2);
			v14[2 + v4] ^= *(BYTE *)(v3 + v4 + 1);
			v14[3 + v4] ^= v6;
			v7 = *(BYTE *)(v3 + v4 + 4);
			v14[4 + v4] ^= *(BYTE *)(v3 + v4 + 3);
			v14[5 + v4] ^= v7;
			v4 += 6;
		}
		while ( v4 < 48 );
		sub_1001EF60(v14);
		DesEncode_1001EED0((BYTE*)v14);
		v8 = 0;
		do
		{
			v9 = v14[1 + v8];
			v20[v8] ^= v14[v8];
			v20[1 + v8] ^= v9;
			v10 = v14[3 + v8];
			v20[2 + v8] ^= v14[2 + v8];
			v20[3 + v8] ^= v10;
			v8 += 4;
		}
		while ( v8 < 32 );
		v11 = v13;
		if ( v13 )
		{
			memcpy(v25, v20, 0x20u);
			memcpy(v20, v24, 0x20u);
			memcpy(v24, v25, 0x20u);
		}
		v3 -= 48;
		--v13;
	}
	while ( v11 - 1 >= 0 );
	sub_1001ED90((BYTE*)&v20);
	sub_1001EB20((int)&v20, (DWORD *)a3);
	return 0;
}

// 关键函数*****
int __stdcall sub_1001F960(int a3, const char *sEncodeData, char *sKeyString)
{
	char *v3; // esi
	int v4; // ebp
	int v5; // edi
	int v6; // ebp
	int v7; // esi
	char *v8; // edi
	int v9; // edx
	char *v10; // edi
	char *v11; // esi
	char v12; // dl
	char v13; // al
	char v14; // cl
	char v15; // dl
	char v16; // al
	char v17; // cl
	char v18; // dl
	char v19; // al
	char v20; // dl
	char v21; // cl
	int v22; // eax
	char v23; // cl
	char v24; // dl
	char v25; // cl
	int v26; // eax
	bool v27; // zf
	int v28; // ebx
	int v29; // esi
	char v31; // [esp+17h] [ebp-379h]
	void *v32; // [esp+18h] [ebp-378h]
	void *pByteDatas; // [esp+1Ch] [ebp-374h]
	int v34; // [esp+20h] [ebp-370h]
	int v35; // [esp+24h] [ebp-36Ch]
	int v36; // [esp+28h] [ebp-368h]
	int v37; // [esp+2Ch] [ebp-364h]
	char v38; // [esp+30h] [ebp-360h]
	char v39; // [esp+31h] [ebp-35Fh]
	char v40; // [esp+32h] [ebp-35Eh]
	char v41; // [esp+33h] [ebp-35Dh]
	char v42; // [esp+34h] [ebp-35Ch]
	char v43; // [esp+35h] [ebp-35Bh]
	char v44; // [esp+36h] [ebp-35Ah]
	char v45; // [esp+37h] [ebp-359h]
	int v46; // [esp+38h] [ebp-358h]
	int v47; // [esp+3Ch] [ebp-354h]
	char v48; // [esp+40h] [ebp-350h]
	char v49; // [esp+80h] [ebp-310h]
	int v50; // [esp+38Ch] [ebp-4h]

	v35 = a3;
	v50 = 0;
	v34 = 0;
	//ReturnThisPtr(&v31);
	v50 = 1;
	v3 = (char *) new char[0x800];
	v3[base64Decode_1000F080(v3, (char *)sEncodeData, strlen(sEncodeData))] = 0;
	v4 = strlen(v3);
	v5 = v4 / 2;
	pByteDatas =  new char[v4 / 2];
	stringDataToByteData_1000EF90((int)v3, (BYTE*)pByteDatas, v4);
	delete(v3);
	v6 = v5 / 8;
	v7 = 8 * (v5 / 8);
	v37 = 8 * (v5 / 8);
	v8 = (char *)new char[v7 + 1];
	v9 = *((DWORD *)sKeyString + 1);             // sKeyString 为8个字节，取后4个字节
	v46 = *(DWORD *)sKeyString;                  // sKeyString 为8个字节，取前4个字节
	v32 = v8;
	v47 = v9;
	stringToBitData_1001EAE0((int)&v46, (int)&v48);// 将字符串转成bit数据存储，如：'a'的ascII是0x61,0x61的二进制是0110 0001,则转换结果为：01 00 00 00  00 01 01 00，即转为2进制形式，反向存储，每一位用一个字节存储
	convBitData_1001F5A0((int)&v48, (int)&v49);
	if ( v6 <= 0 )
	{
		v25 = v45;
	}
	else
	{
		v10 = v8 + 3;
		v11 = (char *)pByteDatas + 2;
		v36 = (BYTE *)v32 - (BYTE *)pByteDatas;
		do
		{
			v12 = *(v11 - 1);
			v13 = *v11;
			LOBYTE(v46) = *(v11 - 2);
			v14 = v11[1];
			BYTE1(v46) = v12;
			v15 = v11[2];
			BYTE2(v46) = v13;
			v16 = v11[3];
			HIBYTE(v46) = v14;
			v17 = v11[4];
			LOBYTE(v47) = v15;
			v18 = v11[5];
			BYTE1(v47) = v16;
			BYTE2(v47) = v17;
			HIBYTE(v47) = v18;
			sub_1001F400((int)&v46, (int)&v49, (int)&v38);
			v19 = v38;
			v20 = v40;
			*(v10 - 2) = v39;
			v21 = v41;
			*(v10 - 3) = v19;
			v22 = v36;
			*v10 = v21;
			v23 = v44;
			v11[v22] = v20;
			v24 = v42;
			LOBYTE(v22) = v43;
			v10[3] = v23;
			v25 = v45;
			v10[1] = v24;
			v10[2] = v22;
			v10[4] = v25;
			v11 += 8;
			v10 += 8;
			--v6;
		}
		while ( v6 );
		v8 = (char *)v32;
		v7 = v37;
	}
	if ( v25 >= 8 )
	{
		v26 = v34;
	}
	else
	{
		v26 = 8 - v25;
		v27 = v26 == 7;
		if ( v26 >= 7 )
			goto LABEL_13;
		do
		{
			if ( *(&v38 + v26) )
				break;
			++v26;
		}
		while ( v26 < 7 );
	}
	v27 = v26 == 7;
LABEL_13:
	if ( v27 )
	{
		v28 = v25;
		if ( 8 - v25 > 0 )
			memcpy(&v8[v7 - 8], &v38, 8 - v25);
		v7 -= v28;
	}
	v8[v7] = 0;
	v29 = v35;
// 	std::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string<char,std::char_traits<char>,std::allocator<char>>(
// 		v35,
// 		v8);
	v34 = 1;
	delete(pByteDatas);
	delete(v8);
	LOBYTE(v50) = 0;
	//nullsub_1(&v31);
	return v29;
}



