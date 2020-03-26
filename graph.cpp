#include<stdio.h>
#include<stdlib.h>
struct Node { 
    struct Node*sag;
	struct Node*alt;
	int sagdk,altdk; 
	int total;
	int index1;
	int index2;
	char index[2];
	 
};
void graphMaker(int x,int y,Node*nodes[5][6]){
	for(int i=0; i<x;i++){
			nodes[i][0]=(struct Node*)malloc(sizeof(struct Node));
		for(int j=0;j<y;j++){
				nodes[i][j+1]=(struct Node*)malloc(sizeof(struct Node));
				nodes[i][j]->sag=nodes[i][j+1];
				nodes[i][j]->altdk=1;
				nodes[i][j]->sagdk=1;
				nodes[i][j]->total=9999;
				nodes[i][j]->index1=j;		
		}
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			nodes[i][j]->index2=i;
			nodes[i][j]->alt=nodes[i+1][j];
			
		}
	
	}		
}
char paths[2][10][127];
int sureler[127];
int sayac=0;
void pathfinder(Node*node,int a){
	Node*olasilik[2];
	
	
	
	if(node->sagdk!=-1){
		paths[0][(node->index1)+(node->index2)][sayac]=node->sag->index[0];
		paths[1][(node->index1)+(node->index2)][sayac]=node->sag->index[1];
		a+=node->sagdk;
		olasilik[0]=node->sag;
		pathfinder(olasilik[0],a);
	}
	
	if(node->altdk!=-1){
		paths[0][(node->index1)+(node->index2)][sayac]=node->alt->index[0];
		paths[1][(node->index1)+(node->index2)][sayac]=node->alt->index[1]; 
		olasilik[1]=node->alt;
		a+=node->altdk;
		if(node->sagdk!=-1)
		a-=node->sagdk;
		pathfinder(olasilik[1],a);
			
	}
	
	if(node->sagdk==-1&&node->altdk==-1){
		paths[0][0][sayac+1]=paths[0][0][sayac];
		paths[0][1][sayac+1]=paths[0][1][sayac];
		paths[0][2][sayac+1]=paths[0][2][sayac];
		paths[0][3][sayac+1]=paths[0][3][sayac];
		paths[0][4][sayac+1]=paths[0][4][sayac];
		paths[0][5][sayac+1]=paths[0][5][sayac];
		paths[0][6][sayac+1]=paths[0][6][sayac];
		paths[0][7][sayac+1]=paths[0][7][sayac];
		paths[0][8][sayac+1]=paths[0][8][sayac];
		paths[1][0][sayac+1]=paths[1][0][sayac];
		paths[1][1][sayac+1]=paths[1][1][sayac];
		paths[1][2][sayac+1]=paths[1][2][sayac];
		paths[1][3][sayac+1]=paths[1][3][sayac];
		paths[1][4][sayac+1]=paths[1][4][sayac];
		paths[1][5][sayac+1]=paths[1][5][sayac];
		paths[1][6][sayac+1]=paths[1][6][sayac];
		paths[1][7][sayac+1]=paths[1][7][sayac];
		paths[1][8][sayac+1]=paths[1][8][sayac];
		paths[1][9][sayac+1]=paths[1][9][sayac];
		sureler[sayac]=a;
		sayac++;
		a=0;
	}
	
}

void indexscaner(int alt,int sag,Node*node[5][6],int altdk,int sagdk,char num,char letter){

	node[sag][alt]->altdk=altdk;
	node[sag][alt]->sagdk=sagdk;
	node[sag][alt]->index[0]=letter;	
	node[sag][alt]->index[1]=num;
	
	
}

int main(){
	struct	Node*node[5][6];
	graphMaker(5,6,node);
	
indexscaner(0,0,node,1,1,'1','A');
indexscaner(1,0,node,2,2,'1','B');
indexscaner(2,0,node,1,1,'1','C');
indexscaner(3,0,node,2,1,'1','D');
indexscaner(4,0,node,1,2,'1','E');
indexscaner(5,0,node,1,-1,'1','F');
indexscaner(0,1,node,2,3,'2','A');
indexscaner(1,1,node,2,1,'2','B');
indexscaner(2,1,node,1,3,'2','C');
indexscaner(3,1,node,2,3,'2','D');
indexscaner(4,1,node,2,1,'2','E');
indexscaner(5,1,node,3,-1,'2','F');
indexscaner(0,2,node,2,1,'3','A');
indexscaner(1,2,node,1,2,'3','B');
indexscaner(2,2,node,1,1,'3','C');
indexscaner(3,2,node,1,3,'3','D');
indexscaner(4,2,node,1,1,'3','E');
indexscaner(5,2,node,3,-1,'3','F');
indexscaner(0,3,node,1,1,'4','A');
indexscaner(1,3,node,3,2,'4','B');
indexscaner(2,3,node,3,2,'4','C');
indexscaner(3,3,node,2,2,'4','D');
indexscaner(4,3,node,1,1,'4','E');
indexscaner(5,3,node,3,-1,'4','F');
indexscaner(0,4,node,-1,2,'5','A');
indexscaner(1,4,node,-1,2,'5','B');
indexscaner(2,4,node,-1,1,'5','C');
indexscaner(3,4,node,-1,1,'5','D');
indexscaner(4,4,node,-1,2,'5','E');
indexscaner(5,4,node,-1,-1,'5','F');

	pathfinder(node[0][0],0);
		
	for(int i =0;i<126;i++){
		printf("%d. yol: A1-",i+1);
	for(int j=0;j<9;j++){
		printf("%c%c-",paths[0][j][i],paths[1][j][i]);
	}
	printf(" = %d \n",sureler[i]);
}	
}
