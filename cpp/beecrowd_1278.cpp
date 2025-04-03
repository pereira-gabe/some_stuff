#include <bits/stdc++.h>

using namespace std;  //beecrowd exercise

int main(){
    int casos, indice = 0, maiorString = 0;
    cin >> casos;

    string entrada, palavra;
    string saida[casos];

    cin.ignore();  // ignorar o '\n' que fica no buffer (aprendi com deepseek)

    if (casos > 0){
        for (int i = 0; i < casos; i++){  
            getline(cin, entrada);

            stringstream ss(entrada);  // lembrar dessa biblioteca para depois

            while (ss >> palavra){  
                saida[indice] += palavra + " "; 
            }

            if (saida[indice].size() > maiorString){
                maiorString = saida[indice].size();
            }

            indice++;  
        }

        //provavelmente tem um jeito menos idiota de fazer esse código inteiro e especialmente essa parte, mas isso é o que temos pra hoje
   
        indice = 0;

        /*
        for (string s : saida){
            cout << s;
        }
        */
        
        for (int i = 0; i < casos; i++){
            int espacos = maiorString - saida[i].size();

            if (espacos > 0)
            {
                saida[i].insert(0, espacos, ' ');
            }
            
            cout << saida[i] << endl;
        }

        //cout << maiorString << endl;
    }   

    return 0;
}

// atualizacao 03/04/2025, o codigo de cima nao passa no beecrowd apesar de funcionar nos meus casos de teste 
//e eu nao consegui arrumar essa logica burra entao o codigo certo ta comentado aqui embaixo, MAS AINDA ASSIM DA PRESENTATION ERROR

#include <bits/stdc++.h>

using namespace std;

int main() {
    bool primeiroCaso = true;

    while (true) {
        int N;
        cin >> N;

        if (N == 0) {
            break;
        }

        cin.ignore();

        vector<string> linhas(N);
        int comprimentoMaximo = 0;

        for (int i = 0; i < N; i++) {
            getline(cin, linhas[i]);

            string linhaTrimmed = "";
            bool emEspaco = false;
            for (char c : linhas[i]) {
                if (c == ' ') {
                    if (!emEspaco && linhaTrimmed.length() > 0) {
                        linhaTrimmed += ' ';
                    }
                    emEspaco = true;
                } else {
                    linhaTrimmed += c;
                    emEspaco = false;
                }
            }

            linhas[i] = linhaTrimmed;
            comprimentoMaximo = max(comprimentoMaximo, (int)linhas[i].length());
        }

        if (!primeiroCaso) {
            cout << endl;
        }
        primeiroCaso = false;

        for (const string &linha : linhas) {
            int espacosParaAdicionar = comprimentoMaximo - linha.length();
            cout << string(espacosParaAdicionar, ' ') << linha << endl;
        }
    }

    return 0;
}
