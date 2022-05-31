#include <stdio.h>
#include <string.h>
#include "colaGrafo.h"
#define GRAPH_CAPACITY 32

typedef struct graph{
    int edges[GRAPH_CAPACITY][GRAPH_CAPACITY];
    char vertices[GRAPH_CAPACITY][20];
    int flag[GRAPH_CAPACITY];
    int size;
}Graph;

void initGraph(Graph *g);
int AddVertice(Graph *g, char vertice[20]);
int findVertice(Graph graph, char vertice[20]);
int AddEdge(Graph *g, char verticesource[20], char verticedestiny[20]);
void printgraph(Graph graph);
int full(Graph g);
int existR(Graph *graph, char vertice1[20], char vertice2[20]);
int deleteedge(Graph *g, char *v1, char *v2);
int deleteV(Graph *g, char *vertice);

void graphc(Graph *g);
void Flags(Graph *g);
void bfs(Graph *graph, char vertice[50]);

int main()
{
    Graph graph;
    int relacion;
    initGraph(&graph);
    graphc(&graph);
    printgraph(graph);

    printf("bfs1: ");
    bfs(&graph, "A");
    printf("\n");
    Flags(&graph);
    printf("bfs2: ");
    bfs(&graph, "B");
    int existe=existR(&graph, "A", "B");
    printf("\nHay relacion? (1-si, 0-no) %d", existe);
    int eliminar=deleteedge(&graph, "A", "B");
    printf("\nse elimino relacion? (1-si, 0-no) %d", eliminar);
    int eliminarv= deleteV(&graph, "F");
    printf("\nse elimino el vertice? (1-si, 0-no) %d\n\n", eliminarv);
    printgraph(graph);

}

//esta funcion esta bien
void initGraph(Graph *g)
{
    g->size = 0;
    Flags(g);
}
void graphc(Graph *g)
{

    AddVertice(g,"A");
    AddVertice(g,"B");
    AddVertice(g,"C");
    AddVertice(g,"D");
    AddVertice(g,"E");
    AddVertice(g,"F");

    AddEdge(g, "A", "B");
    AddEdge(g, "A", "D");
    AddEdge(g, "A", "E");
    AddEdge(g, "B", "C");
    AddEdge(g, "B", "E");
    AddEdge(g, "B", "F");

}
void Flags(Graph *g)
{
    for (int i=0; i< GRAPH_CAPACITY; i++)
    {
        g->flag[i]=0;
    }
}
//esta funcion esta bien
int AddVertice(Graph *g, char vertice[20])
{
if(g->size < GRAPH_CAPACITY)
{
    if(findVertice(*g, vertice) == -1 && (full(*g)!=-1))
        strcpy(g->vertices[g->size], vertice);
        for(int r=0; r< GRAPH_CAPACITY; r++)
        {
            g->edges[r][g->size]=0;
        }
        for(int c=0; c< GRAPH_CAPACITY; c++)
        {
            g->edges[g->size][c]=0;
        }
        g->size++;
    }
    return 1;
}

int findVertice(Graph graph, char vertice[20])
{
    int i;
    int result = -1;
    for(i=0;i < graph.size && result == -1; i++)
    {
        if (strcmp(graph.vertices[i], vertice)==0)
            result = i;
    }
    return result;
}
//esta funcion esta bien
int AddEdge(Graph *g, char verticesource[20], char verticedestiny[20])
{
    int possource = findVertice(*g, verticesource);
    int posdestiny = findVertice(*g, verticedestiny);

    if(possource != -1 && posdestiny != -1)
    {
        g->edges[possource][posdestiny]=1;
        g->edges[posdestiny][possource]=1;

        return 1;
    }
    return -1;
}

//esta funcion esta bien
void printgraph(Graph graph)
{
    printf("\t");
    for(int i=0; i< graph.size;i++)
    {
        printf("\t%s\t", graph.vertices[i]);
    }
    printf("\n");
    for(int r=0; r< graph.size; r++)
    {
        printf("%s  ", graph.vertices[r]);
        for(int c=0; c< graph.size;c++)
        {
            printf("\t\t%d", graph.edges[r][c]);
        }
        printf("\n");
    }
}
void bfs(Graph *graph, char vertice[50])
{
    Cola colaVertice;
    int posvertice= findVertice(*graph, vertice);
    char VerticeActual[50];
    inicializacion(&colaVertice);
    graph->flag[posvertice] = 1;
    insertar(&colaVertice, vertice);

    while(!estaVacia(colaVertice))
    {
        eliminar(&colaVertice, VerticeActual);
        posvertice= findVertice(*graph, VerticeActual);
        printf("%s", VerticeActual);
        for(int i=0; i< graph->size; i++) {
            if (posvertice != 1 && graph->edges[posvertice][i] == 1 && graph->flag[i]== 0)
            {
                graph->flag[i]=1;
                insertar(&colaVertice, graph->vertices[i]);
            }}}}
int deleteedge(Graph *g, char vertice1[20], char vertice2[20])
{
    int posVertice1= findVertice(*g, vertice1);
    int posVertice2= findVertice(*g, vertice2);
    if(g->edges[posVertice1][posVertice2]==1)
    {
        g->edges[posVertice1][posVertice2]==0;
        return 1;
    }
    else{
        return 0;
    }}
int deleteV(Graph *g, char *vertice)
{
    int aux= findVertice(*g, vertice);
    if(full(*g)==-1 && aux == -1)
        for(;aux< g->size-1;aux++)
        {
            strcpy(g->vertices[aux], g->vertices[aux+1]);
        }
        g->size--;
        return 1;
}
int existR(Graph *graph, char vertice1[20], char vertice2[20])
{
    int posVertice1= findVertice(*graph, vertice1);
    int posVertice2= findVertice(*graph, vertice2);
    for(int i=0; i< graph->size; i++)
    {
        if(posVertice1 !=1 && graph->edges[posVertice1][posVertice2]==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }}}
int full(Graph g)
{
    if(g.size==GRAPH_CAPACITY)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
//<>