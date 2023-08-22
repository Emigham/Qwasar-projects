#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    char count[128] = {0};
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            int val = argv[i][j];
            count[val] += 1;
        }
    }

    for (int x = 0; x < 128; x++)
    {
        if (count[x]) printf("%c:%d\n", x, count[x]);
    }

    return 0;
}
