#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	char	c;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			int len = strlen(argv[i]);
			for (int j = 0; j < len; j++)
			{
				c = argv[i][j];
				if ('a' <= argv[i][j] && argv[i][j] <= 'z')
					c -= 32;
				std::cout << c;
			}
			if (i + 1 < argc)
				std::cout << ' ';
		}
	}
	std::cout << std::endl;
	return 0;
}
