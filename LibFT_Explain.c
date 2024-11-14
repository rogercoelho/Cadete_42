/*
Este arquivo é uma réplica do libft da 42SP com comentários de explicação de cada função em português.
Cada linha de código terá seu comentário de explicação.
Normalmente o nome da função é uma abreviação do seu objetivo e aí fica mais fácil entender seu objetivo.
Vamos usar como exemplo a função ft_atoi. O "atoi" é uma abreviação de "ascii to integer".
Ou seja ft_a(de "ascii")to(de "to")i(de "integer").
É claro que isso é uma concepção e entendimento pessoal, que encontrei de assimilar a função com seu objetivo.
Então, fique livre de discordar e encontrar sua propria assimilação.
Fique livre também para fazer suas proprias inclusões de comentários e liberar uma nova versão deste arquivo.
*/


//============================================================================================================
//============================================================================================================

/*
---> ft_atoi <---
A função ft_atoi (ascii to integer) tem como onjetivo fazer a conversão de um valor da tabela ASCII para
um valor inteiro ( do tipo int).
Consulte a tabela ascii digitando man ascii no terminal.
*/

// inclui a biblioteca libft.h
#include "libft.h"

//chama a função atoi que recebe como parâmetro um ponteiro da variavel str do tipo const char.
// const -> não deixa modificar o ponteiro. char --> variavel.
int	ft_atoi(const char *str)
{
	// criamos 3 variáveis do tipo int. (i)iterador, que é um contador, (signal) para receber o sinal de
	// positivo ou negativo e o (result) que vai armazenar o resultado.
	int	i;
	int	signal;
	int	result;

	// iniciamos as variáveis com valor. (i) com 0 porque é um contador, (signal) com 1 para positivo
	// e (result) com 0 para alterarmos depois.
	i = 0;
	signal = 1;
	result = 0;

	// Enquanto (while) a variável (str) na posicao de (i) contador for igual (==) a espaço (' ')
	// ou (||) enquanto a váriavel na posição do contador for maior ou igual (>=) a 9
	// e (&&) enquanto a variavel na posição do contador for menor ou igual (<=) a 13.
	// adiciona +1 ao contador (i++).
	// OBS: Veja a tabela ascii de 9 a 13 pois o atoi ignora estes: (\t, \n, \v, \f, \r ).
	// OBS_2: Como o while tem apenas uma linha nao precisa abrir e fechar chaves "{}"
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;

	// Se a variável na posição do contador for igual ao sinal de menos ('-')
	// ou se a variável na pocição do contador for igual ao sinal de mais ('+')
	if (str[i] == '-' || str[i] == '+')
	{

		// Se a variável na posição do contador somado a mais 1 for igual ao sinal de mais ( '+')
		// ou se a variável na posição do contador somado a mais 1 for igual ao sinal de menos ('-')
		// retorna e sai da função (return(0).
		// Obs: Esta parte verifica que a variável tem 2 sinais antes dos numeros. Ex: ++123 ou +-123.
		//      Se tiver retorna e sai da função.
		if ((str[i] + 1 == '+') || (str[i] + 1 == '-'))
			return (0);

		// Se a variável na posição do contador for igual ao sinal de menos ('-')
		// entao invertemos o sinal da variável (signal) para -1
		// Obs: Isso quer dizer que o numero da variável (str) é negativo.
		if (str[i] == '-')
		{
			signal = -1;
		}

		// Adicionamos mais 1 ao contador (i++).
		i++;
	}

	// Enquanto a variável na posção do contador for maior ou igual a 0
	// e enquanto a variável na posição do contador for menor ou igual a 9.
	while (str[i] >= '0' && str[i] <= '9')
	{

		// a variável (result) recebe o valor dela (result) multiplicado por 10 (* 10)
		// mais (+) o valor da variável (str) na posição do contador. O menos 0 (- '0')
		// converte o valor de Ascii para Inteiro.
		// Obs: A parte (result * 10) faz com que a gente "mova" a posicao dos numeros na variavel (result)
		//		exemplo: 12 * 10 = 120 --> mais o valor da variável (str[i]) que pode ser de 0 a 9
		//		fica 120 - 129.
		result = result * 10 + (str[i] - '0');

		// Adicionamos mais 1 ao contador (i++).
		i++;
	}

	// Depois de feita a conversão retorna as variáveis (signal) multiplicando (*) com (result).
	// como signal so pode ser 1 ou -1, tranforma o retorno do numero em positivo ou negativo.
	return (signal * result);
}

//============================================================================================================
//============================================================================================================

/*
---> ft_bzero <---
A função ft_bzero (be zero "seja 0") tem como onjetivo fazer com que um bloco de memória receba o valor 0.
A memória sendo preenchida com zeros é util para limpar dados de forma segura ou inicializar um buffer antes
de usar.
*/

// inclui a biblioteca libft.h
#include "libft.h"

//chama a função bzero que recebe como parâmetro um ponteiro da variavel str do tipo void
// e uma variavel de "tamanho" do tipo size_t. O size_t é mais usado para contadores ou para
// identificar um tamanho de algo. Neste caso é o tamanho do ponteiro que será preenchido com 0.
// void -> não possui um retorno (vazio).
void	ft_bzero(void *str, size_t len)
{
	unsigned char	*str_loc;
	size_t			i;

	i = 0;
	str_loc = (unsigned char *)str;
	while (i < len)
	{
		str_loc[i] = 0;
		i++;
	}
}
