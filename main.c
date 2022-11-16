#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int a;
	int fils[99999];
}arbre;
typedef struct{
	int *a;
	struct frere *fils;
}arbre_bin;
typedef struct{
   arbre ar;
   struct frere *f;
}frere;
arbre *noeud(arbre *l,int n,int m){
	int j,i;
	printf("\n==================REMARQUE===========================\n");
	printf("Si le neud n'a pas de fils entrez (-1).");
	printf("\n=====================================================\n");
	 for(i=0;i<n;i++){
	 	if(i==0){
	 	printf("\n Donnez l'information de la racine:");
	 	scanf("%d",&l[i].a);	
		 }
		else{
	 	printf("\n Donnez l'information du neud No(%d):",i);
	 	scanf("%d",&l[i].a);
	 }
	 	for(j=0;j<m;j++){
	 		printf("Donnez le fils No(%d) du neud(%d) :",j+1,i);
	 		scanf("%d",&l[i].fils[j]);
		 }
	}
	 return l;
}
void aff(arbre *l,int n,int m){
	int i,j,v;
	printf("La racine = %d \n",l[0].a);
    printf("Les fils de la racine sont :\n");
	for(i=0;i<m;i++){
      v=l[0].fils[i];
	  if(v!=-1) printf("\t %d",l[v].a);
	  else printf("\nLa racine n'a pas le fils No(%d).\n",i+1);
	}
	 for(i=1;i<n;i++){
	 	printf("\n___________________________________________________\n");
	 	printf("\nLes fils de (%d) sont : \n",l[i].a);
	 	for(j=0;j<m;j++){
         v=l[i].fils[j];
	     if(v!=-1) printf("\t %d",l[v].a);
	     else printf("\nLe noeud n'a pas le fils No(%d).\n",j+1);
		 }
	 }	
}
frere *creer_liste(frere *new,arbre *l,int k){
	frere *nouv,*p,*pt;
	nouv=(frere*)malloc(sizeof(frere));
	nouv->ar.a=l[k].a;
	nouv->f=NULL;
	if(new==NULL){
	 return nouv;
	}
	else{
	 p=new;
	 while(p->f!=NULL){
	 	p=p->f;
	 }
	 p->f=nouv;
	 return nouv;
	}
}
void aff_liste(frere *l){
	frere *p;
	int i=0;
	p=l;
	while(p!=NULL){
		printf("\t/ %d",p->ar.a);
	p=p->f;
	}
}
arbre_bin *passage(arbre *l,int i,int n,int m){
	arbre_bin *nouv;
	frere *p;
	int j;
    if(i<n){
	nouv=(arbre_bin*)malloc(sizeof(arbre_bin));
    nouv->a=&l[i].a;
    nouv->fils=NULL;
    printf("\nLe noeud:%d\n",*(nouv->a));
    if(l[i].fils[0]!=-1) printf("Son fils :%d \t Les frere du fils:",l[l[i].fils[0]]);
    if(l[i].fils[0]!=-1) nouv->fils=creer_liste(nouv->fils,l,l[i].fils[0]);
    p=nouv->fils;
    for(j=1;j<m;j++){
    if(l[i].fils[j]!=-1) nouv->fils=creer_liste(nouv->fils,l,l[i].fils[j]);
	}
	aff_liste(p);
	return nouv;
	}
}
/*void aff_arbre_bin(arbre_bin *l){
   arbre_bin *pp;
	frere *pt,*p;
    pp=l;
    p=pp->fils;
    pt=l;
    while(pp!=NULL){
    	printf("\nLe noeud:%d\n",*(pp->a));
    	printf("Son fils :%d \t Les frere du fils:",p->ar.a);
    	aff_liste(p);
		pp=pp->fils;
		p=pp->fils;
    	while(pt->f!=NULL){
    		pt=pt->f;
    		aff_arbre_bin(pt);
		}
		pt=pp;
	}
}*/
int main() {
	arbre *t;
	arbre_bin *h,*mm;
	int m,i,n;
	printf("Donnez la taille de l'arbre:");
	scanf("%d",&n);
	printf("Donnez l'ordre de l'arbre:");
	scanf("%d",&m);
	t=(arbre*)malloc(n*sizeof(arbre));
	mm=(arbre_bin*)malloc(n*sizeof(arbre_bin));
	t=noeud(t,n,m);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	aff(t,n,m);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    int v=t[0].fils[0];
//	printf("%d",&t[v]);
	mm=passage(t,0,n,m);
	h=mm;
	for(i=1;i<n;i++){
	mm=passage(t,i,n,m);
	}
	aff_arbre_bin(h);
}
