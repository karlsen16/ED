#include "exercicios.h"
#include "grafos.h"

void exercicio1 () {
  int verticesGrafoMatriz = 6;
  GrafoM* grafoMatriz = criarGrafoMatriz (verticesGrafoMatriz);
  inicializaGrafoMat(grafoMatriz);
  adicionaArestaMatriz(0, 1, grafoMatriz, 1);
  adicionaArestaMatriz(0, 2, grafoMatriz, 1);
  adicionaArestaMatriz(0, 5, grafoMatriz, 1);
  adicionaArestaMatriz(1, 2, grafoMatriz, 1);
  adicionaArestaMatriz(1, 3, grafoMatriz, 1);
  adicionaArestaMatriz(2, 3, grafoMatriz, 1);
  adicionaArestaMatriz(2, 4, grafoMatriz, 1);
  adicionaArestaMatriz(3, 4, grafoMatriz, 1);
  adicionaArestaMatriz(4, 5, grafoMatriz, 1);
  imprimeGrafoMat(grafoMatriz);

  int verticesGrafoListaAdj = 6;
  GrafoA* grafoListaAdj = criarGrafoAdj (verticesGrafoListaAdj);
  adicionaArestaLista(0, 1, grafoListaAdj, 1);
  adicionaArestaLista(0, 2, grafoListaAdj, 1);
  adicionaArestaLista(0, 5, grafoListaAdj, 1);
  adicionaArestaLista(1, 2, grafoListaAdj, 1);
  adicionaArestaLista(1, 3, grafoListaAdj, 1);
  adicionaArestaLista(2, 3, grafoListaAdj, 1);
  adicionaArestaLista(2, 4, grafoListaAdj, 1);
  adicionaArestaLista(3, 4, grafoListaAdj, 1);
  adicionaArestaLista(4, 5, grafoListaAdj, 1);
  imprimeGrafoAdj(grafoListaAdj);

  liberarGrafoAdj (grafoListaAdj);
  liberarGrafoMatriz (grafoMatriz);
}

void exercicio2 () {
  int verticesGrafoMatriz = 6;
  GrafoM* grafoMatriz = criarGrafoMatriz (verticesGrafoMatriz);
  inicializaGrafoMat(grafoMatriz);
  adicionaArestaGrafoM(0, 1, grafoMatriz, 1);
  adicionaArestaGrafoM(0, 5, grafoMatriz, 1);
  adicionaArestaGrafoM(1, 2, grafoMatriz, 1);
  adicionaArestaGrafoM(1, 3, grafoMatriz, 1);
  adicionaArestaGrafoM(3, 2, grafoMatriz, 1);
  adicionaArestaGrafoM(2, 0, grafoMatriz, 1);
  adicionaArestaGrafoM(2, 4, grafoMatriz, 1);
  adicionaArestaGrafoM(4, 3, grafoMatriz, 1);
  adicionaArestaGrafoM(5, 4, grafoMatriz, 1);
  imprimeGrafoMat(grafoMatriz);

  int verticesGrafoListaAdj = 6;
  GrafoA* grafoListaAdj = criarGrafoAdj (verticesGrafoListaAdj);
  adicionaArestaGrafoA(0, 1, grafoListaAdj, 1);
  adicionaArestaGrafoA(0, 5, grafoListaAdj, 1);
  adicionaArestaGrafoA(1, 2, grafoListaAdj, 1);
  adicionaArestaGrafoA(1, 3, grafoListaAdj, 1);
  adicionaArestaGrafoA(3, 2, grafoListaAdj, 1);
  adicionaArestaGrafoA(2, 0, grafoListaAdj, 1);
  adicionaArestaGrafoA(2, 4, grafoListaAdj, 1);
  adicionaArestaGrafoA(4, 3, grafoListaAdj, 1);
  adicionaArestaGrafoA(5, 4, grafoListaAdj, 1);
  imprimeGrafoAdj(grafoListaAdj);

  liberarGrafoAdj (grafoListaAdj);
  liberarGrafoMatriz (grafoMatriz);
}

void exercicio3 () {
  int verticesGrafoMatriz = 6;
  GrafoM* grafoMatriz = criarGrafoMatriz (verticesGrafoMatriz);
  inicializaGrafoMat(grafoMatriz);
  adicionaArestaGrafoM(0, 1, grafoMatriz, 1);
  adicionaArestaGrafoM(0, 3, grafoMatriz, 5);
  adicionaArestaGrafoM(1, 3, grafoMatriz, 8);
  adicionaArestaGrafoM(3, 4, grafoMatriz, 3);
  adicionaArestaGrafoM(3, 3, grafoMatriz, 6);
  adicionaArestaGrafoM(2, 0, grafoMatriz, 5);
  adicionaArestaGrafoM(2, 3, grafoMatriz, 4);
  adicionaArestaGrafoM(4, 2, grafoMatriz, 7);
  adicionaArestaGrafoM(4, 5, grafoMatriz, 9);
  adicionaArestaGrafoM(5, 0, grafoMatriz, 2);

  imprimeGrafoMat(grafoMatriz);
  listaNumeroArestasIncidentesMatriz(3, grafoMatriz);
  listaNumeroArestasSaemMatriz(4, grafoMatriz);
  listaVerticesAdjacentesMatriz(2, grafoMatriz);

  int verticesGrafoListaAdj = 6;
  GrafoA* grafoListaAdj = criarGrafoAdj (verticesGrafoListaAdj);
  adicionaArestaGrafoA(0, 1, grafoListaAdj, 1);
  adicionaArestaGrafoA(0, 3, grafoListaAdj, 5);
  adicionaArestaGrafoA(1, 3, grafoListaAdj, 8);
  adicionaArestaGrafoA(3, 4, grafoListaAdj, 3);
  adicionaArestaGrafoA(3, 3, grafoListaAdj, 6);
  adicionaArestaGrafoA(2, 0, grafoListaAdj, 5);
  adicionaArestaGrafoA(2, 3, grafoListaAdj, 4);
  adicionaArestaGrafoA(4, 2, grafoListaAdj, 7);
  adicionaArestaGrafoA(4, 5, grafoListaAdj, 9);
  adicionaArestaGrafoA(5, 0, grafoListaAdj, 2);

  imprimeGrafoAdjPonderado(grafoListaAdj);
  listaNumeroArestasIncidentesAdj(3, grafoListaAdj);
  listaNumeroArestasSaemAdj(4, grafoListaAdj);
  listaVerticesAdjacentesAdj(2, grafoListaAdj);

  liberarGrafoAdj (grafoListaAdj);
  liberarGrafoMatriz (grafoMatriz);
}

void exercicio4 () {

}
