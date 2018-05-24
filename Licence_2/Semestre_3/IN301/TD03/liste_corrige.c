#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUT 0
#define FIN 1
#define TRIE 2


struct elem{
	int val;
	struct elem *suiv;
};

typedef struct elem* liste;


struct elem_liste{
	liste l;
	struct elem_liste *suiv;
};

typedef struct elem_liste* liste_liste;


//Genere un entier entre 0 et n
int alea(int n)
{
	return rand()%(n+1);
}
liste creer_liste(){return NULL;}

int est_vide(liste l)
{
	if(l == NULL)
		return 1;
	return 0;
}

void affiche_liste(liste l)
{
	
	if(est_vide(l))
	{
		printf("La liste est vide \n");
		return;
	}
	while(l)
	{
		printf("%d ",l->val);
		l = l->suiv;
	}
	printf("\n");
}

liste libere_liste(liste l)
{
	liste tmp;
	while(l)
	{
		tmp = l->suiv;
		//printf("libération de %d\n",l->val);
		free(l);
		l = tmp;
	}
	return NULL;
}
liste ajoute_elem_debut(liste l,int i)
{
	liste new = malloc(sizeof(struct elem));
	new->val = i;
	new->suiv = l;
	return new;
}

liste ajoute_elem_fin(liste l, int i)
{
	liste new = malloc(sizeof(struct elem));
	new->val = i;
	new->suiv = NULL;
	if(est_vide(l))
	{
		return new;
	}
	liste debut = l;
	//on place le pointeur sur le dernier element de la liste
	while(l->suiv)
		l = l->suiv;
	l->suiv = new;
	return debut;
}

liste ajoute_elem_trie(liste l,int i)
{
	liste new = malloc(sizeof(struct elem));
	new->val = i;
	if(est_vide(l))//la liste est vide
	{
		new->suiv = NULL;
		return new;
	}

	if(l->val > i)//insertion au debut
	{
		new->suiv = l;
		return new;
	}
	liste debut = l;
	//on sarrête soit quand on est au bout, soit quand on doit ajouter l'element
	while(l->suiv)
	{
		if(l->suiv->val > i)//insertion au milieu
		{
			new->suiv = l->suiv;
			l->suiv = new;
			return debut;
		}
		l = l->suiv;
	}
	//Si on arrive la, c'est qu'on est à la fin.
	l->suiv = new;
	new->suiv = NULL;
	return debut;
}
liste generer_liste(liste l,int Nmax, int mode)
{
	int nombre_tire;
	do{
		nombre_tire = alea(Nmax);
		switch(mode)
		{
			case 0:
				l = ajoute_elem_debut(l,nombre_tire);
			break;
			case 1:
				l = ajoute_elem_fin(l,nombre_tire);
			break;
			default: 
				l = ajoute_elem_trie(l,nombre_tire);
		}

	}while(nombre_tire != 0);
	return l;
}
int compte_elems(liste l)
{
	if(est_vide(l))return 0;
	int compteur = 1;
	while(l->suiv)
	{
		compteur++;
		l = l->suiv;
	}
	return compteur;
}

//renvoi l'indice du premier element qui à la valeur val dans la liste
int recherche_elem(liste l, int i){

	if(est_vide(l))return -1;
	int compteur = 0;
	while (l->suiv){
		if (i == l->val)
			return compteur;
		
		compteur ++;
		l = l->suiv;
	}
	//Test du dernier élément
	if(i == l->val)
		return compteur;
	return -1;
}

//supprime l'element d'indice i
liste supprime_elem(liste l, int i)
{
	if(est_vide(l))return l;
	//Premier element
	liste tmp;
	if(i == 0)
	{
		tmp = l->suiv;
		free(l);
		return tmp;
	}
	liste debut = l;
	int compteur = 0;
	while(l->suiv->suiv)
	{
		if(compteur == i-1)
		{
			tmp = l->suiv;
			l->suiv = l->suiv->suiv;
			free(tmp);
			return debut;
		}
		compteur++;
		l = l->suiv;
	}
	//cas du dernier element
	if(compteur == i-1)
	{
		tmp = l->suiv;
		l->suiv = NULL;
		free(tmp);
	}
	return debut;
	
}

//retourne l1.l2
liste concatener_listes(liste l1, liste l2)
{
	liste debut = l1;
	while(l1->suiv)
		l1 = l1->suiv;
	l1->suiv = l2;
	return debut;
}

liste entrelacer_tries(liste l1, liste l2)
{

	if(est_vide(l1))return l2;
	if(est_vide(l2))return l1;
	liste retour;
	if(l1->val < l2->val)
	{
		retour = l1;
		l1 = l1->suiv;
	}
	else
	{
		retour = l2;
		l2 = l2->suiv;
	}
	liste tmp = retour;
	while((l1 != NULL) && (l2 != NULL))
	{
		if(l1->val < l2->val)
		{
			tmp->suiv = l1;
			l1 = l1->suiv;
		}
		else
		{
			tmp->suiv = l2;
			l2 = l2->suiv;
		}
		tmp = tmp->suiv;
	}
	if(l1)
	{
		tmp->suiv = l1;
	}
	else
	{
		tmp->suiv = l2;
	}
	return retour;

}
liste tri_a_bulles(liste l)
{
	int taille = compte_elems(l);
	if(taille < 2)return l;
	int i,j;
	liste debut = l;
	liste tmp;
	for(i=taille-1;i>0;i--)
	{
		l = debut;
		if(l->val > l->suiv->val)
		{
			tmp = l->suiv;
			l->suiv = l->suiv->suiv;
			tmp->suiv = l;
			debut = tmp;
			l=debut;
		}
		for(j=0;j<i-1;j++)
		{
			if(l->suiv->val > l->suiv->suiv->val)
			{
				tmp = l->suiv;
				l->suiv = l->suiv->suiv;
				tmp->suiv = l->suiv->suiv;
				l->suiv->suiv = tmp;
			}
			l = l->suiv;
		}
	}
	return debut;
}

liste renverse(liste l)
{
	liste tmp;
	liste last = NULL;
	while(l->suiv)
	{
		tmp = l->suiv;
		l->suiv = last;
		last = l;
		l = tmp;
	}
	l->suiv = last;
	return l;

}
liste tri_fusion(liste l,int taille)
{

	int g = taille/2;
	liste debut = l;
	liste l2;
	int i;
	if(g>=1)
	{
		for(i=0;i<g-1;i++)
		{
			l = l->suiv;
		}
		l2 = l->suiv;
		l->suiv = NULL;
		if(taille-g == 1)
		{
			return(entrelacer_tries(debut,l2));
		}
		else
		{
			return(entrelacer_tries(tri_fusion(debut,g),tri_fusion(l2,taille-g)));	
		}
		
	}
	else
	{
		return l;
	}
}

liste crible_era(int n)
{
	int i;
	liste l = creer_liste();
	for(i=n;i>1;i--)
	{	
		l = ajoute_elem_debut(l,i);
	}
	liste debut = l;
	liste parcours;
	liste tmp;
	while(l->suiv)
	{
		parcours = l;
		while(parcours->suiv)
		{
			if(!(parcours->suiv->val % l->val))//divisible par l->val
			{
				tmp = parcours->suiv;
				parcours->suiv = parcours->suiv->suiv;
				free(tmp);
			}
			parcours = parcours->suiv;
			if(parcours == NULL)break;
		}
		l = l->suiv;
	}
	return debut;
}

liste_liste creer_liste_liste(int k)
{
	int i;
	liste_liste new,tmp;
	tmp = NULL;
	for(i=0;i<k;i++)
	{
		new = malloc(sizeof(struct elem_liste));
		new->l=NULL;
		new->suiv =tmp;
		tmp = new;
	}
	return new;
}
liste_liste ajoute_elem_classement(liste_liste liste,int val,int k)
{
	liste_liste debut = liste;
	int i;
	for(i=0;i<val%k;i++)liste = liste->suiv;
	liste->l = ajoute_elem_trie(liste->l,val);
	return debut;
}
void affiche_liste_liste(liste_liste liste, int k)
{
	int i;
	for(i=0;i<k;i++)
	{
		printf("Elements modulo k = %d : ",i);affiche_liste(liste->l);
		liste = liste->suiv;
	}
}
liste_liste libere_liste_liste(liste_liste liste,int k)
{
	int i;
	liste_liste tmp;
	for(i=0;i<k;i++)
	{
		tmp = liste->suiv;
		libere_liste(liste->l);
		free(liste);
		liste = tmp;
	}
	return NULL;
}
int main(){

	srand(time(NULL));//initialisation de la graine
	liste l = creer_liste();
	affiche_liste(l);
	int Nmax = 20;
	
	printf("Création d'une liste en ajoutant les éléments au début :\n");
	l = generer_liste(l,Nmax,DEBUT);
	affiche_liste(l);

	printf("On vide la liste.\n");
	l = libere_liste(l);
	affiche_liste(l);

	printf("Création d'une liste en ajoutant les éléments à la fin :\n");
	l = generer_liste(l,Nmax,FIN);

	printf("On vide la liste.\n");
	l = libere_liste(l);
	affiche_liste(l);

	printf("Création d'une liste en ajoutant les éléments triés :\n");
	l = generer_liste(l,Nmax,TRIE);
	affiche_liste(l);

	printf("La liste contient %d elements\n\n",compte_elems(l));

	int x= 0;
	char reponse = 'a';
	int position;
	while(x != -1)
	{
		printf("Recherchez un élément positif (-1 stop) : ");scanf("%d",&x);
		if(x == -1)break;
		position = recherche_elem(l,x);
		if(position == -1)
		{
			printf("L'élement %d n'est pas dans la liste.\n",x);
		}
		else
		{
			printf("L'élement %d est à la position %d dans la liste.\n",x,position);
			reponse = 'a';
			while((reponse != 'o') && (reponse != 'n'))
			{
				printf("Voulez vous supprimer l'élément à la position %d de votre liste ?(o/n) ",position);scanf("%s",&reponse);
				if(reponse == 'o')
				{
					l = supprime_elem(l,position);	
				}
			}
			printf("La liste contient %d elements\n",compte_elems(l));
			affiche_liste(l);
			printf("\n");
		}	
	}

	liste l2 = creer_liste();
	l2 = generer_liste(l2,Nmax,TRIE);

	printf("Concaténation de la liste l1 (%d éléments) = ",compte_elems(l));affiche_liste(l);
	printf("avec la liste l2 (%d éléments) = ",compte_elems(l2));affiche_liste(l2);
	l=concatener_listes(l,l2);
	affiche_liste(l);
	printf("La liste contient %d elements\n\n",compte_elems(l));
	l=libere_liste(l);

	l2 = creer_liste();
	l = creer_liste();
	l = generer_liste(l,Nmax,TRIE);

	l2 = generer_liste(l2,Nmax,TRIE);

	printf("Entrelacement trié de la liste l1 (%d éléments) = ",compte_elems(l));affiche_liste(l);
	printf("avec la liste l2 (%d éléments) = ",compte_elems(l2));affiche_liste(l2);
	l=entrelacer_tries(l,l2);
	affiche_liste(l);
	printf("La liste contient %d elements\n\n",compte_elems(l));
	libere_liste(l);

	l = creer_liste();
	printf("Création d'une liste en ajoutant les éléments au début :\n");
	l = generer_liste(l,Nmax,DEBUT);
	affiche_liste(l);
	l=tri_a_bulles(l);
	printf("Liste triée après tri à Bulles:");affiche_liste(l);
	l=renverse(l);
	printf("Liste renversée:");affiche_liste(l);
	libere_liste(l);

	l = creer_liste();
	printf("Création d'une liste en ajoutant les éléments au début :\n");
	l = generer_liste(l,Nmax,TRIE);
	affiche_liste(l);
	l=tri_fusion(l,compte_elems(l));
	printf("Liste triée après tri fusion:");affiche_liste(l);
	libere_liste(l);

	x=0;
	while(x<2)
	{
		printf("\nEntrez un entier positif > 2: ");scanf("%d",&x);
	}
	l = crible_era(x);
	printf("Les nombres premiers plus petits que %d sont: ",x);affiche_liste(l);
	libere_liste(l);

	x=0;
	while(x<=0)
	{
		printf("\nEntrez un entier positif K: ");scanf("%d",&x);
	}
	int nombre_tire = 0;
	liste_liste liste = creer_liste_liste(x);
	do{
		nombre_tire = alea(Nmax);
		liste = ajoute_elem_classement(liste,nombre_tire,x);
	}while(nombre_tire != 0);
	affiche_liste_liste(liste,x);
	liste = libere_liste_liste(liste,x);
}