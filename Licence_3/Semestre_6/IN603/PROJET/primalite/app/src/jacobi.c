/**
 * \file jacobi.c
 * \brief Fonctions concernant l'algorithme de Jacobi.
 * \author Clément Caumes - Yassin Doudouh
 * \date 26 Avril 2018
 *
 * Programme de test de primalité de Solovay-Strassen.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

/**
 * \fn void reduit_num_mod_denom(mpz_t nouv,mpz_t n,mpz_t m)
 * \brief Fonction qui calcule le modulo d'un nombre. 
 * \param nouv Résultat qui sera initialisé.
 * \param n Base du calcul. 
 * \param m Module du calcul. 
 */
void reduit_num_mod_denom(mpz_t nouv,mpz_t n,mpz_t m){
	mpz_t nn,mm;
	mpz_init(nn);
	mpz_init(mm);
	mpz_set(nn,n);
	mpz_set(mm,m);
	mpz_mod (nouv, nn, mm);
	mpz_clear(nn);
	mpz_clear(mm);
}

/**
 * \fn int pgcd_recursif(mpz_t result,mpz_t a,mpz_t b)
 * \brief Fonction qui calcule le PGCD. 
 * \param a Premier nombre du pgcd.
 * \param b Deuxième nombre du pgcd. 
 * \return 1 si a et b sont premiers entre eux, 0 sinon.
 */
int pgcd_recursif(mpz_t result,mpz_t a,mpz_t b){
	mpz_t reste;
	mpz_init(reste);
	// r=a%b
	mpz_mod(reste,a,b);
	
	// si r==0 return b
	if(mpz_sgn(reste)==0){
		mpz_set(result,b);
		mpz_clear(reste);
		return 1;
	}
	// sinon return pgcd(b,r)
	else{
		pgcd_recursif(result,b,reste);
		mpz_clear(reste);
		return 1;
	}
	return 1;
}

/**
 * \fn int pgcd_binary(mpz_t result,mpz_t a,mpz_t b)
 * \brief Fonction qui calcule le PGCD. 
 * \param a Premier nombre du pgcd.
 * \param b Deuxième nombre du pgcd. 
 * \return 1 si a et b sont premiers entre eux, 0 sinon.
 */
int pgcd_binaire(mpz_t result,mpz_t a,mpz_t b){
	mpz_t a_abs;
	mpz_t b_abs;
	mpz_init(a_abs);
	mpz_init(b_abs);
	
	mpz_abs(a_abs,a); // a_abs=|a|
	mpz_abs(b_abs,b); // b_abs=|b|
	
	// si |b|>|a| return pgcd(b,a)
	if(mpz_cmp(b_abs,a_abs)>0){
		pgcd_binaire(result,b,a);
		mpz_clear(a_abs);
		mpz_clear(b_abs);
		return 1;
	}
	
	// si b==0 return a
	if(mpz_sgn(b)==0){
		mpz_set(result,a);
		mpz_clear(a_abs);
		mpz_clear(b_abs);
		return 1;
	}
	
	int parite_a=mpz_tstbit(a,0);
	int parite_b=mpz_tstbit(b,0);
	
	mpz_t deux;
	mpz_init(deux);
	mpz_set_ui(deux,2);
	
	// si a et b sont pairs return 2*pgcd(a/2,b/2)
	if((parite_a==0)&&(parite_b==0)){
		mpz_cdiv_q (a,a,deux);
		mpz_cdiv_q (b,b,deux);
		pgcd_binaire(result,a,b);
		mpz_mul_ui(result,result,2);
		mpz_clear(deux);
		mpz_clear(a_abs);
		mpz_clear(b_abs);
		return 1;
	}
	
	// si a est pair et b impair return pgcd(a/2,b)
	if((parite_a==0)&&(parite_b==1)){
		mpz_cdiv_q (a,a,deux);
		pgcd_binaire(result,a,b);
		mpz_clear(deux);
		mpz_clear(a_abs);
		mpz_clear(b_abs);
		return 1;
	}
	
	// si a est impair et b pair return pgcd(a,b/2)
	if((parite_a==1)&&(parite_b==0)){
		mpz_cdiv_q (b,b,deux);
		pgcd_binaire(result,a,b);
		mpz_clear(deux);
		mpz_clear(a_abs);
		mpz_clear(b_abs);
		return 1;
	}
	
	// sinon return pgcd((|a|-|b|)/2,b)
	else{
		mpz_sub(a,a_abs,b_abs);
		mpz_cdiv_q (a,a,deux);
		pgcd_binaire(result,a,b);
		mpz_clear(deux);
		mpz_clear(a_abs);
		mpz_clear(b_abs);
		return 1;
	}
	return 1;
}

/**
 * \fn int premier_entre_eux_recursif(mpz_t a,mpz_t b)
 * \brief Fonction qui teste si deux nombres sont premiers entre eux. 
 * \param a Premier nombre du pgcd.
 * \param b Deuxième nombre du pgcd. 
 * \return 1 si a et b sont premiers entre eux, 0 sinon.
 */
int premier_entre_eux_recursif(mpz_t a,mpz_t b){
	mpz_t aa,bb,result;
	mpz_init(aa);
	mpz_init(bb);
	mpz_init(result);
	mpz_set(aa,a);
	mpz_set(bb,b);
	
	// calcul du pgcd recursif 
	pgcd_recursif(result,aa,bb);
	int test;
	if(mpz_cmp_d(result,1)==0) test=1;
	else test=0;
	
	mpz_clear(aa);
	mpz_clear(bb);
	mpz_clear(result);
	
	return test;
}

/**
 * \fn int premier_entre_eux_binaire(mpz_t a,mpz_t b)
 * \brief Fonction qui teste si deux nombres sont premiers entre eux. 
 * \param a Premier nombre du pgcd.
 * \param b Deuxième nombre du pgcd. 
 * \return 1 si a et b sont premiers entre eux, 0 sinon.
 */
int premier_entre_eux_binaire(mpz_t a,mpz_t b){
	mpz_t aa,bb,result;
	mpz_init(aa);
	mpz_init(bb);
	mpz_init(result);
	mpz_set(aa,a);
	mpz_set(bb,b);
	
	// calcul du pgcd binaire
	pgcd_binaire(result,aa,bb);
	int test;
	if(mpz_cmp_d(result,1)==0) test=1;
	else test=0;
	
	mpz_clear(aa);
	mpz_clear(bb);
	mpz_clear(result);
	
	return test;
}

/**
 * \fn int premier_entre_eux_iteratif(mpz_t a,mpz_t b)
 * \brief Fonction qui teste si deux nombres sont premiers entre eux. 
 * \param a Premier nombre du pgcd.
 * \param b Deuxième nombre du pgcd. 
 * \return 1 si a et b sont premiers entre eux, 0 sinon.
 */
int premier_entre_eux_iteratif(mpz_t a,mpz_t b){
	mpz_t aa,bb,tmp;
	mpz_init(aa);
	mpz_init(bb);
	mpz_init(tmp);
	mpz_set(aa,a);
	mpz_set(bb,b);
	
	
	// si a==b==0 --> PAS PREMIERS ENTRE EUX
	if((mpz_cmp_ui(aa,0)==0)&&(mpz_cmp_ui(bb,0)==0)){
		mpz_clear(aa);
		mpz_clear(bb);
		return 0;
	}
	// si a==0 et b==1 --> PREMIERS ENTRE EUX
	if((mpz_cmp_ui(aa,0)==0)&&(mpz_cmp_ui(bb,1)==0)){
		mpz_clear(aa);
		mpz_clear(bb);
		return 1;
	}
	// si a==1 et b==0 --> PREMIERS ENTRE EUX
	if((mpz_cmp_ui(aa,1)==0)&&(mpz_cmp_ui(bb,0)==0)){
		mpz_clear(aa);
		mpz_clear(bb);
		return 1;
	}
	
	// divisions successives d'euclide
	while(mpz_sgn(bb)!=0){
		mpz_set(tmp,aa);
		mpz_set(aa,bb);
		mpz_mod (bb, tmp, bb);
	}
	//if a==0 pas de pgcd
	if(mpz_sgn(aa)==0){
		mpz_clear(tmp);
		mpz_clear(aa);
		mpz_clear(bb);
		return -1;
	}
	else {
		int test=mpz_cmp_d (aa,1);
		mpz_clear(tmp);
		mpz_clear(aa);
		mpz_clear(bb);
		if(test==0) return 1; //PREMIERS ENTRE EUX
		else return 0; //NON PREMIERS ENTRE EUX
	}
	return -1;
}

/**
 * \fn int jacobi(mpz_t num,mpz_t denum)
 * \brief Fonction qui calcule le symbole de Jacobi. 
 * \param num Numérateur du symbole de Jacobi.
 * \param denum Dénominateur du symbole de Jacobi. 
 * \return 0, 1 ou -1 résultats possibles du symbole de Jacobi.
 */
int jacobi(mpz_t num,mpz_t denum){
	
	// si denominateur pair --> ERREUR
	if(mpz_tstbit (denum,0)==0){
		printf("Le denominateur doit etre impair");
		exit(0);
	}
	// si numerateur==denominateur --> 0
	if(mpz_cmp (num,denum)==0){
		return 0;
	}
	
	/* ETAPE 1
	 * Réduire le numerateur modulo le denominateur 
	 * (propriete 1)
	 * */
	mpz_t congr;
	mpz_init(congr);
	reduit_num_mod_denom(congr,num,denum);
	
	// si on peut réduire le numérateur (propriete 1)
	if(mpz_cmp(num,congr)!=0) {
		// jacobi(num,denum)=jacobi(congr,denum) si num=congr mod denum
		int test=jacobi(congr,denum);
		mpz_clear(congr);
		return test;
	}
	else {
		mpz_clear(congr);
	}
	
	/* ETAPE 2
	 * si num==2 alors jacobi(num,denum)=1 ou -1 selon denum
	 * (propriete 5)
	 * */
	if(mpz_cmp_d (num,2)==0){
		mpz_t congr1;
		mpz_t huit;
		mpz_init(congr1);
		mpz_init(huit);
		mpz_set_d(huit,8);
		mpz_mod (congr1,denum,huit);
		// si denum=1 mod 8 ou si denum=7 mod 8 --> jacobi(2,denum)=1
		if((mpz_cmp_d (congr1,1)==0)||(mpz_cmp_d (congr1,7)==0)){
			mpz_clear(congr1);
			mpz_clear(huit);
			return 1;
		}
		// si denum=3 mod 8 ou si denum=5 mod 8 --> jacobi(2,denum)=-1
		else if((mpz_cmp_d (congr1,3)==0)||(mpz_cmp_d (congr1,5)==0)){
			mpz_clear(congr1);
			mpz_clear(huit);
			return -1;
		}
		else{
			mpz_clear(congr1);
			mpz_clear(huit);
		}
	}
	
	/* ETAPE 2
	 * si num=2*x alors 
	 * jacobi(num,denum)=jacobi(2*x,denum)=jacobi(2,denum)*jacobi(x,denum)
	 * (propriete 3)
	 * */
	mpz_t congr_deux,deux;
	mpz_init(congr_deux);
	mpz_init(deux);
	mpz_set_ui(deux,2);
	int test_congr=mpz_divisible_p (num,deux);
	//si num multiple de 2 
	if(test_congr!=0){
		mpz_t facteur;
		mpz_init(facteur);
		//num=facteur*deux
		mpz_cdiv_q (facteur,num,deux);
		
		int calcul2=jacobi(deux,denum)*jacobi(facteur,denum);
		mpz_clear(congr_deux);
		mpz_clear(deux);
		mpz_clear(facteur);
		return calcul2;
	}
	mpz_clear(congr_deux);
	mpz_clear(deux);
	
		
	// ETAPE 3
	// propriete 4
	
	/* ETAPE 3
	 * (propriete 4)
	 * si num==1 alors jacobi(num,denum)=1
	 * */
	if(mpz_cmp_d (num,1)==0) return 1;
	/* ETAPE 3
	 * (propriete 2)
	 * si pgcd(num,denum)!=1 alors jacobi(num,denum)=0
	 * */
	if(premier_entre_eux_iteratif(num,denum)==0) return 0;
	
	/* ETAPE 4
	 * (propriete 6)
	 * sinon alors pgcd(num,denum)=1 
	 * alors jacobi(num,denum)=jacobi(denum,num) ou -1*jacobi(denum,num) selon les cas
	 * */
	mpz_t congr2,congr3;
	mpz_t quatre;
	mpz_init(congr2);
	mpz_init(congr3);
	mpz_init(quatre);
	mpz_set_d(quatre,4);
	mpz_mod (congr2,num,quatre);
	mpz_mod (congr3,denum,quatre);
		
	// si denum=1 mod 4 ou si num=1 mod 4 --> jacobi(num,denum)=jacobi(denum,num)
	if((mpz_cmp_d (congr2,1)==0)||(mpz_cmp_d (congr3,1)==0)){
		mpz_clear(congr2);
		mpz_clear(congr3);
		mpz_clear(quatre);
		return jacobi(denum,num);
	}
	// si denum=num=3 mod 4 --> jacobi(num,denum)=-1*jacobi(denum,num)
	else if((mpz_cmp_d (congr2,3)==0)&&(mpz_cmp_d (congr3,3)==0)){
		mpz_clear(congr2);
		mpz_clear(congr3);
		mpz_clear(quatre);
		return -1*jacobi(denum,num);
	}
	else{
		mpz_clear(congr2);
		mpz_clear(congr3);
		mpz_clear(quatre);
	}
	return 1;
}
