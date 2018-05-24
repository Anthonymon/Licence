(defun interspace (symbole liste)
	(cond
		((null liste) nil)
		((null (cdr liste)) (list (car liste)))
		(t
			(cons (car liste) (cons symbole (interspace symbole (cdr liste))))
		)
	)
)
