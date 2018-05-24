(defun exo1 (liste)
	(cond
		((null liste) t)
		((null (cdr liste)) t)
		((= 1 (- (car liste) (car (cdr liste)) )) (exo1(cdr liste)))
		((= -1 (- (car liste) (car (cdr liste)) )) (exo1(cdr liste)))
		(t nil)
	)
)

(defun carre (nb)
	(cond
		((not (numberp nb)) nil)
		((<= nb 5) nil)
		(t
			(* nb nb)
		)
	)
)

(defun calcul-min (liste &optional(minimum 1000))
	(cond
		((null liste) minimum)
		((< (car liste) minimum) (calcul-min (cdr liste) (car liste)))
		(t (calcul-min (cdr liste) minimum))
	)
)
