#include <iostream>
using namespace std;

class Hash {
	private: 
		int FuncaoHash(Aluno aluno);
		int max_itens;
		int max_posicoes;
		int quant_itens;
		Aluno* estrutura;
	
	public:
		Hash(int tam_vetor, int max);
		~Hash();
		bool estaCheio();
		int obterTamanhoAtual();
		void inserir(Aluno aluno);
		void deletar(Aluno aluno);
		void buscar(Aluno& aluno, bool &busca);
		void imprimir();
};

Hash::FuncaoHash (Aluno aluno) {
	return (aluno.obterRa() % max_posicoes);
}

Hash::Hash (int tam_vetor, int max) {
	quant_itens = 0;
	max_itens = max;
	max_posicoes = tam_vetor;
	estrutura = new Aluno[tam_vetor];
}

Hash::~Hash () {
	delete [] estrutura; 
}

Hash::estaCheio () {
	return (quant_itens == max_itens);
}

Hash::obterTamanhoAtual () {
	return (quant_itens);
}

Hash::inserir (Aluno aluno) {
	int local = FuncaoHash(aluno);
	estrutura[local] = aluno;
	quant_itens++;
}

Hash::deletar (Aluno aluno) {
	int local = FuncaoHash(aluno);
	if (estrutura[local].obterRa() != -1) {
		estrutura[local] = Aluno(-1, " ");
		quant_itens--;
	}
	
}

void Hash::buscar (Aluno& aluno, bool& busca) {
	int local = FuncaoHash(aluno);
	Aluno aux = estrutura[local];
	if (aluno.obterRa() != aux.obterRa()) {
		busca = false;
	} else {
		busca = true;
		aluno = aux;
	}
	
}

void Hash::imprimir () {
	cout << "Tabela Hash:" << endl;
	for (int i = 0; i < max_itens; i++)
	{
		for (estrutura[i] != -1)
		{
			cout << i << ":" << estrutura[i].obterRa;
			cout << estrutura[i].obterNome() << endl;
		}
	}
}

//----------------------------------------------------------------------

class Aluno {
	private:
		int ra;
		string nome;
		
	public:
		Aluno();
		Aluno(int r, string n);
		int obterRa();
		string obterNome();
};

Aluno::Aluno() {
	ra = -1;
	nome = " ";
}

Aluno::Aluno(int r, string n) {
	ra = r;
	nome = n;
}

Aluno::obterRa() {
	return ra;
}

Aluno::obterNome () {
	return nome;
}

int main()
{
	
	return 0;
}

