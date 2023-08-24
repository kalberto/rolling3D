#include<iostream>

class Cheat
{
private:
	bool rafagan_cheat;
	bool water1_cheat;
	bool water2_cheat;
	int rafagan_cheat_code[6];
	int water1_cheat_code[6];
	int water2_cheat_code[6];
	int* buffer;
	int count;
public:

	void Create()
	{
		count = 0;
		buffer = new int[6];
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
		buffer[3] = 0;
		buffer[4] = 0;
		buffer[5] = 0;
		
		
		rafagan_cheat =water1_cheat = water2_cheat =  false;
		
		rafagan_cheat_code[0] = 1;
		rafagan_cheat_code[1] = 2;
		rafagan_cheat_code[2] = 3;
		rafagan_cheat_code[3] = 4;
		rafagan_cheat_code[4] = 5;
		rafagan_cheat_code[5] = 6;

		water1_cheat_code[0] = 3;
		water1_cheat_code[1] = 1;
		water1_cheat_code[2] = 0;
		water1_cheat_code[3] = 3;
		water1_cheat_code[4] = 9;
		water1_cheat_code[5] = 6;

		water2_cheat_code[0] = 0;
		water2_cheat_code[1] = 7;
		water2_cheat_code[2] = 0;
		water2_cheat_code[3] = 3;
		water2_cheat_code[4] = 9;
		water2_cheat_code[5] = 6;









	}

	static Cheat & getInstance()
	{
		static Cheat cheat;

		return cheat;
	}

	 void Add_to_Code(int m)
	{
		buffer[count] = m;
		if (count == 5)
		{
			
			count = 0;
			rafagan_cheat = CheckCodes(rafagan_cheat_code);
			water1_cheat = CheckCodes(water1_cheat_code);
			water2_cheat = CheckCodes(water2_cheat_code);
		}
		else
			count++;
		std::cout << buffer[count]<<"na pos " << count << std::endl;

	}

	bool CheckCodes(int * comparavel)
	{
		int r;
		for (int i = 0; i < 6; i++)
		{
			if (buffer[i] != comparavel[i])
				return false;
		}
		return true;
	}


	static bool Get_Rafagan_Cheat()
	{
		return getInstance().rafagan_cheat;
	}
	static bool Get_Water1_Cheat()
	{
		return getInstance().water1_cheat;
	}
	static bool Get_Water2_Cheat()
	{
		return getInstance().water2_cheat;
	}

};