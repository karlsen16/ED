ArvoreB* remover (ArvoreB *A, TIPO chave) {
  if(!vazia(A)) {
    /*caso 1*/
    /*Remoção de uma chave em um nó folha*/
    /*com T ou mais chaves. Apenas remove a chave*/
    if(A->folha) {
      if(pertence(A, chave))
        removeOrdenado(A, chave);
    }
    else {
      int indice = retornaIndice(A, chave);
      ArvoreB *tmp;
      /*casos 2*/
      /*Remoção de uma chave em nó interno*/
      if(pertence(A, chave)) {
        /*caso 2a*/
        /*Verifica se a maior chave a esquerda pode ser*/
        /*removida e substituir a chave que queremos remover*/
        tmp = herdeiroEsquerda(A, indice);
        if(elegivel(tmp)) {
          elevar(A, tmp, indice, tmp->n-1);
        }
        else {
          /*caso 2b*/
          /*Semelhante ao caso anterior, mas agora com a menor*/
          /*chave a direita*/
          tmp = herdeiroDireita(A, indice);
          if(elegivel(tmp)) {
            elevar(A, tmp, indice, 0);
          }
          /*caso 2c*/
          /*Não existe possíveis herdeiros, será necessário*/
          /*mesclar dois nós filhos e então remover a chave*/
          else {
            /*Caso 2c simples em que a chave a ser removida*/
            /*está em nó pai de folha com pelo menos T chaves*/
            if(A->filhos[indice]->folha && A->n > T-1) {
              ArvoreB *mesclado = mesclar(A->filhos[indice], A->filhos[indice+1]);
              if(indice == 0)
                A->filhos[indice+1] = mesclado;
              else
                A->filhos[indice] = mesclado;
              removeOrdenado(A, chave);
            }
            else {
              /*outros casos 2c*/
              /*Aqui entrariam mais dois casos 2c:*/
              /*a) nó da chave a ser removida tem T-1 chaves*/
              /*b)     "  "        " "     é pai de um nó interno*/
            }
          }
        }
      }
      /*A chave a ser removida não está em um nó interno*/
      else {
        /*casos 3*/
        /*Verifica o nó filho para saber se*/
        /*modificações são necessárias*/
        if(A->filhos[indice]->folha &&
          pertence(A->filhos[indice], chave) &&
          !elegivel(A->filhos[indice])) {
          /*caso 3a*/
          /*Um nó vizinho a esquerda ou a direita pode*/
          /*promover uma de suas chaves para o pai e*/
          /*o pai rebaixa uma das suas para o nó folha*/
          /*com a chave a ser removida*/
          int vizinho = verificaVizinhos(A, indice);
          /*A função verificaVizinhos retorna o indice do*/
          /*nó filho que tem T ou mais chaves ou -1 se*/
          /*nenhum for elegível*/
          if(vizinho != -1) {
            TIPO promovido;
            A->filhos[indice] = remover(A->filhos[indice], chave);
            if(vizinho > indice) {
              promovido = A->filhos[vizinho]->chaves[0];
              A->filhos[indice] = inserir(A->filhos[indice], A->chaves[indice]);
              A->chaves[indice] = promovido;
            }
            else {
              promovido = A->filhos[vizinho]->chaves[A->filhos[vizinho]->n-1];
              A->filhos[indice] = inserir(A->filhos[indice], A->chaves[indice-1]);
              A->chaves[indice-1] = promovido;
            }
            removeOrdenado(A->filhos[vizinho], promovido);
          }
          /*caso 3b simples*/
          /*Nenhum dos vizinhos podia emprestar uma de suas chaves*/
          /*então os dois vão ser unidos e a chave poderá ser removida*/
          else if(elegivel(A)) {
            int i;
            removeOrdenado(A->filhos[indice], chave);
            if(indice == 0 || indice == 1) {
              A->filhos[1] = inserir(A->filhos[1], A->chaves[0]);
              for(i = 0; i < A->filhos[0]->n; i++)
                A->filhos[1] = inserir(A->filhos[1], A->filhos[0]->chaves[i]);
              removeOrdenado(A, A->chaves[0]);
            }
            else {
              A->filhos[indice-1] = inserir(A->filhos[indice-1], A->chaves[indice-1]);
              for(i = 0; i < A->filhos[indice]->n; i++)
                A->filhos[indice-1] = inserir(A->filhos[indice-1], A->filhos[indice]->chaves[i]);
              removeOrdenado(A, A->chaves[indice-1]);
            }
          }
          else {
            /*outros casos 3b*/
            /*Aqui entraria o caso 3b em que o nó pai*/
            /*da folha com a chave a ser removida*/
            /*possui T-1 chaves*/
          }
        }
        /*Continua o caminho pela árvore*/
        else {
          A->filhos[indice] = remover(A->filhos[indice], chave);
        }
      }
    }
  }
  return A;
}
