(defun interspace (carac liste)
	(cond
		((null liste) nil)
		((null (cdr liste)) liste)
		(t
			(append (list (car liste) carac) (interspace carac (cdr liste)) )
		)
	)
)
