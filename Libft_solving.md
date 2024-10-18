--> ft_toupper.c  <--
---------------------
== A funcao deve pegar os caracteres da tabela ascii de "a" a "z" minusculo e tranformar para maiusculo.
== Fazemos um filtro entao de 97 a 122 e subtraimos -32 que é a diferença entre as letras maiusculas de "A" a "Z".
== Exemplo: ascii 97 => "a" -32 => ascii 65 => "A".
== E ai retorna o resultado (c).
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
		return (c);
	}
	return (c);
}

---------------------

--> ft_tolower.c <--
--------------------
Segue o mesmo padrao acima, porém ao invés de 97 a 122, é 65 a 90 e ao invés de subtrair, somamos +32.
E ai retorna o resultado (c).

---------------------

--> ft_isprint.c <--
--------------------
== A função deve pegar todos os caracteres que são imprimiveis da tabela ascii (32 a 126).
== Sim, espaço é "imprimivel".
== E ai retorna o resultado (c).

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (c);
	}
	return (0);
}

---------------------

--> ft_isdigit <--
------------------
== A função deve pegar todos os caracteres da tabela ascii que são digitos (48 a 57).
== E ai retorna o resultado (c).

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (c);
	}
	return (0);
}

---------------------

--> ft_isascii <--
------------------
== Essa função retorna o valor se estiver dentro da tabela ascii.
== Se o valor estiver fora da tabela ascii, entao nao retorna nada e finaliza.

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

---------------------

--> ft_isalpha <--
------------------
== A função deve retornar 1 se o valor estiver dentro da tabela ascii de letras minusculas ou maiusculas (65 a 90 e 97 a 122).
== Caso contrario deve retornar 0;

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

---------------------

--> ft_isalnum <--
------------------
== A funcao deve pegar todos os caracteres (maiusculos e minusculos) e todos os numeros da tabela ascii.
== e ai retorna o resultado (c).

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
	{
		return (c);
	}
	return (0);
}

---------------------

--> ft_atoi <--
== Essa função converte ascii para inteiro (ascii to integer). Ele pega uma string de caracteres (ex: 1234) e converte em um numero inteiro do tipo int.
== Ela deve ignorar os espaçoes em branco no inicio da string de acordo com a tabela ascii (de 9 a 13 e ' ').
== Após isso a função verifica se o número é positivo ou negativo. Devemos tratar o sinal negativo para tranformar o numeto int em negativo também.
== Se não tiver sinal ou se tiver um +, tratamos ele como positivo.
== Mas se tiver um sinal em seguida do outro, devemos tratar como "caractere invalido" e parar a funcao (retornar 0).
== Assim como também devemos parar a funcao quando for encontrado letras ou outros caracteres que nao sejam numeros.
== Criamos uma variavel iterador, uma para o sinal e outra para o resultado final.
== O calculo do atoi funciona aqui. O Resultado recebe ele mesmo multiplicado por 10 para "percorrer" as casas decimais e somar o valor da string menos '0'.
== A string - '0' é o que pega o inteiro na tabela ascii.

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	result;

	i = 0;
	signal = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if ((str[i] + 1 == '+') || (str[i] + 1 == '-'))
			return (0);
		if (str[i] == '-')
		{
			signal = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (signal * result);
}

---------------------

--> ft_strncmp <--
------------------
== Esta função compara duas strings ate um numero N de caracteres.
== Se o N for maior que zero faz a comparacao, senao ja retorna 0 mesmo.
== Para fazer o comparativo, usamos a posicao do ponteiro para "ver" o caractere.
== Se eles forem diferentes, entao retorna a diferença entre os caracteres do ponteiro.
== É muito importante incluir unsigned char (para nao retornar valor negativo).
== Se a primeira string chegar ao final '\0' não tem mais necessidade de comparar, pois por conseqencia a string 2 sera maior do que a string 1.
== Entao é o momento de passar o ponteiro para as proximas "casas" incrementando ele.
== Também temos que decrementar o tamanho N até que chegue a 0.
== E ai repete o looping. Quando N chegar a 0 significa que as strings sao iguais e nao tem diferenca de retorno.

#include "libft.h"

int	ft_strncmp(const char *str_1, const char *str_2, size_t n)
{
	while ((n > 0))
	{
		if (*str_1 != *str_2)
			return ((unsigned char)*str_1 - (unsigned char)*str_2);
		if (*str_1 == '\0' || *str_2 == '\0')
			return (0);
		str_1++;
		str_2++;
		n--;
	}
	return (0);
}

---------------------

--> ft_strnstr <--
------------------
