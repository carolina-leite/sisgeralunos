# Sistema de Gerenciamento de Alunos

Cada aluno da disciplina possui as seguintes informações armazenadas:
• Nome (cujos caracteres não devem incluir acentos e cedilhas);
• RA (inteiro);
• Nota da primeira prova obrigatória (P1);
• Nota da segunda prova obrigatória (P2);
• Nota do trabalho prático (T);
• Nota da prova optativa (PO).

A média final MF é calculada de acordo com a seguinte fórmula:
MF = 0,35 * P1 + 0,35 * P2 + 0,3 * T,
sendo que a nota da prova optativa (PO) pode substituir a menor das notas de
prova (P1 ou P2), caso seja maior que tal nota. O aluno cuja média final for maior ou
igual a 6,0 será considerado aprovado, caso contrário, estará reprovado.

A aplicação fornece um menu com as seguintes funções:
1. Cadastrar um novo aluno: insere um novo aluno na lista contendo os dados
fornecidos como entrada pelo usuário.

2. Buscar aluno: solicita ao usuário uma cadeia de caracteres e lista os nomes
completos, a média final e a situação (aprovado ou reprovado) de todos os
alunos cujos nomes casam (total ou parcialmente com a cadeia fornecida). A
listagem mostra ao final uma contagem do número de resultados
encontrados;

3. Ler arquivo com listagem de alunos: solicita ao usuário o nome de um arquivo
de texto contendo os dados de alunos. Esse arquivo conterá os dados de, no
máximo, um aluno por linha e, em cada linha, todos os dados do aluno deverão
ser informados na mesma ordem descrita na descrição da estrutura que define
um aluno. Se o aluno não fez PO, o arquivo deve conter a nota zero no local
adequado. Ao final do cadastramento, exibe na tela uma contagem de quantos alunos 
foram cadastrados. 

4. Gerar arquivo com dados dos alunos aprovados, ordenados em ordem
alfabética: escreve um arquivo texto contendo os nomes, RAs e as médias finais
dos alunos aprovados na disciplina, um aluno por linha. Os alunos constantes
no arquivo resultante devem estar em ordem alfabética de nome. (OBS: caso
existam dois ou mais alunos com o mesmo nome, resolva o "empate" colocando
aquele que tem menor RA na frente). Ao final do arquivo, deve aparecer a
contagem de alunos aprovados. O nome do arquivo de saída deve ser
aprovados.txt.

5. Gerar arquivo com dados dos alunos reprovados, ordenados em ordem
alfabética: escreve um arquivo texto contendo os nomes e as médias finais dos
alunos reprovados na disciplina, um aluno por linha. Os alunos constantes no
arquivo resultante devem estar em ordem alfabética de nome. Ao final do
arquivo, deve aparecer a contagem de alunos reprovados. O nome do arquivo
de saída deve ser reprovados.txt. 

6. Fechar programa: encerra a execução do programa. Antes do encerramento,
salve todos os dados dos alunos armazenados no vetor em um arquivo de saída
chamado "atual.txt", colocando um aluno por linha, com os campos separados
por espaço.

*Trabalho acadêmico desenvolvido pela Aluna Ana Carolina durante a disciplina de Algoritmos e Programação 2, no ano de 2021.
