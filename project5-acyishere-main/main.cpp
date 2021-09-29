#include<iostream>
#include<cstring>

using namespace std;

int main(int argc, char* argv[]){

	FILE*  inFile = fopen(argv[1],"r");
	FILE* outFile = fopen(argv[2],"w");

	int ind; // number of individuals
	fscanf(inFile,"%d",&ind);

	int parents[ind+1][20]; // parents[i][j] represents the 2^j th ancestor of ith id.
	memset(parents,0,sizeof parents);
	for(int i=0;i<ind;i++){
		int x;
		fscanf(inFile,"%d",&x);
		parents[i+1][0]=x+1;
	}

	for(int j=1;j<20;j++)
		for(int i=1;i<=ind;i++)
			parents[i][j] = parents[parents[i][j-1]][j-1];
		int Q;
		fscanf(inFile,"%d",&Q);

	while(Q--){
		int x,y;
		fscanf(inFile,"%d%d",&x,&y);
		x++;
		for(int i=0;i<20;i++)
			if(y&(1<<i))
				x=parents[x][i];
		fprintf(outFile,"%d\n",x-1);
	}
}
