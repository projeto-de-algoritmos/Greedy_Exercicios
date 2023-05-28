#include <stdio.h>

#define MAX_N 25
#define MAX_M 1000001

int N, M;
int blocos[MAX_N];
int mochila[MAX_M];

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int calculadoraMochila()
{
    for (int i = 1; i <= M; ++i)
    {
        mochila[i] = -1;
    }
    mochila[0] = 0;

    for (int i = 0; i < N; ++i)
    {
        int bloco = blocos[i];
        for (int j = bloco; j <= M; ++j)
        {
            if (mochila[j - bloco] != -1)
            {
                if (mochila[j] == -1)
                {
                    mochila[j] = mochila[j - bloco] + 1;
                }
                else
                {
                    mochila[j] = min(mochila[j], mochila[j - bloco] + 1);
                }
            }
        }
    }
    return mochila[M];
}

int main()
{
    int T; // número de instâncias

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &N, &M); // tipos de blocos e comprimento pedido pelo artista
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &blocos[i]); // scanf dos blocos disponíveis
        }

        printf("%d\n", calculadoraMochila());
    }

    return 0;
}