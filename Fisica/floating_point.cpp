#pragma once

#include <stdio.h>
#include <memory.h>
#include <stdint.h>
#include <bitset>

using namespace std;

union int_float_bits {
    int32_t int_bits;
    float float_bits;
};

union int_double_bits {
    int64_t int_bits;
    double double_bits;
};

float intBitsToFloat(int32_t x)
{
    union int_float_bits bits;
    bits.int_bits = x;
    return bits.float_bits;
}

double longIntBitsToDouble(int64_t x)
{
    union int_double_bits bits;
    bits.int_bits = x;
    return bits.double_bits;
}

//int main() {
//	bitset<32> bs(string("11000001000100000000000000000000"));
//	int i = (int)(bs.to_ulong());
//	cout<<intBitsToFloat(i);
//}
	/*system("pause");*/

	//printf("%f\n", intBitsToFloat(bitset<32>(string("11000001000100000000000000000000")).to_ulong));
	//printf("%f\n", longIntBitsToDouble(0b1100000000100010000000000000000000000000000000000000000000000000L));
