#include<stdio.h>
#include<queue>
using namespace std;
struct Node{
    int x,y,z;
}node;

bool inq[2000][200][65]={false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={1,-1,0,0,0,0};
int Z[6]={0,0,1,-1,0,0};
int m,n,l,t;
int martrix[2000][200][64];
int sum=0;

bool juge(int x,int y,int z){
    if(x>=m||x<0||y>=n||y<0||z>=l||z<0) return false;
    if(martrix[x][y][z]==0||inq[x][y][z]==true) return false;
    return true;
}

int BFS(int x,int y,int z){
    int ans=0;
    queue<Node> q;
    node.x=x,node.y=y,node.z=z;
    q.push(node);
    inq[x][y][z] = true;
    while(!q.empty()){
        Node now = q.front();
        q.pop();
        ans++;
        for(int i=0;i<6;i++){
            int newX = now.x+X[i];
            int newY = now.y+Y[i];
            int newZ = now.z+Z[i];
            if(juge(newX,newY,newZ)){
                node.x=newX,node.y=newY,node.z=newZ;
                q.push(node);
                inq[newX][newY][newZ]=true;
            }
        }
    }
    if(ans>=t) return ans;
    else return 0;
}

int main(){
    scanf("%d%d%d%d",&m,&n,&l,&t);
    for(int z=0;z<l;z++)
        for(int x=0;x<m;x++)
        for(int y=0;y<n;y++)
        scanf("%d",&martrix[x][y][z]);
    for(int z=0;z<l;z++)
        for(int x=0;x<m;x++)
    for(int y=0;y<n;y++){
        if(martrix[x][y][z]==1&&inq[x][y][z]==false){
         sum+=BFS(x,y,z);
        }
    }
    printf("%d",sum);
    return 0;
}
