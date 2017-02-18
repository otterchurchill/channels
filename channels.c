#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

struct nodeS{
    bool isActive;
    int uid;
    int tempUid;
    int onehop;
    int twohops;
    struct stype *nextNode;    
};
typedef struct nodeS node;

struct channelS{
    int * queue;
    sem_t raceCondition;
    sem_t sync;
};

typedef struct channelS channel;


struct queNodeS {
    int * value;
    struct stype *next;
} queNodeS;

typedef struct queNodeS queNode;

 struct argsS{
    node * cNode;
    channel * cChannel;
    int cPhase;
    int cInd;
};

typedef struct argsS args;


void write(node * currNode, int value);
int read(channel * currChan);

void getIn(node * nodes){
    int atoiIN= 0, count = 0;
    node * oldNode = NULL;
    char *input = (char *) calloc(56,sizeof(char));
    while (fgets(input,5,stdin) != 0){
		node *  newNode = (node *)malloc(sizeof(node));
		int atoiIn = atoi(input);
		newNode->uid= atoiIn;
		if(count == 0){
		printf("Start %d \n", newNode->uid);
	  	  nodes = newNode;
		}
		else{
	   	   oldNode->nextNode = newNode;
		   printf("curr %d old %d \n", newNode->uid, oldNode->uid);
		}
		oldNode = newNode;
		count++;
	}
    	oldNode->nextNode = null;
}

void semIntit(channel * newC){
    sem_int(&(newC->raceCondition), 0, 1);
    sem_int(&(newC->sync), 0, 0);
}

void main(){
	node *  Nodes;
    	int nodeNum = getIn(Nodes);
	node nodeArr[nodeNum];
	channel channelArr[nodeNum];
	arg argArr[nodeNum];
	
	nodeArr[i] = nodes;
	node* currNode = nodes->nextNode;

	for(int i = 1; i < nodeNum; i++){
	    nodeArr[i] = currNode; 
	    currNode = currNode->nextNode;
	}	

	for(int i = 0; i < nodeNum; i++){
	    channelArr[i] = (channel*)malloc(sizeof(channel));
	    semIntit(channelArr[i]);
	}
	pthread_t threadIds[nodeNum];
	
	int phases = 0;
	
	int i =0;
	for(i = 0; i < nodeNum; i++)
	    argArr[i] = (arg*)malloc(sizeof(arg));
	    argArr[i]->cNode = nodeArr[i];
	    argArr[i]->cChannel = channelArr[i];
	    argArr[i]->cPhase = phase;
	    argArr[i]->cInd = i;
	    pthread_create(threadIds[i], NULL, (void *)makeThr, (void *)argArr[i]);
	    
	for(i=0; i < nodeNum; i++)
	    pthread_join(threadId[i],NULL);   
	phase+=1;

    
}



void write(node *currNode,int value){

    sem_wait(&(currChan->raceCondition));//wait(raceCon_sema)
	while(ptr != NULL){
	    prev= ptr
	    ptr= ptr->next;
	}
	
    node->nextNode->currChan->queue->prev->next= (node *)malloc(sizeof(node)); //put value on the queue
    node->nextNode->currChan->queue->prev->next->value = value; //put value on the queue
    sem_post(&(currChan->raceCondition));//post(race_condition_sema)
    sem_post(&(currChan->sync));//post(synchronization_sema)

}


int read(channel *currChan){
    sem_wait(&(currChan->sync)); //wait(sync_sema)
    sem_wait(&(currChan->raceCondition));//wait(raceCon_sema)
    int value = currChan->queue->value;//int value = remove value from the queue
    currChan->queue = currChan->queue->next;
    sem_wait(&(currChan->raceCondition));//post(raceCon_sema)
    return value; //return value;
}

void makeThr(void * arg){
    bool noLeader = true;
    while(noLeader){
	if(currNode-> isActive){//if Active
	    write(node,tuid);//write temp uid  !!!! Value?!
	    node->onehop = read(node)//read one hop temp uid
	    write(node,onehop)//write one hop temp uid
    

	    node->twohop = read(node->channel)//read two hop temp uid
	    if(onehop == currNode-> tuid){//if one hop temp uid == temp uid
		printf("Leader: %d \n", currNode->uid);//this node is the leader
		noLeader= false;
	    }
	    else if(onehop > twohop)//else if one hop tuid> two hop tuid && one hop tuid > tuid
	    //this node continues to be active
		currNode->tuid= onehop;//tuid = one hop tuid
    
	    //else
		currNode->isActive = false; //this node is a relay node
    
    }

    
	if(!currNode->isActive){//if Relay
	    read(channel);//read tuid
	    write(channel,value);//write tuid
	    read(channel);//read tuid
	    write(channl),value;//write tuid

	}

pthread_exit(1);
    }
}
