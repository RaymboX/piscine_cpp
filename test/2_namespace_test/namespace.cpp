#include <stdio.h>

namespace One
{
	int	value = 1;
} // namespace one

namespace Two
{
	int	value = 2;
}

namespace Trois
{
	int	value = 3;
}

namespace Trois_cpy = Trois;

int main(void)
{
	printf("ns1::value=%d\n", One::value);
	printf("ns2::value=%d\n", Two::value);
	printf("ns3::value=%d\n", Trois::value);
	printf("ns3_cpy::value=%d\n", Trois_cpy::value);
	return (0);
}