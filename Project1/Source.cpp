#include<iostream>
#include<time.h>


int main()
{
	srand(time(NULL));
	float r;
	  
	float x = rand() % 10 + 1;
	float y = rand() % 10 + 1;

	
	r = x / y;


	std::cout << x << "  /  " << y << "  =  " << r << std::endl;
	system("pause");
	return 0;
}