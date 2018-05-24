(defun interspace (caractere liste)
	(cond
		((null liste) nil)
		(t
			(append (list (car liste) caractere)(interspace caractere (cdr liste)))
		)
	)
)
