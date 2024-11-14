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
	// Declara a variavel (str_loc) do tipo ponteiro de unsigned char e um contador (i) do tipo size_t.
	unsigned char	*str_loc;
	size_t			i;

	// Inicializa a variável (i) com 0 e a variável (str_loc) recebe o valor do ponteiro (str).
	i = 0;
	str_loc = (unsigned char *)str;

	// Enquanto o contador (i) for menor que o tamanho (len) passado como parâmetro
	// a variável (str_loc) na posição do contador (i) recebe o valor 0.
	// incrementa o contador + 1 (i++).
	// Obs: O valor 0 é o valor que queremos preencher o ponteiro.
	while (i < len)
	{
		str_loc[i] = 0;
		i++;
	}
}

//============================================================================================================
//============================================================================================================

/*
---> ft_calloc <---
A função ft_calloc ("Chama" alocação) tem como objetivo alocar um bloco de memória e preencher com 0.
Isso é util para inicializar um buffer ou para garantir que a memória esteja limpa antes de usar.
*/

// inclui a biblioteca libft.h
#include "libft.h"

//chama a função calloc que recebe como parâmetro dois tamanhos do tipo size_t
// a variavel num com o numero de elementos e a variavel size com o tamanho de cada elemento.
void	*ft_calloc(size_t num, size_t size)
{
	// declara a variavel total_mem_size do tipo size_t que é o tamanho total da memória
	// e a variavel str que é um ponteiro do tipo void e que vai receber os valores.
	size_t	total_mem_size;
	void	*str;

	// total_mem_size recebe o valor do numero de elementos multiplicado pelo tamanho de cada elemento.
	// str recebe o valor da alocação de memória com o tamanho total (total_mem_size).
	total_mem_size = num * size;
	str = malloc(total_mem_size);

	// Se a variável (str) for igual a 0 (NULL) retorna NULL.
	// Obs: Isso é uma verificação para saber se a alocação de memória foi feita com sucesso.
	// Obs_2: O if nao está entre chaves "{}" porque só tem uma linha.
	if (str == 0)
		return (NULL);

	// Aqui eu uso a função ft_memset para preencher o bloco de memória com 0.
	// Eu poderia usar a função ft_bzero que faz a mesma coisa preechendo com 0.
	// Ou eu poderia usar o calloc ao invés do malloc, que faz a alocação e preenche com 0.
	ft_memset(str, 0, total_mem_size);

	// Retorna o ponteiro (str) que é o bloco de memória alocado e preenchido com 0.
	return (str);
}

//============================================================================================================
//============================================================================================================

/*
---> ft_isalnum <---
A função ft_isalnum (é alfanumérico) tem como objetivo verificar se um caractere é alfanumérico.
Ou seja, se é uma letra ou um número. Caso verdadeiro retorna um numero diferente de 0 e se for
falso retorna 0. Ele utiliza a tabela ascii para fazer a verificação.
*/

// inclui a biblioteca libft.h
#include "libft.h"

//chama a função isalnum que recebe como parâmetro uma variavel do tipo inteiro (c) que é
// o caractere a ser verificado.
int	ft_isalnum(int c)
{
	// Se o caractere (c) estiver entre 65 e 90 (letras maiusculas) ou entre 97 e 122 (letras minusculas)
	// ou entre 48 e 57 (numeros de 0 a 9) retorna o caractere (c).
	// Obs: A tabela ascii tem os valores de 65 a 90 para as letras maiusculas, 97 a 122 para as letras
	// minusculas e 48 a 57 para os numeros de 0 a 9.
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (c);

	// Se não estiver entre os valores acima retorna 0.
	return (0);
}

//============================================================================================================
//============================================================================================================

/*
---> ft_isalpha <---
A função ft_isalpha (é alfabetico) tem como objetivo verificar se um caractere é uma letra.
Ou seja, se é uma letra do alfabeto. Caso verdadeiro retorna um numero diferente de 0 e se for
falso retorna 0. Ele utiliza a tabela ascii para fazer a verificação.
*/

// inclui a biblioteca libft.h
#include "libft.h"

//chama a função isalpha que recebe como parâmetro uma variavel do tipo inteiro (c) que é
// o caractere a ser verificado.
int	ft_isalpha(int c)
{
	// Se o caractere (c) estiver entre 65 e 90 (letras maiusculas) ou entre 97 e 122 (letras minusculas)
	// retorna 1.
	// Obs: A tabela ascii tem os valores de 65 a 90 para as letras maiusculas e 97 a 122 para as letras
	// minusculas.
	// Obs_2: Eu poderia retornar o caractere (c) ao invés de 1, pois qualquer valor diferente de 0
	//é verdadeiro.
	// Obs_3: O if nao está entre chaves "{}" porque só tem uma linha.
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);

	// Se não estiver entre os valores acima retorna 0.
	return (0);
}

//============================================================================================================
//============================================================================================================

/*
---> ft_isascii <---
A função ft_isascii (é ascii) tem como objetivo verificar se um caractere é um caractere da tabela ascii.
Ou seja, se é um caractere que pode ser impresso na tela. Caso verdadeiro retorna um numero diferente de 0
e se for falso retorna 0. Ele utiliza a tabela ascii para fazer a verificação.
*/

// inclui a biblioteca libft.h
#include "libft.h"

//chama a função isascii que recebe como parâmetro uma variavel do tipo inteiro (c) que é
// o caractere a ser verificado.
int	ft_isascii(int c)
{
	// Se o caractere (c) estiver entre 0 e 127 (toda a tabela ascii) retorna 1.
	// Obs: A tabela ascii tem os valores de 0 a 127.
	// Obs_2: Eu poderia retornar o caractere (c) ao invés de 1, pois qualquer valor diferente de 0
	//é verdadeiro.
	// Obs_3: O if nao está entre chaves "{}" porque só tem uma linha.
	if (c >= 0 && c <= 127)
		return (1);

	// Se não estiver entre os valores acima retorna 0.
	return (0);
}

//============================================================================================================
//============================================================================================================

/*
---> ft_isdigit <---
A função ft_isdigit (é digito) tem como objetivo verificar se um caractere é um número.
Ou seja, se é um número de 0 a 9. Caso verdadeiro retorna um numero diferente de 0 e se for
falso retorna 0. Ele utiliza a tabela ascii para fazer a verificação.
*/

// inclui a biblioteca libft.h
#include "libft.h"

//chama a função isdigit que recebe como parâmetro uma variavel do tipo inteiro (c) que é
// o caractere a ser verificado.
int	ft_isdigit(int c)
{
	// Se o caractere (c) estiver entre 48 e 57 (numeros de 0 a 9) retorna (c).
	// Obs: A tabela ascii tem os valores de 48 a 57 para os numeros de 0 a 9.
	// Obs_2: Eu poderia retornar o valor 1 ao invés da variavel (c), pois qualquer valor diferente de 0
	//é verdadeiro.
	// Obs_3: O if nao está entre chaves "{}" porque só tem uma linha.
	if (c >= 48 && c <= 57)
		return (c);

	// Se não estiver entre os valores acima retorna 0.
	return (0);
}

//============================================================================================================
//============================================================================================================

/*
---> ft_isprint <---
A função ft_isprint (é printável) tem como objetivo verificar se um caractere é um caractere "imprimivel".
Ou seja, se é um caractere que pode ser impresso na tela. Caso verdadeiro retorna um numero diferente de 0
e se for falso retorna 0. Ele utiliza a tabela ascii para fazer a verificação.
*/

// inclui a biblioteca libft.h
#include "libft.h"

//chama a função isprint que recebe como parâmetro uma variavel do tipo inteiro (c) que é
// o caractere a ser verificado.
int	ft_isprint(int c)
{
	// Se o caractere (c) estiver entre 32 e 126 (caracteres imprimiveis) retorna (c).
	// Obs: A tabela ascii tem os valores de 32 a 126 para os caracteres imprimiveis.
	// Obs_2: Eu poderia retornar o valor 1 ao invés da variavel (c), pois qualquer valor diferente de 0
	//é verdadeiro.
	// Obs_3: O if nao está entre chaves "{}" porque só tem uma linha.
	if (c >= 32 && c <= 126)
		return (c);

	// Se não estiver entre os valores acima retorna 0.
	return (0);
}

//============================================================================================================
//============================================================================================================

/*
---> ft_itoa <---
A função itoa (integer to ASCII) tem como objetivo converter um número inteiro (int) em uma representação
em forma de string (char *) utilizando a tabela ascci para a conversão. Isso é útil para exibir números
como texto ou para utilizá-los em funções que lidam com strings.
*/

// inclui a biblioteca libft.h
#include "libft.h"

//chama a função itoa que recebe como parâmetro uma variavel do tipo inteiro (n) que é
// o número a ser convertido.
char	*ft_itoa(int n)
{
	// declara as variaveis num, len e str.
	// num é o número a ser convertido.
	// len é o tamanho da string que vai receber o número convertido.
	// str é a string que vai receber o número convertido.
	long	num;
	size_t	len;
	char	*str;

	// num recebe o valor do número a ser convertido.
	// len recebe o tamanho da string que vai receber o número convertido.
	// str inicializa com 0.
	// Obs: O tamanho da string é importante para alocar a memória corretamente e o ft_itoa_len
	// é uma função auxiliar que faz essa contagem e será explicada a seguir.
	num = n;
	len = ft_itoa_len(num);
	str = 0;

	// str recebe o valor da função ft_num_to_str que tem como parâmetro o número a ser convertido,
	// a string que vai receber o número convertido e o tamanho da string.
	// Obs: A função ft_num_to_str é uma função auxiliar que faz a conversão do número para string e
	// será explicada a seguir.
	str = ft_num_to_str(num, str, len);

	// Se str for igual a 0 retorna NULL.
	// Obs: Isso é uma verificação para saber se a alocação de memória foi feita com sucesso.
	// Obs_2: O if nao está entre chaves "{}" porque só tem uma linha.
	// Obs_3: a forma escrita (!str) é a mesma coisa que (str == 0) ou (str == NULL).
	if (!str)
		return (NULL);

	// Retorna a string com o número convertido.
	return (str);
}

// Função auxiliar (ft_itoa_len) para contar o tamanho da string que vai receber o número convertido.
// Recebe como parâmetro a variável num do tipo long que é o número a ser convertido.
static size_t	ft_itoa_len(long num)
{
	// declara a variavel len.
	// len inicializa recebendo 0.
	size_t	len;
	len = 0;

	// Se a variavel (num) número for igual a 0 retorna 1. Porque o número 0 tem tamanho 1.
	// Ele tem tamanho 1 porque é um caractere.
	if (num == 0)
		return (1);

	// Se o número for menor que 0 incrementa len + 1 e inverte o sinal do número.
	// Obs: O incremento de len é para contar o sinal do número e a variável num recebe o valor
	// de - num para inverter o sinal de negativo para positivo.
	// Ex: -123 = -(-123) = 123.
	if (num < 0)
	{
		len++;
		num = -(num);
	}

	// Enquanto o número for maior ou igual a 1 incrementa len + 1 e divide o número por 10.
	// Obs: Isso é para contar a quantidade de digitos do número.
	// Obs_2: Ao invés de escrever num /= 10 poderia escrever num = num / 10.
	while (num >= 1)
	{
		len++;
		num /= 10;
	}

	// Retorna o tamanho da string.
	return (len);
}

// Função auxiliar (ft_num_to_str) para converter o número em string.
// Recebe como parâmetro o número a ser convertido, a string que vai receber o número convertido
// e o tamanho da string.
static char	*ft_num_to_str(long num, char *str, size_t len)
{
	// str recebe o valor da alocação de memória com o tamanho da string + 1.
	// Obs: O + 1 é para acomodar o caractere de terminação de string '\0'.
	// Obs_2: O calloc é uma função que aloca memória e preenche com 0.
	str = ft_calloc(len + 1, sizeof(char));

	// Se str for igual a 0 retorna NULL.
	// Obs: Isso é uma verificação para saber se a alocação de memória foi feita com sucesso para
	// proteger o programa de falhas de alocação de memória.
	// Obs_2: O if nao está entre chaves "{}" porque só tem uma linha.
	if (str == NULL)
		return (NULL);

	// Se o número for menor que 0 o primeiro caractere da string recebe o sinal de menos '-'.
	// E inverte o sinal do número ou seja a variavel (str) na posição 0 recebe o sinal de negativo.
	// E a variavel (num) (que está rmazenando um número negativo) recebe o valor de - num para
	// inverter o sinal de negativo para positivo.
	// Obs: Incluimos entao o sinal de negativo na string como caractere e invertemos o sinal do número.
	if (num < 0)
	{
		str[0] = '-';
		num = -(num);
	}

	// Decrementa o tamanho da string porque o primeiro caractere já foi preenchido com o sinal.
	len--;

	// Enquanto o tamanho da string for maior que 0. Eu poderia escrever (len > 0) ao invés de (len).
	while (len)
	{
		// O caractere da string na posição do tamanho recebe o resto da divisão do número por 10
		// mais o caractere '0'. Ele é preenchido do final para o início.
		// Obs: O resto da divisão por 10 é para pegar o último digito do número.
		// Obs_2: O caractere '0' é para converter o número em caractere.
		str[len] = (num % 10) + '0';

		// Divide o número por 10.
		num /= 10;

		// Decrementa o tamanho da string.
		len--;
	}

	// Se o primeiro caractere da string for diferente de '-' o primeiro caractere da string
	// recebe o resto da divisão do número por 10 mais o caractere '0'.
	// Obs: Isso é para adicionar o último digito do número na string.
	if (str[0] != '-')
		str[0] = (num % 10) + '0';

	// Retorna a string com o número convertido.
	return (str);
}
