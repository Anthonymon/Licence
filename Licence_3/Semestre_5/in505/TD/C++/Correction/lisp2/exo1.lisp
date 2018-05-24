(defun diff_rec (liste)
	(if (not (listp liste))
		nil
		(cond
			((null liste) t)
			((null (cdr liste)) t)
			((or (not (numberp (car liste))) (not (numberp (cadr liste)))) nil)
			((= 1 (abs (- (car liste) (cadr liste))))
				(diff1 (cdr liste))
			)
			(t nil)
		)
	)
)


(defun diff_it (liste)
	(cond 
		((not (listp liste)) nil)
		((or (null liste) (null (cdr liste))) t)
		(t
			(do ((tmp liste (cdr tmp))) ;double parentheses, do prend une liste de variables
				((null (cdr tmp)) t) ;condition d'arret du do, if implicite
				(if (or (not (numberp (car tmp))) (not (numberp (cadr tmp))))
					(return nil)
				)
				(if (not (= 1 (abs (- (car tmp) (cadr tmp)))))
					(return nil)
				)
			)
		)
	)
)
