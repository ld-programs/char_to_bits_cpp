#include <cmath>

class bitmap
{
public:
	#define max_size 8
	bool bit[max_size];

	bitmap()
	{
		for(int i = 0; i < max_size; i++)
			bit[i] = false;
	};

	bitmap(int temp)
	{
		bitmap();

		from(temp);
	};

	bitmap(char temp)
	{
		bitmap((int)temp);
	};

	bitmap& from(unsigned int temp)
	{
		from((int)temp);

		return *this;
	}

	bitmap& from(int temp)
	{
		for (int i = (max_size - 1); i >= 0; i--) {
			bit[i] = (bool)(temp / pow_int(2, i));
			temp = temp % pow_int(2, i);
		}
		return *this;
	};

	bitmap& from(char temp){
		from((int)temp);

		return *this;
	};

	operator int()
	{
		int temp = 0;

		for(int i = 0; i < max_size; i++){
			temp += (bit[i] * pow_int(2,i));
		}

		return temp;
	};

	operator char()
	{
		return (char)((int)this);
	};

private:

	int pow_int(int x, int y)
	{
		return (int)pow((float)x, (float)y);
	};
};