## Bit Masking

### O que é?

Bitmasking é a técnica de utilizar os bits de um número inteiro para guardar informações. Essa é uma técnica muito poderosa já que operações com bits são realizadas de maneira otimizada pelo processador, além disso, ela ajuda a economizar espaço já que ao invés utilizar um array ou um Set para manter os dados ela utiliza apenas um número.


### Inteiros:

Mas para começar a conhecer a bitmask primeiramente é necessário conhecer as características do tipos inteiros mais mais utilizados. A tabela a seguir mostram alguns dados importantes.

| Tipo              | Bytes | Bits | Menor Valor                | Maior Valor                |
|-------------------|-------|----------------|------------------------------|----------------------------|
| int               | 4     | 32              | -2,147,483,648             | 2,147,483,647              |
| unsigned int      | 4     | 32              | 0                          | 4,294,967,295              |
| long long         | 8     | 64              | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807  |
| unsigned long long | 8     | 64              | 0                          | 18,446,744,073,709,551,615 |

A primeira caracteristica a se observar é a quantidade de bits disponiveis, esse será o limitador da quantidade de dados que você poderá armazenar. Caso você utilize uma mascará para representar a presença ou não  de elementos em um conjunto, é obrigatório que o tamanho deste conjunto não seja maior que 60.

### Representando Conjuntos:

Na minha opinião a principal coisa a se entender sobre bitmask, é que os números entre 0 e $2^{n}$ vão incluir todas as possibilidades de conjuntos que podem existir com $n$ elementos. Por exemplo: O número 3 (0b11) indica a presença do elemento na posição 0 e na posição 1. O número 123(0b1111011) indica a presença dos elementos 0,1,3,4,5 e 6.O número $2^{7}$ (0b10000000) indica a presença do elemento 7, já o numero ${2^{7}-1}$ (0b1111111) indica a presença de todos os elementos de 0 à 6.

Então com uma mascara de bit você pode representar conjuntos, economizando espaço e economizando tempo de processamento. Outra vantagem é que você pode iterar sobre todas as possibilidades daquele conjunto apenas iterando entre  0 e $2^{n}$.  Mas tome cuidado com o TLE já que um conjunto com $n+1$ elementos terá o dobro das combinações da de tamanho $n$, causando uma explosão combinatoria rapidamente.

### Operações bitwise:

Agora que entendemos um pouco mais sobre o que é e para que serve bitmask, é importante saber como realizar as prinicipais operações binárias na sua linguagem de programação. Em C/C++ você utilizará os seguintes operadores.

- And,  mantém apenas os bits/elementos que estão presentes em ambos os números:

	`11 & 8 = 8`

- Or, mantém os bits/elementos que aparecem em pelo menos um dos números: 

	`11 | 8 = 11`

- Xor, mantém apenas o bits/elementos que aparecem em apenas um dos números: 
	
	`11 ^ 8 = 3`

- Not, estarão presentes apenas os bits/elementos que não aparecem no número:	

	`~ 11 = -12`

Obs: Como todos os bits vão ser invertidos inclusive os 0's à esquerda, o resultado da operação dependerá do tamanho do número inteiro e se se ele utiliza ou não o bit mais significativo para representar o sinal.
```
int: -12
unsigned int: 4294967284
long long: -12
unsigned long long: 18446744073709551604
```

- Deslocamento para esquerda (equivalente a uma multiplicação por **$2^{ i }$**):
```
    n << i = m 
    1 << 1 = 2
    1 << 2 = 4
    1 << 3 = 8
    ...
    1 << 31 = 2147483648
```
- Deslocamento para direita (equivalente a uma divisão inteira por **$2^{ i }$**):
```
    n >> i = m
    32 >> 1 = 16
    32 >> 2 = 8
    32 >> 3 = 4
    ...
    32 >> 6 = 0
```


### Operações de conjunto:

Abaixo estão listadas as principais operações que são utilizadas em máscaras que representam conjuntos.

- Adicionar elemento i ao conjunto:

```c++
	conjunto |= (1 << i);
```

- Remover elemento i do conjunto;

```c++
	conjunto &= ~(1 << i);
```

- Verificar se o elemento i está no conjunto:
	
```c++
	if(conjunto  & (1 << i))
```

- Obter interseção entre dois conjuntos:

```c++
	conjunto = conjuntoA & conjuntoB;
```	

- Obter união entre dois conjuntos:

```c++
	conjunto = conjuntoA | conjuntoB;
```

- Contar a quantidade de elementos no conjunto:
```c++
	qtd_elementos = __builtin_popcount(conjunto);

```

### Aplicando Bitmask:

Já que você viu as principais operações com bitmask, agora vamos aplicá-las em alguns problemas simples:

1. **Dada uma string S composta apenas de letras minusculas, imprima a quantindade de letras diferentes que são encontradas em S:**

Existem diversas formas de resolver esse problema de maneira eficiente, mas imagine uma solução utilizando Set. Nessa solução, provavelmente você irá iterar sobre a string, inserir os caracteres que aparecerem em um Set e, no final, a resposta será o tamanho do Set, como no código abaixo:

```c++

    string s;
    cin >> s;
    set<char> conjunto;
    for(int i = 0; i < s.size(); i++){
        conjunto.insert(s[i]); 
    }
    cout << conjunto.size() << endl;
```
Agora vamos fazer a análise de complexidade desse algoritmo. Dado que podemos aproximar a complexidade de inserção em um Set para $O(log(M))$, sendo $M$ o tamanho final do Set, e que a complexidade para iterar na string é $O(N)$, temos que a complexidade total do algoritmo é $O(Nlog(M))$.

Mas já que estamos utilizando uma solução baseada em conjuntos, podemos adaptar essa solução para utilizar Bitmask, como abaixo:

```c++
    string s;
    cin >> s;
    int conjunto = 0;
    for(int i = 0; i < s.size(); i++){
        int bit_idx = s[i] - 'a';
        conjunto |=  (1 << bit_idx);
    }
    cout << __builtin_popcount(conjunto) << endl;
```
Fazendo a análise de complexidade do algoritmo acima, temos que a complexidade de inserção em um conjunto representado por uma bitmask é $O(1)$, e a complexidade para percorrer a string é $O(N)$, portanto a complexidade final é $O(N)$. Então, apesar do código utilizando bitmask ser um pouco mais difícil, ainda há um ganho de desempenho em relação à solução com Set, onde, para alguns problemas, essa pode ser a diferença entre um TLE e um AC.

Então resumindo, caso você precise de uma solução que utilize conjuntos e que eles não sejam grandes ( <= 60), a melhor abordagem é utilizar bitmask!

**2. Iu Gy Ho possui um deck de cartas de um jogo que coincidentemente possui o mesmo nome que o dele(???). Devido a alguns traumas do passado Iu Gy não quer mostrar seu melhor deck em batalha, portanto ele irá jogar apenas com o subdeck com as I-ésima maior pontuação.**

**Os decks tem tamanho N (1<= N <= 10) e Iu Gy Ho irá escolher o I-ésimo (1 <= I <= $2^{n}$) subdeck mais poderoso. A força de um deck é igual a soma da força F(0 <= F <= 3000) de cada uma das cartas que compõe o deck.**

**Como resposta imprima a força do subdeck escolhido.**


Uma solução simples para esse problema é iterar sobre todas as possibilidades e ir adicionando a força de cada subdeck em um vector e no final ordena-lo e pegar o I-ésimo maior. Utilizando bitmask essa solução pode ser implementada assim:

```c++
    int n, i;
    cin >> n >> i;
    vector<int> forca(n);
    vector<int> forca_subdecks;

    for(int k = 0; k < n; k++)
        cin >> forca[k];
    
    for(int conjunto = 0; conjunto < (2 << n); conjunto++){
        int forca_atual = 0;
        for(int bit_idx = 0; bit_idx < n; bit_idx++)
            if(conjunto & (1 << bit_idx))
                forca_atual += forca[bit_idx];
        forca_subdecks.push_back(forca_atual);
    }
    
    sort(forca_subdecks.begin(), forca_subdecks.end(), greater<int>());
    cout << forca_subdecks[i-1] << endl;
```

Você entende que um número pode representar um conjunto, e que é fácil iterar sobre todas as combinações que ele pode assumir, assim como é facil de obter o valor total do conjunto. Para isso basta verificar quais elementos compõem o número e adicionar o valor inidividual de cada ao valor total.

### Problemas

[1791D - Distinct Split](https://codeforces.com/contest/1791/problem/D)

[1840B - Binary Cafe](https://codeforces.com/problemset/problem/1840/B)

[1553C - Penalty](https://codeforces.com/contest/1553/problem/C)

[1790E - Vlad and a Pair of Numbers](https://codeforces.com/contest/1790/problem/E)

[1829H - Don't Blame Me](https://codeforces.com/problemset/problem/1829/H)

Obs: A lista inclui problemas que envolvem bitmask ou apenas que envolvem operações bitwise. O objetivo é se familiarizar com ambas.
