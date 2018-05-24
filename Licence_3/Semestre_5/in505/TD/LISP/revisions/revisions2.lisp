(defun replace-symb (symb1 symb2 liste)
	(cond
		((null liste) liste)
		((and (atom liste)(eq symb1 liste)) symb2)
		((atom liste) liste)
		((consp liste) (cons (replace-symb symb1 symb2 (car liste)) (replace-symb symb1 symb2 (cdr liste))))
	)
)

(defun replace-symb2 (symb1 symb2 liste)
	(cond 
		((null liste) liste)
		(if (and (atom liste) (eq liste symb1)) 
			symb2
			liste
		)
		(t
			(cons (replace-symb symb1 symb2 (car liste)) (replace-symb symb1 symb2 (cdr liste)))
		)
	)
)



(defun addlist (liste1 liste2)
	(cond
		((not (listp liste1)) liste2)
		((not (listp liste2)) liste1)
		((null liste1) liste2)
		((null liste2) liste1)
		(t
			(cons (+ (car liste1) (car liste2)) (addlist (cdr liste1) (cdr liste2)))
		)
	)
)
