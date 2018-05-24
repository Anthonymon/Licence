; renvoyer le dernier element d'une liste
(defun my-last (liste)
	(cond	
			((null liste) nil)
			((null (cdr liste)) (car liste))
			(t (my-last (cdr liste)))
	)
)

; trouver l'avant dernier element d'une liste
(defun my-second-last1(liste)
	(cond	
			((null liste) nil)
			((null (cdr liste)) nil)
			((null (cddr liste)) (car liste))
			(t (my-second-last1(cdr liste)))
	)
)

(defun my-second-last2(liste)
	(cond
			((< (length liste) 2) nil)
			((eql (length liste) 2) (car liste))
			(t (my-second-last (cdr liste)) )
	)
)

; trouver le k-ieme element d'une liste
(defun my-find (liste k)
	(cond
			((equal (numberp k) nil) nil)
			((equal 0 k) (car liste))
			(t (my-find (cdr liste) (- k 1)))
	)
)

; trouver le nombre d'elements d'une liste
(defun compte-elem (liste)
	(cond 
			((null liste) 0)
			(t (+ 1 (compte-elem (cdr liste))))
	)
)

; inverser les elements d'une liste
(defun my-reverse (liste)
	(cond
			((null liste) nil)
			((null (cdr liste)) liste)
			(t (append (my-reverse (cdr liste))(list (car liste))))
	)
)

; aplatir une structure de listes imbriquees
(defun my-flatten(liste)
	(cond
			((null liste) nil)
			;(t (append (car liste) (my-flatten (cdr liste))))
			(t (append (if (listp (car liste))
								(my-flatten (car liste))
								(list (car liste))
						)
						(my-flatten(cdr liste))
				)
			)
	)
)

; ecrire une fonction qui prend une liste de nombres et renvoie vrai si et seulement si la difference entre deux nombres successifs est 1 
(defun diff(liste)
	(cond
			((null liste) t)
			((null (cdr liste)) t)
			((= (- (car liste) (car (cdr liste))) 1) (diff (cdr liste)) )
			((= (- (car liste) (car (cdr liste))) -1) (diff (cdr liste)) )
			(t nil)
	)

)

; renvoyer le carre d'un nombre et ne le calcule pas si le nombre est inferieur ou egal a 5
(defun carre(nb)
	(cond
		((<= nb 5) nil)
		(t (* nb nb))
	)
)

; afficher le plus petit et le plus grand element d'une liste
(defun min-max (liste)
	(if (not (listp liste)) 
		(nil)
		(let ((minimum (car liste))(maximum (car liste)))
			(dolist (x liste)
				(if (< x minimum)(setf minimum x))
				(if (> x maximum)(setf maximum x))
			)
			(format t "min: ~A max: ~A" minimum maximum)
		)
	)
)

; calculer le produit des deux plus grands nombres d'une liste
(defun maxi(liste)
	(cond
		((null liste) nil)
		((not(listp liste)) nil)
		(t
			(let ((maximum (car liste)))
				(progn
					(dolist (elem liste)
						(if (> elem maximum)(setf maximum elem))
					)
				)
				maximum
			)
		)
	)
)

(defun produit-maxi(liste)
	(cond
		((null liste) nil)
		((not(listp liste)) nil)
		((null (cdr liste)) nil)
		(t (* (maxi liste) (maxi (remove (maxi liste) liste))))
	)
)

; inverser la liste
(defun my-rever(liste)
	(cond
		((null liste) nil)
		(t (append (my-rever (cdr liste)) (list (car liste)) ) )
	)
)

; faire la meme chose que nth
(defun my-nth(liste nb)
	(cond
		((not(listp liste)) nil)
		((< nb 0) nil)
		((= nb 0)(car liste))
		(t (my-nth (cdr liste)(- nb 1)))
	)
)

; faire la meme chose que nthcdr
(defun my-nthcdr (liste nb)
	(cond
		((not (listp liste)) nil)
		((< nb 0) nil)
		((= nb 0) liste )
		(t (my-nthcdr (cdr liste) (- nb 1)))
	)
)

; calcule le max
(defun calcul-max-iteratif(liste)
	(cond
		((null liste) nil)
		((not(listp liste)) nil)
		(t
			(let ((maximum (car liste)))
				(progn
					(dolist (elem liste)
						(if (> elem maximum)(setf maximum elem))
					)
				)
				maximum
			)
		)
	)
)

; compte le nombre d'elements dans une liste
(defun compte(liste caractere)
	(cond
		((not (listp liste)) nil)
		((null liste) 0)
		((eql (car liste) caractere) (+ 1 (compte (cdr liste) caractere)))
		(t (compte (cdr liste) caractere))	
	)
)

(defun compte2(liste caractere)
	(cond
		((null liste) nil)
		((not(listp liste)) nil)
		(t
			(let ((compteur 0))
				(progn
					(dolist (elem liste)
						(if (eql elem caractere)(setf compteur (+ compteur 1)))
					)
				)
				compteur
			)
		)
	)
)

; affiche le nombre de fois qu'apparait chaque caractere
(defun compte (elem liste)
	(cond 
		((null liste) 0)
		(t
			(if (eql elem (car liste))
				(+ 1 (compte elem (cdr liste)))
				(compte elem (cdr liste))
			)
		)
	)
)

;(defun compte-freq(liste)
;	(cond 
;		((null liste) nil)
;		((not (listp liste)) nil)
;		(t
;			(let ((compteur 0))
;				(progn
;					(dolist (elem liste)
;						(progn
;							(setf compteur (compte elem liste))
;							(format t "\"~A\" -> ~A ~%" elem compteur)
;							(setf compteur 0)
;							(setf liste (remove elem liste))
;						)
;					)
;				)
;			)
;		)
;	)
;)

(defun compte-freq-rec (liste)
	(cond
		((null liste) nil)
		(t
			(progn
				(format t "\"~A\" -> ~A ~%" (car liste) (compte (car liste) liste))
				(compte-freq-rec (cdr (remove (car liste) liste)))
				;(compte-freq-rec (cdr liste))
				;(compte-freq-rec (cdr (remove (car liste) (cdr liste))))
			)
		)
	)
)

; faire un tri

(defun calcul-max (liste &optional(maximum 0))
	(cond
		((null liste) maximum)
		(t
			(if (< maximum (car liste))
				(calcul-max (cdr liste) (car liste))
				(calcul-max (cdr liste) maximum)
			)
		)
	)
)

(defun calcul-min (liste &optional(minimum 1000))
	(cond
		((null liste) minimum)
		(t
			(if (> minimum (car liste))
				(calcul-min (cdr liste) (car liste))
				(calcul-min (cdr liste) minimum)
			)
		)
	)
)

(defun tri (liste)
	(cond
		((null liste) nil)
		(t
			(append 
				(list (calcul-min liste)) 
				(tri (remove (calcul-min liste) liste))
			)
		)
	)
)

; extraire une sous liste dans une liste
(defun enleve-deb (liste deb)
	(cond 
		((not(numberp deb)) nil)
		((< deb 0) nil)
		((= deb 0) liste)
		(t
			(enleve-deb (cdr liste) (- deb 1))
		)
	)
)

(defun enleve-fin (liste fin)
	(cond 
		((not(numberp fin)) nil)
		((< fin 0) nil)
		((= fin 0) (car liste))
		(t
			;(enleve-fin (cdr liste) (- fin 1))
			(cons (car liste) (enleve-fin (cdr liste) (- fin 1)))
		)
	)
)


(defun extraire (liste deb fin)
	(cond 
		((> deb fin) nil)
		(t
			(enleve-deb (enleve-fin liste fin) deb)
		)
	)
)

