#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *top=NULL;
struct node *temp=NULL;
struct node *front=NULL;
struct node *rear=NULL;

void stack_ekleme(int veri){
	struct node *yeni=(struct node*) malloc(sizeof(struct node));
	yeni->data=veri;
	
	if(top==NULL){
		top=yeni;
		top->next=NULL;
	}
	else{
		yeni->next=top;
		top=yeni;
	}	
}

void stack_yazdir(){ 
	if(top==NULL) 
		printf("stack bos");
	else{
		printf("\n STACK \n");
		temp=top;
		while(temp->next!=NULL){
			printf("%d ->",temp->data);
			temp=temp->next;
		}
		printf("%d \n",temp->data);
	}	
}

void queue_ekleme(int veri){
	
	struct node *yeni=(struct node *) malloc(sizeof(struct node));
	yeni->data=veri;
	yeni->next=NULL;
	if(front==NULL){
		yeni->next=NULL;
		front=rear=yeni;
	}
	else{
		yeni->next=NULL;
		rear->next=yeni;
		rear=yeni;
	}
}

void queue_yazdir(){
	printf("QUEUE: ");	
	if(front==NULL)
		printf("kuyruk bos\n");		
	else{
		temp=front;
		while(temp->next!=NULL){
			printf("%d ->",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
	}
}

void bul_sil_stack(int aranan){
	struct node *onceki=NULL;
	struct node *sonraki=NULL;
	temp=top;
	if(temp->data==aranan){
		top=top->next;
		free(temp);
	}
	
	else{
		if(temp->next->next!=NULL){
			while(temp->next->data!=aranan)
				temp=temp->next;
		onceki=temp;
		sonraki=temp->next->next;
		free(temp->next);
		onceki->next=sonraki;
	}
		else{
			free(temp->next);
			temp->next=NULL;
		}
	}
}

void bul_sil_queue(int aranan){
	struct node *onceki=NULL;
	struct node *sonraki=NULL;
	temp=front;
	if(temp->data==aranan){
		front=front->next;
		free(temp);
	}
	
	else{
		if(temp->next->next!=NULL){
			while(temp->next->data!=aranan)
				temp=temp->next;
		onceki=temp;
		sonraki=temp->next->next;
		free(temp->next);
		onceki->next=sonraki;
	}
		else{
			free(temp->next);
			temp->next=NULL;
		}
	}
}

void bul_goster_stack(int aranan,int sayac){
	temp=top;
	while(temp->data!=aranan){
		sayac++;
		temp=temp->next;
	}
	 printf("%d %d.dugumdedir.\n",aranan,sayac);
		
}

void bul_goster_queue(int aranan,int sayac){
	temp=front;
	while(temp->data!=aranan){
		sayac++;
		temp=temp->next;
	}
	 printf("%d %d.dugumdedir.\n",aranan,sayac);
}

int main(){
	int sayi,aranan,secim,secim2,secim3,sayac=1;
		printf("1->stack islem\n");
		printf("2->queue islem\n");
		scanf("%d",&secim);
		switch(secim){
			case 1:
				while(1){
				printf("1->ekle\n");
				printf("2->bul ve sil\n");
				printf("3->bul ve goster\n");
				printf("4->tumunu listele\n");
				printf("5->cikis\n");
				scanf("%d",&secim2);
				switch(secim2){
					case 1:
						printf("sayi: ");
						scanf("%d",&sayi);
						stack_ekleme(sayi);
						break;
					case 2:
						printf("aranan: ");
						scanf("%d",&aranan);
						bul_sil_stack(aranan);
						break;
					case 3:
						printf("aranan: ");
						scanf("%d",&aranan);
						bul_goster_stack(aranan,sayac);
						break;	
					case 4:
						stack_yazdir();
						break;
					case 5:
						return 0;	
				}
			}
			case 2:
				while(1){
				printf("\n1->ekle\n");
				printf("2->bul ve sil\n");
				printf("3->bul ve goster\n");
				printf("4->tumunu listele\n");
				printf("5->cikis\n");
				scanf("%d",&secim3);
				switch(secim3){
					case 1:
						printf("sayi: ");
						scanf("%d",&sayi);
						queue_ekleme(sayi);
						break;
					case 2:
						printf("aranan: ");
						scanf("%d",&aranan);
						bul_sil_queue(aranan);
						break;
					case 3:
						printf("aranan: ");	
						scanf("%d",&aranan);
						bul_goster_queue(aranan,sayac);
						break;
					case 4:
						 queue_yazdir();
						 break;
					case 5:
						return 0;	 	
				}
			}
		}
}
